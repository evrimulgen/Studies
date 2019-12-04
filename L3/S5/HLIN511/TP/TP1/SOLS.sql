Q1:
select nom,prenom 
from abonne 
where ville='MONTPELLIER';
//
Q2:
select * 
from exemplaire 
where code_pret='EMPRUNTABLE';
//
Q3:
select titre,categorie 
from livre 
where categorie<>'MEDECINE' 
and categorie<>'SCIENCES' 
and categorie<>'LOISIR' 
ORDER by categorie;
//
Q4:
select * 
from emprunt 
where D_RET_REEL is null;
//
Q5:
select num_ex, d_emprunt 
from abonne a, emprunt e 
where a.num_ab=e.num_ab 
and prenom='JEAN' 
and nom='DUPONT' 
order by d_emprunt asc;
//
Q6:
select numero,code_pret,etat 
from exemplaire e, livre l 
where titre='LE MUR' and l.isbn=e.isbn;
//
Q7:
SOLUTION1:
select numero
from exemplaire ex, livre li
where li.isbn=ex.isbn
and li.isbn=(select l.isbn
		from livre l,exemplaire e
		where numero=4112
		and etat='BON'
		and l.isbn=e.isbn);
//
SOLUTION 2:
select e2.numero
from exemplaire e1,exemplaire e2
where e1.isbn=e2.isbn
and e1.etat='BON'
and e1.numero=4112
and e2.numero<>4112;
//
SOLUTION 3:
select numero
from exemplaire
where etat='BON'
and numero<>4112
and isbn in(select isbn
    	    from exemplaire
	    where numero=4112);
//
Q8:


