package locations1;

public class CompteAvecSeuil extends Compte{
	static int seuil=2;
	int compteur=0;
	
	public CompteAvecSeuil(Client c) {
		super(c);
	}
	
	
	public double prixLocation(Produit p) {
		if(compteur==seuil) {
			compteur=0;
			return 0.0;
		}else {
		compteur++;
		return super.prixLocation(p);
		}
	}
	
}
