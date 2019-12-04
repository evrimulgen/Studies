package bibliotheque;

public class AbonneMineur extends Abonne {
	
	AbonneMineur(String s){
		super(s);
	}
	
	public boolean emprunte(Exemplaire e){
		if (e.getNb().getPublicCible() != Public.adulte ){
			return super.emprunte(e);
		}else{
			return false;
		}
	}

}
