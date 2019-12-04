package tpVeto;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
	private Client() {}

	public static void main(String[] args) {

		String host = (args.length < 1) ? null : args[0];
		
		// gestionnaire de sécurité
	    if (System.getSecurityManager() == null) {
	    	System.setProperty("java.security.policy","security");
	        System.setSecurityManager(new SecurityManager());
	    }
	    
		try {
			
			Registry registry = LocateRegistry.getRegistry(host);
			Animal stub = (Animal) registry.lookup("Animal");
			String response = stub.getNameMaster();
			System.out.println("response: " + response);
			stub.displayNameAnimal();
		} catch (Exception e) {
			System.err.println("Client exception: " + e.toString());
			e.printStackTrace();
		}
	}
}
