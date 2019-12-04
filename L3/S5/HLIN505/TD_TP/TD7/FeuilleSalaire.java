package td7;

public class FeuilleSalaire implements Iterable<Object>  {

	private String employeur;
	private String salarie;
	private String conventionCollective;
	private Double nbHeuresPayes; 
	private Double prelevementsFiscaux;
	private Double netAPayer;
	
	public FeuilleSalaire(String e,String s,String cc,Double nbhp,Double pf,Double np)
	{
		employeur=e;
		salarie=s;
		conventionCollective=cc;
		nbHeuresPayes=nbhp;
		prelevementsFiscaux=pf;
		netAPayer=np;
	}
	
	
	public IterateurFS iterator()
	{
		return new IterateurFS(this);
	}


	public String getEmployeur() {
		return employeur;
	}


	public void setEmployeur(String employeur) {
		this.employeur = employeur;
	}


	public String getSalarie() {
		return salarie;
	}


	public void setSalarie(String salarie) {
		this.salarie = salarie;
	}


	public String getConventionCollective() {
		return conventionCollective;
	}


	public void setConventionCollective(String conventionCollective) {
		this.conventionCollective = conventionCollective;
	}


	public Double getNbHeuresPayes() {
		return nbHeuresPayes;
	}


	public void setNbHeuresPayes(Double nbHeuresPayes) {
		this.nbHeuresPayes = nbHeuresPayes;
	}


	public Double getPrelevementsFiscaux() {
		return prelevementsFiscaux;
	}


	public void setPrelevementsFiscaux(Double prelevementsFiscaux) {
		this.prelevementsFiscaux = prelevementsFiscaux;
	}


	public Double getNetAPayer() {
		return netAPayer;
	}


	public void setNetAPayer(Double netAPayer) {
		this.netAPayer = netAPayer;
	}
	
	public String toString()
	{
		return getEmployeur()+"\n"+getSalarie()+"\n"+getConventionCollective()+"\n"+getNbHeuresPayes()+"\n"+getPrelevementsFiscaux()+"\n"+getNetAPayer()+"\n \n";
	}
	
}
