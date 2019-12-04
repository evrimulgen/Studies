package bibliotheque;

import java.util.ArrayList;

public class NoticeBibliograpĥique {
	private String isbn;
	private String titre;
	private String sstritre;
	private Public publicCible;
	private ArrayList<Contribution> contributeurs;
	private ArrayList<Exemplaire> exemplairesN;
	
	public NoticeBibliograpĥique(String isbn, String titre, String sstritre, Public publicCible) {
		this.isbn = isbn;
		this.titre = titre;
		this.sstritre = sstritre;
		this.publicCible = publicCible;
		this.contributeurs = new ArrayList<Contribution>();
		this.exemplairesN = new ArrayList<Exemplaire>();
	}

	public String getIsbn() {
		return isbn;
	}

	public void setIsbn(String isbn) {
		this.isbn = isbn;
	}

	public String getTitre() {
		return titre;
	}

	public void setTitre(String titre) {
		this.titre = titre;
	}

	public String getSstritre() {
		return sstritre;
	}

	public void setSstritre(String sstritre) {
		this.sstritre = sstritre;
	}

	public Public getPublicCible() {
		return publicCible;
	}

	public void setPublicCible(Public publicCible) {
		this.publicCible = publicCible;
	}
	
	public ArrayList<Contributeur> getContributeur(){
		  ArrayList<Contributeur> cbts = new ArrayList<Contributeur>();
		  
		  
		  for (int i=0;i < this.contributeurs.size();i++){
			  cbts.add(this.contributeurs.get(i).getCbt());
		  }
		  
		  return cbts;
		  
	}

	public ArrayList<Contribution> getContributeurs() {
		return contributeurs;
	}

	public void setContributeurs(ArrayList<Contribution> contributeurs) {
		this.contributeurs = contributeurs;
	}

	public ArrayList<Exemplaire> getExemplairesN() {
		return exemplairesN;
	}

	public void setExemplairesN(ArrayList<Exemplaire> exemplairesN) {
		this.exemplairesN = exemplairesN;
	}
		  
		  
		  
	public boolean estDisponible(){
		
		return !this.exemplairesN.isEmpty();
	
	}
	

}
