SELECT title
FROM movies
WHERE id in (
	SELECT movie_id
	FROM ratings
	WHERE movie_id in (
		SELECT movie_id
		FROM people JOIN stars ON people.id = stars.person_id
		WHERE people.name = "Chadwick Boseman"
	)
	ORDER BY ratings.rating DESC
	LIMIT 5
)
