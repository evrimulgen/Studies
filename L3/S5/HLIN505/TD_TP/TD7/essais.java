package td7;

import java.awt.Color;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class essais {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		//1 - Feu Tricolore
		System.out.println("Feu Triclolore \n ");
		FeuTricolore f = new FeuTricolore();
		Iterator<Color> it = f.iterator();
		
		for(int i=0;i < 3;i++)
			System.out.println(it.next());
		
		FeuilleSalaire fs = new FeuilleSalaire("UM","Adel","N/A",300.0,1000.0,2000.0);
		Iterator<Object> it1 = fs.iterator();
		
		//2 - Itérer sur un objet complexe
		System.out.println("\n Feuille de Salaire \n ");
		
		for(int i=0;i < 6;i++)
			System.out.println(it1.next());
		
		//3 - Premières utilisations de lambdas
		System.out.println("\n Collection de Feuilles de Salaire \n ");
		
		FeuilleSalaire fs1 = new FeuilleSalaire("UM","Farid","N/A",300.0,500.0,2400.0);
		FeuilleSalaire fs2 = new FeuilleSalaire("UB","Islam","N/A",500.0,700.0,2500.0);
		FeuilleSalaire fs3 = new FeuilleSalaire("UM","Natalie","N/A",100.0,1000.0,2000.0);
		
		ArrayList<FeuilleSalaire> L = new ArrayList<FeuilleSalaire> ();
		L.add(fs);
		L.add(fs1);
		L.add(fs2);
		L.add(fs3);
		
		CollectionFeuillesSalaire CFS = new CollectionFeuillesSalaire(L);
		//CFS.triParNombreHeuresP();// Question 3
		CFS.triParNombreHeuresP_Lambda();
		CFS.print(); // Question 1
		System.out.println("entrez le nom d'une entreprise \n");
		Scanner sc = new Scanner(System.in);
		String ent = sc.next();
		ArrayList<FeuilleSalaire> L1 = CFS.retourneFeuillesSalaires(ent);
		//Question 4
		for(FeuilleSalaire s : L1)
			System.out.println(s.toString());
			
		//Question 5 
		ArrayList<String> L2 = CFS.listeEntreprise(ent);
		for(String y : L2)
			System.out.println(y);
	}

}
