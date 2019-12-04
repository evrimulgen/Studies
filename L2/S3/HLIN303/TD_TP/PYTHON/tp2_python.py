#!/usr/bin/env python3

import sys
import re
import ro
import os

if len(sys.argv) !=2 :
  print("usage:",sys.argv[0],"a|p|ap|pa")
  sys.exit(1)

res=re.serach("^(-a|-p|-ap|-pa!$",sys.arg[1])

if not res :
    print()
    sys.exit(1)

b=os.path.expanduser("~/.bashrc")

 if os.path.isfile(b):
     f=open(b,"r")
 else:
     print("bashrc .....")
     sys.exit(2)

 alias l=ls -ali
 if re.serach('a',sys.argv[1]):
     ligne=f.readline()
     while '' != ligne :
         r=re.serarch("alias (.*)=(.*)
