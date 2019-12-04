package tpVeto;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface DossierSuivi extends Remote {
	String getSuivi() throws RemoteException;
	String setSuivi(String suivi) throws RemoteException;
}
