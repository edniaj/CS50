SELECT AVG(songs.energy)
FROM artists INNER JOIN songs
WHERE artists.id = songs.artist_id and artists.name = "Drake"