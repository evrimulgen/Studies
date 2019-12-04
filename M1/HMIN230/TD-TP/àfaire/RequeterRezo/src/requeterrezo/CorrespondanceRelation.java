package requeterrezo;

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
 * Permet de retourner le type d'une relation � partir de son nom et inversement. Dans RequeterRezo, une instance unique est cr��e � chaque session.
 * Si cela est possible, elle est remplie au d�marrage. Sinon elle est rempli au fur et � mesure que les nouvelles relations sont rencontr�es. 
 * @author jimmy.benoits
 */
class CorrespondanceRelation {

	/**
	 * Lie un nom de relation � son type.
	 */
	protected HashMap<String, Integer> nom_vers_id;
	
	/**
	 * Lie un type de relation � son nom.
	 */
	protected HashMap<Integer, String> id_vers_nom;

	/**
	 * Constructeur param�tr�. 
	 * @param nom_vers_id Table liant un nom � un type de relation.
	 * @param id_vers_nom Table inverse de nom_vers_id, liant un type de relation � son nom.
	 */
	protected CorrespondanceRelation(HashMap<String, Integer> nom_vers_id, HashMap<Integer, String> id_vers_nom) {
        this.nom_vers_id = nom_vers_id;
        this.id_vers_nom = id_vers_nom;
    }

	/**
	 * Constructeur par d�faut. Initialise les tables.
	 */
	protected CorrespondanceRelation() {
        nom_vers_id = new HashMap<>();
        id_vers_nom = new HashMap<>();
    }

	/**
	 * Retourne le nom d'une relation si la correspondance existe.
	 * @param id_relation Type d'une relation.
	 * @return Le nom de la relation dont le type est pass� en param�tre si la correspondance existe (chargement correct au d�marrage de la session
	 * ou la relation a d�j� rencontr� dans un mot). Null si le type ne correspond pas � un type de relation de rezoJDM ou 
	 * que la correspondance n'a pas encore �t� faite.
	 */
	protected String get(int id_relation) {
        return id_vers_nom.get(id_relation);
    }

	/**
	 * Retourne le type d'une relation si la correspondance existe.
	 * @param nom_relation Nom d'une relation.
	 * @return Le type de la relation dont le nom est pass� en param�tre si la correspondance existe (chargement correct au d�marrage de la session
	 * ou la relation a d�j� rencontr� dans un mot). Null si le nom ne correspond pas � un type de relation de rezoJDM ou 
	 * que la correspondance n'a pas encore �t� faite.
	 */
	protected Integer get(String nom_relation) {
        return nom_vers_id.get(nom_relation);
    }

	/**
	 * Ajoute une nouvelle correspondance.
	 * @param nom Nom d'une relation.
	 * @param id Type d'une relation.
	 */
	protected void ajouter(String nom, int id) {
		nom_vers_id.put(nom, id);
	}

	/**
	 * Ajoute une nouvelle correspondance.
	 * @param id Type d'une relation.
	 * @param nom Nom d'une relation.
	 */
	protected void ajouter(int id, String nom) {
		id_vers_nom.put(id, nom);
	}

   
}
