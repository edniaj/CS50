SELECT songs.name
FROM artists INNER JOIN songs
WHERE songs.artist_id = artists.id and songs.name LIKE "%feat.%"