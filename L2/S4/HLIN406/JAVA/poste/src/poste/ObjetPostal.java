/**
 * 
 */
package poste;

/**
 * @author mterki
 *
 */
abstract public class ObjetPostal {
	private String origine;
	private String destination;
	private String code_postal;
	private int poids;
	private float volume;
	private int tx_recommandation;
	
	public ObjetPostal(String o,String d,String c,int p,float v,int t){
		this.origine=o;
		this.destination=d;
		this.code_postal=c;
		this.poids=p;
		this.volume=v;
		this.tx_recommandation=t;
	}
	
	//accesseurs

	public String getOrigine() {
		return origine;
	}

	public void setOrigine(String origine) {
		this.origine = origine;
	}

	public String getDestination() {
		return destination;
	}

	public void setDestination(String destination) {
		this.destination = destination;
	}

	public String getCode_postal() {
		return code_postal;
	}

	public void setCode_postal(String code_postal) {
		this.code_postal = code_postal;
	}

	public int getPoids() {
		return poids;
	}

	public void setPoids(int poids) {
		this.poids = poids;
	}

	public float getVolume() {
		return volume;
	}

	public void setVolume(float volume) {
		this.volume = volume;
	}

	public int getTx_recommandation() {
		return tx_recommandation;
	}

	public void setTx_recommandation(int tx_recommandation) {
		this.tx_recommandation = tx_recommandation;
	}
	
	
	abstract public float tarif_base();
	
	
	public float Taux_Aff(){
		if (this.tx_recommandation == 1) return (float)(0.5+this.tarif_base());
		else  if (this.tx_recommandation == 2)  return (float)(1.5+this.tarif_base());
		else return (float) 0.0;
	}
	
	abstract public float Taux_remb();
	
	public String toString(){
		return "origine :"+origine+"destination :"+destination+"Code postal : "+code_postal+"poids :"+poids+"volume :"+volume+"taux de recommandation :"+tx_recommandation;
	}
	
	
	
	
}

