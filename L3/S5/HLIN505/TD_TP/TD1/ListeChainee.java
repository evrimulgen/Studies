package td1;

public class ListeChainee {
	private Node racine;
	private class Node {
		private String nom;
		private Node succ;
		
		public Node(String n){
			nom=n;
			succ=null;
		}
		
		
	}
	
	public ListeChainee(){
		racine = null;
	}
	
	public Node getRacine(){
		return racine;
	}
	
	public void ajouterNoeud(String n){
		Node tete = new Node(n);
		tete.succ=racine;
		racine = tete;
	}
	
	public int tailleListe1(Node n){
		if(n == null) return 0;
		else return 1+tailleListe1(n.succ);
		
	}
	
	public String afficherListe1(Node n){
		if(n == null) return " ";
		else return n.nom+" "+afficherListe1(n.succ);
		
	}
	
	public int tailleListe(){
		int t=0;
		Node n=racine;
		
		while( n != null){
			t++;
			n=n.succ;
		}
		return t;
	}
	
	public void afficherListe(){
		Node n=racine;
		
		while( n != null){
			System.out.print(n.nom+" ");
			n=n.succ;
		}
		
	}
	
	public ListeChainee renverser() {
		ListeChainee L = new ListeChainee();
	    Node n =racine;
	    while ( n!= null){
	    	L.ajouterNoeud(n.nom);
	    	n=n.succ;
	    }
	    
	   return L;
	}
	
}
	
	
	

