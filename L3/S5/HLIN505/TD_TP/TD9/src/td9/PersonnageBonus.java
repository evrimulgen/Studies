package td9;

public class PersonnageBonus extends Personnage {

	
	public PersonnageBonus(String n,int nbP,int nbV)
	{
		super(n,nbP,nbV);
	}
	
	public void setNombrePoints(int nombrePoints)
	{
		int gain=this.nombrePoints - nombrePoints;
		this.nombrePoints = nombrePoints;
		if(gain > 50)
		  this.nombreVies= nombreVies+2;
			
	}
	
	
}
