/*
CFG

s -> gn gv 
gn -> det nom 
gv -> vt gn 
vt -> regarde | regardent 
nom -> chat | chien | chats | chiens 
det -> le | la | les 



%Arbre d'analyse


%interrogation s(T,[phrase],[]).


entre(Mot,[Mot|Reste],Reste).

vt(T1,X,Y):-entre(regarde,T1,X,Y).
det(T1,X,Y):-entre(le,T1,X,Y).
n(T1,X,Y):-entre(chien,T1,X,Y).

gn([T1,T2],X,Y):-det(T1,X,I),n(T2,I,Y).

*/


[gv,[vt,regarde],[gn,[det,le],[n,chien]]]

s([S,T1,T2],X,Y):-vt(T1,X,I),gn(T2,I,Y).
