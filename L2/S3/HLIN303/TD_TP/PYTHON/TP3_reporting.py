#!/usr/bin/env python3

import os
import re

connexion={}
p=os.popen("last",'r')


ligne=p.readline();
print(ligne)

res=re.compile("(\w+) (Tue|Wed|Thr|Fri|Sat|Sun|Mon) (Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec) ")
r=res.search(ligne)

print("login",r.group(1))
print("jour",r.group(2))
print("mois",r.group(3))
print("nj",r.group(4))



