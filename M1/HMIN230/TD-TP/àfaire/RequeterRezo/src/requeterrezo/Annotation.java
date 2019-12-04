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


/**
 * 
 * Les annotations sont un moyen dans rezoJDM de poser des informations sur les relations.
 * Ces informations peuvent porter sur la fr�quence (toujours vrai, rare, toujours faux, etc.), la pertinence, le caract�re humouristique, etc.
 * Une relation peut �tre annot�e plusieurs fois (quelque chose peut �tre � la fois "toujours vrai" et "non pertinent").
 * Et une annotation peut �tre elle-m�me annot�e.
 * 
 *  Les annotations sont un outils puissants mais parfois difficile � prendre en main. 
 *  Dans rezoJDM, une annotation transforme une relation en un noeud. RequeterRezo regroupe au m�me endroit les annotations portant sur les relations
 *  du terme demand�. Cela permet de savoir quelles relations sont annot�es. Pour obtenir la valeur de (ou des) annotations ("rare", "pertinent", etc.)
 *  il est n�cessaire d'effectuer une nouvelle requ�te (gr�ce au "nom" de l'annotation).
 *  
 *  Le nom d'une annotation est compos� de ":r" suivi de l'ID de la relation annot�e. Par exemple : ":r34672520". Le nom format� permet de lire
 *  l'annotation : "m�choire --r_has_part#9:33524--&gt; gencive"
 *  
 *  @see Noeud
 * @author jimmy.benoits
 */
public class Annotation extends Noeud {

	/**
	 * 01/01/2019 - V1.0
	 */
	private static final long serialVersionUID = 1L;
	
	/**
	 * Noeud source de la relation annot�e. 
	 */
	protected Noeud source;
	
	/**
	 * Type de la relation annot�e.
	 */
    protected int typeRelation;
    
    /**
     * Nom du type de la relation annot�e. Cela permet un affichage "format�" lisible de l'annotation.
     */
    protected String nomTypeRelation;
    
    /**
     * Noeud destination de la relation annot�e.
     */
    protected Noeud destination;
    
    /**
     * Poids de la relation annot�e.
     */
    protected int poidsRelation;

    /**
     * Construit une annotation � partir d'un noeud annotation (la r�ification de la relation annot�e), d'un noeud source, d'un noeud destination, d'un type et d'un poids.
     * @param nom Nom donn�e � l'annotation. Par convention, dans rezoJDM, les annotations sont de la forme ":r" suivi de l'ID de la relation annot�e.
     * @param idJDM ID du noeud annotation (r�ification de la relation annot�e).
     * @param type type du noeud annotation (r�ification de la relation annot�e).
     * @param poids poids  du noeud annotation (r�ification de la relation annot�e).
     * @param source Noeud source de la relation annot�e.
     * @param typeRelation Type de la relation annot�e.
     * @param nomTypeRelation Nom du type de la relation annot�e.
     * @param destination Noeud destination de la relation annot�e.
     * @param poidsRelation Poids de la relation annot�e.
     */
    protected Annotation(
            String nom, long idJDM, int type, int poids,
            Noeud source,
            int typeRelation, String nomTypeRelation,
            Noeud destination,
            int poidsRelation) {
        super(nom, idJDM, type, "[" + source.getNom() + " --" + nomTypeRelation + "#" + typeRelation + ":" + destination.getIdRezo() + "--> " + destination.getNom() + "]", poids);
        this.nomTypeRelation = nomTypeRelation;
        this.source = source;
        this.typeRelation = typeRelation;
        this.destination = destination;
        this.poidsRelation = poidsRelation;
    }
    
    
    @Override
    public String toString() {
        return nom+";"+idRezo+";"+type+";"+ poids + ";" + 
                source.getIdRezo() + ";" + 
                typeRelation + ";"+ nomTypeRelation +";"+ 
                destination.getIdRezo();
    }

}
