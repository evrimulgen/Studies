package td5.Exo2;

public class Tableau<T extends Comparable<T> >  
{
	private T  tab [];
	
	public Tableau(T tableau[])
	{
		tab=tableau;
	}
	
	public void triBulles(){
		int i=tab.length - 2;
		boolean ech = true;
		
		while( i>=2 && ech)
		{
			ech = false;
			for(int j=0; j <= i;j++)
				if( tab[j].compareTo(tab[j+1]) > 0 )
				{
					T aux = tab[j];
					tab[j]=tab[j+1];
					tab[j+1]=aux;
					ech=true;
				}
			i--;
		}
	}
	
	
	public void affiche()
	{
		for(int i=0;i < tab.length;i++)
			System.out.print(tab[i]+"  ");
		System.out.println();
	}
	
}
