package requeterrezo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.MalformedURLException;
import java.net.SocketTimeoutException;
import java.net.URL;
import java.net.URLConnection;
import java.net.URLEncoder;
import java.util.AbstractMap.SimpleEntry;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


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
 * Version "live" de RequeterRezo. Les requ�tes qui ne sont pas directement r�cup�r�es depuis le cache sont effectu�es sur le service rezo-dump
 * (http://www.jeuxdemots.org/rezo-dump.php). 
 * L'int�r�t de RequeterRezoDump est sa rapidit� de prise en main mais cela vient avec un co�t : 
 * - Les requ�tes dont les r�sultats sont trop gros sont tronqu�s (seulement les 25 000 premi�res relations sont retourn�es).
 * - Le serveur peut-�tre en maintenance ou inaccessible. 
 * 
 * @author jimmy.benoits
 */
public class RequeterRezoDump extends RequeterRezo {


	/**
	 * Les constructeurs de RequeterRezoDump utilisent les constructeurs de {@link RequeterRezo} puis construisent les �quivalences entre 
	 * noms et types de relations gr�ce � la page : http://www.jeuxdemots.org/jdm-about-detail-relations.php
	 * @see RequeterRezo#RequeterRezo(Configuration)
	 * @param configuration Configuration
	 */
	public RequeterRezoDump(Configuration configuration) {
		super(configuration);
		this.construireRelations();
	}

	/**
	 * Les constructeurs de RequeterRezoDump utilisent les constructeurs de {@link RequeterRezo} puis construisent les �quivalences entre 
	 * noms et types de relations gr�ce � la page : http://www.jeuxdemots.org/jdm-about-detail-relations.php
	 * @see RequeterRezo#RequeterRezo(long, int, boolean)
	 * @param tailleCache Taille maximale du cache (en octet)
	 * @param peremption D�lais de p�remption (en heure)
	 * @param avertissement True si RequeterRezo est autoris� � utiliser System.err pour afficher des messages, false sinon. 
	 */
	public RequeterRezoDump(long tailleCache, int peremption, boolean avertissement) {
		super(tailleCache, peremption, avertissement);
		this.construireRelations();
	}

	/**
	 * Les constructeurs de RequeterRezoDump utilisent les constructeurs de {@link RequeterRezo} puis construisent les �quivalences entre 
	 * noms et types de relations gr�ce � la page : http://www.jeuxdemots.org/jdm-about-detail-relations.php
	 * @see RequeterRezo#RequeterRezo(long, int)
	 * @param tailleCache Taille maximale du cache (en octet)
	 * @param peremption D�lais de p�remption (en heure)
	 */
	public RequeterRezoDump(long tailleCache, int peremption) {
		super(tailleCache, peremption);
		this.construireRelations();
	}

	/**
	 * Les constructeurs de RequeterRezoDump utilisent les constructeurs de {@link RequeterRezo} puis construisent les �quivalences entre 
	 * noms et types de relations gr�ce � la page : http://www.jeuxdemots.org/jdm-about-detail-relations.php
	 * @see RequeterRezo#RequeterRezo(String, String, boolean)
	 * @param tailleCache Taille maximale du cache. Attent un nombre suivi d'une unit� ("ko", "mo", "go", avec "ko" par d�faut).
	 * @param peremption D�lais de p�remption. Attent un nombre suivi d'une unit� ('j' pour journ�e ou 'h' pour heure, 'h' par d�faut).
	 * @param avertissement True si le syst�me est autoris� � envoyer des messages sur System.err, false sinon.
	 */
	public RequeterRezoDump(String tailleCache, String peremption, boolean avertissement) {
		super(tailleCache, peremption, avertissement);
		this.construireRelations();
	}

	/**
	 * Les constructeurs de RequeterRezoDump utilisent les constructeurs de {@link RequeterRezo} puis construisent les �quivalences entre 
	 * noms et types de relations gr�ce � la page : http://www.jeuxdemots.org/jdm-about-detail-relations.php
	 * @see RequeterRezo#RequeterRezo(String, String)
	 * @param tailleCache Taille maximale du cache. Attent un nombre suivi d'une unit� ("ko", "mo", "go", avec "ko" par d�faut).
	 * @param peremption D�lais de p�remption. Attent un nombre suivi d'une unit� ('j' pour journ�e ou 'h' pour heure, 'h' par d�faut).
	 */
	public RequeterRezoDump(String tailleCache, String peremption) {
		super(tailleCache, peremption);
		this.construireRelations();
	}

	/**
	 * Les constructeurs de RequeterRezoDump utilisent les constructeurs de {@link RequeterRezo} puis construisent les �quivalences entre 
	 * noms et types de relations gr�ce � la page : http://www.jeuxdemots.org/jdm-about-detail-relations.php
	 * @see RequeterRezo#RequeterRezo()
	 */
	public RequeterRezoDump() {
		super();
		this.construireRelations();
	}

	@Override
	protected final void construireRelations() {
		CorrespondanceRelation correspondanceRelation = RequeterRezo.correspondancesRelations;
		URL url;
		URLConnection jd;
		try {
			url = new URL("http://www.jeuxdemots.org/jdm-about-detail-relations.php");
			jd = url.openConnection();
			jd.setConnectTimeout(10_000);
			jd.setReadTimeout(10_000);
			String nom;
			int id = 0;
			String id_;
			String div[];

			try (BufferedReader lecteur = new BufferedReader(new InputStreamReader(jd.getInputStream(), "CP1252"))) {
				String ligne;
				while ((ligne = lecteur.readLine()) != null && !(ligne.contains("<TR valign= \"top\">"))) {
				}
				while ((ligne = lecteur.readLine()) != null) {
					if (ligne.contains("rel_id")) {
						div = ligne.split("\\\"");
						id_ = div[4];
						id_ = id_.substring(1, id_.length());
						id = Integer.parseInt(id_);
					}
					if (ligne.contains("rel_name")) {
						div = ligne.split("\\\"");
						if (ligne.length() > 1) {
							nom = div[4];
							nom = nom.substring(1, nom.length());
							correspondanceRelation.ajouter(nom, id);
							correspondanceRelation.ajouter(id, nom);                            
						}
					}
				}                
			} catch (IOException e) {
				if(avertissement){
					System.err.println("Avertissement RequeterRezo : Une erreur est survenue lors de la lecture de la liste des relations depuis JeuxDeMots... La liste des relations sera construites au fur et � mesure.");            	
				}
			}
		} catch (IOException e) {
			if(avertissement){
				System.err.println("Avertissement RequeterRezo : Impossible de charger la liste des relations depuis JeuxDeMots... Le serveur est peut-�tre indisponible.");            
			}
		}
	}

	/**
	 * Construit l'URL rezo-dump � partir d'une requ�te.
	 * @param cleCache Requ�te � effectuer.
	 * @return l'URL rezo-dump correspondant � la requ�te.
	 */
	protected static String construireURL(CleCache cleCache) {
		String mot = cleCache.nom;
		Filtre filtre = cleCache.filtre;
		int typeRelation = cleCache.typeRelation;
		boolean rejeterEntrantes = false;
		boolean rejeterSortantes = false;

		if (null != filtre) switch (filtre) {
		case RejeterRelationsEntrantesEtSortantes:
			rejeterEntrantes = true;
			rejeterSortantes = true;
			break;
		case RejeterRelationsEntrantes:
			rejeterEntrantes = true;
			break;
		case RejeterRelationsSortantes:
			rejeterSortantes = true;
			break;
		default:
			break;
		}

		String encode;
		String url = "http://www.jeuxdemots.org/rezo-dump.php?gotermsubmit=Chercher&gotermrel=";

		try {
			encode = URLEncoder.encode(mot, "LATIN1");
			if (typeRelation != -1) {
				url +=  encode + "&rel=" + Integer.toString(typeRelation);
			} else {
				url += encode;
			}
			if (rejeterSortantes) {
				url += "&relout=norelout";
			}
			if (rejeterEntrantes) {
				url += "&relin=norelin";
			}
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
			url += mot;
		}	
		return url;
	}

	@Override
	protected Resultat construireMot(CleCache cleCache) {
		Resultat resultat = new Resultat(cleCache);
		Etat etat = Etat.OK;    	
		String motNom = cleCache.nom;  
		long motIdRezo = -1;
		String motDefinition = "";
		int motType = -1;
		int motPoids = 0;
		String motMotFormate = motNom;
		URL jdm=null;
		try {
			jdm = new URL(construireURL(cleCache));
		}
		catch(MalformedURLException e) {
			e.printStackTrace();
			return resultat;
		}
		URLConnection jd=null;
		try{
			jd=jdm.openConnection();
			jd.setConnectTimeout(10_000);
			jd.setReadTimeout(10_000);
		}
		catch(IOException e) {	
			if(avertissement){
				System.err.println("Erreur RequeterRezo : l'URL \""+jdm+"\" pour le mot \""+cleCache.nom+"\" n'est pas valide.");
			}
			resultat.etat  = Etat.SERVEUR_INACCESSIBLE;
			return resultat;
		}
		try (BufferedReader lecteur = new BufferedReader(new InputStreamReader(jd.getInputStream(), "CP1252"))) {
			String ligne;
			String definition = "";
			String[] pdivisions;
			boolean pasDeRelationsSortantes=false;
			boolean pasDeRelationsEntrantes=false;

			HashMap<Long, Noeud> motVoisinage = new HashMap<>();
			HashMap<Integer, ArrayList<Voisin>> motRelationsEntrantes = new HashMap<>();
			HashMap<Integer, ArrayList<Voisin>> motRelationsSortantes = new HashMap<>();
			ArrayList<Annotation> motAnnotations = new ArrayList<>();

			//definition
			if (jdm.toString().contains("norelout")) {
				pasDeRelationsSortantes=true;
			}
			if (jdm.toString().contains("norelin")) {
				pasDeRelationsEntrantes=true;
			}
			while ((ligne = lecteur.readLine()) != null && !(ligne.startsWith("<CODE>"))) {}
			if(ligne == null) {
				//si on n'a jamais rencontrer la balise <CODE> c'est que le mot n'existe pas
				resultat.etat = Etat.INEXISTANT;
				return resultat;
			}
			while ((ligne = lecteur.readLine()) != null && !(ligne.startsWith("<def>"))) {
				ligne = StringUtils.unescapeHtml3(ligne);
				if(ligne.contains("eid=")) {
					int ind = ligne.lastIndexOf("eid=");
					String id = ligne.substring(ind+4,ligne.length()-1);
					motIdRezo = Long.parseLong(id);					
				}
				else if(ligne.equals("<WARNING>TOOBIG_USE_DUMP<WARNING>")) {
					etat = Etat.TROP_GROS;
				}
			}

			if (ligne == null) {
				//Balise <CODE> mais pas balise <def> => la requ�te doit �tre relancer
				resultat.etat = Etat.RENVOYER;
				return resultat;
			}     

			do {
				definition += StringUtils.unescapeHtml3(ligne);
			} 
			while ((ligne = lecteur.readLine()) != null && !(ligne.endsWith("</def>")));
			definition += StringUtils.unescapeHtml3(ligne);
			definition = definition.substring(5, definition.length() - 6);
			definition = definition.replaceAll("<br />", "");

			if (definition.equals("")) {
				definition = "Pas de d�finition disponible ou d�finition r�partie dans les raffinements s�mantiques (voir relation \"r_raff_sem\").";
			}
			while ((ligne = lecteur.readLine()) != null && !(ligne.startsWith("// les noeuds/termes (Entries) : e;eid;'name';type;w;'formated name'"))) {
			}

			HashMap<Long, Long> annotations=new HashMap<>();			
			boolean premier= false;
			Noeud noeud_voisin;
			Voisin voisin;

			String regex_annotation = ":r\\d+";
			Pattern pattern = Pattern.compile(regex_annotation);
			Matcher matcher;

			String id_tmp;
			Long id;
			String terme;
			String type;
			String poids;
			String motFormate;
			String id_annot;

			boolean trouveId;
			boolean trouveTerme;
			boolean trouveType;
			boolean trouvePoids;
			boolean trouveMotFormate;

			//Traitement du voisinage
			while ((ligne = lecteur.readLine()) != null && !(ligne.startsWith("// les types de relations (Relation Types) :"))) {
				ligne = StringUtils.unescapeHtml3(ligne);

				id_tmp="";				
				terme="";
				type="";
				poids="";
				motFormate="";

				trouveId=false;
				trouveTerme=false;
				trouveType=false;
				trouvePoids=false;
				trouveMotFormate=false;

				int i = 2;
				while (i<ligne.length()) {
					if (!trouveId) {
						if(ligne.charAt(i)==';') {
							trouveId=true;
							i++;
						}
						else {
							id_tmp+=ligne.charAt(i);
						}
					}

					if (!trouveTerme ) {
						if (trouveId) {
							if(ligne.charAt(i)=='\'' && ligne.charAt(i+1)==';' && ligne.charAt(i-1)!=';') {
								trouveTerme=true;
								i=i+2 ;
							}
							else {
								terme+=ligne.charAt(i);
							}
						}
					}

					if (!trouveType) {
						if (trouveId && trouveTerme) {
							if(ligne.charAt(i)==';') {
								trouveType=true;
								i++;
							}
							else {
								type+=ligne.charAt(i);
							}
						}	
					}

					if (!trouvePoids) {
						if (trouveId && trouveTerme && trouveType) {
							if(ligne.charAt(i)==';') {
								trouvePoids=true;
								i++;
							}
							else {
								poids+=ligne.charAt(i);
							}
						}
					}

					if (!trouveMotFormate) {
						if (trouveId && trouveTerme && trouveType && trouvePoids) {
							motFormate+=ligne.charAt(i);		
						}
					}

					i++;					
				}

				if (terme.length()>2) {
					terme=terme.substring(1, terme.length());}
				if (motFormate=="") {
					motFormate=terme;
				}
				else {
					motFormate=motFormate.substring(1,motFormate.length()-1);
				}
				if (trouveId && trouveType) {
					if (premier==false) {
						motType = Integer.parseInt(type);
						motMotFormate = motFormate;						
						premier=true;
					}
					id = Long.parseLong(id_tmp);
					matcher = pattern.matcher(terme);
					if(matcher.matches()) {
						//					if(terme.matches(":r\\d+")) {
						id_annot = terme.substring(2,terme.length());
						//						annotations.put(Long.parseLong(id_annot),id+";"+type+";"+poids);
						annotations.put(id,Long.parseLong(id_annot));
						//						relations.put(Long.parseLong(terme.substring(2, terme.length())), null );
					}					
					noeud_voisin=new Noeud(terme, id, Integer.parseInt(type), motFormate,Integer.parseInt(poids));
					motVoisinage.put(id,noeud_voisin);
				}					
			}


			//Traitement des types de relations utilis�es dans le mot : on ajoute s'il y a des choses � ajouter
			CorrespondanceRelation correspondance = RequeterRezo.correspondancesRelations;			
			Integer id_type_relation;
			String nom_type_relation;
			while ((ligne = lecteur.readLine()) != null && !(ligne.startsWith("// les relations sortantes") || ligne.startsWith("// les relations entrantes") )) { //|| ligne.startsWith("// les relations entrantes")) { // && !(ligne.startsWith("// les relations entrantes"))) {
				ligne = StringUtils.unescapeHtml3(ligne);
				pdivisions=ligne.split("\\;");
				if (pdivisions.length>1 ){
					id_type_relation = Integer.parseInt(pdivisions[1]);
					nom_type_relation = pdivisions[2].substring(1, pdivisions[2].length()-1);
					if(correspondance.get(id_type_relation)==null) {
						correspondance.ajouter(nom_type_relation, id_type_relation);					
						correspondance.ajouter(id_type_relation, nom_type_relation);
					}
				}
			}			
			int type_relation;

			//Traitements des relations
			ArrayList<Entry<Long, Integer>> liste_annotations = new ArrayList<>();
			HashMap<Long, String> mapping_relations = new HashMap<>();

			//Traitement des relations sortantes
			//(possibilit� d'annotations)			
			int poids_relation;
			long id_destination;
			while (pasDeRelationsSortantes==false && (ligne = lecteur.readLine()) != null && !(ligne.startsWith("// les relations entrantes"))) {
				pdivisions=ligne.split(";");
				if (pdivisions.length>1){	
					id_destination = Long.parseLong(pdivisions[3]);
					type_relation=Integer.parseInt(pdivisions[4]);
					poids_relation = Integer.parseInt(pdivisions[5]);
					if (!(motRelationsSortantes.containsKey(type_relation))) {
						motRelationsSortantes.put(type_relation, new ArrayList<>());
					}
					//cas annotation
					if(type_relation == 128) {						
						liste_annotations.add(new SimpleEntry<Long, Integer>(id_destination, poids_relation));
					}
					//cas normal
					else {
						noeud_voisin=motVoisinage.get(id_destination);
						voisin=new Voisin(noeud_voisin,poids_relation);
						motRelationsSortantes.get(type_relation).add(voisin);
					}
					mapping_relations.put(Long.parseLong(pdivisions[1]), ligne);
				}
			}

			// Relations entrantes
			//Pas d'annotation possible
			while (pasDeRelationsEntrantes==false && ((ligne = lecteur.readLine()) != null && !(ligne.startsWith("// END")))) {
				pdivisions=ligne.split(";");
				if (pdivisions.length>1){
					type_relation=Integer.parseInt(pdivisions[4]);
					if (!(motRelationsEntrantes.containsKey(type_relation))) {
						motRelationsEntrantes.put(type_relation, new ArrayList<>());
					}
					noeud_voisin = motVoisinage.get(Long.parseLong(pdivisions[2]));
					voisin = new Voisin(noeud_voisin,Integer.parseInt(pdivisions[5]));
					motRelationsEntrantes.get(type_relation).add(voisin);
					mapping_relations.put(Long.parseLong(pdivisions[1]), ligne);
				}
			}

			//Traitement des annotations : possible maintenant que l'on a toutes les relations
			Annotation annotation;
			long id_annotation, id_relation_annotee;
			Noeud noeud_annotation;
			long id_source_relation, id_destination_relation;
			Noeud source_relation, destination_relation;					
			for(Entry<Long, Integer> entry : liste_annotations) {
				id_annotation = entry.getKey();
				noeud_annotation = motVoisinage.get(id_annotation);				
				id_relation_annotee = Long.parseLong(noeud_annotation.getNom().substring(2));				
				if(mapping_relations.containsKey(id_relation_annotee)) {									
					ligne = mapping_relations.get(Long.parseLong(noeud_annotation.getNom().substring(2)));
					pdivisions = ligne.split(";");
					id_source_relation = Long.parseLong(pdivisions[2]);
					id_destination_relation = Long.parseLong(pdivisions[3]);
					type_relation = Integer.parseInt(pdivisions[4]);
					poids_relation = Integer.parseInt(pdivisions[5]);
					source_relation = motVoisinage.get(id_source_relation);
					destination_relation = motVoisinage.get(id_destination_relation);

					annotation = new Annotation(noeud_annotation.getNom(), noeud_annotation.idRezo, noeud_annotation.getType(), entry.getValue(),
							source_relation, type_relation, correspondance.get(type_relation), destination_relation, poids_relation);
					motAnnotations.add(annotation);
				}
				else if(avertissement){					
					System.err.println("Avertissement RequeterRezo : l'annotation \""+noeud_annotation.getNom()+"\" r�f�re une relation qui n'existe pas.");
				}
			}
			Mot mot = new Mot(motNom, motIdRezo, motType, motMotFormate, motPoids, motDefinition,
					motVoisinage, motRelationsEntrantes, motRelationsSortantes, motAnnotations,
					cleCache);
			resultat = new Resultat(cleCache, mot, etat, EtatCache.EN_ATTENTE);
		}
		catch (SocketTimeoutException ex) {
			if(avertissement){
				System.err.println("ERREUR RequeterRezo : Timeout en effectuant la requ�te \""+cleCache.toString()+"\".");			
			}
			resultat.etat = Etat.SERVEUR_INACCESSIBLE;
			return resultat;
		} 
		catch (IOException ex) {
			if(avertissement){
				System.err.println("ERREUR RequeterRezo : le fichier n'a pas le format attendu pour la requ�te \""+cleCache.toString()+"\".");
			}
			ex.printStackTrace();
			return resultat;
		}

		//Important : demand� par le cr�ateur de JeuxDeMots 
		//afin d'�viter une surcharge du serveur. 
		//La mise en cache permet de limiter n�anmoins ces appels.
		try {
			Thread.sleep(100);
		}catch(InterruptedException e) {
			if(avertissement){
				System.err.println("ERREUR RequeterRezo : mise en pause interrompue lors de la requ�te \""+cleCache.toString()+". La mise en pause est importante pour �viter une surcharge du serveur.");						
			}
			return new Resultat(cleCache);
		}	   
		return resultat;
	}

}
