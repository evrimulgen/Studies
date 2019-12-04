package etudiant;


public class Evaluation{
   
    private  float Note_UE;
    private  String Code_UE;

    //constructeur
    
    public Evaluation(float Note_UE,String Code_UE){
	this.Note_UE = Note_UE;
	this.Code_UE = Code_UE;
    }

    // accesseurs 
    public float  getNote(){return this.Note_UE;}
    public String getCode(){return this.Code_UE;}
    public void setNote(float n){this.Note_UE=n;}
    public void setCode(String s){this.Code_UE=s;}

    //mth s

    public String sup_10(){
	if( Note_UE >=10) return Code_UE;
	else return "";
    }
	

}
