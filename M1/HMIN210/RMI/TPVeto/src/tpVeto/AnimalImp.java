package tpVeto;


import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;


public class AnimalImp extends UnicastRemoteObject  implements Animal {
	
	private String nameAnimal;
	private String nameMaster;
	
	public AnimalImp(String nameAnimal, String nameMaster) throws RemoteException {
		this.nameAnimal = nameAnimal;
		this.nameMaster = nameMaster;
	}
	
	public String getNameMaster() throws RemoteException{
		return this.nameMaster;
	}
	public String getNameAnimal() throws RemoteException{
		return this.nameAnimal;
	}
	public void displayNameMaster() throws RemoteException{
		System.out.println(nameMaster);
	}
	public void displayNameAnimal()  throws RemoteException{
		System.out.println(nameAnimal);
	}
	
	
}
