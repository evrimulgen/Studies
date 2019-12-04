package grahics;

import javax.swing.JFrame;

public class MyFrame extends JFrame {
	
	public MyFrame()
	{
		super(); // sinon, serait ajouté par le compilateur 
		setTitle("Ma petite application"); 
		setSize(400,400) ;  
		setLocation(100,100) ; 
	}
}
