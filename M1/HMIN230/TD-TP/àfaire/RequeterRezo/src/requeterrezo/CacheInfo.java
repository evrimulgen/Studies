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
 *	Informations li�es � une requ�te entr�e dans le cache. Contient son identifiant dans le cache (permettant de retrouver son emplacement 
 *	dans le dossier de cache), sa date d'entr�e dans le cache, sa date de derni�re consultation, son nombre d'occurrences, la taille du fichier sur
 *	le disque (en octet) et l'�tat de la requ�te ({@link Etat}).
 * @author jimmy.benoits
 */
class CacheInfo implements Serializable{

	/**
	 * 01/01/2019 - V1.0
	 */
	private static final long serialVersionUID = 1L;
	
	/**
	 * Identifiant de la requ�te dans le cache. Permet de retrouver son emplacement dans le cache.
	 */
	protected final int ID;
	
    /**
     * Date d'entr�e dans le cache.
     */
    protected Date dateCache;
    
    /**
     * Nombre d'occurrences (nombre de consultation dans le cache et �ventuellement le nombre de demande avant son entr�e).
     */
    protected int occurrences;
    
    /**
     * Date de la derni�re occurrence.
     */
    protected Date dateOccurrences;
    
    /**
     * Taille du fichier sur le disque (en octet).
     */
    protected long tailleFichier;
    
    /**
     * Etat de la requ�te.
     */
    protected Etat etat;
    
    
    /**
     * Appel�e lors d'une consultation. Incr�mente le nombre d'occurrence et met � jour � la date de consultation.
     */
    protected void incrementeOccurrences() {
        ++occurrences;
        dateOccurrences = new Date();
    }

    /**
     * Constructeur param�tr�.
     * @param ID Id de la requ�te.
     * @param dateCache Date d'entr�e dans le cache.
     * @param occurrences Nombre d'occurrences.
     * @param dateOccurrences Date de la derni�re occurrence.
     * @param tailleFichier Taille du fichier sur le disque (en octet).
     * @param etat Etat de la requ�te.
     */
    public CacheInfo(int ID, Date dateCache, int occurrences, Date dateOccurrences, long tailleFichier, Etat etat) {
        this.ID = ID;
        this.dateCache = dateCache;
        this.occurrences = occurrences;
        this.dateOccurrences = dateOccurrences;
        this.tailleFichier = tailleFichier;
        this.etat = etat;        
    }

    @Override
    public String toString() {       
        return ID + ";" +  
               Utils.formatDate.format(dateCache) + ";" + 
                occurrences + ";" + 
                Utils.formatDate.format(dateOccurrences) + ";" + 
                this.tailleFichier+";"+this.etat;
    }

}
