package bibliotheque;

public class Contribution {
	private NatureContribution natureCbt;
	private Contributeur cbt;
	private NoticeBibliograpĥique noticeBb;
	
	public Contribution(NatureContribution natureCbt, Contributeur cbt, NoticeBibliograpĥique noticeBb) {
		super();
		this.natureCbt = natureCbt;
		this.cbt = cbt;
		this.noticeBb = noticeBb;
	}

	public NatureContribution getNatureCbt() {
		return natureCbt;
	}

	public void setNatureCbt(NatureContribution natureCbt) {
		this.natureCbt = natureCbt;
	}

	public Contributeur getCbt() {
		return cbt;
	}

	public void setCbt(Contributeur cbt) {
		this.cbt = cbt;
	}

	public NoticeBibliograpĥique getNoticeBb() {
		return noticeBb;
	}

	public void setNoticeBb(NoticeBibliograpĥique noticeBb) {
		this.noticeBb = noticeBb;
	}
	
	
	
	

}
