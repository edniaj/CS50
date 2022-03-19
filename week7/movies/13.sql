SELECT name
FROM people
where id in (
	SELECT person_id
	FROM stars
	WHERE movie_id in (
		SELECT movie_id
		FROM stars
		WHERE person_id = (
			SELECT id
			FROM people
			WHERE name = "Kevin Bacon" AND birth = 1958
		)
	) AND person_id != (
		SELECT id
		FROM people
		WHERE name = "Kevin Bacon" AND birth = 1958
	)
)
