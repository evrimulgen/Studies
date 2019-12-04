package quincaillerie;

import java.util.ArrayList;

public abstract class PieceComposite extends Piece{
	private int dureeMontage;
	ArrayList<Piece> pieces;
	//constructeur
	
	public PieceComposite(String nom,String suffixeReference,int dm){
		super(nom,suffixeReference);
		dureeMontage=dm;
		pieces = new ArrayList<Piece>();
	
	}
	
	
	//accesseurs
	
	public int getDureeMontage() {
		return dureeMontage;
	}




	public void setDureeMontage(int dureeMontage) {
		this.dureeMontage = dureeMontage;
	}




	public ArrayList<Piece> getPieces() {
		return pieces;
	}




	public void setPieces(ArrayList<Piece> pieces) {
		this.pieces = pieces;
	}


	//Méthodes

	public float prix(){
		float sommep=0;
		for(Piece p : pieces)
			sommep += p.prix();
		return sommep;
	}
	
	public int dureeFabrication(){
		int df=pieces.get(0).dureeFabrication();
		for(Piece p: pieces){
			if (df < p.dureeFabrication())
				df=p.dureeFabrication();
		}
		return df;
	}
	
	public int garantie(){
		int g=pieces.get(0).garantie();
		for(Piece p: pieces){
			if (g > p.garantie())
				g=p.garantie();
		}
		return g;
	}
		
	public void ajoutPiece(Piece p){
		pieces.add(p);
	}
	
	public String afficheT(int i){
		String finale="";
		for(Piece p : pieces){
				finale+="  "+p.afficheCommeComposant(i);
				if(p instanceof PieceComposite){
				finale+=((PieceComposite )p).afficheT(i+1);
				}
		}
		return finale;
	}
	
}
