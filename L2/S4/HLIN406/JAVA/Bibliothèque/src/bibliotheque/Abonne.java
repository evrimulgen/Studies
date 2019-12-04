package bibliotheque;

import java.util.ArrayList;

public class Abonne {
	
	private String nom;
	private int numero=0;
	private ArrayList<Exemplaire> exemplairesEmpruntes;
	static private int nbAbonnes=0;
	
	public Abonne(String n){
		nom=n;
		numero++;
		nbAbonnes++;
		exemplairesEmpruntes = new ArrayList<Exemplaire>();
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
	}

	public ArrayList<Exemplaire> getExemplairesA() {
		return exemplairesEmpruntes;
	}

	public void setExemplairesA(ArrayList<Exemplaire> exemplairesEmpruntes) {
		this.exemplairesEmpruntes = exemplairesEmpruntes;
	}

	public static int getNbAbonnes() {
		return nbAbonnes;
	}

	public static void setNbAbonnes(int nbAbonnes) {
		Abonne.nbAbonnes = nbAbonnes;
	}
	
	public boolean emprunte(Exemplaire e){
		if (this.exemplairesEmpruntes.size() < 5){ 
				if(e.empruntePar(this)){
					exemplairesEmpruntes.add(e);
			    	return true;
					}else{
					return false;	
			}}else{
				return false;
			}
	}
	
	public void rendre(Exemplaire e){
		
		exemplairesEmpruntes.remove(e);
		e.retourApresEmprunt();
	}
		
	
	
}
