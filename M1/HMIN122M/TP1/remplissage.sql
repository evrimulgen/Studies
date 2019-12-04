prompt -------------------------------------------;
prompt --- Suppression des anciens tuples --------;
prompt -------------------------------------------;

ALTER SESSION SET nls_date_format='DD-MON-YYYY'

DELETE FROM photographie;
DELETE FROM utilisateur;
DELETE FROM publie;
DELETE FROM configuration;
DELETE FROM appareilPhoto;
DELETE FROM appartenirGalerie;
DELETE FROM appartenirAlbum;
DELETE FROM collection;
DELETE FROM galerie;
DELETE FROM album;
DELETE FROM contenuNum;
DELETE FROM commentaire;
DELETE FROM discussion;
DELETE FROM balisePhoto;
DELETE FROM aimerPhoto;
DELETE FROM marquerPhoto;
DELETE FROM possedeDiscussion;
DELETE FROM abonnement;

INSERT INTO contenuNum VALUES  ('01247');
INSERT INTO contenuNum VALUES  ('01248');
INSERT INTO contenuNum VALUES  ('01249');
INSERT INTO contenuNum VALUES  ('01250');
INSERT INTO contenuNum VALUES  ('01251');


INSERT INTO photographie(idP,lieu,licence,idCNum) VALUES ('12578','MONTPELLIER','tous droits réservés','01247');
INSERT INTO photographie (idP,lieu,licence,idCNum)VALUES ('12579','NIMES','tous droits réservés','01248');
INSERT INTO photographie (idP,lieu,licence,idCNum)VALUES ('12580','LILLE',NULL,'01249');
INSERT INTO photographie (idP,lieu,licence,idCNum)VALUES ('12581','PARIS',NULL,'01250');
INSERT INTO photographie (idP,lieu,licence,idCNum)VALUES ('12582','LYON','tous droits réservés','01251');


INSERT INTO collection VALUES  ('00011');
INSERT INTO collection VALUES  ('00012');
INSERT INTO collection VALUES  ('00013');
INSERT INTO collection VALUES  ('00014');
INSERT INTO collection VALUES  ('00015');
INSERT INTO collection VALUES  ('00016');
INSERT INTO collection VALUES  ('00017');
INSERT INTO collection VALUES  ('00018');
INSERT INTO collection VALUES  ('00019');
INSERT INTO collection VALUES  ('00020');

INSERT INTO album VALUES  ('89111','00011');
INSERT INTO album VALUES  ('89112','00012');
INSERT INTO album VALUES  ('89113','00013');
INSERT INTO album VALUES  ('89114','00014');
INSERT INTO album VALUES  ('89115','00015');

INSERT INTO galerie VALUES  ('21542','00016');
INSERT INTO galerie VALUES  ('21543','00017');
INSERT INTO galerie VALUES  ('21544','00018');
INSERT INTO galerie VALUES  ('21545','00019');
INSERT INTO galerie VALUES  ('21546','00020');

INSERT INTO utilisateur VALUES ('00051','FRGT','89111','11111','12578');
INSERT INTO utilisateur VALUES ('00052','GSHU','89112','11112','12579');
INSERT INTO utilisateur VALUES ('00053','HTIW','89113','11113','12580');
INSERT INTO utilisateur VALUES ('00054','IUJX','89114','11114','12599');
INSERT INTO utilisateur VALUES ('00055','JWGY','89115','11115','12582');


INSERT INTO publie VALUES ('00051','12578','23-02-18');
INSERT INTO publie VALUES ('00052','12579','01-01-18');
INSERT INTO publie VALUES ('00053','12580','31-01-18');
INSERT INTO publie VALUES ('00054','12581','22-08-18');
INSERT INTO publie VALUES ('00055','12582','09-05-18');


