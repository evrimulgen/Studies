package etudiant;



import java.util.Scanner;

public class Etudiant_test{
    
	public static void main(String args[]){

	Scanner sc = new Scanner(System.in);    

    
	
	System.out.println("saisissez le nom");
	String nom=sc.next();

	System.out.println("saisissez l'age");
	int age=sc.nextInt();

	System.out.println("saisissez la date de naissance");
	int date_n=sc.nextInt();

	System.out.println("saisissez l code d'inscription");
	
	Code_Inscription ci_1;
	
	String ci=sc.next();
	if(ci == "Premiere_Inscription")  ci_1=Code_Inscription.Premiere_Inscription;
	else if(ci == "Reinscription") ci_1=Code_Inscription.Reinscription;
	else ci_1=Code_Inscription.Reinscription;
	
      

        
	


	Code_Pays cp_1;
	
	String cp=sc.next();
	if(cp == "français")  cp_1=Code_Pays.français;
	else if(cp == "etrangers_francophones") cp_1=Code_Pays.etrangers_francophones;
      	else if(cp == "etrangers_non_francophones") cp_1=Code_Pays.etrangers_non_francophones;
	else  cp_1=Code_Pays.français;
	



	
	

	    

	System.out.println("saissisez les notes et les noms des UEs");

	System.out.print("UE1 = ");
	String UE1=sc.nextLine();
	System.out.print(":");
	int n1=sc.nextInt();
	System.out.println("");

	

	System.out.print("UE2 = ");
	String UE2=sc.nextLine();
	System.out.print(":");
	int n2=sc.nextInt();
	System.out.println("");

    
	System.out.print("UE3 = ");
	String UE3=sc.nextLine();
	System.out.print(":");
	int n3=sc.nextInt();
	System.out.println("");

   
    
	Etudiant e1=new Etudiant(nom,date_n,ci_1,cp_1,n1,UE1,n2,UE2,n3,UE3);

	System.out.println("Metion"+e1.mention());
	System.out.println("Moyenne"+e1.moyenne());
	e1.LigneResultats();

	sc.close();
    }
}
