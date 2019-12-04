package td5.Exo2;

public class Exercice2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Integer T[]={ 6,5,4,3,2};
		Tableau<Integer> obj=new Tableau<Integer>(T);
		obj.affiche();
		System.out.println(" \n ");
		obj.triBulles();
		obj.affiche();

	}

}
