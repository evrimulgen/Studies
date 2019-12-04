package requeterrezo;

import java.io.File;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
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
 * Classe utilitaire regroupant des outils divers.
 * @author jimmy.benoits
 */
class Utils {

	/**
	 * Format des dates utilis�es pour le cache.
	 */
	protected static SimpleDateFormat formatDate = new SimpleDateFormat("dd-MM-yyyy hh:mm:ss aaa");

	/**
	 * D�termine si une date est "p�rim�e".
	 * @param date Date � tester.
	 * @param peremption Nombre d'heures du d�lais de p�remption.
	 * @return True si le nombre d'heures qui s�pare la date � tester du moment actuel est sup�rieur au d�lais de p�remption.
	 */
	protected static boolean perime(Date date, int peremption) {
		return heuresEcarts(new Date(), date) > peremption;
	}

	/**
	 * D�termine le nombre d'heure entre deux dates.
	 * @param maintenant Premi�re date.
	 * @param enregistrement Seconde date.
	 * @return Le nombre d'heure entre la premi�re et la seconde date. La premi�re est suppos�e �tre la plus r�cente.
	 */
	protected static int heuresEcarts(Date maintenant, Date enregistrement) {
		return (int) ((maintenant.getTime() - enregistrement.getTime()) / 3_600_000);
	}

	/**
	 * Retourne l'ID d'un �l�ment du cache � partir de son chemin.
	 * @param chemin Chemin d'un fichier du cache (si id = 126, le chemin sera "1/2/6.cache").
	 * @return L'id d'un �l�ment du cache si on a pu le construire, null sinon.
	 */
	protected static Integer recupererID(String chemin){
		Integer res = null;
		String tmp = "";
		String c;	
		if(chemin.endsWith(".cache")) {
			chemin = chemin.substring(0, chemin.length()-6);
			String cheminCache = RequeterRezo.cheminCache;		
			int indexOf = chemin.indexOf(cheminCache);
			int tailleCheminCache = cheminCache.length();
			if(indexOf != -1 && (indexOf+tailleCheminCache) < chemin.length()) {
				chemin = chemin.substring(indexOf+tailleCheminCache+1);			
				//replaceAll(File.separator,"") => pas possible sous WIN car File.separator est caract�re d'�chappement
				for(int i = 0; i < chemin.length(); ++i) {
					c = String.valueOf(chemin.charAt(i));
					if(!c.equals(File.separator)) {
						tmp += c;
					}
				}
				chemin = tmp;
				try {
					res = Integer.parseInt(chemin);
				}catch(NumberFormatException e) {
					res = null;
				}
			}	
		}
		return res;
	}

	protected static String construireChemin(int ID) {
		String res = RequeterRezo.cheminCache;
		String tmp = Integer.toString(ID);
		for (int i = 0; i < tmp.length(); ++i) {
			res += File.separator + tmp.charAt(i);
		}
		return res +".cache";
	}

	protected static ArrayList<File> fichiersCache(File fichierCache) {		
		ArrayList<File> fichiersCache = new ArrayList<>();
		if(fichierCache.isDirectory()) {
			for(File fichier : fichierCache.listFiles()) {
				fichiersCache.addAll(fichiersCache(fichier));						
			}			
		}else if(fichierCache.getName().endsWith(".cache")){			 
			fichiersCache.add(fichierCache);
		}		
		return fichiersCache;
	}

	protected static TypeNoeud equivalenceNoeud(int typeNoeud) {
		switch (typeNoeud) {
		case 0:
			return TypeNoeud.n_generic;

		case 1:
			return TypeNoeud.n_term;

		case 2:
			return TypeNoeud.n_form;

		case 4:
			return TypeNoeud.n_pos;

		case 5:
			return TypeNoeud.n_concept;

		case 6:
			return TypeNoeud.n_flpot;

		case 8:
			return TypeNoeud.n_chunk;

		case 9:
			return TypeNoeud.n_question;

		case 10:
			return TypeNoeud.n_relation;

		case 11:
			return TypeNoeud.r_rule;

		case 12:
			return TypeNoeud.n_analogy;

		case 13:
			return TypeNoeud.n_commands;

		case 14:
			return TypeNoeud.f_synt_function;

		case 18:
			return TypeNoeud.n_data;

		case 36:
			return TypeNoeud.n_data_pot;

		case 444:
			return TypeNoeud.n_link;

		case 666:
			return TypeNoeud.n_AKI;

		case 777:
			return TypeNoeud.n_wikipedia;

		default:
			return TypeNoeud.non_defini;
		}
	}
}
