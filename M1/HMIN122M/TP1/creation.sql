DROP TABLE photographie;
DROP TABLE publie;
DROP TABLE utilisateur;
DROP TABLE configuration;
DROP TABLE appareilPhoto;
DROP TABLE appartenirGalerie;
DROP TABLE appartenirAlbum;
DROP TABLE collection;
DROP TABLE galerie;
DROP TABLE album;
DROP TABLE contenuNum;
DROP TABLE commentaire;
DROP TABLE discussion;
DROP TABLE balisePhoto;
DROP TABLE aimerPhoto;
DROP TABLE marquerPhoto;
DROP TABLE possedeDiscussion;
DROP TABLE abonnement;


CREATE TABLE  utilisateur (
	idU NUMERIC(5), 
	pseudonyme VARCHAR(50), 
	idDisc NUMERIC(5),
	idCNum NUMERIC(5),
	idP NUMERIC(5),
	CONSTRAINT PK_utilisateur PRIMARY KEY (idU),
	CONSTRAINT FK_utilisateur_contenuNum FOREIGN KEY  (idCNum) REFERENCES contenuNum(idCNum),
	CONSTRAINT FK_utilisateur_album FOREIGN KEY  (idA)  REFERENCES album(idA),
	CONSTRAINT FK_utilisateur_photographie FOREIGN  KEY (idP) REFERENCES photographie(idP)
);

CREATE TABLE photographie  (
       idP  NUMERIC(5),
       lieu  VARCHAR(20),
       licence  VARCHAR(50),
       idDisc NUMERIC(5),
       idCNum NUMERIC(5),
       CONSTRAINT PK_photographie PRIMARY KEY (photographie),
       CONSTRAINT FK_photographie_discussion FOREIGN KEY (idDisc) REFERENCES discussion(idDisc),
       CONSTRAINT FK_photographie_contenuNum FOREIGN KEY (idCNum) REFERENCES contenuNum(idCNum)
 );

CREATE TABLE appareilPhoto (
	idApp NUMERIC(5),
	marque VARCHAR(10),
	idPh NUMERIC(5),
	CONSTRAINT PK_appareilPhoto PRIMARY KEY (idApp),
	CONSTRAINT FK_appareilPhoto_photographie FOREIGN KEY (idPh) REFERENCES photographie(idPh)
);

CREATE TABLE configuration (
       idApp NUMERIC(5),
       idP NUMERIC(5),
       ouvretureF VARCHAR(10),
       distanceF VARCHAR(10),
       tempsEVARCHAR(10),
       flash  VARCHAR(10),
       CONSTRAINT PK_configuration PRIMARY KEY (idApp,idPH)
);


CREATE TABLE appartenirGalerie(
	idU NUMERIC(5),
	idP NUMERIC(5),
	idG NUMERIC(5),
	CONSTRAINT PK_appartenirGalerie (idU,idG,idP),
	CONSTRAINT FK_appartenirGalerie_GALERIE FOREIGN KEY  (idG) REFERENCES galerie(idG),
	CONSTRAINT FK_appartenirGalerie_utilisateur FOREIGN KEY  (idU) REFERENCES utilisateur(idU),
	CONSTRAINT FK_appartenirGalerie_photographie FOREIGN KEY  (idP) REFERENCES photographie(idP)
);


CREATE TABLE apparteniralbum(
	idU NUMERIC(5),
	idP NUMERIC(5),
	IDA NUMERIC(5),
	CONSTRAINT PK_apparteniralbum (idU,IDA,idP),
	CONSTRAINT FK_apparteniralbum_photographie FOREIGN KEY  (idP) REFERENCES photographie(idP),
	CONSTRAINT FK_apparteniralbum_album FOREIGN KEY  (idA) REFERENCES album(idA)
);

CREATE TABLE collection(
	idC NUMERIC(5),
	CONSTRAINT PK_collection (idC)
);

