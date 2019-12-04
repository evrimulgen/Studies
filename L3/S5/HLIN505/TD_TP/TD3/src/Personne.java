public class Personne implements Comparable<Personne>
{
	 	private String nom;
	 	private int age;
	 	
	 	public Personne(String s,int a)
	 	{
	 		nom=s;
	 		age=a;
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



		public int compareTo(Personne p)
	 	{
	 		return this.nom.compareTo(p.getNom());
	 	}

	 
}



