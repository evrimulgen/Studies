mongoimport --db allovoisins --collection membres --file Collections/membres.json  --jsonArray  --drop;
mongoimport --db allovoisins --collection biens	--file Collections/biens.json --jsonArray  --drop;
mongoimport --db allovoisins --collection services --file Collections/services.json --jsonArray  --drop;
mongoimport --db allovoisins --collection disponibilites --file Collections/disponibilites.json --jsonArray  --drop;
mongoimport --db allovoisins --collection utilisations --file Collections/utilisations.json --jsonArray  --drop;
mongoimport --db allovoisins --collection descriptifBiens --file Collections/descriptifBiens.json --jsonArray  --drop;
mongoimport --db allovoisins --collection descriptifServices --file Collections/descriptifServices.json --jsonArray  --drop;