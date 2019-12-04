/*Première	étape	:	Gestion	de	valeurs	*/
/*
CREATE OR REPLACE PROCEDURE NOMBRE_EMPRUNTS (NUMERO IN INTEGER)
IS
CURSOR C IS 
SELECT NUM_AB
FROM EMPRUNT 
WHERE NUM_AB=NUMERO;
TOTALE INTEGER := 0;
N NUMBER(6) ;
BEGIN
OPEN C;
FETCH C INTO N;
WHILE(C%FOUND)
LOOP
TOTALE := TOTALE+1;
DBMS_OUTPUT.PUT_LINE(TOTALE);
FETCH C INTO N ;
END LOOP;
IF(TOTALE = 0) THEN
DBMS_OUTPUT.PUT_LINE('NUMERO D ABONNE INVALIDE ');
ELSE 
INSERT INTO AB_NB VALUES(NUMERO,TOTALE);
END IF;
EXCEPTION WHEN OTHERS THEN DBMS_OUTPUT.PUT_LINE(SQLERRM);
END;
/

*/


CREATE OR REPLACE PROCEDURE NOMBRE_EMPRUNTS (NUMERO IN INTEGER)
IS
CURSOR C IS 
SELECT *
FROM EMPRUNT 
WHERE NUM_AB=NUMERO;
TOTALE INTEGER := 0;
BEGIN
FOR T IN C 
LOOP 
TOTALE := TOTALE+1;
END LOOP;
IF(TOTALE = 0) THEN
DBMS_OUTPUT.PUT_LINE('NUMERO D ABONNE INVALIDE ');
ELSE 
INSERT INTO AB_NB VALUES(NUMERO,TOTALE);
EXCEPTION WHEN OTHERS THEN DBMS_OUTPUT.PUT_LINE(SQLERRM);
END;
