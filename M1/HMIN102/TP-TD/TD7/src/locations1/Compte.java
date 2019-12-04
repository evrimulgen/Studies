package locations1;

public class Compte {
	private Client customer;
	
	public Compte(Client c) {
		customer=c;
	}
	
	public double prixLocation(Produit p) {
		return p.prixLocation();
	}

}
