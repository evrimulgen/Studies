package Veterinaire;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;

public class CabinetVeterinaireImp<AnimalImp> extends UnicastRemoteObject   implements CabinetVeterinaire{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private ArrayList <AnimalImp> animals ;
	private ArrayList <EspeceImp> especes;

	protected CabinetVeterinaireImp() throws RemoteException {
		super();
		this.animals = new ArrayList<AnimalImp> (); 
		this.especes= new ArrayList <EspeceImp> ();
		// TODO Auto-generated constructor stub
	}

	@Override
	public Animal getAnimal(String nom) throws RemoteException {
		
		int indice =0;
		while (indice<this.animals.size()) {
		
			if (((Animal) this.animals.get(indice)).getNameAnimal().equals(nom)) {
				return (Animal) this.animals.get(indice);
					}	
			indice++;
		}
		return null;
		
	}
	
	public void addSpicy(EspeceImp spc) {
		this.especes.add(spc);
	}
	
	private void setData(ArrayList<AnimalImp> newAnimals,ArrayList<EspeceImp> newspicies) throws RemoteException {
		this.animals=newAnimals;
		this.especes=newspicies;
	}

		
	
	@Override
	public void addAnimal(Veterinaire.AnimalImp animal) throws RemoteException {
		// TODO Auto-generated method stub
		 this.animals.add((AnimalImp) animal);
	}

	

	

	

}
