package td5;

import java.util.LinkedList;

public class Pile<A> implements IPile<A>
{
	private LinkedList<A> P;
	
	public Pile()
	{
		P = new LinkedList<A>();
	}
	
	@Override
	public boolean estVide()
	{
		return P.isEmpty();
	}
	
	@Override
	public void empiler(A a)
	{
		P.addFirst(a);
	}
	
	@Override
	public A depile()
	{
		return P.removeFirst();
	}
	
	@Override
	public int nbElements()
	{
		return P.size();
	}
	
	@Override
	public A sommet()
	{
		return P.getFirst();
	}
		
}
