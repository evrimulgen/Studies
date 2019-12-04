package dico;


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
		System.out.println(clef);
		if(this.isEmpty()){
			return index;
		}else{
		while(index<keys.length && !trouve) {
			if(keys[index]!= null && clef.compareTo(keys[index])>0){
					trouve=true;
					index++;
			}else if (keys[index]== null) 
			{
				trouve = true;
			}
		}
		
		System.out.println(index);
	
		Object[] keys1 = new Object[taille+1];
		for(int i=0;i<keys.length;i++)
		{
			if(i == index)
				i++;
			else keys1[i]=keys[i];
		}	
		
		keys=keys1;
		
		return index;
		}
	}

}
