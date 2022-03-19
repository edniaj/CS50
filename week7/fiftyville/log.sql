-- Keep a log of any SQL queries you execute as you solve the mystery.

DESTINATION -> LaGuardia Airport

SELECT full_name
FROM airports
WHERE id in
(
	SELECT destination_airport_id
	FROM flights
	WHERE year = 2021 and month = 7 and day =29
	ORDER by hour ASC LIMIT 1
)


3.2/ Investigate earliest flight


(130) 555-0289	(996) 555-8899	2021	7	28	51
(499) 555-9472	(892) 555-8872	2021	7	28	36
(367) 555-5533	(375) 555-8161	2021	7	28	45
(609) 555-5876	(389) 555-5198	2021	7	28	60
(499) 555-9472	(717) 555-1342	2021	7	28	50
(286) 555-6063	(676) 555-6554	2021	7	28	43
(770) 555-1861	(725) 555-3243	2021	7	28	49
(031) 555-6622	(910) 555-3251	2021	7	28	38
(826) 555-1652	(066) 555-9701	2021	7	28	55
(338) 555-6650	(704) 555-2131	2021	7	28	54


SELECT *
FROM phone_calls
WHERE year = 2021 and month = 7 and day =28 and duration <= 60

3.1/  Investigate phone number

As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say
that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the
phone to purchase the flight ticket.
3/


Diana 1
Bruce 1
Matching Phone number with people




Iman 1
Luca 1
Diana 1 (770) 555-1861
Bruce 1 (367) 555-5533
Matching license plate with people

SELECT name
FROM people
WHERE id in (
	SELECT person_id
	FROM bank_accounts
	WHERE account_number in (
		SELECT account_number
		FROM atm_transactions
		WHERE day = 28 and atm_location = "Leggett Street"
	)
)

2.1.1/ Find name based on people id from bank account info thru ATM transaction



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