SELECT name FROM
people JOIN stars ON stars.person_id = people.id 
WHERE movie_id IN (
SELECT movie_id FROM
movies JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE person_id = (SELECT id FROM
people WHERE people.name = "Kevin Bacon" AND birth = 1958))
GROUP BY name
EXCEPT SELECT name FROM people WHERE name = "Kevin Bacon";




