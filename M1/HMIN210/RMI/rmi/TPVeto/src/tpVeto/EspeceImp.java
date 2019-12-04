package tpVeto;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class EspeceImp extends UnicastRemoteObject implements Espece {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String espece;
	private int dureeVie;

	
	public EspeceImp(String espece, int dureeVie) throws RemoteException {
		super();
		this.espece = espece;
		this.dureeVie = dureeVie;
	}
	@Override
	public String getEspece() throws RemoteException {
		// TODO Auto-generated method stub
		return espece;
	}

	@Override
	public String setEspece(String espece) throws RemoteException {
		// TODO Auto-generated method stub
		return this.espece=espece;
	}

	public int getDureeVie() throws RemoteException  {
		return dureeVie;
	}

	public void setDureeVie(int dureeVie) throws RemoteException  {
		this.dureeVie = dureeVie;
	}
	
}
