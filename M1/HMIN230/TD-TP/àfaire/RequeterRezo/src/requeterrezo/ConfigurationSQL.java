package requeterrezo;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.AbstractMap.SimpleEntry;
import java.util.ArrayList;
import java.util.List;


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
 * Contient les �l�ments sp�cifiques � la configuration d'un syst�me "local" de RequeterRezo ({@link RequeterRezoSQL}).
 * Les �l�ments en plus d'une configuration classique ({@link Configuration}) sont : 
 * - SERVEUR_MYSQL : adresse du serveur MySQL.
 * - NOM_BASE_DE_DONNEES : nom de la base de donn�es contenant les donn�es rezoJDM.
 * - NOM_UTILISATEUR : nom de l'utilisateur � utiliser pour la connexion au serveur MySQL.
 * - MOT_DE_PASSE : mot de passe de l'utilisateur � utiliser pour la connexion au serveur MySQL.
 * 
 * Tout autre couple "CLE=VALEUR" sera interpr�t� comme un param�tre sp�cifique � passer lors de la connexion au serveur MySQL.
 * @author jimmy.benoits
 */
public class ConfigurationSQL extends Configuration {

	/**
	 * Adresse du serveur MySQL.
	 */
	protected String serveur_SQL;

	/**
	 * Nom de la base de donn�es contenant les donn�es rezoJDM.
	 */
	protected String nom_base_de_donnees;

	/**
	 * Nom de l'utilisateur.
	 */
	protected String nom_utilisateur;

	/**
	 * Mot de passe.
	 */
	protected String mot_de_passe;

	/**
	 * Param�tres compl�mentaires utilis�s lors de la connexion au serveur MySQL.
	 */
	protected List<SimpleEntry<String, String>> parametres;

	/**
	 * Constructeur param�tr�.
	 * @param serveur_sql Adresse du serveur MySQL.
	 * @param nom_base_de_donnees Nom de la base de donn�es contenant les donn�es rezoJDM.
	 * @param nom_utilisateur Nom de l'utilisateur.
	 * @param mot_de_passe Mot de passe.
	 */
	public ConfigurationSQL(String serveur_sql, String nom_base_de_donnees, String nom_utilisateur, String mot_de_passe) {
		super();
		this.nom_base_de_donnees = nom_base_de_donnees;
		this.nom_utilisateur = nom_utilisateur;
		this.mot_de_passe = mot_de_passe;
		this.serveur_SQL = serveur_sql;
		this.parametres = new ArrayList<>();
		//        this.parametres.add(new SimpleEntry<>("useLegacyDatetimeCode", "false"));
		//        this.parametres.add(new SimpleEntry<>("serverTimezone", "Europe/Amsterdam"));
	}


	/**
	 * Construit un objet ConfigurationSQL � partir d'un fichier de configuration. 
	 * Les valeurs g�n�riques ({@link Configuration}) doivent �tre pr�sentes.
	 * Les valeurs sp�cifiques sont : 
	 * - SERVEUR_MYSQL : adresse du serveur MySQL.
	 * - NOM_BASE_DE_DONNEES : nom de la base de donn�es contenant les donn�es rezoJDM.
	 * - NOM_UTILISATEUR : nom de l'utilisateur � utiliser pour la connexion au serveur MySQL.
	 * - MOT_DE_PASSE : mot de passe de l'utilisateur � utiliser pour la connexion au serveur MySQL.
	 * 
	 * Tout autre couple "CLE=VALEUR" sera interpr�t� comme un param�tre sp�cifique � passer lors de la connexion au serveur MySQL.
	 * @param chemin_fichier_configuration Chemin vers le fichier de configuration pour {@link RequeterRezoSQL}.
	 * @throws FileNotFoundException Le fichier de configuration n'a pas �t� trouv�.
	 * @throws IOException Le fichier de configuration n'a pas pu �tre ouvert.
	 * @throws ConfigurationException Une erreur est survenue lors de l'interpr�tation du fichier de configuration.
	 */
	public ConfigurationSQL(String chemin_fichier_configuration) throws FileNotFoundException, IOException, ConfigurationException {
		super(chemin_fichier_configuration);
		try (BufferedReader reader = new BufferedReader(new FileReader(chemin_fichier_configuration))) {
			String ligne;
			int indexOf;
			String cle, valeur;
			this.parametres = new ArrayList<>();
			while ((ligne = reader.readLine()) != null) {
				if (!ligne.isEmpty() && ligne.charAt(0) != '#') {
					if ((indexOf = ligne.indexOf('=')) != -1) {
						cle = ligne.substring(0, indexOf);
						valeur = ligne.substring(indexOf + 1);
						switch (cle.toUpperCase()) {
						case "MODE" : {
							//d�j� trait�
							break;
						}    
						case "AVERTISSEMENT" : {
							//d�j� trait�
							break;
						}
						case "PEREMPTION": {
							//d�j� trait�
							break;
						}
						case "CHEMIN_CACHE": {
							//d�j� trait�
							break;
						}
						case "TAILLE_MAX_CACHE": {
							//d�j� trait�
							break;
						}
						case "SERVEUR_MYSQL": {
							this.serveur_SQL = valeur;
							break;
						}
						case "NOM_BASE_DE_DONNEES": {
							this.nom_base_de_donnees = valeur;
							break;
						}
						case "NOM_UTILISATEUR": {
							this.nom_utilisateur = valeur;
							break;
						}
						case "MOT_DE_PASSE": {
							this.mot_de_passe = valeur;
							break;
						}
						default: {
							//autres param�tres du serveur MYSQL
							this.parametres.add(new SimpleEntry<>(cle, valeur));
							break;
						}
						}
					} else {
						throw new ConfigurationException("Erreur Configuration RequeterRezo : la ligne \"" + ligne + "\" n'a pas pu �tre interpr�t�e.");
					}
				}
			}
		}
	}

	/**
	 * Adresse du serveur MySQL.
	 * @return L'adresse du serveur MySQL.
	 */
	public String getServeur_SQL() {
		return serveur_SQL;
	}


	/**
	 * Nom de la base de donn�es contenant les donn�es rezoJDM.
	 * @return Nom de la base de donn�es utilis�e pour la connexion.
	 */
	public String getNom_base_de_donnees() {
		return nom_base_de_donnees;
	}

	/**
	 *  Nom d'utilisateur.
	 * @return Le nom d'utilisateur utilis�e pour la connexion. 
	 */
	public String getNom_utilisateur() {
		return nom_utilisateur;
	}

	/**
	 * Mot de passe.
	 * @return Le mot de passe utilis�e pour la connexion.
	 */
	public String getMot_de_passe() {
		return mot_de_passe;
	}
	
	/**
	 * Param�tres compl�mentaires utilis�s lors de la connexion au serveur MySQL.
	 * @return La liste des couples (CLE,VALEUR) des param�tres compl�mentaires.
	 */
	public List<SimpleEntry<String, String>> getParametres() {
		return parametres;
	}

}
