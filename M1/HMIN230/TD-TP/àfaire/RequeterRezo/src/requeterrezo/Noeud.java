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
import java.util.Objects;

/**
 * Objet de base de rezoJDM. Un noeud est compos� de : 
 * - un nom : cha�ne de caract�re unique (g�n�ralement le "mot" lui-m�me).
 * - d'un ID : entier unique.
 * - d'un type : les types de noeuds utilis�s dans rezoJDM sont disponibles � l'adresse (http://www.jeuxdemots.org/jdm-about.php) 
 * et dans l'enum {@link TypeNoeud}.
 * - d'un mot format� : souvent identique au "nom" sauf lorsque celui-ci est sous une forme peu lisible. Dans ce cas, 
 * le mot format� permet un affichage lisible. Il est d�conseill� de l'utiliser pour d'autre raison qu'� des fins d'affichage.
 * - d'un poids : le poids du noeud dans rezoJDM.
 * @author jimmy.benoits
 */
public class Noeud implements Serializable{

	/**
	 * 01/01/2019 - V1.0
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * Cha�ne de caract�res d�crivant le mot. Le nom d'un terme est unique dans rezoJDM.
	 * C'est l'�l�ment � utiliser pour effectuer une requ�te.	
	 */
	protected final String nom;

	/**
	 * ID du noeud dans rezoJDM.
	 */
	protected long idRezo;

	/**
	 * Type du noeud dans rezoJDM (-1 par d�faut, en cas d'absence de type).
	 */
	protected int type = -1;

	/**
	 * Bien souvent identique au "nom", mais propose parfois d'autres informations (notamment pour les annotations o� les raffinements).
	 * Il est d�conseill� de l'utiliser pour d'autre raison qu'� des fins d'affichage.
	 */
	protected String motFormate;

	/**
	 * Poids du mot dans RezoJDM.
	 */
	protected int poids;

	/**
	 * Constructeur param�tr�.
	 * @param nom nom du noeud.
	 * @param idRezo id du noeud.
	 * @param type type du noeud.
	 * @param motFormate mot format� du noeud.
	 * @param poids poids du noeud.
	 */
	protected Noeud(String nom, long idRezo, int type, String motFormate, int poids) {
		this.nom = nom;
		this.idRezo = idRezo;
		this.type = type;
		this.motFormate = motFormate;
		this.poids = poids;
	}

	/**
	 * Cr�� un noeud � partir uniquement de son nom et utilise les valeurs par d�faut pour le reste.
	 * @param nom
	 */
	protected Noeud(String nom) {
		this.nom = nom;
		this.motFormate = nom;
	}

	/**
	 * Retourne le nom du mot. C'est la partie � utiliser pour effectuer des requ�tes. 
	 * @return une cha�ne de caract�re unique (g�n�ralement le "mot" lui-m�me).
	 */
	public String getNom() {
		return nom;
	}

	/**
	 * Retourne l'id du mot dans rezoJDM.
	 * @return l'identifiant unique du mot dans rezoJDM. 
	 */
	public long getIdRezo() {
		return idRezo;
	}

	/**
	 * Retourne le type du mot dans rezoJDM. Les types de noeuds utilis�s dans rezoJDM sont disponibles � l'adresse (http://www.jeuxdemots.org/jdm-about.php) 
	 * et dans l'enum {@link TypeNoeud}.
	 * @return retourne le type du noeud dans rezoJDM.
	 */
	public int getType() {
		return type;
	}

	/**
	 * Souvent identique au "nom" sauf lorsque celui-ci est sous une forme peu lisible. Dans ce cas, 
	 * le mot format� permet un affichage lisible. Il est d�conseill� de l'utiliser pour d'autre raison qu'� des fins d'affichage.
	 * @return Le mot format� du mot.
	 */
	public String getMotFormate() {
		return motFormate;
	}

	/**
	 * Retourne le poids du mot dans rezoJDM.
	 * @return le poids du mot dans rezoJDM.
	 */
	public int getPoids() {
		return poids;
	}

	@Override
	public int hashCode() {
		int hash = 7;
		hash = 41 * hash + Objects.hashCode(this.nom);
		return hash;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null) {
			return false;
		}
		if (getClass() != obj.getClass()) {
			return false;
		}
		final Noeud other = (Noeud) obj;
		return !Objects.equals(this.nom, other.nom);
	}

	protected static Noeud lire(String ligne) {
		Noeud noeud = null;

		return noeud;
	}

	@Override
	public String toString() {
		String res = String.valueOf(idRezo)+";";
		res += "'"+nom+"';";
		res += String.valueOf(type)+";";
		res += String.valueOf(poids);
		if(!nom.equals(motFormate)) {
			res += ";"+motFormate;
		}
		return res;
	}
}
