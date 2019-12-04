#!/usr/bin/env python3

import sys
import re

for i in sys.argv[1:] :
   resultat_1 = re.search("-.*a+", i)
   resultat_2 = re.search("-.*p+", i)
   if(resultat_1) and (resultat_2) : print("Option a! ou Option p!")
   elif (resultat_1) : print("Option a!")
   elif (resultat_2) : print("Option p!")
   else : print("les options utitlisés sont incorrectes")
