package quincaillerie;

public class PieceDeBase extends Piece {
	private float prix;
	private int garantie;
	private int dureeFabrication;
	private final  String PrefixeRef="00";
	
	public PieceDeBase(String nom,String suffixeReference,float prix,int garantie,int df){
		super(nom,suffixeReference);
		this.prix=prix;
		this.garantie=garantie;
		this.dureeFabrication=df;
	}
	
	//Méthodes(accesseurs)
	public float prix(){
		return prix;
	}
	
	public String getPrefixeReference(){
		return PrefixeRef;
	}
	
	public int dureeFabrication(){
		return dureeFabrication;
	}
	
	public int garantie(){
		return garantie;
	}

	public void setPrix(float prix) {
		this.prix = prix;
	}

	public void setGarantie(int garantie) {
		this.garantie = garantie;
	}

	public void setDureeFabrication(int dureeFabrication) {
		this.dureeFabrication = dureeFabrication;
	}
	
	public String affiche(){
		return super.affiche()+"\n prix : "+prix+" euros"+"\n garantie : "+garantie+" mois"+"\n duree de fabrication : "+dureeFabrication+" jour(s)";
	}
	
	
}
