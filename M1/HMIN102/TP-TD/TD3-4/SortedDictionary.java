package dicoTest;


public class SortedDictionary extends AbstractDictionary {

	public SortedDictionary(int number) {
		super(number);
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
		int taille=keys.length;
		Comparable<Object> clef=(Comparable)key;
	
		int index=0;
		boolean trouve=false;
		while(index<taille && !trouve) {
			if(clef.compareTo(keys[index])>0){
					trouve=true;
					index++;
			}else {
				index++;
			}
		}
		
		Object[] keys1 = new Object[taille+1];
		for(int i=0;i<keys1.length;i++)
			if(i!= index)
				keys1[i]=keys[i];
		
		keys=keys1;
		
		return index;
	}

}
