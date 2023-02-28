-- Feladat: def1
SELECT Szulo.veznev&" "&Szulo.kernev&" l?nya "&Gyerek.veznev&" "&Gyerek.kernev
FROM (U AS Szulo INNER JOIN G ON Szulo.id = G.szulo) INNER JOIN U AS Gyerek ON G.gyerek = Gyerek.id
WHERE Gyerek.nem = "No";



-- Feladat: def2
SELECT Szulo.veznev&" "&Szulo.kernev&" apja "&Gyerek.veznev&" "&Gyerek.kernev&"-nak"
FROM (U AS Gyerek INNER JOIN G ON Gyerek.id = G.gyerek) INNER JOIN U AS Szulo ON G.szulo = Szulo.id
WHERE Szulo.nem = "F?rfi";



-- Feladat: def3
SELECT Nagyszulo.veznev & " " & Nagyszulo.kernev & " unok?ja " & Gyerek.veznev & " " & Gyerek.kernev AS Expr1
FROM (U AS Nagyszulo INNER JOIN G ON Nagyszulo.id = G.szulo) INNER JOIN (G AS G_1 INNER JOIN U AS Gyerek ON G_1.gyerek = Gyerek.id) ON G.gyerek = G_1.szulo;



-- Feladat: def4
SELECT DISTINCT fater.veznev & " " & fater.kernev & " ?s " & muter.veznev & " " & muter.kernev & " h?zasp?r" AS Expr1
FROM ((U AS fater INNER JOIN G ON fater.id = G.szulo) INNER JOIN G AS G_1 ON G.gyerek = G_1.gyerek) INNER JOIN U AS muter ON G_1.szulo = muter.id
WHERE (((G.szulo)<[G_1].[szulo]));



-- Feladat: def5
SELECT DISTINCT U.veznev&" "&U.kernev&" ?s "&U_1.veznev&" "&U_1.kernev&" tes?k"
FROM U INNER JOIN (U AS U_1 INNER JOIN (G INNER JOIN G AS G_1 ON G.szulo = G_1.szulo) ON U_1.id = G.gyerek) ON U.id = G_1.gyerek
WHERE G.gyerek < G_1.gyerek;



-- Feladat: def6
SELECT DISTINCT U.veznev&" "&U.kernev&" ?s "&U_1.veznev&" "&U_1.kernev&" tes?k"
FROM U INNER JOIN (U AS U_1 INNER JOIN (G INNER JOIN G AS G_1 ON G.szulo = G_1.szulo) ON U_1.id = G.gyerek) ON U.id = G_1.gyerek
WHERE G.gyerek < G_1.gyerek AND U_1.nem = "No" AND U.nem = "No";



-- Feladat: def7
SELECT *
FROM (SELECT szulo, gyerek FROM G)  AS T INNER JOIN U ON T.szulo = U.id
WHERE U.nem = "No";



-- Feladat: egroup1
SELECT TOP 1 Count(veznev)
FROM U
GROUP BY veznev
ORDER BY Count(veznev) DESC;



-- Feladat: egroup2
SELECT U.veznev & " " & U.kernev & ": " & gy
FROM (SELECT szulo, count(gyerek) AS gy FROM G GROUP BY szulo)  AS T INNER JOIN U ON T.szulo = U.id;



-- Feladat: egroup3
SELECT TOP 1 U.veznev & " " & U.kernev & ": " & gy
FROM (SELECT szulo, count(gyerek) AS gy FROM G GROUP BY szulo)  AS T INNER JOIN U ON T.szulo = U.id
ORDER BY gy DESC;



-- Feladat: egroup4
SELECT U.veznev & " " & U.kernev & ": " & gy
FROM (SELECT szulo, count(gyerek) AS gy FROM G GROUP BY szulo)  AS T INNER JOIN U ON T.szulo = U.id
WHERE gy=2;



-- Feladat: egroup5
SELECT gy, COUNT(gy)
FROM (SELECT szulo, count(gyerek) AS gy FROM G GROUP BY szulo)  AS [%$##@_Alias]
GROUP BY gy;



-- Feladat: egroup6
SELECT Count(*)
FROM (SELECT Count(veznev) AS hord FROM U GROUP BY veznev)  AS [%$##@_Alias]
WHERE hord = 1;



-- Feladat: esum1
SELECT DISTINCT veznev
FROM U;



-- Feladat: esum2
SELECT Count(*)
FROM (SELECT DISTINCT veznev FROM U)  AS [%$##@_Alias];



-- Feladat: esum3
SELECT MAX(veznev), MIN(veznev)
FROM U;



-- Feladat: esum4
SELECT Count(*)
FROM U
GROUP BY nem;



-- Feladat: proj1
SELECT Count(*)
FROM G
GROUP BY szulo
HAVING Count(G.gyerek) > 0;



-- Feladat: proj2
SELECT Count(*)
FROM G
GROUP BY szulo;



-- Feladat: proj3
SELECT veznev&" "&kernev
FROM (SELECT szulo FROM G GROUP BY szulo)  AS T INNER JOIN U ON U.id = T.szulo
ORDER BY veznev, kernev;



-- Feladat: proj4
SELECT TOP 1 veznev&" "&kernev
FROM (SELECT szulo FROM G GROUP BY szulo)  AS T INNER JOIN U ON U.id = T.szulo
ORDER BY veznev, kernev;



-- Feladat: proj5
SELECT veznev&" "&kernev
FROM (SELECT gyerek, Count(szulo) FROM G GROUP BY gyerek)  AS T INNER JOIN U ON U.id = T.gyerek;



-- Feladat: proj6
SELECT COUNT(*)
FROM (SELECT gyerek, Count(szulo) FROM G GROUP BY gyerek)  AS [%$##@_Alias];



-- Feladat: proj7
SELECT veznev&" "&kernev
FROM (SELECT gyerek, Count(szulo) FROM G GROUP BY gyerek)  AS T INNER JOIN U ON U.id = T.gyerek
ORDER BY veznev, kernev;



-- Feladat: proj8
SELECT TOP 1 veznev&" "&kernev
FROM (SELECT gyerek, Count(szulo) FROM G GROUP BY gyerek)  AS T INNER JOIN U ON U.id = T.gyerek
ORDER BY veznev DESC , kernev DESC;



