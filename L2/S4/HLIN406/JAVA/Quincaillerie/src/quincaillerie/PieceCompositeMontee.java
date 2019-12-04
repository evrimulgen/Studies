package quincaillerie;

import java.util.ArrayList;

public class PieceCompositeMontee extends PieceComposite {
	private float prixMontage;
	private final String prefixeReference="02";
	
	public PieceCompositeMontee(String nom,String suffixeReference,int dm,float pm){
		super(nom,suffixeReference,dm);
		this.prixMontage=pm;
		pieces = new ArrayList<Piece>();
	}
	
	public float prix(){
		return  super.prix()+this.prixMontage;
	}
	

	public String getPrefixeReference(){
		return this.prefixeReference;
	}
	
	public int dureeFabrication(){
		return super.getDureeMontage()+super.dureeFabrication();
	}
	
	public int garantie(){
		return super.garantie()+6;
	}


	
	public String affiche(){
		return super.affiche()+"\n prix :"+prix()+" euros"+"\n garantie :"+this.garantie()+" mois"+"\n duree de fabrication :"+this.dureeFabrication()+" jour(s)"+"\n durée de montage atelier : "+this.getDureeMontage()+" jour(s)"+"\n prix du montage : "+this.prixMontage+" euros"+"\n composants : \n"+super.afficheT(1);
	}
	
	
}
