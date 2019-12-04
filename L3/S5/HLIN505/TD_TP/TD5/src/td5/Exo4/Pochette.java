package td5.Exo4;

import java.util.ArrayList;

public class Pochette <T> 
{
	String theme;
	ArrayList<T> listeDocuments;
	
	public Pochette()
	{
		listeDocuments = new ArrayList<T>();
		theme = "";
	}
	
	public Pochette(String th,ArrayList<T> ld)
	{
		theme=th;
		listeDocuments= ld;
	}
	
	public void ajouter(T e)
	{
		listeDocuments.add(e);
	}

	public int nombreDocuments()
	{
		return	listeDocuments.size();
	}
	
	public String toString()
	{
		return theme+" "+nombreDocuments();
	}

	public String getTheme() {
		return theme;
	}

	public void setTheme(String theme) {
		this.theme = theme;
	}
	
	public void Transferer(Pochette<? super T> p)
	{

			for(T e : listeDocuments)
			{
				p.ajouter(e);
			}
			
			listeDocuments.removeAll(listeDocuments);
	}
	
}
