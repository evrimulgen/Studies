package td7;

import java.util.Comparator;

public class ComparateurParNBHP implements Comparator <FeuilleSalaire>{

	public int compare(FeuilleSalaire fs1,FeuilleSalaire fs2)
	{
		return (int) (fs1.getNbHeuresPayes()-fs2.getNbHeuresPayes());
	}
}
