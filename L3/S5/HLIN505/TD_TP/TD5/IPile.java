package td5;

public interface IPile<A> 
{
	boolean estVide();
	void empiler(A a);
	A depile(); //retourne l'element en sommet de pile et depile
	int nbElements();
	A sommet(); //retourne de sommet de pile mais ne le depile pas
}
