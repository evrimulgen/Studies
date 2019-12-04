package poste;

public class Lettre extends ObjetPostal{
	
	private boolean urgente;
	final static float tarif_base=(float) 0.5;
	
	public Lettre(String o, String d, String c, int p, float v, int t, boolean urgente) {
		super(o, d, c, p, v, t);
		this.urgente = urgente;
	}

	public boolean isUrgente() {
		return urgente;
	}

	public void setUrgente(boolean urgente) {
		this.urgente = urgente;
	}

	public  float tarif_base() {
		return tarif_base;
	}
	
	public float Raux_Aff(){
		if (this.urgente) return (float)0.3 ;
		else return super.Taux_Aff();
		
		}
	
	public float Taux_remb(){
		if ( this.getTx_recommandation() == 1 ) return (float)1.5;
		if ( this.getTx_recommandation() == 2 ) return 15;
		else return 0;
		
	}
	
	public String toString(){
		return super.toString()+"urgente :"+urgente;
	}
	
	

}
