package td5;

public class Exercice1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Pile<Integer> listEntiers = new Pile<Integer>();
		listEntiers.empiler(1);
		listEntiers.empiler(2);
		listEntiers.empiler(3);
		listEntiers.empiler(31);
		listEntiers.empiler(15);
		
		System.out.println("les entiers \n");
		
		System.out.println("es que la pile est vide  "+listEntiers.estVide());
		System.out.println("Depiler  "+listEntiers.depile());
		System.out.println("Sommet  "+listEntiers.sommet());
		int taille = listEntiers.nbElements();
		System.out.println("taille de la pile  "+taille);
		for(int i=0;i<taille;i++)
			listEntiers.depile();
		
		System.out.println("es que la pile est vide  "+listEntiers.estVide());
		
		
		System.out.println(" \n \n les chaines \n");
		
		Pile<String> listChaine = new Pile<String>();
		listChaine.empiler("adel");
		listChaine.empiler("nu");
		listChaine.empiler("you");
		listChaine.empiler("can");
		listChaine.empiler("ti");
		
		System.out.println("es que la pile est vide  "+listChaine.estVide());
		System.out.println("Depiler  "+listChaine.depile());
		System.out.println("Sommet  "+listChaine.sommet());
		int taille1 = listChaine.nbElements();
		System.out.println("taille de la pile  "+taille);
		for(int i=0;i<taille1;i++)
			listChaine.depile();
		
		System.out.println("es que la pile est vide  "+listChaine.estVide());
		
		
	}

}
