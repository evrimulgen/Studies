package grahics;

import javax.swing.*;
import java.awt.FlowLayout;
import java.awt.GridLayout;

public class FenFlowLayout  extends JFrame{

	 private JButton [] boutons; 
	  
	 public FenFlowLayout() 
	 { 
	  setSize(400, 400); 
	  setTitle("Fenêtre avec un FlowLayout"); 
	   
	  boutons = new JButton[5]; 
	  for (int i = 0; i < boutons.length; i ++) 
	    boutons[i]= new JButton("Bouton "+i); 
	  setLayout(new FlowLayout()); 
	  for (int i = 0; i < boutons.length; i ++) 
	    add(boutons[i]);
	  
	 
	 } 
}
