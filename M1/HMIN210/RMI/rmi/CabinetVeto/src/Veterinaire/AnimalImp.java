package Veterinaire;


import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;


public class AnimalImp extends UnicastRemoteObject  implements Animal {
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String nameAnimal;
	private String nameMaster;
	private DossierSuivi suiv;
	private Espece spicy;
	
	public AnimalImp(String nameAnimal, String nameMaster,DossierSuivi docS,Espece esp) throws RemoteException {
		super();
		this.nameAnimal = nameAnimal;
		this.nameMaster = nameMaster;
		this.spicy = esp;
		this.suiv=docS;
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
	
	public DossierSuivi getFicheSuivi() throws RemoteException{
		return this.suiv;
	}
	public void setFicheSuivi(String suivi) throws RemoteException{
		this.suiv.setSuivi(suivi);
	}
	public Espece getAnimalEspece() throws RemoteException{
		return this.spicy;
	}
	public void setAnimalEspece(String espece) throws RemoteException{
		this.spicy.setEspece(espece);
	}
	
	
}
