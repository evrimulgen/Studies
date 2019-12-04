CREATE OR REPLACE PROCEDURE P1 (COEFF IN FLOAT,NUM_A IN INTEGER,REDUC_A OUT FLOAT)
IS
/* VARIABLES LOCALES */
BEGIN
SELECT REDUC INTO REDUC_A FROM ABONNE WHERE NUM_AB=NUM_A;
REDUC_A := REDUC_A * COEFF;
EXCEPTION WHEN OTHERS THEN DBMS_OUTPUT.PUT_LINE(SQLERRM);
END;
/