package Veterinaire;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Animal extends Remote {
	String getNameMaster() throws RemoteException;
	String getNameAnimal() throws RemoteException;
	void displayNameMaster() throws RemoteException;
	void displayNameAnimal()  throws RemoteException;
	DossierSuivi getFicheSuivi() throws RemoteException;
	void setFicheSuivi(String suivi) throws RemoteException;
	Espece getAnimalEspece() throws RemoteException;
	void setAnimalEspece(String espece) throws RemoteException;
}
