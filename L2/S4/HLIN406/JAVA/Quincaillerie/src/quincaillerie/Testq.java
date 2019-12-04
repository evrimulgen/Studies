package quincaillerie;

public class Testq {
	public static void main(String args[]){
		//System.out.println("Piece de base : \n");
		//PieceDeBase vis = new PieceDeBase("vis","7152",(float)0.01,12,1);
		//System.out.println(vis.affiche());
		//System.out.println("\n");
		
		//System.out.println("Piece Composite en kits : \n");
		
		Piece pneuK = new PieceDeBase("pneu","4714",10,12,1);
		Piece chmabreAirK = new PieceDeBase("chambre à air","4565",9,12,1);
		PieceCompositeEnKit janteK = new PieceCompositeEnKit("jante","4541",10);
		Piece disqueJanteK = new PieceDeBase("disque de jante","1214",2,12,3);
		Piece rayon1K = new PieceDeBase("rayon","4748",1,12,2);
		Piece rayon2K = new PieceDeBase("rayon","4748",1,12,2);
		Piece rayon3K = new PieceDeBase("rayon","4748",1,12,2);
		
		janteK.ajoutPiece(disqueJanteK);
		janteK.ajoutPiece(rayon1K);
		janteK.ajoutPiece(rayon2K);
		janteK.ajoutPiece(rayon3K);
		
		PieceCompositeEnKit roueK = new PieceCompositeEnKit("roue de bouette en kit","1512",15);
		roueK.ajoutPiece(pneuK);
		roueK.ajoutPiece(chmabreAirK);
		roueK.ajoutPiece(janteK);
	//	System.out.println(roueK.affiche());
	//	System.out.println("\n");
		
	//	System.out.println("Piece Composite montée : \n");
		
		Piece pneuM = new PieceDeBase("pneu","4714",10,12,1);
		Piece chmabreAirM = new PieceDeBase("chambre à air","4565",9,12,1);
		
		PieceComposite janteM = new PieceCompositeEnKit("jante","4541",10);
		Piece disqueJanteM = new PieceDeBase("disque de jante","1214",2,12,3);
		Piece rayon1M = new PieceDeBase("rayon","4748",1,6,2);
		Piece rayon2M = new PieceDeBase("rayon","4748",1,12,2);
		Piece rayon3M = new PieceDeBase("rayon","4748",1,12,2);
		
		janteM.ajoutPiece(disqueJanteM);
		janteM.ajoutPiece(rayon1M);
		janteM.ajoutPiece(rayon2M);
		janteM.ajoutPiece(rayon3M);
		
		
		
		PieceComposite roueB = new PieceCompositeMontee("roue de brouette","1512",1,15);
		roueB.ajoutPiece(pneuM);
		roueB.ajoutPiece(chmabreAirM);
		roueB.ajoutPiece(janteM);
		//System.out.println(roueB.affiche());
		//System.out.println("\n");

		//panier et comparaisons
		
		Panier p= new Panier();
		p.ajouter(roueK);
		p.ajouter(roueB);
		System.out.println("calcul prix panier = "+p.calculPrix());
		System.out.println(p.enlever(roueB));
		for(ItemPanier ip : p.getItems()){
			System.out.println("nom : "+ip.getP().getNom()+" total :  "+ip.calculPrix()+" quantité : "+ip.getQuantite());
		}
		
		
		
		
	}

}
