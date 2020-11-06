SELECT name
FROM people
JOIN stars ON stars.person_id = people.id
WHERE movie_id in

(SELECT movie_id
FROM stars
JOIN people ON (people.id = stars.person_id)
WHERE people.birth = 1958 AND people.name = "Kevin Bacon")
AND people.name != "Kevin Bacon";