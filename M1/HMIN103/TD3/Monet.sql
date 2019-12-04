DROP TABLE presse;
DROP TABLE presse_journal;
DROP TABLE presse_journal_nom;
DROP TABLE presse_journal_directeur;
DROP TABLE presse_journal_directeur_nom;
DROP TABLE presse_journal_directeur_prenom;
DROP TABLE presse_journal_article;
DROP TABLE presse_journal_article_corps;
DROP TABLE presse_journalistes;
DROP TABLE presse_journalistes_journaliste;
DROP TABLE presse_journalistes_journaliste_anonymisation;


CREATE TABLE presse (
	node  	VARCHAR(5),
	txtval 	VARCHAR(5),
	numval 	NUMERIC(5),
	CONSTRAINT PK_PRESSE PRIMARY KEY(node)
);

CREATE TABLE presse_journal(	
	node	VARCHAR(5),
	txtval  VARCHAR(5),
	numval 	NUMERIC(5)
	CONSTRAINT PK_PRESSE_journal PRIMARY KEY(node)	
);

CREATE TABLE presse_journal_nom(
	node 	VARCHAR(5),
	txtval 	VARCHAR(5),
	numval	NUMERIC(5)
	CONSTRAINT PK_PRESSE_journal_nom PRIMARY KEY(node)
);

CREATE TABLE presse_journal_directeur(	
	node 	VARCHAR(5),
	txtval	VARCHAR(5),
	numval	NUMERIC(5)
	CONSTRAINT PK_PRESSE PRIMARY KEY(node)
);


CREATE TABLE presse_journal_directeur_nom(	
	node	VARCHAR(5), 
	txtval 	VARCHAR(5),
	numval 	NUMERIC(5)
	CONSTRAINT PK_PRESSE PRIMARY KEY(node)
);

CREATE TABLE presse_journal_directeur_prenom(	
	node 	VARCHAR(5),
	txtval	VARCHAR(5),
	numval	NUMERIC(5)
	CONSTRAINT PK_PRESSE PRIMARY KEY(node)
);

CREATE TABLE presse_journal_article(	
	node 	VARCHAR(5),
	txtval	VARCHAR(5),
	numval	NUMERIC(5)
	CONSTRAINT PK_PRESSE PRIMARY KEY(node)
);

CREATE TABLE presse_journal_article_corps(	
	node 	VARCHAR(5),
	txtval	VARCHAR(5),
	numval	NUMERIC(5)
	CONSTRAINT PK_PRESSE PRIMARY KEY(node)
);

CREATE TABLE presse_journalistes(	
	node 	VARCHAR(5),
	txtval	VARCHAR(5),
	numval	NUMERIC(5)
	CONSTRAINT PK_PRESSE PRIMARY KEY(node)
);

CREATE TABLE presse_journalistes_journaliste(	
	node 	VARCHAR(5),
	txtval	VARCHAR(5),
	numval	NUMERIC(5)
	CONSTRAINT PK_PRESSE PRIMARY KEY(node)
);	

CREATE TABLE presse_journalistes_journaliste_anonymisation(	
	node 	VARCHAR(5),
	txtval	VARCHAR(5),
	numval	NUMERIC(5)
	CONSTRAINT PK_PRESSE PRIMARY KEY(node)	
);





