public class Livre
{
	public String titre,editeur,auteur;
	public int isbn,nb_exemplaires;
	public Commentaire comment;

	public Livre (String titre,String auteur,String editeur,int isbn,int nb_exemplaires){
		this.titre= titre;
		this.editeur= editeur;
		this.auteur= auteur;
		this.isbn= isbn;
		this.nb_exemplaires= nb_exemplaires;
		this.comment= new List<Commentaire>();
	}
	
	public String getAuteur(){
		return this.auteur;
	}
	
	public int getISBN(){
		return this.isbn;
	}
	
	public void setAuteur(String auteur){
		return this.auteur=auteur;
	}
	
	public void setISBN(int isbn){
		this.isbn=isbn;
	}
	
}

/
*Creation d'une application .ASPECT NET 
*créer un web service
*Remplir webService dans la barre de rechreche
*/
public class Bibliotheque {
	
	public List<Livre> livres,
	public List<Abonne> abonnes;
	
	public Bibliotheque(List<Livre> livres,List<Abonne> abonnes){
	}
	
	public getLivres(){
		return this.livres;
	}
	
	public getAbonnes(){
		return this.abonnes;
	}
	
	public Livre RechOuvrageISBN(int isbn){
		int indice=0;
		while(indice < livres.count){
			if(livres..Equals(isbn)){
				return livres.At();
			}else{
				indice++;
			}
		}
	}

	public Livre RechOuvrageISBN(int isbn){
	}	
}

public class Abonne {
	
	public int numAbonnee;
	public String mdp;
	
	public Abonne (int numAb,String mdp){
		this.numAbonnee=numAbonnee;
		this.mdp=mdp;
	}
	
	public int getNumAbonnee(){
		return this.numAbonnee;
	}
	
	public int getMdp(){
		return this.mdp;
	}
	
	public void setNumAbonnee(int numAbonnee){
		this.numAbonnee=numAbonnee;
	}
	
	public void setMdp(String mdp){
		this.mdp=mdp;
	}
	
	
	
}


public class Commentaire {

	public String contenue;
}