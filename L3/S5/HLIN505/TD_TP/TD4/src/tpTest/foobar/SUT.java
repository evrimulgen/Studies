package tpTest.foobar;

public class SUT {
	private int x;
	private int y;
	private int z;

	public SUT(int x, int y, int z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}
	public SUT(){
		x=1;
		y=3;
		z=5;
	}

	/**
	 * Si t est strictement plus petit que x, on retourne x, sinon si t est strictement plus grand que z, on retourne z, sinon on retourne y.
	 * @param t un entier quelconque
	 * @return x si t<x, z si t>z, y sinon 
	 */
	public int foo(int t){  
		//x=1 , y=3 , z = 5 ,t=2 , res =3 [0] -> foo(2)=3
		//x=5 , y=3 , z = 1 ,t=2 , res =5 [1] -> foo(2)=1
		//x=5 , y=1 , z = 3 ,t=2 , res =5 [2] -> foo(2)=1
		//x=3 , y=1 , z = 5 ,t=2 , res =3 [3] -> foo(2)=1
		//x=3 , y=5 , z = 1 ,t=2 , res =3 [4] -> foo(2)=1
		//x=1 , y=5 , z = 3 ,t=2 , res =5[5]  -> foo(2)=5
		int resultat=0;
		if (t<x) resultat=x;
		if (t>z) resultat=z;
		else resultat=y;
		return resultat;
	}
	
	/**
	 * décale circulairement les valeurs de x, y et z : x prend la valeur de y, y prend la valeur de z et z prend la valeur de x
	 */
	public void bar(){
		int temp=x;
		x=y; //x = 3 
		y=z; // y =5
		z=temp; //z=1
	}
	
	
	public int getX() {
		return x;
	}
	public void setX(int x) {
		this.x = x;
	}
	public int getY() {
		return y;
	}
	public void setY(int y) {
		this.y = y;
	}
	public int getZ() {
		return z;
	}
	public void setZ(int z) {
		this.z = z;
	}
	/**
	 * 
	 */
	public void foobar()throws FooBarException{
		if (x<0) throw new FooBarException();
	}
}
