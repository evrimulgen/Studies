package poste;

public class Colis extends ObjetPostal {

	public String declaration;
	public float valeur;
	final public static float tarif_base=2;
	
	
	
	
	
	public Colis(String o, String d, String c, int p, float v, int t, String declaration, float valeur) {
		super(o, d, c, p, v, t);
		this.declaration = declaration;
		this.valeur = valeur;
	}


	public String getDeclaration() {
		return declaration;
	}


	public void setDeclaration(String declaration) {
		this.declaration = declaration;
	}


	public float getValeur() {
		return valeur;
	}

	public void setValeur(float valeur) {
		this.valeur = valeur;
	}

	public float tarif_base(){
		return tarif_base;
	};
	
	public float Taux_Aff(){
		
		if ( this.getVolume() <= 1/8) return (super.Taux_Aff()+2);
		else return (super.Taux_Aff()+5);
	}
	
	public float Taux_remb(){
		if ( this.getTx_recommandation() == 1 ) return (float)0.1*this.valeur;
		if ( this.getTx_recommandation() == 2 ) return (float)0.5*this.valeur;
		else return 0;
	}
	
	public String toString(){
		return super.toString()+"declaration :"+declaration+"valeur déclaré :"+valeur;
	}
	
	
}
