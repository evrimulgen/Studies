package td9;

public abstract class Personnage {
	protected String nom;
	protected int nombrePoints;
	protected int nombreVies;
	
	public Personnage(String n,int nbP,int nbV)
	{
		nom=n;
		nombrePoints = nbP;
		nombreVies = nbV;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public int getNombrePoints() {
		return nombrePoints;
	}

	public abstract void setNombrePoints(int nombrePoints);

	public int getNombreVies() {
		return nombreVies;
	}

	public void setNombreVies(int nombreVies) {
		this.nombreVies = nombreVies;
	}
	
	
	
}
