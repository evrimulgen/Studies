package locations2;

public class ProduitSolde extends Produit {
	static double reduction=0.8;
	public ProduitSolde(String name,double prx) {
		super(name,prx);
	}
	
	public double prixLocation() {
		return super.prixLocation()*reduction;
	}

}
