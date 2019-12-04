package dico;

public class OrderedDictionary extends AbstractDictionary {
	

	public OrderedDictionary(int number) {
		super(number);
	}
	

	public OrderedDictionary() {
		super();
	}

	
	public int indexOf(Object key) {
		int i=0,index=-1;
		boolean trouve = true;
		while(trouve && i<keys.length ){
			if (keys[i]==key){ index=i; trouve=false;}
			i++;
		}
		return index;
	}

	
	public int newIndexOf(Object key) {
		if(keys[keys.length-1] == null && keys.length-this.size() == 1) return keys.length-1;
		else {
			Object[] clefs= new Object [this.size()+1];
			Object[] valeurs= new Object [this.size()+1];
			
			for(int i=0;i<keys.length;i++){
				if(keys[i]!= null && values[i]!=null){
					clefs[i]=keys[i];
					valeurs[i]=values[i];
				}
			}
			this.keys=clefs;
			this.values=valeurs;
			return keys.length-1;
			}
	}
	
	
}
