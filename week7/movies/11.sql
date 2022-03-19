SELECT title
FROM movies JOIN ratings ON movies.id = ratings.movie_id
WHERE id in (
	SELECT movie_id
	FROM ratings
	WHERE movie_id in (
		SELECT movie_id
		FROM people JOIN stars ON people.id = stars.person_id
		WHERE people.name = "Chadwick Boseman"
	)
)
ORDER BY ratings.rating DESC
	LIMIT 5
