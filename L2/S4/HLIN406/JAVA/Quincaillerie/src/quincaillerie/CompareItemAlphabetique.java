package quincaillerie;

import java.util.Comparator;

public class CompareItemAlphabetique implements Comparator<ItemPanier> {
	
	public int compare(ItemPanier i1,ItemPanier i2){
		return i1.getP().getNom().compareTo(i2.getP().getNom());
	}

}
