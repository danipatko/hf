-- Feladat: 2jelenleg
SELECT nev
FROM Tag AS T
WHERE T.elhunyt IS NULL
ORDER BY nev;



-- Feladat: 3mas
SELECT Tag.nev, Tag.identitas, Tagsag.tipus, Tagsag.ev
FROM Tag INNER JOIN Tagsag ON Tag.id = Tagsag.tagid
WHERE (Tagsag.tipus = "r" OR Tagsag.tipus = "l") AND Tag.identitas IS  NOT NULL
ORDER BY Tagsag.ev;



-- Feladat: 4mikor
SELECT Tag.nev, Min(Tagsag.ev)
FROM Tag INNER JOIN Tagsag ON Tag.id = Tagsag.tagid
GROUP BY Tag.nev;



-- Feladat: 5arany
SELECT (SELECT Count(*) FROM Tag WHERE Tag.nem = "n")/Count(*)
FROM Tag;



-- Feladat: 6atlag
SELECT Avg(inter)
FROM (SELECT Max(Tagsag.ev) - Min(Tagsag.ev) AS inter FROM Tag INNER JOIN Tagsag ON Tag.id = Tagsag.tagid GROUP BY tagid HAVING Count(*) = 2)  AS [%$##@_Alias];



-- Feladat: 7teller
SELECT nev, ev, elhunyt
FROM tag, tagsag
WHERE tag.id=tagid
AND ev<=(SELECT Max(T1.ev) FROM Tag AS T INNER JOIN Tagsag AS T1 ON T1.tagid = T.id WHERE nev = "Teller Ede")
AND (elhunyt>=(SELECT Min(T1.ev) FROM Tag AS T INNER JOIN Tagsag AS T1 ON T1.tagid = T.id WHERE nev = "Teller Ede") OR elhunyt IS NULL)
AND tipus='t';



-- Feladat: 8rendes
SELECT Tagsag.ev, Tag.nev, Tag.szuletett&" - "&Tag.elhunyt AS elt
FROM Tag INNER JOIN Tagsag ON Tag.id = Tagsag.tagid
WHERE Tagsag.tipus="r"
ORDER BY Tagsag.ev, Tag.nev;



