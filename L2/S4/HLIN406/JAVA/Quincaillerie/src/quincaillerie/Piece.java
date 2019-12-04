package quincaillerie;

public abstract class Piece {
	private String nom;
	private String suffixeReference;
	
	//Constructeur
	public Piece(String nom,String suffixeReference){
		this.nom=nom;
		this.suffixeReference=suffixeReference;
	}
	
	//Accesseurs
	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public String getSuffixeReference() {
		return suffixeReference;
	}

	public void setSuffixeReference(String suffixeReference) {
		this.suffixeReference = suffixeReference;
	}
	//Méthodes
	public abstract float prix();
	public abstract int garantie();
	public abstract int dureeFabrication();
	public abstract String getPrefixeReference();
	public  String reference(){
		return getPrefixeReference()+suffixeReference;
	}
	
	public String affiche(){
		return "\n nom : "+nom+"\n référence : "+this.getPrefixeReference()+suffixeReference;
	};
	
	public String afficheCommeComposant(int decalage){
		String decal="";
		for (int i=0;i<decalage;i++)
			decal+=" ";
		return decal+this.nom+" - "+this.reference()+"\n";
			
		
	}
	
	
 }

