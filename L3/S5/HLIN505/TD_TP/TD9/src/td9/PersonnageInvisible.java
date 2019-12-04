package td9;

public class PersonnageInvisible extends Personnage {

	private boolean visible;
	private int tempsAttente;
	private int tempsInvis;
	
	public PersonnageInvisible(String n,int nbP,int nbV,boolean v,int tA,int tI)
	{
		super(n,nbP,nbV);
		visible=v;
		tempsAttente=tA;
		tempsInvis=tI;
	}

	public void setNombrePoints(int nombrePoints)
	{
		this.nombrePoints=nombrePoints;
	}

}
	
