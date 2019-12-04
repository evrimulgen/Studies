package waterGame;

//PlantUML

public class TransferWater implements ICommand {
	int state;
	Can bidon1,bidon2;
	
	public TransferWater(int state,Can bidon1,Can bidon2){
		
	}
	

	public void execute() {
		int gap;
		if(bidon2.isFull()) {
			
		}else {
			gap=bidon2.getCapacity()-bidon2.getLevel();
			bidon1.takeWaterFrom(gap);
			bidon2.setLevel(gap+bidon2.getLevel());
		}
	}

}
