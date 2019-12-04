package Veterinaire;
import java.rmi.registry.Registry;
import java.security.AccessControlException;
import java.rmi.registry.LocateRegistry;

public class Server {

	public Server() {}


	public static void main(String args[]) {

		 try {   
			 if(System.getSecurityManager() == null){
					System.setProperty("java.security.policy", "GestSecu");
					System.setSecurityManager(new SecurityManager());
				}
	
		
			CabinetVeterinaireImp cabinet = new CabinetVeterinaireImp();
			
			
			EspeceImp esp1=new EspeceImp("canidés",20);
			EspeceImp esp2=new EspeceImp("félins",40);
			EspeceImp esp3=new EspeceImp("serpentes",20);
			
			cabinet.addSpicy(esp1);
			cabinet.addSpicy(esp2);
			cabinet.addSpicy(esp3);
			
			DossierSuivImp doc1=new DossierSuivImp("bon");
			DossierSuivImp doc2=new DossierSuivImp("moyen");
			DossierSuivImp doc3=new DossierSuivImp("mauvais");
			
			cabinet.addAnimal(new AnimalImp("Chien","Popey",doc1,esp1));
			cabinet.addAnimal(new AnimalImp("Serpant","Norbert",doc2,esp2));
			cabinet.addAnimal(new AnimalImp("Lion","Izem",doc3,esp3));
			
			
			
			Registry registry = LocateRegistry.getRegistry();
			//Registry registry = LocateRegistry.getRegistry();
			if (registry==null){
				System.err.println("RmiRegistry not found");
			}else{
				 registry.bind("Cabinet",cabinet);
				 System.err.println("Server ready");
			}
		} catch (Exception e) {
			System.err.println("Server exception: " + e.toString());
			//e.printStackTrace();
		}
	}
}