package td5.Exo3;

public class Exercice3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		FileAttentePriorite<Personne> personnes=new FileAttentePriorite<Personne>();
		personnes.entre(new Personne("adel",20));
		personnes.entre(new Personne("haydar",58));
		personnes.entre(new Personne("sabri",11));
		
		System.out.println(personnes.sort().getNom());
	}

}
