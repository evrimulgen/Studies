package requeterrezo;


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


import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;

/**
 * La classe Mot est l'objet principal retourn� par une requ�te dans RequeterRezo. 
 * Un mot contient notamment les informations sur le noeud rezoJDM associ� ({@link Noeud}) 
 * ainsi que les relations entrantes, sortantes et les annotations.
 * Si un mot a �t� construit par une requ�te "live" ({@link RequeterRezoDump}), alors sa d�finition (si elle existe) est aussi retourn�e.
 * 
 * @author jimmy.benoits
 */
public class Mot extends Noeud implements Serializable{

	/**
	 * 01/01/2019 - V1.0
	 */
	private static final long serialVersionUID = 1L;
	
	/**
	 * D�finition du mot dans rezoJDM si la requ�te est effectu�e avec {@link RequeterRezoDump}.
	 */
	protected String definition = "";
	
	/**
	 * Table d'association des noeuds du voisinage du terme (id -&gt; {@link Noeud}).
	 */
	protected HashMap<Long, Noeud> voisinage;
	
	/**
	 * Table d'assocation des relations entrantes (dont le Mot est la destination).
	 * La table lie un type de relation et une liste de voisin ({@link Voisin}).
	 */
	protected HashMap<Integer, ArrayList<Voisin>> relationsEntrantes;
	
	/**
	 * Table d'assocation des relations sortantes (dont le Mot est la source).
	 * La table lie un type de relation et une liste de voisin ({@link Voisin}).
	 */
	protected HashMap<Integer, ArrayList<Voisin>> relationsSortantes;
	
	/**
	 * Liste des annotations portant sur les relations du mot.
	 */
	protected ArrayList<Annotation> annotations;
	
	/**
	 * Descriptif interne de la requ�te.
	 */
	protected final CleCache cleCache;

	
	/**
	 * Constructeur param�tr�. 
	 * @param nom Nom du terme dans rezoJDM.
	 * @param id ID du terme dans rezoJDM.
	 * @param type type du terme dans rezoJDM.
	 * @param mot_formate mot format� du terme dans rezoJDM.
	 * @param poids poids du terme dans rezoJDM.
	 * @param description d�finition du terme dans rezoJDM.
	 * @param voisinage Table d'association du voisinnage d'un terme (id -> {@link Noeud}).
	 * @param relationsEntrantes Table d'assocation des relations entrantes (dont le Mot est la destination).
	 * @param relationsSortantes Table d'assocation des relations sortantes (dont le Mot est la source).
	 * @param annotations Liste des annotations portant sur les relations du mot.
	 * @param cleCache Descriptif interne de la requ�te.
	 */
	protected Mot(String nom, long id, int type, String mot_formate, int poids, String description,
			HashMap<Long, Noeud> voisinage,
			HashMap<Integer, ArrayList<Voisin>> relationsEntrantes,
			HashMap<Integer, ArrayList<Voisin>> relationsSortantes,
			ArrayList<Annotation> annotations,
			CleCache cleCache) {
		super(nom, id, type, mot_formate, poids);
		this.voisinage = voisinage;
		this.relationsEntrantes = relationsEntrantes;
		this.relationsSortantes = relationsSortantes;
		this.definition = description;
		this.annotations = annotations;
		this.cleCache = cleCache;
	}


	/**
	 * D�finition du mot dans rezoJDM si la requ�te est effectu�e avec {@link RequeterRezoDump}.
	 * @return La d�finition du mot si cela est possible.
	 */
	public String getDefinition() {
		return definition;
	}

	/**
	 * Modifie la d�finition (en local) du terme.
	 * @param definition D�finition du terme.
	 */
	public void setDefinition(String definition) {
		this.definition = definition;
	}

	/**
	 * Table d'association des noeuds du voisinage du terme (id -&gt; {@link Noeud}).
	 * @return retourne le voisinage du mot.
	 */
	public HashMap<Long, Noeud> getVoisinage() {
		return voisinage;
	}

	/**
	 * Retourne les voisins ({@link Voisin}) du terme pour les relations entrantes dont le nom de la relation est pass� en param�tre.
	 * Une relation entrante est une relation dont la destination est le mot.
	 * @param nomType Nom de la relation.
	 * @return Les voisins ({@link Voisin}) du terme pour les relations entrantes dont le nom de la relation est pass� en param�tre. S'il n'y en a aucun,
	 * ou si le nom de correspond pas � une relation existante, retourne une liste vide.
	 */
	public ArrayList<Voisin> getRelationsEntrantesTypees(String nomType){
		ArrayList<Voisin> resultats;
		Integer type = RequeterRezo.correspondancesRelations.get(nomType);
		if(type != null) {
			resultats = getRelationsEntrantesTypees(type);
		}else {
			resultats = new ArrayList<>();
		}
		return resultats;
	}

	/**
	 * Retourne les voisins ({@link Voisin}) du terme pour les relations sortantes dont le nom de la relation est pass� en param�tre.
	 * Une relation sortante est une relation dont la source est le mot.
	 * @param nomType Nom de la relation.
	 * @return Les voisins ({@link Voisin}) du terme pour les relations sortantes dont le nom de la relation est pass� en param�tre. S'il n'y en a aucun,
	 * ou si le nom de correspond pas � une relation existante, retourne une liste vide.
	 */
	public ArrayList<Voisin> getRelationsSortantesTypees(String nomType){
		ArrayList<Voisin> resultats;
		Integer type = RequeterRezo.correspondancesRelations.get(nomType);
		if(type != null) {
			resultats = getRelationsSortantesTypees(type);
		}else {
			resultats = new ArrayList<>();
		}
		return resultats;
	}


