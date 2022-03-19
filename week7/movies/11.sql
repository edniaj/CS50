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




-- write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Chadwick Boseman.