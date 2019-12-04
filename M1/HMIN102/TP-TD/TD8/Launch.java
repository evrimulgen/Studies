package waterGame;

public class Launch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//créer bidons b1 b2 b3
		Can b1=new Can(2,5);
		Can b2=new Can(0,5);
		Can b3=new Can(0,5);
		//créer invoker
		Invoker invoker=new Invoker();
		
		invoker.doCommand(new fillCan(b3));
		invoker.doCommand(new TransferWater(b3,b1));
		invoker.undoLast();
		
	}
	

}
