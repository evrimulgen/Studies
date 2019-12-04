package poste;

import java.util.Date;

public class ColisExpress extends Colis {
	
	private Date date_envoie;
	private int num_suivie;
	private int num_colis_ex;
	private boolean emballage_B;
	
	
	
	public ColisExpress(String o, String d, String c, int p, float v, int t, String declaration, float valeur,
			Date date_envoie, int num_suivie, int num_colis_ex, boolean emballage_B) {
		super(o, d, c, p, v, t, declaration, valeur);
		this.date_envoie = date_envoie;
		this.num_suivie = num_suivie;
		this.num_colis_ex = num_colis_ex;
		this.emballage_B = emballage_B;
	}



	
	public float Taux_Aff(){
		
		if (emballage_B) return 33;
		else return 30;
	}
	
	public String toString(){
		return super.toString()+"date d' envoie = "+date_envoie+"numero de suivie"+num_suivie+"numero de colis expresse"+num_colis_ex+"emballage :"+emballage_B+"\n";
	}
	
	

}
