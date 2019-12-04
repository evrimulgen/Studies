package waterGame;

public class fillCan implements ICommand {
	int state;
	Can bidon;
	
	public fillCan(int state,Can bidon){
	
	}
	
	public void execute() {	
		bidon.setLevel(bidon.getCapacity());
		bidon.fill();
	}
	
}
