package locations1;

public class Produit {
	private double prixVente;
	private String nom;
	
	public Produit(String nm,double prx) {
		this.nom=nm;
		this.prixVente=prx;
	}
	
	public double prixLocation() {
		return prixVente*5/100 ;
	}
}
