package bibliotheque;

public class Exemplaire {

	private boolean enReparation;
	private boolean estDisponible;
	private Abonne abonne;
	private NoticeBibliograpĥique nb;
	
	public Exemplaire(boolean r,Abonne a){
		enReparation =r;
		if ( r ) estDisponible = false ; else estDisponible = true;
		abonne = a;
	}

	public boolean isEnReparation() {
		return enReparation;
	}

	public void setEnReparation(boolean enReparation) {
		this.enReparation = enReparation;
	}

	public boolean isEstDisponible() {
		return estDisponible;
	}

	public void setEstDisponible(boolean estDisponible) {
		this.estDisponible = estDisponible;
	}

	public Abonne getAbonne() {
		return abonne;
	}

	public void setAbonne(Abonne abonne) {
		this.abonne = abonne;
	}

	public NoticeBibliograpĥique getNb() {
		return nb;
	}

	public void setNb(NoticeBibliograpĥique nb) {
		this.nb = nb;
	}
	
	
	public boolean empruntePar(Abonne a){
		if (this.nb.estDisponible()){
			this.abonne=a;
		    return true;
		    }else{
    		return false;
		    }
	}
	
	public void retourApresEmprunt(){
		abonne=null;
	}
		
	public void miseEnReparation(){
		enReparation = true;
		estDisponible = false;
	}
	
	public void retourEnRayon(){
		estDisponible=true;
	}
	
	
	
	
	
	
}
