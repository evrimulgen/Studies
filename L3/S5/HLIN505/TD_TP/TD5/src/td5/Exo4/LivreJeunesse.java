package td5.Exo4;

public class LivreJeunesse extends Livre implements DocumentJeunesse {

	private int agemin;
	
	public LivreJeunesse(String ti,String ty,int a)
	{
		super(ti,ty);
		agemin=a;
		
	}
	
	public int getAgemin()
	{
		return agemin;
	}
}
