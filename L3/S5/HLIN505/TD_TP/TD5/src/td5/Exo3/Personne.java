package td5.Exo3;

public class Personne implements  ElementAvecPriorite 
{
	private String nom;
	private int age;
	private int priorite;
	public Personne(){};
	public Personne(String n,int a)
	{
		nom=n;age=a;
		if ( age>0 && age<12) priorite = 1;
				else if ( age>60) priorite = 2;
					else priorite =3;
			 
			
	}
	public int priorite() {
		return priorite;
	}
	
	public void setPriorite(int p)
	{
		if ( age>0 && age<12 && p == 1) priorite =1;
		else if ( age>60 && p == 2) priorite =2;
			else priorite =3;
	}

	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	

}
