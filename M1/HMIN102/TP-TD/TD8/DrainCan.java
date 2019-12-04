package waterGame;

public class DrainCan implements ICommand {
	int state;
	Can bidon;
	
	public DrainCan(int state,Can bidon){
		
	}
	
	public void execute() {
		bidon.setLevel(0);
		bidon.drain();
	}

}
