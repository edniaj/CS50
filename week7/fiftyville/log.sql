-- Keep a log of any SQL queries you execute as you solve the mystery.




4/ Im the bakery owner, and someone came in, suspiciously whispering into a phone for about half an hour. They never bought anything.

3/As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say
that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the
phone to purchase the flight ticket.




SELECT *
FROM bank_accounts
WHERE account_number in (
	SELECT account_number
	FROM atm_transactions
	WHERE day = 28 and atm_location = "Leggett Street"
)

2.1.1/



SELECT *
FROM atm_transactions
WHERE day = 28 and atm_location = "Leggett Street"
2.1 /

2/ I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma s bakery,
I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.



5P2BI95
94KL13X
6P58WS2
4328GD8
G412CB7
L93JTIZ
322W7JE
0NTHK55

SELECT *
FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND year = 2021 AND hour = 10 AND minute <= 25

1.1/ Potential license plate

1/ Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.


/////////////////////////////////////////////////
SELECT *
FROM interviews
WHERE transcript like "%bakery%"

Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
Interviews were conducted today with three witnesses who were present at the time –
each of their interview transcripts mentions the bakery.

SELECT *
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND year = 2021