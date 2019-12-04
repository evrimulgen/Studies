
INSERT INTO OPERATEUR VALUES('OP42','ROBERT',32);
INSERT INTO OPERATEUR VALUES('OP10','SOPHIE',41);
INSERT INTO OPERATEUR VALUES('OP78','LUCETTE',25);
INSERT INTO OPERATEUR VALUES('OP22','ALBERT',25);
INSERT INTO OPERATEUR VALUES('OP57','MARC',38);


INSERT INTO MACHINE VALUES('M12','PERSEUCE');
INSERT INTO MACHINE VALUES('M13','PONCEUSE');
INSERT INTO MACHINE VALUES('M14','TOUR NUMERIQUE');


INSERT INTO PIECE VALUES('P1','PIECE1','M12','OP10',250);
INSERT INTO PIECE VALUES('P2','PIECE2','M12','OP22',600);
INSERT INTO PIECE VALUES('P3','PIECE3','M14','OP22',200);
INSERT INTO PIECE VALUES('P4','PIECE4','M13','OP78',150);


INSERT INTO QUALIFIE_SUR VALUES('OP10','M12',to_date('15-JAN-00'));
INSERT INTO QUALIFIE_SUR VALUES('OP22','M12',to_date('20-MAY-01'));
INSERT INTO QUALIFIE_SUR VALUES('OP10','M13',to_date('10-OCT-99'));
INSERT INTO QUALIFIE_SUR VALUES('OP42','M13',to_date('17-JAN-02'));
INSERT INTO QUALIFIE_SUR VALUES('OP78','M12',to_date('19-JUL-98'));
INSERT INTO QUALIFIE_SUR VALUES('OP10','M14',to_date('04-MAY-01'));