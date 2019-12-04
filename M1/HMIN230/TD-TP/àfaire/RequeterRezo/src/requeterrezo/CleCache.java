package requeterrezo;

import java.io.Serializable;
import java.util.Objects;


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
 * Repr�sente une requ�te. Compos� du nom du terme recherch�, du type de la relation si la requ�te avait un filtre de type (ou -1 sinon)
 * et du filtre ({@link Filtre}) utilis�.
 * @author jimmy.benoits
 */
class CleCache implements Serializable{

	/**
	 * 01/01/2019 - V1.0
	 */
	private static final long serialVersionUID = 1L;
	
	/**
	 * Nom du terme recherch�. Il est pr�f�rable de toujours effectuer des requ�tes gr�ce au "nom" des termes de rezoJDM et de n'utiliser les
	 * noms format�s qu'� des fins d'affichage.
	 */
	protected String nom;
	
	/**
	 * Type de la relation si un filtre sur le type a �t� utilis� (-1 sinon).
	 */
	protected int typeRelation;
	
	/**
	 * Filtre entrants / sortants / les deux / aucun.
	 */
	protected Filtre filtre;

	/**
	 * Constructeur simple. 
	 * @param nom Nom du terme.
	 */
	protected CleCache(String nom) {
		this.nom = nom;
		this.typeRelation = -1;
		this.filtre = Filtre.AucunFiltre;
	}

	/**
	 * Constructeur param�tr�.
	 * @param nom Nom du terme.
	 * @param type Type de relation (-1 si aucun filtre sur le type).
	 * @param filtre Filtre utilis�.
	 */
	protected CleCache(String nom, int type, Filtre filtre) {
		this.nom = nom;
		this.typeRelation = type;
		this.filtre = filtre;
	}

//	protected static CleCache lire(String ligne) {
//		CleCache res = null;
//		String nom = ligne;
//		int typeRelation = -1;
//		Filtre filtre = Filtre.AucunFiltre;
//		int indexOf;
//		String tmp;
//		indexOf = ligne.lastIndexOf(';');
//		if(indexOf+1 < ligne.length()) {
//			tmp = ligne.substring(indexOf+1, ligne.length());
//			try{
//				filtre = Filtre.valueOf(tmp);
//			}catch(NumberFormatException e) {
//				e.printStackTrace();
//			}
//			ligne = ligne.substring(0, indexOf);
//
//			indexOf = ligne.lastIndexOf(';');
//			if(indexOf+1 < ligne.length()) {
//				tmp = ligne.substring(indexOf+1, ligne.length());
//				try{
//					typeRelation = Integer.parseInt(tmp);					
//				}catch(NumberFormatException e) {
//					e.printStackTrace();
//				}
//				nom = ligne.substring(0, indexOf);
//				res = new CleCache(nom, typeRelation, filtre);
//			}
//		}		
//		return res;
//	}

//	protected static CleCache construireCleCache(String ligne) {
//		CleCache cleCache = null;
//		String nom;
//		int type;
//		Filtre filtre;
//
//		String tmp;
//		//r�cup�rer partie filtre => apr�s dernier ';'
//		int indexOf = ligne.lastIndexOf(';');
//		if(indexOf != -1) {
//			tmp = ligne.substring(indexOf+1, ligne.length());
//			ligne = ligne.substring(0,indexOf);			
//			try {
//				filtre = Filtre.valueOf(tmp);
//				//r�cup�rer partie type relation => apr�s dernier ';' restant
//				indexOf = ligne.lastIndexOf(';');
//				if(indexOf != -1) {
//					tmp = ligne.substring(indexOf+1, ligne.length());
//					ligne = ligne.substring(0,indexOf);			
//					try {
//						type = Integer.parseInt(tmp);
//						//r�cup�rer le mot => partie restante sans le premier (') et le dernier (') caract�res
//						if(ligne.length() >2) {
//							nom = ligne.substring(1, ligne.length()-1);
//							cleCache = new CleCache(nom, type, filtre);
//						}						
//					}catch(NumberFormatException e) {
//						e.printStackTrace();
//					}
//				}	
//			}catch(IllegalArgumentException e) {
//				e.printStackTrace();
//			}
//		}
//
//		return cleCache;
//	}

	@Override
	public String toString() {
		return "'" + nom + "';" + typeRelation + ";" + filtre;
	}

	@Override
	public int hashCode() {
		int hash = 5;
		hash = 29 * hash + Objects.hashCode(this.nom) + Objects.hashCode(this.filtre) + Objects.hashCode(this.typeRelation);
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
		final CleCache other = (CleCache) obj;
		return Objects.equals(this.nom, other.nom) && (this.typeRelation == other.typeRelation) && (this.filtre == other.filtre);
	}

}
