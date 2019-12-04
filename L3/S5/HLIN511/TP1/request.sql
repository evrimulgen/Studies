--1
SELECT NOM,PRENOM
FROM ABONNE
WHERE VILLE='MONTPELLIER';

--2
SELECT *
FROM EXEMPLAIRE
WHERE CODE_PRET='EMPRUNTABLE';

--3

SELECT TITRE,CATEGORIE
FROM LIVRE
WHERE CATEGORIE<>'SCIENCES'
      AND
      CATEGORIE<>'LOISIRS'
      AND
      CATEGORIE<>'MEDECINE';


SELECT TITRE,CATEGORIE
FROM LIVRE
WHERE CATEGORIE NOT IN ('SCIENCES','LOISIRS','MEDECINE');
--4

SELECT *
FROM EMPRUNT
WHERE  D_RET_REEL = NULL;

--5

SELECT NUM_EX,D_EMPRUNT
FROM ABONNE,EMPRUNT
WHERE ABONNE.NUM_AB=EMPRUNT.NUM_AB;

--6

SELECT  NUM_EX,CODE_PRET,ETAT
FROM LIVRE,EXEMPLAIRE,EMPRUNT
WHERE EXEMPLAIRE.NUMERO=EMPRUNT.NUM_EX 
      AND
      LIVRE.ISBN=EXEMPLAIRE.ISBN
      AND
      TITRE='LE MUR';

--7

SELECT E2.NUMERO
FROM EXEMPLAIRE E1,EXEMPLAIRE E2
WHERE E2.ETAT='BON'
      AND
      E2.ISBN=E1.ISBN
      AND
      E1.NUMERO='4112'
      AND
      E2.NUMERO<>'4112'

--8

SELECT CATEGORIE
FROM LIVRE
WHERE CATEGORIE NOT IN (SELECT CATEGORIE
       	FROM LIVRE,EXEMPLAIRE,EMPRUNT
	WHERE LIVRE.ISBN=EXEMPLAIRE.ISBN
	      AND
	      EXEMPLAIRE.NUMERO=EMPRUNT.NUM_EX);

--9

SELECT COUNT(*)
FROM EMPRUNT,ABONNE
WHERE EMPRUNT.NUM_AB=ABONNE.NUM_AB
      AND
      NOM='RENARD' 
      AND
      PRENOM='ALBERT';

--10
SELECT MIN(TARIF)
FROM ABONNE

--11
SELECT NUMERO
FROM EXEMPLAIRE
WHERE ETAT='ABIME'
      AND
      NUMERO NOT IN ( SELECT NUM_EX
      	     	      FROM EMPRUNT );

--12
SELECT MOT
FROM MOT_CLEF
WHERE MOT NOT IN (SELECT MOT
      	      	  FROM CARACTERISE ) ;


--13
SELECT NOM,PRENOM,COUNT(*) AS NB_E,CATEGORIE 
FROM ABONNE,EMPRUNT,LIVRE,EXEMPLAIRE
WHERE EMPRUNT.NUM_AB = ABONNE.NUM_AB
      AND
      EMPRUNT.NUM_EX=EXEMPLAIRE.NUMERO
      AND
      EXEMPLAIRE.ISBN=LIVRE.ISBN
GROUP BY NOM,PRENOM,CATEGORIE;

--14
SELECT ISBN
FROM EXEMPLAIRE E1,EXEMPLAIRE E2
WHERE ISBN