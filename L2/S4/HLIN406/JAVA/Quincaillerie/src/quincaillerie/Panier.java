package quincaillerie;

import java.util.ArrayList;

public class Panier {
	ArrayList<ItemPanier> items;
	
	public Panier(){
		items = new ArrayList<ItemPanier>();
	}
	
	public float calculPrix(){
		float s=0;
		for(ItemPanier ip : items){
			s+=ip.calculPrix();
		}
		return s;
	}
	
	public void ajouter(Piece p){
		if (items.contains(p)){
			items.get(items.indexOf(p)).add();
		}else{
			items.add(new ItemPanier(1,p));
		}
	}
	
	public boolean enlever(Piece p){
		if (items.contains(p)){
			items.get(items.indexOf(p)).remove();
		}
		return items.remove(p);
		}

	public ArrayList<ItemPanier> getItems() {
		return items;
	}

	public void setItems(ArrayList<ItemPanier> items) {
		this.items = items;
	}
	
	
	
	//modifier ajouter et enlever !!!!!!!
}
