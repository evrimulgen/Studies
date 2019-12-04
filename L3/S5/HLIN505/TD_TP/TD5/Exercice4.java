package td5;

public class Exercice4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		Pochette<GuideVoyage> pgv=new Pochette<GuideVoyage>();
		
		pgv.ajouter(new GuideVoyage("l'asie","dépliant"));
		pgv.ajouter(new GuideVoyage("l'europe","catalogue"));
		//pgv.ajouter(new LivreJeunesse("ratus","contine",8));
		pgv.setTheme("leMonde");
		System.out.println(pgv.toString());
		
		Pochette<Document> MaPochette=new Pochette<Document>();
		MaPochette.ajouter(new GuideVoyage("l'asie","dépliant"));
		MaPochette.ajouter(new LivreJeunesse("diego l'explorateur","livreEnfant",5));
		MaPochette.ajouter(new Livre("Les bénéfices du sexe","manuel"));
		MaPochette.setTheme("ouvertureSpirituelle");
		System.out.println(MaPochette.toString());
		
		PochetteJeunesse<DocumentJeunesse> youth = new PochetteJeunesse<DocumentJeunesse>();
		youth.setAgeconseille(10);
		youth.ajouter(new LivreJeunesse("l'alchimiste","roman",15));
		
		Pochette<Document> trsf= new Pochette<Document>();
		pgv.Transferer(trsf);
		trsf.setTheme("transfert");
		System.out.println(trsf.toString());
		
		Pochette<Livre> livres= new Pochette<Livre>();
		Pochette<LivreJeunesse> livresJeu= new Pochette<LivreJeunesse>();
		PochetteJeunesse<LivreJeunesse> lj= new PochetteJeunesse<LivreJeunesse>();
		
		//Questions 14
		//livres
		livres.ajouter(new Livre("a","roman"));
		livres.ajouter(new Livre("b","manuel"));
		livres.ajouter(new Livre("c","receuil"));
		livres.setTheme("livres");	
		//livresJeu
		livresJeu.ajouter(new LivreJeunesse("diego","enfant",4));
		livresJeu.setTheme("Jeune!!!");
		
		//lj
		lj.setAgeconseille(12);
		lj.ajouter(new LivreJeunesse("a","b",10));
		lj.ajouter(new LivreJeunesse("c","d",10));
		
		livresJeu.Transferer(livres);
		System.out.println(livres.toString());
		
		lj.Transferer(livres);
		System.out.println(livres.toString());
		
	}
}
