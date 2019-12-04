#!/usr/bin/env python
# -*- coding: utf-8 -*-

import re,sys

fd =open(sys.argv[1],"r")
fichier = fd.readlines()
fdr = open(sys.argv[1]+".resultat","w")

nbr = 0
nbr2 = 0

for ligne in fichier :
    longueur = len(ligne)
    nbr = nbr + longueur
    p = 0
    while p < longueur -1 :
        r = re.search("("+ligne[p]+"+)",ligne[p:]) 
        l = len(r.group(1))
        if l > 1 :
            fdr.write(ligne[p]+"|"+str(l)+"|")
            nbr2 = nbr2 + 3 + len(str(l))
        else :
            fdr.write(ligne[p])
            nbr2 = nbr2 + 1
        p = p+1
    fdr.write("\n")
    nbr2 = nbr2 +1
fdr.close()
print("G = ",nbr,"-",nbr2,"=",nbr-nbr2)

