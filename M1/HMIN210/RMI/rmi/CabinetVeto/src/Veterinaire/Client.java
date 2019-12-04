package Veterinaire;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client {
	private Client() {}

	public static void main(String[] args) {

		//String host = (args.length < 1) ? null : args[0];
		try {
			if(System.getSecurityManager() == null){
				System.setProperty("java.security.policy", "./GestSecu");
				System.setSecurityManager(new SecurityManager());
			}
			Registry registry = LocateRegistry.getRegistry(1206);
			CabinetVeterinaire stub = (CabinetVeterinaire) registry.lookup("Cabinet");
			Animal animal1 = stub.getAnimal("Felix");
			String response = animal1.getNameAnimal();
			System.out.println("response: " + response);
			Espece esp=animal1.getAnimalEspece();
			System.out.println("Details espece:  Nom : " + esp.getEspece() + "Duree de vie : "+ esp.getDureeVie());
			System.out.println("Ajouter un animal");
			stub.addAnimal(new AnimalImp("Scooby", "Rex Brasco",new DossierSuivImp("bon"),new EspeceImp("canidé",20)));
			Animal animal2 = stub.getAnimal("Scooby");
			String response2 = animal2.getNameAnimal();
			System.out.println("response: " + response2);
			
			} catch (Exception e) {
			System.err.println("Client exception: " + e.toString());
			e.printStackTrace();
		}
	}
}