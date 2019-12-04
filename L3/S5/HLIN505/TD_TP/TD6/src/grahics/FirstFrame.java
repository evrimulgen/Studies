package grahics;

import javax.swing.*; 


public class FirstFrame {
	
	public FirstFrame()
	{
		JFrame f = new MyFrame(); 
		f.setVisible(true); 
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		/*JFrame f = new MyFrame(); // ou : MyFrame f = new MyFrame(); 
		f.setVisible(true); // sinon la fenêtre n'est pas visible 
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);*/
		
		//firstFrame a = new firstFrame();
		//new firstFrame();
		
		/*GraphConsole f = new GraphConsole(); 
		  f.setVisible(true); 
		  while(true) 
		  { 
		   System.out.println("nouveau titre?"); 
		   Scanner sc = new Scanner(System.in); 
		   String rep = sc.nextLine();    
		   f.setTitle(rep);    
		  }
		  */
		
		  FenBouton fb = new FenBouton(); 
		  fb.setVisible(true); 
		  
		
		  FenBorderLayout fbl = new FenBorderLayout(); 
		  fbl.setVisible(true); 
		  
		  FenFlowLayout ffl = new FenFlowLayout();
		  ffl.setVisible(true);
		  
		  GridLayoutB glb = new GridLayoutB();
		  glb.setVisible(true);
	}

}
