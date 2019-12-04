package grahics;

import java.awt.FlowLayout;

import javax.swing.*;


public class FenBouton extends JFrame{

	private JButton bouton1;
	private JButton bouton2;
	
	public FenBouton() 
	 { 
	  setSize(400, 400); 
	  setTitle("Fenêtre à un bouton"); 
	  setLayout(new FlowLayout()); 
	   
	  bouton1 = new JButton("Hello");
	  bouton2 = new JButton("beauty 3:)");
	  this.add(bouton1); // équivalent à add(bouton, "Center"), voir plus loin  
	  this.add(bouton2);
	 } 
}
