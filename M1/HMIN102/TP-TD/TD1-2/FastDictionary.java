package dico;

public class FastDictionary extends AbstractDictionary {

	
	public FastDictionary(int number) {
		super(number);
	}


	public int indexOf(Object key) {
		int code= key.hashCode();
		if( code <0 ) code=code*(-1);
		code=code%keys.length;
		//System.out.println(code);
		int i=code;
		while(keys[i] != key && i<keys.length) {
				i++;
		}if(i == keys.length){return -1;}
		return i;	
	
	}

	public void grow(){
		Object[] clefs= new Object [2*keys.length];
		Object[] valeurs= new Object [2*keys.length];
		
		for(int i=0;i<keys.length*3/4;i++){
			if(keys[i]!= null && values[i]!=null){
				clefs[i]=keys[i];
				valeurs[i]=values[i];
			}
		}
		this.keys=clefs;
		this.values=valeurs;
	}
	
	
	public int newIndexOf(Object key) {
		if (mustGrow()){
			grow();
		}
		int code= key.hashCode();
		if( code <0 ) code=code*(-1);
		code=code%keys.length;
		//System.out.println(code);
		int i=code;
		while(keys[i] != null && i<keys.length) {
				i++;
		}if(i == keys.length){return -1;}
		return i;	
	}
	
	public boolean mustGrow(){
		return (this.size() == keys.length*3/4);
	}
	
	
}
