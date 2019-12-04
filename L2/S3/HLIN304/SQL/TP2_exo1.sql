SELECT COUNT(*),ANNEE
FROM FILM
GROUP BY ANNEE ;


SELECT ANNEE,NBSPECTATEURS 
FROM FILM 
GROUP BY ANNEE,NBSPECTATEURS;


SELECT ANNEE ,COUNT(*)AS NBFILM
FROM FILM
WHERE (ANNEE >= 1990 )
GROUP BY ANNEE ; 


SELECT ANNEE ,COUNT(*)AS NBFILM ,NBSPECTATEURS
FROM FILM
GROUP BY ANNEE ,NBSPECTATEURS
HAVING (NBSPECTATEURS >= 1000000);