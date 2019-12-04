package requeterrezo;

import java.io.Serializable;
import java.util.Date;


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
 * Contient la date de la derni�re demande ainsi que le nombre de demande d'une requ�te en attente.
 * 
 *  @see Attente
 * @author jimmy.benoits
 */
class AttenteInfo implements Serializable{

	/**
	 * 01/01/2019 - V1.0
	 */
	private static final long serialVersionUID = 1L;
	
	/**
	 * Nombre d'occurrences de la requ�te (depuis sa premi�re rencontre, m�me si elle est pass�e par le cache en attendant).
	 * Si un nombre d'heure sup�rieur au d�lais de p�remption s'est �coul�e depuis la derni�re demande, le compteur est r�initialis�.
	 */
	protected int occurrences;
	
	/**
	 * Date de la derni�re occurrence.
	 */
	protected Date dateOccurrences;

	/**
	 * Incr�mente le nombre d'occurence. 
	 * Si un nombre d'heure sup�rieur au d�lais de p�remption s'est �coul�e depuis la derni�re demande, le compteur est r�initialis�.
	 * @param peremption
	 */
    protected void incrementeOccurrences(int peremption) {
        if (Utils.perime(dateOccurrences, peremption)) {
            occurrences = 1;
        } else {
            ++occurrences;
        }
        dateOccurrences = new Date();
    }

    /**
     * Constructeur param�tr� 
     * @param occurrences Nombre d'occurrence de la requ�te.
     * @param date_occurrences Date de la dern�re occurrence.
     */
    protected AttenteInfo(int occurrences, Date date_occurrences) {
        this.occurrences = occurrences;
        this.dateOccurrences = date_occurrences;
    }
    
    /**
     * Constructeur par d�faut. Le nombre d'occurrence de base est fix� � 1 et une nouvelle date est cr��e.
     */
    protected AttenteInfo() {
        occurrences = 1;
        dateOccurrences = new Date();
    }
    
    @Override
    public String toString() {       
        return occurrences + ";" + Utils.formatDate.format(dateOccurrences);
    }
}
