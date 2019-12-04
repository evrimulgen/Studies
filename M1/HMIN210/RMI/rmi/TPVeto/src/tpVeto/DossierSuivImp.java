package tpVeto;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class DossierSuivImp extends UnicastRemoteObject implements DossierSuivi {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String folder;
	
	public DossierSuivImp(String folder) throws RemoteException {
		super();
		this.folder = folder;
	}

	@Override
	public String getSuivi() throws RemoteException {
		// TODO Auto-generated method stub
		return this.folder;
	}

	@Override
	public String setSuivi(String suivi) throws RemoteException {
		// TODO Auto-generated method stub
		return this.folder=suivi;
	}

}
