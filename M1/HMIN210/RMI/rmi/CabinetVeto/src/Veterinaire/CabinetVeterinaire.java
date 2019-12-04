package Veterinaire;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface CabinetVeterinaire extends Remote {
	Animal getAnimal(String nom) throws RemoteException;
	void addAnimal (AnimalImp animal) throws RemoteException;
}
