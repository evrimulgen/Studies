DROP TABLE Abonne ;
DROP TABLE Ouvrage;
DROP TABLE Commentaire;



CREATE  TABLE   Abonne (
	NumAbonne INT(10) NOT NULL PRIMARY KEY,
	mdp VARCHAR(16)
);


CREATE  TABLE Ouvrage (
	ISBN VARCHAR(30) NOT NULL  PRIMARY KEY,
	titre VARCHAR(30),
	auteur VARCHAR(40),
	nbExemplaire INT(10),
	editeur VARCHAR(30)
);


CREATE  TABLE  Commentaire (
	contenue VARCHAR(100),
	reader INT(10),
	livre VARCHAR(30),
	PRIMARY KEY (reader,livre)
);


ALTER TABLE Commentaire ADD FOREIGN KEY(livre) REFERENCES Ouvrage(ISBN);
ALTER TABLE Commentaire ADD FOREIGN KEY(reader) REFERENCES Abonne(NumAbonne);




prompt -- *******************************************************************************
prompt --           INSERTION ABONNE
prompt -- *******************************************************************************







prompt -- *******************************************************************************
prompt --           INSERTION  OUVRAGE 
prompt -- *******************************************************************************











prompt -- *******************************************************************************
prompt --           INSERTION  COMMENTAIRE
prompt -- *******************************************************************************
