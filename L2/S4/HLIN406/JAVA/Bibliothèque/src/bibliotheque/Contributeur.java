package bibliotheque;

import java.util.ArrayList;

public class Contributeur {
 private String nom;
 private String prenom;
 private ArrayList<Contribution> noticeB;

 public Contributeur(String nom, String prenom) {
	 
	this.nom = nom;
	this.prenom = prenom;
	this.noticeB = new ArrayList<Contribution>();
}

public String getNom() {
	return nom;
}

public void setNom(String nom) {
	this.nom = nom;
}

public String getPrenom() {
	return prenom;
}

public void setPrenom(String prenom) {
	this.prenom = prenom;
}


public void setNoticeB(ArrayList<Contribution> noticeB) {
	this.noticeB = noticeB;
}

public ArrayList<NoticeBibliograpĥique> getNoticeB(){
	  ArrayList<NoticeBibliograpĥique> nbs = new ArrayList<NoticeBibliograpĥique>();
	  
	  
	  for (int i=0;i < this.noticeB.size();i++){
		  nbs.add(this.noticeB.get(i).getNoticeBb());
	  }
	  
	  return nbs;
}
	  
 
 
} 
