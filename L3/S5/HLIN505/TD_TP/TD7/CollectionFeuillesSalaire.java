package td7;

import java.util.ArrayList;
import java.util.Collections;
import java.util.stream.Collectors;



public class CollectionFeuillesSalaire{

	private ArrayList<FeuilleSalaire> lfs;
	
	public CollectionFeuillesSalaire(ArrayList<FeuilleSalaire> lfs)
	{
		this.lfs= lfs;
	}
	
	public void print()
	{
		 // lambda expression
		 lfs.stream().forEach(e -> System.out.println(e.toString()));
		
	}
	
	

	
	public void triParNombreHeuresP()
	{
	  Collections.sort(lfs,new ComparateurParNBHP());
	}
	
	public void triParNombreHeuresP_Lambda()
	{
	  Collections.sort(lfs,(fs1,fs2)->fs1.getNbHeuresPayes().compareTo(fs2.getNbHeuresPayes()));
	}
	
	/*
	 *public void tri()
	 *{
	 *	Comparator<FeuilleSalaire> c = (f1,f2)->Double compare(f1.getNbh(),f2.getNbh());
	 *	listeFeuilles.stream().sorted(c);
	 *} 
	 * 
	 */
	
	public ArrayList<FeuilleSalaire> retourneFeuillesSalaires(String entreprise)
	{
		 ArrayList<FeuilleSalaire> liste =(ArrayList<FeuilleSalaire>) lfs
		.stream()
		.filter(fs->(fs.getEmployeur().equals(entreprise)))
		.collect(Collectors.toList());
		 
		 return liste;
	}
	

	public ArrayList<String> listeEntreprise(String ent)
	{
		ArrayList<String> liste = new ArrayList<String>();
				lfs.stream()
				  	.forEach(fs->(liste.add(fs.getEmployeur())));
		
				return (ArrayList<String>) liste.stream()
							.filter((s->((s.equals(ent)))))
							.collect(Collectors.toList());
	}
	
	
	
}
