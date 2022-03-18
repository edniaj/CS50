SELECT songs.name
FROM artists INNER JOIN songs
WHERE songs.artist_id = artists.id songs.name LIKE "%feat.%"