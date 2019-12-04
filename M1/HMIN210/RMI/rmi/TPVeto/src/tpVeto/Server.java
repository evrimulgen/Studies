package tpVeto;


import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;


public class Server {

	public Server() {}


	public static void main(String args[]) {

		try {
			// gestionnaire de sécurité
		    if (System.getSecurityManager() == null) {
		    	System.setProperty( "java.security.policy", "security");
		        System.setSecurityManager(new SecurityManager());
		    }
		    Espece spicy= new EspeceImp("Serpentes",9);
		    DossierSuivi folder= new DossierSuivImp("bonEtat");
			AnimalImp obj = new AnimalImp("Serpent","Sihem",folder,spicy);
			//Registry registry = LocateRegistry.createRegistry(1099);
			Registry registry = LocateRegistry.getRegistry();
			if (registry==null){
				System.err.println("RmiRegistry not found");
			}else{
				registry.bind("Animal", obj);
				System.err.println("Server ready");
			}
		} catch (Exception e) {
			System.err.println("Server exception: " + e.toString());
			e.printStackTrace();
		}
	}
}