	/**
	 * Retourne les voisins ({@link Voisin}) du terme pour les relations entrantes dont le type de la relation est pass� en param�tre.
	 * Une relation entrante est une relation dont la destination est le mot.
	 * @param type Type de la relation.
	 * @return Les voisins ({@link Voisin}) du terme pour les relations entrantes dont le type de la relation est pass� en param�tre. S'il n'y en a aucun,
	 * ou si le nom de correspond pas � une relation existante, retourne une liste vide.
	 */
	public ArrayList<Voisin> getRelationsEntrantesTypees(int type){
		ArrayList<Voisin> resultats;
		if((resultats = relationsEntrantes.get(type))==null) {
			resultats = new ArrayList<>();
		}
		return resultats;
	}

	/**
	 * Retourne les voisins ({@link Voisin}) du terme pour les relations sortantes dont le type de la relation est pass� en param�tre.
	 * Une relation sortante est une relation dont la destination est le mot.
	 * @param type Type de la relation.
	 * @return Les voisins ({@link Voisin}) du terme pour les relations sortantes dont le type de la relation est pass� en param�tre. S'il n'y en a aucun,
	 * ou si le nom de correspond pas � une relation existante, retourne une liste vide.
	 */
	public ArrayList<Voisin> getRelationsSortantesTypees(int type){
		ArrayList<Voisin> resultats;
		if((resultats = relationsSortantes.get(type))==null) {
			resultats = new ArrayList<>();
		}
		return resultats;
	}

	/**
	 * Retourne la table d'association des relations entrantes.
	 * Une relation entrantes est une relation dont le mot est la destination.
	 * La cl� correspond au type de la relation et la valeur � la liste des voisins ({@link Voisin}). 
	 * @return La table d'association des relations entrantes.
	 */
	public HashMap<Integer, ArrayList<Voisin>> getRelationsEntrantes() {
		return relationsEntrantes;
	}

	/**
	 * Retourne la table d'association des relations sortantes.
	 * Une relation sortantes est une relation dont le mot est la source.
	 * La cl� correspond au type de la relation et la valeur � la liste des voisins ({@link Voisin}). 
	 * @return La table d'association des relations sortantes.
	 */
	public HashMap<Integer, ArrayList<Voisin>> getRelationsSortantes() {
		return relationsSortantes;
	}

	/**
	 * Retourne la liste des annotations ({@link Annotation}) portant sur les relations du mot.
	 * @return la liste des annotations ({@link Annotation}) portant sur les relations du mot.
	 */
	public ArrayList<Annotation> getAnnotations() {
		return annotations;
	}

	
	/**
	 * Fusionne deux mots dans un seul. Cette fonction peut �tre utile lorsque l'on a effectu� deux requ�tes filtr�es sur un m�me terme.
	 * Cela permet de regrouper les deux r�sultats dans un m�me objet.
	 * @param mot1 Premier mot � fusionner. 
	 * @param mot2 Second mot � fusionner.
	 * @return Si les deux mots sont bien le m�me terme, retourne l'union de leur voisinage. Sinon, retourne le premier mot.
	 */
	public static Mot fusion(Mot mot1, Mot mot2) {
		ArrayList<Mot> mots = new ArrayList<>(2);
		mots.add(mot1);
		mots.add(mot2);
		return fusion(mots);
	}

	/**
	 * Fusionne une liste de mot dans un seul. Cette fonction peut �tre utile lorsque l'on a effectu� plusieurs requ�tes filtr�es sur un m�me terme.
	 * Cela permet de regrouper les r�sultats dans un m�me objet.
	 * @param mots Liste de mots � fusionner.
	 * @return Retourne la fusion (l'union des voisinages) des termes identiques au premier mot de la liste.
	 */
	public static Mot fusion(ArrayList<Mot> mots) {
		Mot res = null;
		if(!mots.isEmpty()) {
			res = mots.get(0);
			HashMap<Integer, ArrayList<Voisin>> entrantes = res.getRelationsEntrantes();
			HashMap<Integer, ArrayList<Voisin>> sortantes = res.getRelationsSortantes();
			ArrayList<Annotation> annotations = res.getAnnotations();
			Mot intermediaire;
			int id_relation;
			ArrayList<Voisin> voisins, voisins_intermediaire;
			for(int i = 1; i < mots.size(); ++i) {
				intermediaire = mots.get(i);
				if(intermediaire.getNom().equals(res.getNom())) {
					for(Entry<Integer, ArrayList<Voisin>> entry : intermediaire.getRelationsEntrantes().entrySet()) {
						id_relation = entry.getKey();
						voisins_intermediaire = entry.getValue();
						if((voisins=entrantes.get(id_relation)) == null) {
							entrantes.put(id_relation, voisins_intermediaire);
						}else {
							for(Voisin voisin : voisins_intermediaire) {
								if(!voisins.contains(voisin)) {
									voisins.add(voisin);
								}
							}
						}
					}
					for(Entry<Integer, ArrayList<Voisin>> entry : intermediaire.getRelationsSortantes().entrySet()) {
						id_relation = entry.getKey();
						voisins_intermediaire = entry.getValue();
						if((voisins=sortantes.get(id_relation)) == null) {
							sortantes.put(id_relation, voisins_intermediaire);
						}else {
							for(Voisin voisin : voisins_intermediaire) {
								if(!voisins.contains(voisin)) {
									voisins.add(voisin);
								}
							}
						}
					}
					for(Annotation annotation : intermediaire.getAnnotations()) {
						if(!annotations.contains(annotation)) {
							annotations.add(annotation);
						}
					}
				}
			}
		}		
		return res;
	}

}
