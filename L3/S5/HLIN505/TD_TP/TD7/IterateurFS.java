package td7;


import java.util.Iterator;

public class IterateurFS implements Iterator<Object> {
	
	private Object[] f = new Object[6];
	private int i=0;
	
	public IterateurFS(FeuilleSalaire f)
	{
		this.f[0]= f.getEmployeur();
		this.f[1]= f.getSalarie();
		this.f[2]= f.getConventionCollective();
		this.f[3]= f.getNbHeuresPayes();
		this.f[4]= f.getPrelevementsFiscaux();
		this.f[5]= f.getNetAPayer(); 
		
	}

	
	public boolean hasNext()
	{
		return true;
	}

	public Object next()
	{
			if (i == 5)
			{
				i=0;
			}
			else
			{
				i++;
			}
			return f[i];
		
	}
		
		
	public void remove() throws UnsupportedOperationException
	{
		throw new UnsupportedOperationException();
	}
}
