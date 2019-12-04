/*
CFG

s -> gn gv 
gn -> det nom 
gv -> vt gn 
vt -> regarde | regardent 
nom -> chat | chien | chats | chiens 
det -> le | la | les 

*/
% reperage par difference de listes:
% gn([le,petit,chat,regarde,le,chien],[regarde,le,chien])
% signifie que la fin de la première liste est la deuxième liste et que la diffèrence [le,petit,chat] est un gn

%clause d' INITIALISATION DE "ENTRE"
entre(Mot,[Mot|Reste],Reste).

%initialise le reperage par diffèrence de listes.
% attention à bien mettre le Mot en premier ou (en dernier)
% Mot est une variable qui deviendra un mot et Reste est une liste de mots qui initialise le repérage par différence de liste. 

%interrogation s([le,petit,chat,dort],[]).
%les règles categorie -> mot devient
det(X,Y,sg):-entre(le,X,Y).
det(X,Y,pl):-entre(les,X,Y).
det(X,Y,sg):-entre(la,X,Y).
nom(X,Y,sg):-entre(chat,X,Y).
nom(X,Y,pl):-entre(chats,X,Y).
nom(X,Y,sg):-entre(chien,X,Y).
nom(X,Y,pl):-entre(chiens,X,Y).
vt(X,Y,sg):-entre(regarde,X,Y).
vt(X,Y,pl):-entre(regardent,X,Y).

%les règles de réecriture deviennent  : 
gn(X,Y,N):-det(X,I,N),nom(I,Y,N).
gv(X,Y,N):-vt(X,I,N),gn(I,Y,P).
s(X,Y):-gn(X,I,N),gv(I,Y,N).

%Avec ACCORDS