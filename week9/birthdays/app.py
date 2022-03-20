import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

months = [i for i in range(1,13)] #Number of days

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")
        db.execute("INSERT INTO birthdays (name,month,day) VALUES(?,?,?)",name=name, month=month,day=day)
        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html

        return render_template("index.html")



#
# Complete the implementation of a web application to let users store and keep track of birthdays.

# GET, in a table, all of the people in your database along with their birthdays.

# query the birthdays.db database for all birthdays -> Pass all of that data to your index.html template.

# Render table -> Each row should have two columns: name, birthday
# When the / route is requested via POST, your web application should add a new birthday to your database and then re-render the index page. (Redirect)
# First, in index.html, add an HTML form. The form should let users type in a name, a birthday month, and a birthday day. Be sure the form submits to / (its “action”) with a method of post.

# Then, in app.py, add logic in your POST request handling to INSERT a new row into the birthdays table based on the data supplied by the user. (Using SQL)
# Optionally, you may also:

# Add the ability to delete and/or edit birthday entries.
# Add any additional features of your choosing!