CREATE TABLE galerie(
	idG NUMERIC(5),
	idCollec NUMERIC(5),
	CONSTRAINT PK_galerie PRIMARY KEY (idG),
	CONSTRAINT FK_galerie_collection  FOREIGN KEY (idCollec) REFERENCES collection(idCollec)
);

CREATE TABLE album(
	idCollec NUMERIC(5),
	idA NUMERIC(5),
	CONSTRAINT PK_album PRIMARY KEY (idA),
	CONSTRAINT FK_album_collection FOREIGN KEY (idCollec) REFERENCES  collection(idCollec)
);

CREATE TABLE contenuNum  (
    idCNum NUMERIC(5),
    CONSTRAINT PK_contenuNum PRIMARY KEY (idCNum)
);

CREATE TABLE commentaire  (
    idCom  NUMERIC(5),
    idDisc NUMERIC(5),
    idCNum NUMERIC(5),
    CONSTRAINT PK_commentaire PRIMARY KEY (idCom),
    CONSTRAINT FK_commentaire_discussion FOREIGN KEY (idDisc) REFERENCES discussion (idDisc),
    CONSTRAINT FK_commentaire_contenuNum FOREIGN KEY (idCNum) REFERENCES contenuNum (idCNum)
);

CREATE TABLE discussion  (
    idDisc NUMERIC(5),
    idP    NUMERIC(5),
    CONSTRAINT PK_discussion PRIMARY KEY (idDisc),
    CONSTRAINT FK_discussion_photographie FOREIGN KEY (idP) REFERENCES photographie (idP)
);

CREATE TABLE balisePhoto  (
    idU     NUMERIC(5),
    idP     NUMERIC(5),
    contenu VARCHAR(10),
    CONSTRAINT PK_balise PRIMARY KEY (idU, idP),
    CONSTRAINT FK_balise_utilisateur FOREIGN KEY (idU) REFERENCES utilisateur (idU),
    CONSTRAINT FK_balise_photo   FOREIGN KEY    (idP) REFERENCES photographie (idP)
);

CREATE TABLE aimerPhoto (
    idU     NUMERIC(5),
    idP     NUMERIC(5),
    CONSTRAINT PK_aimer PRIMARY KEY (idU, idP),
    CONSTRAINT FK_aimer_utilisateur FOREIGN KEY (idU) REFERENCES utilisateur (idU),
    CONSTRAINT FK_aimer_photo  FOREIGN KEY     (idP) REFERENCES photographie (idP)
);

CREATE TABLE marquerPhoto  (
    idU     NUMERIC(5),
    idP     NUMERIC(5),
    CONSTRAINT PK_marquer PRIMARY KEY (idU, idP),
    CONSTRAINT FK_marquer_utilisateur FOREIGN KEY (idU) REFERENCES utilisateur (idU),
    CONSTRAINT FK_marquer_photo  FOREIGN KEY      (idP) REFERENCES photographie (idP)
);

CREATE TABLE possedeDiscussion  (
    idP     NUMERIC(5),
    idDisc     NUMERIC(5),
    CONSTRAINT PK_balise PRIMARY KEY (idU, idP),
    CONSTRAINT FK_balise_photo     FOREIGN KEY    (idP) REFERENCES photographie (idP),
    CONSTRAINT FK_balise_discussion FOREIGN KEY (idDisc) REFERENCES discussion (idDisc)
);

CREATE TABLE abonnement  (
    idU_1     NUMERIC(5),
    idU_2    NUMERIC(5),
    CONSTRAINT PK_abonnement PRIMARY KEY (idU_1, idU_2),
    CONSTRAINT FK_abonnement_utilisateur1 FOREIGN KEY(idU_1) REFERENCES utilisateur (idU),
    CONSTRAINT FK_abonnement_utilisateur1 FOREIGN KEY (idU_2) REFERENCES utilisateur (idU)
);
	