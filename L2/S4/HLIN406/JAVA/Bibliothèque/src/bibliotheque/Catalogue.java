package bibliotheque;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Hashtable;

public class Catalogue {
	private Hashtable<String,NoticeBibliograpĥique> notices;
	
	public Catalogue(){
		notices = new Hashtable<String,NoticeBibliograpĥique>();
			}
	
	public NoticeBibliograpĥique getNoticeByisbn(String isbn){
		return notices.get(isbn);
		}
	
	public void ajoutNotice(NoticeBibliograpĥique n){
		notices.put(n.getIsbn(),n);
	}
	
	public ArrayList<NoticeBibliograpĥique> getNoticebyAuthor(String author){
		Collection<NoticeBibliograpĥique> e = notices.values();
		ArrayList<NoticeBibliograpĥique> lesNoticesDeA = new ArrayList<NoticeBibliograpĥique>(); 
		
		for (NoticeBibliograpĥique n : e){
			for (Contributeur c : n.getContributeur()){
				if (c.getNom() == author){
					lesNoticesDeA.add(n);
				}
				
			}
		}
		return lesNoticesDeA;
	}

}
