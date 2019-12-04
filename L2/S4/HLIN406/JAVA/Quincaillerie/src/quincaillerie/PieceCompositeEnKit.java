package quincaillerie;

import java.util.ArrayList;

public class PieceCompositeEnKit extends PieceComposite{
	private final String prefixeReference="01";
	
	public PieceCompositeEnKit(String nom,String suffixeReference,int dm){
		super(nom,suffixeReference,dm);
		pieces = new ArrayList<Piece>();
		
	}
	
	public String getPrefixeReference(){
		return prefixeReference;
	}
	
	public int garantie(){
		return super.garantie()/2;
	}
	

	
	public int dureeFabrication(){
		return super.dureeFabrication();
	}
	
	
	public String affiche(){
		return super.affiche()+"\n prix :"+super.prix()+" euros"+"\n garantie :"+this.garantie()+" mois"+"\n duree de fabrication :"+this.dureeFabrication()+" jours(s)"+"\n durée de montage particulier : "+this.getDureeMontage()+" mn"+"\n composants : \n"+super.afficheT(1);
	}
	
	
}
