SELECT movies.title, ratings.rating
FROM movies JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.year = 2010 and movies.year >0
ORDER BY ratings.rating DESC