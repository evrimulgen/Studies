package Veterinaire;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface DossierSuivi extends Remote {
	String getSuivi() throws RemoteException;
	void setSuivi(String suivi) throws RemoteException;
}
