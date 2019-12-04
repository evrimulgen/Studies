DROP TABLE ACTEUR    
DROP TABLE REALISATEUR    
DROP TABLE GENRE    
DROP TABLE FILM    
DROP TABLE JOUER
 
 


prompt ----CREATION DE LA TABLE acteur----

CREATE TABLE acteur                                                                                                           
(
i dA NUMERIC(2,0) PRIMARY KEY,
nom VARCHAR(50) NOT NULL,
prenom VARCHAR(50),
nationalite VARCHAR(10)
);

----CREATION DE LA TABLE realisateur----


CREATE TABLE realisateur
(
idR NUMERIC(2,0) PRIMARY KEY,
nom VARCHAR(50) NOT NULL,
prenom VARCHAR(50) NOT NULL,
nationalite VARCHAR(10)
);


----CREATION DE LA TABLE genre----


CREATE TABLE genre
(
idG NUMERIC(2,0) PRIMARY KEY,
description VARCHAR(50) NOT NULL

);

----CREATION DE LA TABLE film----


CREATE TABLE film
(
idF NUMERIC(2,0) PRIMARY KEY,
titre VARCHAR(50) NOT NULL,
annee NUMERIC(20,0)
pays VARCHAR(40),
nbspectateurs NUMERIC(30,0),
idGenre  NUMERIC(2,0),
idRealisateur	NUMERIC(2,0),
CONSTRAINT R_REFERENCE FOREIGN KEY (idRealisateur) REFERENCES realisateur (idR),
CONSTRAINT R_GENRE FOREIGN KEY (idGenre) REFERENCES genre (idG),
CHECK (nbspectateurs >0)
);


----CREATION DE LA TABLE jouer----


CREATE TABLE jouer
(
salaire NUMERIC(10,0),
idActeur  NUMERIC(2,0),
idFilm	NUMERIC(2,0),
CONSTRAINT R_ACTEUR FOREIGN KEY (idActeur) REFERENCES realisateur (idA),
CONSTRAINT R_FILM FOREIGN KEY (idFilm) REFERENCES genre (idF),
CONSTRAINT K_JOUER PRIMARY KEY (idActeur,idFilm),
CHECK (salaire > 0)	
);








