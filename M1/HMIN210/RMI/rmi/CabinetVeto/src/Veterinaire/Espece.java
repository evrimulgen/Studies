package Veterinaire;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Espece extends Remote {
	String getEspece() throws RemoteException;
	String setEspece(String espece) throws RemoteException;
	int getDureeVie()throws RemoteException;
	void setDureeVie(int dureeVie)throws RemoteException;
}
