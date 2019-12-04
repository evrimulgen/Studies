package requeterrezo;

import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;


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
 * Objet contenant le r�sultat d'une requ�te effectu�e par RequeterRezo. 
 * Une requ�te retourne toujours un r�sultat contenant : 
 * - un {@link Mot} : le mot demand�. Attention, ceci peut �tre null si le mot n'existait pas ou qu'une erreur est survenue. 
 * - Un {@link Etat} : l'�tat de la requ�te.
 * - un {@link EtatCache} : information concernant la provenance de la requ�te.
 * 
 * @author jimmy.benoits
 */
public class Resultat implements Serializable{

	/**
	 * 01/01/2019 - V1.0
	 */
	private static final long serialVersionUID = 1L;
	
	/**
	 * Descriptif interne de la requ�te.
	 */
	protected final CleCache informationRequete;
	
	/**
	 * Mot demand�, construit depuis le cache ou depuis une requ�te.
	 */
	protected final Mot mot;
	
	/**
	 * Etat de la requ�te.
	 */
	protected Etat etat;
	
	/**
	 * Provenance de la requ�te.
	 */
	protected EtatCache etatCache;
	
	
	/**
	 * Retourne un descriptif de la requ�te contenant le terme recherch�, le type de relation demand� (-1 si aucun) et 
	 * le filtre ({@link Filtre}) directionnel utilis�.
	 * @return Retourne une ligne d�crivant la requ�te.
	 */
	public String informationRequete() {
		return informationRequete.toString();
	}

	/**
	 * Retourne le mot r�sultat.
	 * @return Le mot r�sultat ou null si l'�tat de la requ�te est 
	 *  - {@link Etat#INEXISTANT}
	 *  - {@link Etat#RENVOYER}
	 *  - {@link Etat#SERVEUR_INACCESSIBLE}
	 *  - {@link Etat#ERREUR_REQUETE}
	 *  Dans le cas o� la requ�te a �t� r�alis� en "live" ({@link RequeterRezoDump}), si l'�tat est {@link Etat#TROP_GROS}, 
	 *  le mot retourn� a �t� tronqu� car son nombre de relations d�passait le seuil de 25 000. Pour obtenir un r�sultat "complet", il faudra
	 *  pr�ciser la requ�te (appliquer des filtres) ou utiliser une version "locale" ({@link RequeterRezoSQL}) de RequeterRezo.
	 */
	public Mot getMot() {
		return mot;
	}

	/**
	 * Retourne l'�tat de la requ�te.
	 * @return Indique si la requ�te s'est d�roul�e correctement.
	 */
	public Etat getEtat() {
		return etat;
	}

	/**
	 * Retourne la provenance de la requ�te.
	 * @return Indique si le r�sultat provient du cache et d'une requ�te.
	 */
	public EtatCache getEtatCache() {
		return etatCache;
	}

	/**
	 * Constructeur simple - � partir d'une requ�te. Permet de remplir les champs au fur et � mesure.
	 * @param informationRequete Requ�te dont on construit le r�sultat.
	 */
	protected Resultat(CleCache informationRequete) {
		this(informationRequete, null, Etat.ERREUR_REQUETE, EtatCache.ERREUR_REQUETE);
	}

	/**
	 * Constructeur complet. 
	 * @param informationRequete Requ�te dont on construit le r�sultat.
	 * @param mot Mot r�sultat.
	 * @param etat Etat du r�sultat.
	 * @param etatCache Provenance du r�sultat.
	 */
	protected Resultat(CleCache informationRequete, Mot mot, Etat etat, EtatCache etatCache) {
		this.informationRequete = informationRequete;
		this.mot = mot;
		this.etat = etat;
		this.etatCache = etatCache;
	}

	@Override
	public String toString() {
		return "\""+informationRequete.toString()+"\","+etat.toString()+","+etatCache.toString();
	}

	/**
	 * Construit un objet Resultat d'apr�s un fichier du cache ([ID].cache) construit par la m�thode {@link Resultat#ecrireCache(String, Resultat)}.
	 * @param chemin Chemin vers un fichier Resultat.
	 * @return Un Resultat construit depuis le cache si cela est possible. Null si le fichier est corrumpu (le processus d'�criture a �t� interrompu avant 
	 * sa compl�tion) et null avec affichage d'erreur en cas d'autre erreur. 
	 */
	protected static Resultat lireCache(String chemin, CleCache cleCache) {
		Resultat resultat = new Resultat(cleCache);
		FileInputStream fichierFluxEntrant;
		ObjectInputStream objetFluxEntrant;
		try {
			fichierFluxEntrant = new FileInputStream(chemin);
			objetFluxEntrant = new ObjectInputStream(fichierFluxEntrant);
			resultat = (Resultat) objetFluxEntrant.readObject();
			resultat.etatCache = EtatCache.DEPUIS_CACHE;
			objetFluxEntrant.close();	
			fichierFluxEntrant.close();
		}catch(EOFException e) {
			return null;
		}catch(Exception e) {
			e.printStackTrace();
		}		
		return resultat;
	}

	/**
	 * Enregistre l'objet dans un fichier pouvant �tre lu par {@link Resultat#ecrireCache(String, Resultat)}.
	 * @param chemin Chemin du fichier.
	 * @param resultat R�sultat � enregistrer.
	 * @return True si l'objet a pu �tre enregistrer. False sinon.
	 */
	protected static boolean ecrireCache(String chemin, Resultat resultat) {
		boolean res = false;
		FileOutputStream fichierFluxSortant;
		ObjectOutputStream objetFluxSortant;
		int indexOf = chemin.lastIndexOf(File.separator);
		if(indexOf != -1 && indexOf < chemin.length()) {
			String cheminDossier = chemin.substring(0, indexOf);
			File dossierParent = new File(cheminDossier);
			if(!dossierParent.exists()) {
				dossierParent.mkdirs();
			}
			try {
				fichierFluxSortant = new FileOutputStream(chemin);
				objetFluxSortant = new ObjectOutputStream(fichierFluxSortant);
				objetFluxSortant.writeObject(resultat);
				objetFluxSortant.close();
				fichierFluxSortant.close();
				res = true;
			}catch(IOException e) {
				e.printStackTrace();
			}
		}		
		return res;
	}
}
