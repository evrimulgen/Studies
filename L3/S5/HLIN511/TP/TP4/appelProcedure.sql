DECLARE
REDUC FLOAT;
monException EXCEPTION;
BEGIN
P1(30,902043,REDUC);
IF REDUC > 500 THEN
RAISE monException;
END IF;
dbms_output.put_line('NOUVEL REDUCTION EN FRANCE  '||REDUC);
EXCEPTION WHEN monException THEN DBMS_OUTPUT.PUT_LINE('VOUS ÊTES FOU !!!');
END;
/