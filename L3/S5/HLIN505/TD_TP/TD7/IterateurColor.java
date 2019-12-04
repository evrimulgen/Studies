package td7;

import java.awt.Color;
import java.util.Iterator;

public class IterateurColor implements Iterator <Color>{

	private Color[] c;
	private int i=0;
	
	public IterateurColor (Color[] c)
	{
		this.c = c;
	}
	
	public boolean hasNext()
	{
		return true;
	}
	
	public Color next()
	{
		if (i == 2)
		{
			i=0;
		}
		else
		{
			i++;
		}
		return c[i];
	}
	
	
	public void remove() throws UnsupportedOperationException
	{
		throw new UnsupportedOperationException();
	}
	
}
