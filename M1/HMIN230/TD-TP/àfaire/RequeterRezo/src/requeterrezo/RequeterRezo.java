package requeterrezo;

import java.io.File;
import java.util.ArrayList;
import java.util.Date;
import java.util.Iterator;
import java.util.Map.Entry;


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
 * Classe m�re de la classe principale de RequeterRezo. Regroupe les comportements partag�s par la version "live" ({@link RequeterRezoDump})
 * qui effectue ses requ�tes sur le service rezo-dump (www.jeuxdemots.org/rezo-dump.php) et la version "locale" ({@link RequeterRezoSQL}) qui
 * les effectue sur un serveur MySQL h�bergeant les donn�es de rezoJDM.
 * 
 * Les param�tres principaux de RequeterRezo sont : 
 * - La taille maximale du cache : nombre d'octet � partir duquel le syst�me n'acceptera plus de nouvelles entr�es dans le cache sans en faire
 * sortir une autre. Cela a pour effet de limiter la taille du cache mais le calcul exact pourra �tre l�g�rement plus �lev� que le nombre pr�vu.
 * La valeur par d�faut est fix�e � 100mo.
 * 
 * - Le d�lais de p�remption : nombre d'heure � partir duquel un �l�ment du cache est jug� obsol�te. RezoJDM est une ressource vivante et les
 * �l�ments changent r�guli�rement. C'est pour cela qu'il est parfois n�cessaire de redemander un mot. La fr�quence doit �tre d�finie par l'utilisateur
 * en fonction de ses besoins (�tre toujours � jour avec rezoJDM est-il tr�s important ?).
 * La valeur par d�faut est fix� � 168h (7 jours).
 * 
 * De nombreux constructeurs et m�thodes pour effectu�es des requ�tes sont disponibles. Il est �galement possible de construire votre objet
 * � partir d'un fichier de configuration ".ini" dont un exemplaire est fourni avec cette archive. Passer par un fichier de configuration d�bloque
 * des param�trages non-disponible autrement comme le mode avanc� (qui laisse le soin � l'utilisateur d'appeler lui-m�me la m�thode 
 * {@link RequeterRezo#sauvegarder()}, ce qui est d�conseill�) ou de changer le chemin de stockage du cache.
 * 
 * Un fichier Exemple.java est normalement distribu�e avec RequeterRezo. Il explique les premiers pas pour commencer � utiliser
 * RequeterRezo.
 * @author jimmy.benoits
 */
public abstract class RequeterRezo {

	/**
	 * Chemin par d�faut du dossier du cache.
	 */
	protected final static String CHEMIN_CACHE_DEFAUT = "cache";

	/**
	 * Chemin par d�faut du fichier contenant la s�rialisation de l'index d'attente ({@link Attente}).
	 */
	protected final static String FICHIER_ATTENTE_DEFAUT = CHEMIN_CACHE_DEFAUT + File.separator + "indexAttente";

	/**
	 * Chemin par d�faut du fichier contenant la s�rialisation de l'index du cache ({@link Cache}).
	 */
	protected final static String FICHIER_CACHE_DEFAUT = CHEMIN_CACHE_DEFAUT + File.separator + "indexCache";

	/**
	 * Taille maximale par d�faut du cache (en octet).
	 */
	protected final static long TAILLE_CACHE_DEFAUT = 100_000_000;

	/**
	 * D�lais de p�remption par d�faut (en heure).
	 */
	protected final static int PEREMPTION_DEFAUT = 168;

	/**
	 * Etat par d�faut du mode avanc�.
	 */
	protected final static boolean MODE_AVANCE_DEFAUT = false;

	/**
	 * Etat par d�faut de l'affichage des messages.
	 */
	protected final static boolean AVERTISSEMENT_DEFAUT = true;

	/**
	 * Permet la correspondance entre le nom et le type des relations de rezoJDM.
	 */
	protected static CorrespondanceRelation correspondancesRelations = new CorrespondanceRelation();    

	/**
	 * Mots en attente.
	 */
	protected Attente attente;

	/**
	 * Mots stock�s dans le cache.
	 */
	protected Cache cache;

	/**
	 * Taille maximale du cache (en octet).
	 */
	protected final long tailleCache;

	/**
	 * Nombre d'heure � partir duquel un fichier du cache est consid�r� comme p�rim�. 
	 */
	protected final int peremption;

	/**
	 * Le mode avanc� d�sactive la sauvegarde automatique des index. L'utilisateur doit lui-m�me sauvegarder r�guli�rement gr�ce � la m�thode
	 * {@link RequeterRezo#sauvegarder()}.
	 */
	protected boolean modeAvance;  

	/**
	 * Permet (ou non) � RequeterRezo d'afficher des messages sur System.err.
	 */
	protected boolean avertissement;

	/**
	 * Chemin vers le dossier du cache.
	 */
	protected static String cheminCache= CHEMIN_CACHE_DEFAUT;

	/**
	 * Chemin vers le fichier contenant l'index des mots en attentes.
	 */
	protected static String fichierAttente = FICHIER_ATTENTE_DEFAUT;

	/**
	 * Chemin vers le fichier contenant l'index des mots dans le cache.
	 */
	protected static String fichierCache = FICHIER_CACHE_DEFAUT;

	/**
	 * Constructeur param�tr� utilisant la taille maximale du cache, le d�lais de p�remption et la possibilit� (ou non) d'afficher
	 * des messages d'avertissement sur System.err.
	 * @param tailleCache Taille maximale du cache. Attent un nombre suivi d'une unit� ("ko", "mo", "go", avec "ko" par d�faut).
	 * @param peremption D�lais de p�remption. Attent un nombre suivi d'une unit� ('j' pour journ�e ou 'h' pour heure, 'h' par d�faut).
	 * @param avertissement True si le syst�me est autoris� � envoyer des messages sur System.err, false sinon.
	 */
	public RequeterRezo(String tailleCache, String peremption, boolean avertissement) {
		this.avertissement = avertissement;
		String suffixe;
		int multiplieur;
		long tailleCacheLong;
		//Partie taille cache
		if (tailleCache.length() > 2) {
			suffixe = tailleCache.substring(tailleCache.length() - 2);
			tailleCache = tailleCache.substring(0, tailleCache.length() - 2);
			//cas de base = ko           
			switch (suffixe.toLowerCase()) {
			case "mo": {
				multiplieur = 1_000_000;
				break;
			}
			case "go": {
				multiplieur = 1_000_000_000;
				break;
			}
			default: {
				multiplieur = 1_000;
				break;
			}
			}
			try {
				tailleCacheLong = Long.parseLong(tailleCache);
			} catch (NumberFormatException e) {
				tailleCacheLong = TAILLE_CACHE_DEFAUT;
				multiplieur = 1;
			}
			this.tailleCache = tailleCacheLong * multiplieur;
		} else {
			this.tailleCache = TAILLE_CACHE_DEFAUT;
		}

		//partie peremption
		char dernierChar;
		int peremptionInt;
		if (peremption.length() > 1) {
			dernierChar = peremption.charAt(peremption.length() - 1);
			peremption = peremption.substring(0, peremption.length() - 1);
			//cas de base = h
			multiplieur = 1;
			if (dernierChar == 'j') {
				multiplieur = 24;
			}
			try {
				peremptionInt = Integer.parseInt(peremption);
			} catch (NumberFormatException e) {
				peremptionInt = PEREMPTION_DEFAUT;
				multiplieur = 1;
			}
			this.peremption = peremptionInt * multiplieur;
		} else {
			this.peremption = PEREMPTION_DEFAUT;
		}
		initialiserCache();
		initialiserAttente();
	}

	/**
	 * Constructeur param�tr� utilisant la taille maximale du cache et le d�lais de p�remption.
	 * @param tailleCache Taille maximale du cache. Attent un nombre suivi d'une unit� ("ko", "mo", "go", avec "ko" par d�faut).
	 * @param peremption D�lais de p�remption. Attent un nombre suivi d'une unit� ('j' pour journ�e ou 'h' pour heure, 'h' par d�faut).
	 */
	public RequeterRezo(String tailleCache, String peremption) {		
		this(tailleCache, peremption, AVERTISSEMENT_DEFAUT);
	}

	/**
	 * Constructeur param�tr� utilisant la taille maximale du cache et le d�lais de p�remption.
	 * @param tailleCache Taille maximale du cache (en octet).
	 * @param peremption D�lais de p�remption (en heure).
	 */
	public RequeterRezo(long tailleCache, int peremption) {
		this(tailleCache,peremption,AVERTISSEMENT_DEFAUT);
	}

	/**
	 * Constructeur param�tr� utilisant la taille maximale du cache, le d�lais de p�remption et la possibilit� (ou non) d'afficher
	 * des messages d'avertissement sur System.err.
	 * @param tailleCache Taille maximale du cache (en octet).
	 * @param peremption D�lais de p�remption (en heure).
	 * @param avertissement True si le syst�me est autoris� � envoyer des messages sur System.err, false sinon.
	 */
	public RequeterRezo(long tailleCache, int peremption, boolean avertissement) {
		this.tailleCache = tailleCache;
		this.peremption = peremption;
		this.avertissement = avertissement;
		this.modeAvance = MODE_AVANCE_DEFAUT;
		initialiserCache();
		initialiserAttente();
	}

	/**
	 * Constructeur par d�faut - utilise les valeurs par d�faut.
	 */
	public RequeterRezo() {
		this(TAILLE_CACHE_DEFAUT,PEREMPTION_DEFAUT,AVERTISSEMENT_DEFAUT);
	}

	/**
	 * Constructeur param�tr� utilisant la taille maximale du cache, le d�lais de p�remption, la possibilit� (ou non) d'afficher
	 * des messages d'avertissement sur System.err, l'activation (ou non) du mode avanc� et le chemin vers le dossier de cache. 
	 * Ce constructeur n'est utilisable qu'en passant par un fichier de configuration. 
	 * @param tailleCache Taille maximale du cache (en octet).
	 * @param peremption D�lais de p�remption (en heure).
	 * @param avertissement True si le syst�me est autoris� � envoyer des messages sur System.err, false sinon.
	 */
	private RequeterRezo(long tailleCache, int peremption, boolean avertissement, boolean modeAvance, String cheminCache) {
		this.tailleCache = tailleCache;
		this.peremption = peremption;
		this.avertissement = avertissement;
		this.modeAvance = modeAvance;
		RequeterRezo.cheminCache = cheminCache;
		RequeterRezo.fichierAttente = cheminCache + File.separator + "indexAttente";
		RequeterRezo.fichierCache = cheminCache + File.separator + "indexCache";
		initialiserCache();
		initialiserAttente();
	}

	/**
	 * Construit un objet RequeterRezo � partir d'une {@link Configuration}.
	 * @param configuration Configuration a utiliser.
	 */
	public RequeterRezo(Configuration configuration) {
		this(configuration.getTailleCache(), 
				configuration.getPeremption(), 
				configuration.getAvertissement(),
				configuration.getModeAvance(),
				configuration.getCheminCache());
	}

	/**
	 * Construit les �quivalences entre nom et type de relation. La fa�on de construire est diff�rente suivant que l'on travaille en "live" ({@link RequeterRezoDump}) 
	 * ou en "local" ({@link RequeterRezoSQL}).
	 */
	protected abstract void construireRelations();

	/**
	 * Effectue la requ�te lorsque le cache ne poss�de pas l'�l�ment demande. La fa�on de construire le mot est diff�rente suivant 
	 * que l'on travaille en "live" ({@link RequeterRezoDump}) ou en "local" ({@link RequeterRezoSQL}).
	 * @param cacheKey Requ�te � effectuer.
	 * @return Le resultat de la requ�te.
	 */
	protected abstract Resultat construireMot(CleCache cacheKey);

	/**
	 * Sauvegarde les index permettant le bon fonctionnement du cache d'une ex�cution sur l'autre. 
	 * Cette m�thode n'est utile seulement si le mode avanc� a �t� activ� (ce qui est fortement d�conseill�).	
	 */
	public void sauvegarder() {
		cache.sauvegarderCache(fichierCache);
		attente.sauvegarderAttente(fichierAttente);
	}

	/**
	 * Initialise l'index des mots en attente soit � partir d'une ex�cution pr�c�dente soit en recommen�ant de 0.
	 */
	protected final void initialiserAttente() {
		File dossierCache = new File(cheminCache);
		if(!dossierCache.exists()) {
			dossierCache.mkdir();
			attente = new Attente();
		}else {
			File fichier = new File(fichierAttente);
			if(!fichier.exists()) {
				attente = new Attente();
			}else {
				attente = Attente.chargerAttente(fichierAttente);
				if(attente == null) {
					if(avertissement) {
						System.err.println("Avertissement RequeterRezo : l'index des mots en attentes est illisible");
					}
					attente = new Attente();
				}
			}			
		}
	}

	/**
	 * Initialise l'index des mots du cache soit � partir d'une ex�cution pr�c�dente soit en recommen�ant de 0.
	 * Une v�rification est effectu�e ({@link Cache#verifierIntegrite(String, boolean)} si le chargement se fait depuis un cache existant. 
	 */
	protected final void initialiserCache() {
		File dossierCache = new File(cheminCache);
		if(!dossierCache.exists()) {
			dossierCache.mkdir();
			cache = new Cache(peremption, tailleCache);
		}else {
			File fichier = new File(fichierCache);
			if(!fichier.exists()) {
				cache = new Cache(peremption, tailleCache);
			}else {
				cache = Cache.chargerCache(fichierCache);
				if(cache == null) {
					if(avertissement) {
						System.err.println("Avertissement RequeterRezo : l'index du cache est illisible");
					}
					cache = new Cache(peremption, tailleCache);
				}
				cache.verifierIntegrite(cheminCache, avertissement);
			}	
		}

	}


	/**
	 * Requ�te compl�te � partir d'un terme, d'un type de relation de rezoJDM et d'un filtre.
	 * @param mot Terme de rezoJDM.
	 * @param typeRelation Type de la relation dont on cherche le voisinage pour "mot".
	 * @param filtre Filtre � appliquer.
	 * @return Le r�sultat de la requ�te.
	 */
	public Resultat requete(String mot, int typeRelation, Filtre filtre) {
		CleCache cleCache = new CleCache(mot, typeRelation, filtre);
		Resultat resultat = requeteInterne(cleCache);
		if(!modeAvance) {
			sauvegarder();
		}
		return resultat;
	}	

	/**
	 * Requ�te � partir du terme. Retourne toutes les informations pr�sentes dans le voisinage de ce terme. 
	 * Pour les mots de taille importante, il est vivement d�conseill� d'utiliser une requ�te de la sorte mais plut�t de passer 
	 * par des filtres (type des relations ou entrants / sortants).
	 * @param mot Terme � rechercher dans rezoJDM.
	 * @return Le r�sultat de la requ�te sur le terme demand�, sans aucun filtre.
	 */
	public Resultat requete(String mot) {
		return requete(mot, -1, Filtre.AucunFiltre);
	}

	/**
	 * Requ�te � partir du terme et d'un filtre sur les relations entrantes, sortantes ou les deux.
	 * Pour les mots de taille importante, il est conseill� d'appliquer aussi un filtre sur le type de relation.
	 * @param mot Terme � rechercher dans rezoJDM.
	 * @param filtre Filtre � appliquer (entrants / sortants).
	 * @return Le r�sultat de la requ�te sur le terme demand�, avec un filtre sur la direction des relations. 
	 */
	public Resultat requete(String mot, Filtre filtre) {
		return requete(mot, -1, filtre);
	}

	/**
	 * Requ�te � partir du terme et d'un filtre sur le nom de relation.
	 * @param mot Terme � rechercher dans rezoJDM.
	 * @param typeRelation Type de la relation dont il faut extraire le voisinage.
	 * @return Le r�sultat de la requ�te sur le terme demand�, avec un filtre sur le types des relations. 
	 */
	public Resultat requete(String mot, int typeRelation) {
		return requete(mot, typeRelation, Filtre.AucunFiltre);
	}

	/**
	 * Requ�te � partir du terme et d'un filtre sur le type de relation.
	 * @param mot Terme � rechercher dans rezoJDM.
	 * @param nomTypeRelation nom du type de la relation dont il faut extraire le voisinage.
	 * @return Le r�sultat de la requ�te sur le terme demand�, avec un filtre sur le types des relations. 
	 */
	public Resultat requete(String mot, String nomTypeRelation) {
		Resultat res = null;
		Integer typeRelation = RequeterRezo.correspondancesRelations.get(nomTypeRelation);
		if (typeRelation != null) {
			res = requete(mot, typeRelation, Filtre.AucunFiltre);
		}
		else if(avertissement){
			System.err.println("Erreur RequeterRezo : "
					+ "le type de relation \""+nomTypeRelation+"\" n'a pas �t� reconnu dans la requ�te : "
					+ "\""+mot+","+nomTypeRelation+","+Filtre.AucunFiltre.toString()+"\"");
		}
		return res;
	}

	/**
	 * Requ�te compl�te � partir d'un terme, d'un nom de relation de rezoJDM et d'un filtre.
	 * @param mot Terme de rezoJDM.
	 * @param nomTypeRelation nom du type de la relation dont on cherche le voisinage pour "mot".
	 * @param filtre Filtre � appliquer.
	 * @return Le r�sultat de la requ�te.
	 */
	public Resultat requete(String mot, String nomTypeRelation, Filtre filtre) {		
		Resultat res = null;
		Integer typeRelation = RequeterRezo.correspondancesRelations.get(nomTypeRelation);
		if (typeRelation != null) {
			res = requete(mot, typeRelation, filtre);
		}else if(avertissement){
			System.err.println("Erreur RequeterRezo : "
					+ "le type de relation \""+nomTypeRelation+"\" n'a pas �t� reconnu dans la requ�te : "
					+ "\""+mot+","+nomTypeRelation+","+filtre.toString()+"\"");
		}
		return res;
	}

	/**
	 * Permet d'effectuer une requ�te filtr�e sur plusieurs types.
	 * @param mot Terme sur lequel effectuer la requ�te.
	 * @param nomsTypesRelations Noms ou types des relations, s�par�s par un point-virgule (';').
	 * @return Une liste de r�sultat, chacun contenant le mot avec son voisinage pour le type associ�.
	 */
	public ArrayList<Resultat> requeteMultiple(String mot, String nomsTypesRelations) {
		return requeteMultiple(mot, nomsTypesRelations, Filtre.AucunFiltre);
	}

	/**
	 * Permet d'effectuer une requ�te filtr�e sur plusieurs types. 
	 * @param mot Terme sur lequel effectuer la requ�te.
	 * @param filtre Filtre sur la direction des relations. Le m�me filtre est appliqu� � toutes les requ�tes.
	 * @param nomsTypesRelations Noms ou types des relations, s�par�s par un point-virgule (';').
	 * @return Une liste de r�sultat, chacun contenant le mot avec son voisinage pour le type associ�.
	 */
	public ArrayList<Resultat> requeteMultiple(String mot, String nomsTypesRelations, Filtre filtre) {
		String[] types = nomsTypesRelations.split(";");
		Resultat resultat;
		Integer typeRelation;
		ArrayList<Resultat> listeMots = new ArrayList<>();
		for (String type : types) {
			if (type.startsWith("r_")) {
				resultat = requete(mot, type, filtre);
				listeMots.add(resultat);
			} else {
				try {
					typeRelation = Integer.parseInt(type);
					resultat = requete(mot, typeRelation, filtre);
					listeMots.add(resultat);
				} catch (NumberFormatException numberFormatException) {
					if(avertissement) {
						System.err.println("Erreur requeteMultiple : impossible de lire le type \"" + type + "\". Ignor�.");
					}
				}
			}
		}
		return listeMots;
	}

	/**
	 * Centralisation des requ�tes vers un point unique qui v�rifie si la requ�te existe en cache, s'il faut faire entrer la requ�te dans le cache
	 * ou simplement retourner le r�sultat.
	 * @param cleCache Requ�te � effectuer.
	 * @return Le r�sultat de la requ�te. Soit en provenance du cache, soit en effectuant r�ellement la requ�te.
	 */
	protected Resultat requeteInterne(CleCache cleCache) {
		String avisCache = rencontrerMot(cleCache);
		boolean demande = false;
		Resultat resultat;
		switch (avisCache) {
		case "$DEMANDE$": {
			demande = true;
			break;
		}
		case "$OSEF$": {
			demande = false;
			break;
		}
		default: {                
			resultat = Resultat.lireCache(avisCache, cleCache);
			if(resultat == null) {
				cache.supprimer(cleCache);
				demande = true;
			}else {
				return resultat;
			}
		}
		}
		resultat = construireMot(cleCache);
		if (resultat.mot != null && demande) {
			int occ = 1;
			AttenteInfo info = attente.index.get(cleCache);
			if(info != null) {
				occ = info.occurrences;
			}
			cache.ajouter(cleCache, occ,resultat);
			attente.supprimer(cleCache);
			resultat.etatCache = EtatCache.NOUVELLE_ENTREE;
		}
		return resultat;
	}

	/**
	 * Analyse un requ�te pour d�terminer si : 
	 * - Elle existe dans le cache
	 * - Il faut la faire entrer dans le cache
	 * - Il faut simplement la retourner.
	 * @param mot Requ�te � analyser.
	 * @return La cha�ne "$DEMANDE$" si la requ�te doit �tre effectu�e puis placer dans le cache, "$OSEF$" si elle ne doit pas l'�tre et le chemin
	 * vers le fichier contenant la requ�te si elle existe d�j� en cache.
	 */
	protected String rencontrerMot(CleCache mot) {
		//Soit la requ�te existe dans le cache
		if (this.cache.contient(mot)) {
			return nouvelleOccurrence(mot);
		}
		//Si le cache ne contient pas le mot, on cherche dans les requ�tes en attente  
		AttenteInfo attenteInfo = attente.index.get(mot);
		if(attenteInfo != null) {
			attenteInfo.incrementeOccurrences(peremption);
		}else {
			attente.ajouter(mot,1);
		}
		//Dans tous les cas, le mot est pr�sent maintenant dans index
		//Regarde si on doit le faire entrer dans le cache
		if (demande(mot)) {
			return "$DEMANDE$";
		} else {
			return "$OSEF$";
		}
	}

	/**
	 * Traite le cas d'une requ�te existant dans le cache et d�termine s'il faut : 
	 * - Utiliser le cache retourner le chemin vers le fichier dans le cache (le fichier n'est pas p�rim�)
	 * - Ne pas utiliser le cache et effectuer la requ�te puis : 
	 *     - Ajouter le r�sultat au cache
	 *     - Ne pas ajouter le r�sultat au cache
	 *     
	 * @param mot Requ�te � effectuer.
	 * @return La cha�ne "$DEMANDE$" si la requ�te doit �tre effectu�e puis placer dans le cache, "$OSEF$" si elle ne doit pas l'�tre et le chemin
	 * vers le fichier contenant la requ�te si elle existe d�j� en cache.
	 */
	protected String nouvelleOccurrence(CleCache mot) {
		String res = null;
		CacheInfo info = cache.cache.get(mot);
		if (info != null) {                        
			if (!Utils.perime(info.dateCache, peremption)) {
				info.incrementeOccurrences();
				//On retourne la valeur du cache   
				res = Utils.construireChemin(info.ID); 
			} else {
				//L'entr�e est p�rim�e : on la supprime
				cache.supprimer(mot);
				if (demande(mot)) {			
					//Si le mot est int�ressant (il y a de la place ou il est r�current), 
					//on le demande pour le stocker en cache
					res = "$DEMANDE$";				
				} else {
					//Sinon on effectue une requ�te sur le serveur, sans stocker le r�sultat
					res = "$OSEF$";
				}
			}
		}
		return res;
	}

	/**
	 * D�termine s'il est int�ressant de faire entrer la requ�te dans le cache.
	 * C'est le cas si : 
	 * - Le cache n'est pas plein
	 * - Il existe un �l�ment p�rim� dans le cache
	 * - L'�l�ment du cache le plus proche de la p�remption est moins courant que le candidat
	 *  
	 * @param mot Une requ�te
	 * @return true si la requ�te doit �tre ajouter au cache, false sinon.
	 */
	protected boolean demande(CleCache mot) { 
		boolean res = !cache.estPlein();
		if(!res) {
			//Parcours du cache afin de trouver un voisin p�rim�
			//On en profite pour garder en m�moire le voisin le plus proche de la p�remption
			//(au cas o� il n'y ait aucun p�rim�)
			boolean existePerime = false;
			Iterator<Entry<CleCache, CacheInfo>> iter = this.cache.cache.entrySet().iterator();
			Entry<CleCache, CacheInfo> element;
			Entry<CleCache, CacheInfo> plusVieux;
			Date datePlusVieux;
			//initialisation
			if (iter.hasNext()) {
				element = iter.next();
				plusVieux = element;
				datePlusVieux = plusVieux.getValue().dateCache;				
				if (Utils.perime(datePlusVieux, peremption)) {
					existePerime = true;
				}
				while (!existePerime && iter.hasNext()) {
					element = iter.next();				
					if (Utils.perime(element.getValue().dateCache, peremption)) {
						existePerime = true;						
					} else if (element.getValue().dateCache.after(datePlusVieux)) {
						plusVieux = element;
						datePlusVieux = element.getValue().dateCache;
					}
				}
				if (existePerime) {
					cache.supprimer(element.getKey());
					res = true;
				} 
				//On compare avec les occurrences du plus vieux
				else {
					int occurrence = 1;
					AttenteInfo attenteInfo = this.attente.index.get(mot);
					if(attenteInfo != null) {
						occurrence += attenteInfo.occurrences;
					}
					if(occurrence > plusVieux.getValue().occurrences) {
						//mise en attente du plusVieux
						attente.ajouter(plusVieux.getKey(), plusVieux.getValue().occurrences);
						//suppression dans le cache du plus vieux
						cache.supprimer(plusVieux.getKey());
						//demande d'entrer dans le cache
						res = true;
					}
				}
			}
		}
		return res;
	}


	/**
	 * Indique si RequeterRezo est autoris� � indiquer des messages d'avertissement concernant l'ex�cution des requ�tes.
	 * @return True si RequeterRezo est autoris� � �crire sur System.err, false sinon.
	 */
	public boolean getAvertissement() {
		return avertissement;
	}

	/**
	 * Autorise (ou interdit) RequeterRezo � indiquer des messages d'avertissement concernant l'ex�cution des requ�tes.
	 * @param avertissement True si RequeterRezo est autoris� � �crire sur System.err, false sinon.
	 */
	public void setAvertissement(boolean avertissement) {
		this.avertissement = avertissement;
	}
}
