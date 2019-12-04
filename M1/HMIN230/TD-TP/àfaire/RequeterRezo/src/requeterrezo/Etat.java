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
 * Indique l'�tat de la requ�te. Particuli�rement utile pour les requ�tes "live" (effectu�es avec {@link RequeterRezoDump}).
 * 
 * @author jimmy.benoits
 *
 */
public enum Etat {
	/**
	 * La cha�ne demand�e ne correspond � aucun terme dans rezoJDM. Ceci peut provenir d'un probl�me d'encodage (rezoJDM et RequeterRezo sont
	 * encod� en ISO-8859-1. Le mot r�sultat sera null.
	 */
	INEXISTANT,
	/**
	 * Le mot r�sultat a du �tre tronqu� pour des raisons de performance. Lorsque le r�sultat a plus de 25 000 relations, rezo-dump le tronque
	 * afin de lib�rer de la ressource. Pour �viter ceci, utilisez plus de filtre (notamment sur les grandes entr�es) ou si le probl�me persiste,
	 * passez � une version "locale" de RequeterRezo ({@link RequeterRezoSQL}).
	 */
	TROP_GROS,
	/**
	 * Lorsqu'un mot trop gros n'est pas en cache, il arrive que la premi�re requ�te n'aboutisse pas. Le mot r�sultat sera null. Mais r�-it�rer 
	 * la requ�te devrait permettre d'obtenir un r�sultat (probablement {@link Etat#TROP_GROS}). 
	 */
	RENVOYER,
	/**
	 * Etat retourn� lorsque le service rezo-dump (http://www.jeuxdemots.org/rezo-dump.php) est inacessible. Le mot r�sultat sera null.
	 */
	SERVEUR_INACCESSIBLE,
	/**
	 * Etat de base lorsque la requ�te s'est d�roul�e normalement.
	 */
	OK,
	/**
	 * Autre erreur lors de la requ�te. Cela peut provenir notamment d'un filtre sur un type inconnu par RequeterRezo.
	 */
	ERREUR_REQUETE;
}