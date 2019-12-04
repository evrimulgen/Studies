package etudiant;



public class Resultat{

    private Evaluation[]  evaluations;
    //constructeur
    public Resultat(float Note_a,float Note_b,float Note_c,String UE_1,String UE_2,String UE_3){

	evaluations=new Evaluation[3];

	evaluations[0]=new Evaluation(Note_a,UE_1);
	evaluations[1]=new Evaluation(Note_b,UE_2);
	evaluations[2]=new Evaluation(Note_c,UE_3);
    }
    //accesseur 
    public Evaluation[] getEvals(){
	return this.evaluations;}

    public void setEvals(float Note_1,float Note_2,float Note_3,String UE_1,String UE_2,String UE_3){
	this.evaluations[0].setNote(Note_1);
	this.evaluations[0].setCode(UE_1);
	this.evaluations[1].setNote(Note_2);
	this.evaluations[1].setCode(UE_2);
	this.evaluations[2].setNote(Note_3);
	this.evaluations[2].setCode(UE_3);
    }
	

    public float CalculMoy(){
	float num=evaluations[0].getNote()+evaluations[1].getNote()+evaluations[2].getNote();
	return num/3;
    }

    public Mention CalculMention(){
	
	if ((this.CalculMoy()>=10) && (this.CalculMoy()<12)) return Mention.passable;else
	if ((this.CalculMoy()>=12) && (this.CalculMoy()<14)) return Mention.assez_bien;else
	if ((this.CalculMoy()>=14) && (this.CalculMoy()<16)) return Mention.bien;else
	if ((this.CalculMoy()>=16) && (this.CalculMoy()<18)) return Mention.tres_bien;else
	    if ((this.CalculMoy()>=18) && (this.CalculMoy()<20)) return Mention.excellent;else return Mention.blame;
	
    }
    
    public boolean ajourne(){
	if ((this.CalculMoy()) < 10 ) return true;
	else return false;
    }
    

}
