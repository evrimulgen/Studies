package td5.Exo3;



public class FileAttentePriorite<T extends ElementAvecPriorite> extends FileAttente <T> {

	public T sort()
	{
		T t2=null;
		if (! contenu.isEmpty())
		{
			t2=contenu.get(0);
			int ind=0;
			for(int i=0;i < contenu.size();i++)
			{	
				if (t2.priorite() > contenu.get(i).priorite())
				{
					t2= contenu.get(i);
					ind=i;
				}
			}
			contenu.remove(ind);
		}
		return t2;
	}
}


