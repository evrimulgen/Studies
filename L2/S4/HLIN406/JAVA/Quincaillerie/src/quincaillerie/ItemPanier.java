package quincaillerie;

public class ItemPanier implements Comparable<ItemPanier> {
	private int quantite;
	private Piece p;
	
	public ItemPanier(int quantite,Piece p){
		this.quantite=quantite;
		this.p=p;
	}
	
	public float calculPrix(){
		return quantite*p.prix();
	}
	
	public int compareTo(ItemPanier ip){
		return (int) (this.calculPrix()-ip.calculPrix());
	}
	
	public void add(){
		++quantite;
	}
	
	public void remove(){
		--quantite;
	}

	public int getQuantite() {
		return quantite;
	}

	public void setQuantite(int quantite) {
		this.quantite = quantite;
	}

	public Piece getP() {
		return p;
	}

	public void setP(Piece p) {
		this.p = p;
	}
	
	
	

}
