package bibliotheque;

import java.util.ArrayList;

public class Test {
	
	public static void main(String[] agrs){
	
		Contributeur c1 =new Contributeur("Pennac","Daniel");
		Contributeur c2 =new Contributeur("Mizubayashi","Akari");
		Contributeur c3 =new Contributeur("Treki","adel");
		Contributeur c4 =new Contributeur("Yuri","Boyka");
		Contributeur c5 =new Contributeur("Paul","Walker");
		Contributeur c6 =new Contributeur("Raguegnaroque","Brook");
		
		
		
		NoticeBibliograpĥique nb1= new NoticeBibliograpĥique("NB-fr-1258-9777",
				"la détermination","force mental",Public.adulte);
		NoticeBibliograpĥique nb2= new NoticeBibliograpĥique("NB-jp-1689-9548","tenjou tenge","shonen",Public.junior);
		NoticeBibliograpĥique nb3= new NoticeBibliograpĥique("NB-fr-4548-4784","maya l'abeille","enfants",Public.enfant);
		NoticeBibliograpĥique nb4= new NoticeBibliograpĥique("NB-en-1997-4554","Tom Soyer","Aventure",Public.junior);
		NoticeBibliograpĥique nb5= new NoticeBibliograpĥique("NB-fr-1996-4002","naruto","shonen",Public.junior);
		NoticeBibliograpĥique nb6= new NoticeBibliograpĥique("NB-fr-1995-4780","le sexe c'est bon pour la santé","adulte",Public.adulte);
	
		Contribution contri1 =new Contribution(NatureContribution.redacteur,c1,nb1);
		Contribution contri2 =new Contribution(NatureContribution.redacteurPreface,c1,nb2);
		Contribution contri3 =new Contribution(NatureContribution.illustrateur,c1,nb2);
		Contribution contri4 =new Contribution(NatureContribution.tradcuteur,c1,nb4);
		Contribution contri5 =new Contribution(NatureContribution.redacteurPreface,c1,nb5);
		Contribution contri6 =new Contribution(NatureContribution.redacteur,c1,nb6);
		
		ArrayList<Contribution> Contri = new ArrayList<Contribution>();
		
		Contri.add(contri1);
	
		
		c1.setNoticeB(Contri);
		
		nb1.setContributeurs(Contri);
		nb2.setContributeurs(Contri);
		nb3.setContributeurs(Contri);
		nb4.setContributeurs(Contri);
		nb5.setContributeurs(Contri);
		nb6.setContributeurs(Contri);
		
		Catalogue C1 = new Catalogue();
		C1.ajoutNotice(nb1);
		C1.ajoutNotice(nb2);
		C1.ajoutNotice(nb3);
		C1.ajoutNotice(nb4);
		C1.ajoutNotice(nb5);
		C1.ajoutNotice(nb6);
		
		ArrayList<NoticeBibliograpĥique> NB;
		
		NB = C1.getNoticebyAuthor("Pennac");
		
		for(NoticeBibliograpĥique n : NB){
			System.out.println(n.getTitre());
			
		}
		
		System.out.println("\n");
		System.out.println("les livres : \n");
		
		System.out.println(C1.getNoticeByisbn("NB-jp-1689-9548").getTitre());
		System.out.println(C1.getNoticeByisbn("NB-fr-1995-4780").getTitre());
		
		
		
		
		
		
		
		
	}

}
