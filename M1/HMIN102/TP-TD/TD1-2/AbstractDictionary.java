package dico;

public abstract class AbstractDictionary implements IDictionary {
	protected Object[] keys=null;
	protected Object[] values=null;
	
	public AbstractDictionary (){
		keys = new Object[1];
		values = new Object[1];
	}
	
	public AbstractDictionary (int number){
		keys = new Object[number];
		values = new Object[number];
	}
	
	public abstract int indexOf(Object key);
	
	public Object get(Object key){
		if (indexOf(key) == -1){
			return null;
		}else{
			return values[indexOf(key)];
		}
	}
	
	public IDictionary put(Object key,Object value){
		int newplace=newIndexOf(key);
		values[newplace]=value;
		keys[newplace]=key;
		System.out.println(key+" ; "+value+" at place "+ newplace+"\n"); 
		return this;
	}
	
	public boolean isEmpty(){
		return (this.size() == 0) ? true : false;
	}
	
	public boolean containsKey(Object key){
		return (indexOf(key) != -1)? true : false ; 
	}
	
	public abstract int newIndexOf(Object key);
	
	public int size(){
		int count=0;
		for(int i=0;i<keys.length;i++)
			if (keys[i]!=null) count++;
		return count;
	}
}
