package requeterrezo;

import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Date;
import java.util.HashMap;


/*
RequeterRezo
Copyright (C) 2019  Jimmy Benoits

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


/**
 * Attente d�fini un index des requ�tes d�j� effectu�es mais qui n'ont pas �t� jug�es assez importantes pour entrer dans le cache. 
 * Cela peut permettre de faire entrer dans le cache une requ�te demand�e de nombreuses fois, m�me si le cache est plein.
 * 
 * @see AttenteInfo
 * @author jimmy.benoits
 */
class Attente implements Serializable{

	/**
	 * 01/01/2019 - V1.0
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * Table d'association entre une requ�te {@link CleCache} et les informations sur sa fr�quences {@link AttenteInfo}.
	 */
	protected HashMap<CleCache, AttenteInfo> index;

	/**
	 * Constructeur par d�faut, initialise la table.
	 */
	protected Attente() {
		index = new HashMap<>();
	}

	/**
	 * Fonction appel�e lors du d�marrage d'une session RequeterRezo si un cache existe.
	 * Cela permet de garder en m�moire d'une session sur l'autre les requ�tes courantes. 
	 * @param chemin Chemin vers le fichier � charger.
	 * @return Une table remplie si le fichier a pu �tre charg� correctement. En cas d'EOFException (la processus d'�criture 
	 * a �t� interrompu), l'ancien fichier est supprim� et une nouvelle table est cr�e. Null sinon (avec affichage de l'erreur).
	 */
	protected static Attente chargerAttente(String chemin) {
		FileInputStream fichierFluxEntrant;
		ObjectInputStream objetFluxEntrant;
		Attente attente = null;
		try {
			fichierFluxEntrant = new FileInputStream(chemin);
			objetFluxEntrant = new ObjectInputStream(fichierFluxEntrant);
			attente = (Attente) objetFluxEntrant.readObject();			
			objetFluxEntrant.close();	
			fichierFluxEntrant.close();
		}catch(EOFException e) {
			File aSupprimer = new File(chemin);
			aSupprimer.delete();
			return new Attente();
		}catch(Exception e) {
			e.printStackTrace();
		}
		return attente;
	}

	/**
	 * Fonction appel�e � chaque modification de la table d'attente afin de conserver dans un fichier les informations sur les requ�tes courantes.
	 * @param chemin Chemin vers le fichier � sauvegarder.
	 */
	protected void sauvegarderAttente(String chemin) {
		FileOutputStream fichierFluxSortant;
		ObjectOutputStream objetFluxSortant;
		try {
			fichierFluxSortant = new FileOutputStream(chemin);
			objetFluxSortant = new ObjectOutputStream(fichierFluxSortant);
			objetFluxSortant.writeObject(this);
			objetFluxSortant.close();
			fichierFluxSortant.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Supprime de l'attente une requ�te. Cela est notamment utile lors de l'entr�e d'une requ�te en attente dans le cache.
	 * @param cleCache Requ�te � supprimer.
	 */
	protected void supprimer(CleCache cleCache) {
		if (this.index.containsKey(cleCache)) {
			this.index.remove(cleCache);
		}
	}

	/**
	 * Ajoute une requ�te � l'attente. Le nombre d'occurence est � fixer � en cas de nouvelle entr�e mais le nombre d'occurrence d'une requ�te passant
	 * du cache � l'attente (pas assez utilis�e ou p�rim�e) est conserver. 
	 * @param cleCache Requ�te � ajouter.
	 * @param occurrences 1 en cas de nouvelle entr�e. Sinon le nombre d'occurrence de la requ�te. 
	 */
	protected void ajouter(CleCache cleCache, int occurrences) {
		AttenteInfo info = new AttenteInfo(occurrences, new Date());
		index.put(cleCache, info);
	}
}
