import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd
import datetime
# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    rows = db.execute("SELECT * FROM receipts WHERE user_id = ?", session['user_id'])
    # [{'id': 5, 'price': 23.22, 'amount': 33, 'symbol': 't', 'user_id': 3}, {'id': 6, 'price': 905.39, 'amount': 1, 'symbol': 'TSLA', 'user_id': 3}]
    balance = db.execute("SELECT cash FROM users WHERE id = (?)", session['user_id'])[0]['cash']
    accountHoldings = aggregateBuy()
    accountHoldings = accountHoldings
    listKey = accountHoldings.keys()
    grandTotal = balance
    for i in listKey:
        grandTotal += accountHoldings[i]['amount'] * accountHoldings[i]['price']
    print(f'Grand total: {grandTotal}')
    print(accountHoldings)
    print("balance = ",balance,grandTotal)


    return render_template("index.html", balance=balance, accountHoldings = accountHoldings, listKey=listKey,grandTotal=grandTotal)

def aggregateBuy():
    rows = db.execute("SELECT * FROM receipts WHERE user_id = ?", session['user_id'])
    accountHoldings = {}
    for i in rows:
        amount = i['amount']
        price = lookup(i['symbol'])['price']
        if i['symbol'] not in accountHoldings.keys():
            accountHoldings[i['symbol']] = {"amount":amount, "price":price}
        else:
            if i['action'] == 'buy':
                accountHoldings[i['symbol']]['amount'] += amount
            else:
                accountHoldings[i['symbol']]['amount'] -= amount
    return accountHoldings



@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        value = lookup(symbol)
        if value == None:
            return apology("No selling here bro")
        amount = request.form.get("shares")
        try:
            amount = eval(amount)
            if amount < 0:
                return apology("No Negative number")
        except:
            return apology("Bro... positive integer number only")
        price = value["price"]
        id = session["user_id"]
        print("id = ",type(id),'  ',id)
        # We are doing to edit the database
        balance = db.execute("SELECT cash FROM users WHERE id = (?)", id)[0]['cash']
        totalCost = int(price) * int(amount)
        afterDeduction = balance - totalCost
        print("After deduction   :",afterDeduction)

        if afterDeduction < 0:
            return apology("No money no honey")
        writeDate = str(datetime.datetime.now())
        db.execute("UPDATE users SET cash = ? WHERE id = ?",afterDeduction, id)
        db.execute("INSERT INTO receipts (price, amount, symbol, user_id,action,date) VALUES(?,?,?,?,?, ?)",price,amount,symbol,id,"buy",writeDate)
        # db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", name,hash)
        return redirect("/buy")

    if request.method == "GET":
        return render_template("buy.html")



@app.route("/history")
@login_required
def history():
    values = db.execute("SELECT * FROM receipts")
    print("values = ",values[0]['price'])
    # return render_template("history.html")
    return render_template("history.html",values = values)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")): # rows[0] because its the top of the sqlite row
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "GET":
        return render_template("quote.html")
    if request.method == "POST":
        value = lookup(request.form.get("symbol"))
        print(value)
        return render_template("quoted.html",value=value)


@app.route("/topup", methods=["GET", "POST"])
@login_required
def topup():
    if request.method == "GET":
        return render_template("topup.html")
    if request.method == "POST":
        value = request.form.get("amount")
        value = int(value)
        cashBalance = db.execute("SELECT cash FROM users WHERE id = (?)", session['user_id'])[0]['cash']
        cashBalance += value
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cashBalance, session['user_id'])
        # return render_template("topup.html")
        return redirect("/")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        name = request.form.get("name")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # managing error
        if password != confirmation:
            return apology("Password does not match")
        if name == "" or password == "" or confirmation == "" :
            return apology("Walao")

        # no errors
        hash = generate_password_hash(password)
        if db.execute("SELECT * FROM users WHERE username  = ?", name):
            return apology("User exists in the database")

        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", name,hash)

        return redirect("/")

    if request.method == "GET":
        return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    id = session['user_id']
    if request.method == "POST":
        symbol = request.form.get("symbol") #Symbol that you want to sell
        value = lookup(symbol)
        price = value["price"]
        if value == None:
            return apology("No selling here bro")
        amount = request.form.get("shares")
        try:
            amount = eval(amount)
            if amount < 0:
                return apology("No Negative number")
        except:
            return apology("Bro... positive integer number only")
        accountHoldings = aggregateBuy()
        balanceShare = accountHoldings[symbol]['amount']
        if amount > balanceShare :
            return apology("You dont have enough shares you goofball")
        else :
            cashBalance = db.execute("SELECT cash FROM users WHERE id = (?)", id)[0]['cash']
            cashback = int(amount) * int(price)
            print(cashBalance)
            print(cashback)
            cashBalance += cashback
            print(cashBalance)
            writeDate = str(datetime.datetime.now())
            db.execute("UPDATE users SET cash = ? WHERE id = ?", cashBalance, session['user_id'])
            db.execute("INSERT INTO receipts (price, amount, symbol, user_id,action,date) VALUES(?,?,?,?,?, ?)",price,amount,symbol,session["user_id"],"sell",writeDate)
        return render_template("sell.html")
    if request.method == "GET":
        return render_template("sell.html")



