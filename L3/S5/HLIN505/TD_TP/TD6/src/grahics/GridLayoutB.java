package grahics;

import java.awt.GridLayout;

import javax.swing.*;

public class GridLayoutB extends JFrame{

	 private JButton [] boutons = new JButton[10]; 
	 
	 public GridLayoutB()
	 {	
		 setSize(400, 400); 
		 setTitle("Fenêtre avec un GridLayout"); 
		 setLayout(new GridLayout(3,4));  
		// 3 lignes, 4 colonnes
		 
		 for (int i = 0; i < 10; i ++) 
			   boutons[i]=new JButton("Bouton "+i); 
		 
		 for (int i = 0; i < 10; i ++) 
			 add(boutons[i]);
	 }
}
