declare
prenomA varchar(20);
nomA varchar(20);
villeA varchar(20);
BEGIN
SELECT NOM,PRENOM,VILLE
INTO nomA,prenomA,villeA
FROM ABONNE
WHERE NUM_AB= 901001;
dbms_output.put_line('Abonne  '||nomA ||' '||prenomA||' '||villeA);
exception
WHEN OTHERS THEN dbms_output.put_line('Pb'||SQLERRM);
END;
/
