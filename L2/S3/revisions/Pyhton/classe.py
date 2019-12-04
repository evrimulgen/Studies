#!/usr/bin/env python
#!/usr/bin/env python

import sys,re

suffixes={'.py': '#!/usr/bin/env python',
          '.pl': '#!/usr/bin/env perl'}

for nom_fichier in sys.argv[1:] :
    resultat = re.search("(\...)$",nom_fichier)
    if resultat and suffixes.has_key(resultat.group(1)) :
        print(nom_fichier)
        fd = open(nom_fichier,"r")
        contenue = fd.readlines()
        fd.close()
        if contenue[0] != suffixes[resultat.group(1)] :
            fdr = open(nom_fichier,"w")
            fdr.write(suffixes[resultat.group(1)]+"\n")
            fdr.writelines(contenue)
            fdr.close()
        else :
            print(nom_fichier)
    else :
        print(nom_fichier)

