package etudiant;



public class Etudiant{
   
    private String nom;
    private int age;
    private int date_n;
    private Code_Inscription CodeIns;
    private Code_Pays CodeP;
    private Resultat res;

   
    public Etudiant (String nom,int date_n,Code_Inscription CodeIns,Code_Pays CodeP,int note_1,String UE_1,int note_2,String UE_2,int note_3,String UE_3){
	this.nom=nom;
	this.date_n=date_n;
	this.CodeIns=CodeIns;
	this.CodeP=CodeP;
	this.res=new Resultat(note_1,note_2,note_3,UE_1,UE_2,UE_3);
    }

    //accesseurs
    // en lecture
    public String get_nom(){ return this.nom;}
    public int get_age(){ return this.age;}
    public int get_dateN(){ return this.date_n;}
    public Code_Inscription get_CI(){ return this.CodeIns;}
    public Code_Pays get_CP(){ return this.CodeP;}
    public Resultat get_res(){ return this.res;}
    //en écriture
    public void set_nom(String nom){ this.nom = nom;}
    public void set_age(int a){ this.age=a;}
    public void set_dateN(int d){  this.date_n=d;}
    public void set_CI(Code_Inscription C){  this.CodeIns=C;}
    public void set_CP(Code_Pays P){  this.CodeP=P;}
    public void set_res(int note_1,int note_2,int note_3,String UE_1,String UE_2,String UE_3){
	this.res.setEvals(note_1,note_2,note_3,UE_1,UE_2,UE_3);
    }

    
    
    // méthodes spéciales

    public Mention mention(){return this.res.CalculMention();}
    public float moyenne(){return this.res.CalculMoy();}
    public void LigneResultats(){
	Evaluation[] E=res.getEvals();
	
	if (this.res.ajourne())
	    System.out.println(this.get_nom()+"----"+this.moyenne()+"----"+this.mention()+"----"+E[0].sup_10()+"----"+E[1].sup_10()+"-----"+E[2].sup_10());
	else System.out.println(this.get_nom()+"----"+this.moyenne()+"----"+this.mention());

	
    }

}