INSERT INTO appareilPhoto VALUES  ('06581','CANON','12578');
INSERT INTO appareilPhoto VALUES  ('06582','SONY','12579');
INSERT INTO appareilPhoto VALUES  ('06583','TOSHIBA','12580');
INSERT INTO appareilPhoto VALUES  ('06584','SAMSUMG','12581');
INSERT INTO appareilPhoto VALUES  ('06585','HP','12582');


INSERT INTO configuration VALUES ('06581','12578','40','100','5','OUI');
INSERT INTO configuration VALUES ('06582','12579','41','101','4','NON');
INSERT INTO configuration VALUES ('06583','12580','42','102','2','OUI');
INSERT INTO configuration VALUES ('06584','12581','43','103','3','OUI');
INSERT INTO configuration VALUES ('06585','12582','44','104','6','NON');






INSERT INTO appartenirGalerie VALUES  ('00051','12578','21542');
INSERT INTO appartenirGalerie VALUES  ('00052','12579','21543');
INSERT INTO appartenirGalerie VALUES  ('00053','12580','21544');
INSERT INTO appartenirGalerie VALUES  ('00054','12581','21545');
INSERT INTO appartenirGalerie VALUES  ('00055','12582','21546');



INSERT INTO apparteniralbum VALUES  ('00051','12578','30015');
INSERT INTO apparteniralbum VALUES  ('00052','12579','30016');
INSERT INTO apparteniralbum VALUES  ('00053','12580','30017');
INSERT INTO apparteniralbum VALUES  ('00054','12581','30018');
INSERT INTO apparteniralbum VALUES  ('00055','12582','30019');







INSERT INTO commentaire VALUES  ('78147','18011','01247');
INSERT INTO commentaire VALUES  ('78148','18012','01248');
INSERT INTO commentaire VALUES  ('78149','18013','01249');
INSERT INTO commentaire VALUES  ('78150','18014','01250');
INSERT INTO commentaire VALUES  ('78151','18015','01251');


INSERT INTO discussion VALUES  ('18011','12578');
INSERT INTO discussion VALUES  ('18012','12579');
INSERT INTO discussion VALUES  ('18013','12580');
INSERT INTO discussion VALUES  ('18014','12581');
INSERT INTO discussion VALUES  ('18015','12582');

INSERT INTO balisePhoto VALUES  ('00051','12578');
INSERT INTO balisePhoto VALUES  ('00052','12579');
INSERT INTO balisePhoto VALUES  ('00053','12580');
INSERT INTO balisePhoto VALUES  ('00054','12581');
INSERT INTO balisePhoto VALUES  ('00055','12582');

INSERT INTO aimerPhoto VALUES  ('00052','12578');
INSERT INTO aimerPhoto VALUES  ('00053','12579');
INSERT INTO aimerPhoto VALUES  ('00054','12580');
INSERT INTO aimerPhoto VALUES  ('00051','12581');
INSERT INTO aimerPhoto VALUES  ('00055','12582');

INSERT INTO marquerPhoto VALUES  ('00055','12578');
INSERT INTO marquerPhoto VALUES  ('00054','12579');
INSERT INTO marquerPhoto VALUES  ('00053','12580');
INSERT INTO marquerPhoto VALUES  ('00052','12581');
INSERT INTO marquerPhoto VALUES  ('00051','12582');

INSERT INTO possedeDiscussion VALUES  ('12578','18011');
INSERT INTO possedeDiscussion VALUES  ('12579','18012');
INSERT INTO possedeDiscussion VALUES  ('12580','18013');
INSERT INTO possedeDiscussion VALUES  ('12581','18014');
INSERT INTO possedeDiscussion VALUES  ('12582','18015');

INSERT INTO abonnement VALUES  ('00055','00052');
INSERT INTO abonnement VALUES  ('00054','00053');
INSERT INTO abonnement VALUES  ('00053','00054');
INSERT INTO abonnement VALUES  ('00052','00051');
INSERT INTO abonnement VALUES  ('00051','00055');




















