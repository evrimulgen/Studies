package locations1;

public class CompteAvecReduction extends Compte {
	static double reduction=0.1;
	
	public CompteAvecReduction(Client c) {
		super(c);
	}
	
	public double prixLocation(Produit p) {
		return super.prixLocation(p)*reduction;
	}
}
