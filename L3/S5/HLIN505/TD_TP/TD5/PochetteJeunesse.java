package td5;

import java.util.ArrayList;

public class PochetteJeunesse<T extends DocumentJeunesse> extends Pochette<T>{
	
	
	private int ageconseille=0;
	
	public PochetteJeunesse()
	{
		super();
	}
	
	public PochetteJeunesse(String th,ArrayList<T> ld,int a)
	{
		super(th,ld);
		ageconseille = a;
	}
	
	public int getAgeconseille() {
		return ageconseille;
	}

	public void setAgeconseille(int ageconseille) {
		this.ageconseille = ageconseille;
	}

	public void ajouter(T e) 
	{
		try
		{
			if (e.getAgemin()< ageconseille)
			{
		
					super.listeDocuments.add(e);
			}else
			{
				throw new RuntimeException();
			}
			
		}catch (RuntimeException E){System.out.println("On se calme !!!!");}
	}

	
	
}

