#!/usr/bin/env python3
import re
import os

liste={}
er=re.compile("^(\w)+.*[A-Z][a-z]{2} \s+ ([A-Z][a-z]{2}) \s+ ([0-9]{1,2})")
f=os.popen("last","r")

for ligne in f.readlines():
   res=er.search(ligne)

   if res :
       if res.group(1) in kiste.keys():
               user=liste[res.group(1)]
               if res.group(2) in user.keys():
                     mois=user[res.group(2)]
                     if res.group(3) in mois.keys():
                          mois[res.group(3)] +=1
                     else :
                         mois[res.group]=1
               else:
                   user[res.group[2]]={res.group(3):1}
       else : liste[res.group(1)]={res.group[2]:{res.group[3]:1}}

f.close()

for u in liste.keys():
    print(u,"s'est connceté les : ")
    for m in liste[u].keys():
           for d in liste[u][m].keys():
                 print(d,"r",m,"(",liste[u][m][d],"fois)",end="")

    print()
    
