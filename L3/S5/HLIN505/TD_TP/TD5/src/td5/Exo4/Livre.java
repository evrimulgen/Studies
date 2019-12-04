package td5.Exo4;

public class Livre implements Document
{
	private String titre;
	private String type;
	
	public Livre(String ti,String ty)
	{
		titre=ti;
		type=ty;
	}
	
	public String getType()
	{
		return type;
	}
	public String getTitre()
	{
		return titre;
	}

}
