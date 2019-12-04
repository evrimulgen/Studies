#!/usr/bin/env python3

import os,sys,re

extensions={}

def parcours (repertoire):
            print ("je suis dans le repertoire ",repertoire)
            liste = os.listdir(repertoire)
            for fichier in liste :
                if os.path.isdir(repertoire+"/"+fichier) and not os.path.islink(repertoire+"/"+fichier):

                    parcours(repertoire+"/"+fichier) 
                
                



                else :
                     res=re.search(".*\.(\w+)$",fichier)
                     if res :
                         if (res.group(1) in extensions.keys()):
                          extensions[res.group(1)]+=1
                         else:
                          extensions[res.group(1)]=1



parcours(sys.argv[1])
for ext,n in extensions.items():
    print("{} = {}".format(ext,n))

sys.exit(0)    
