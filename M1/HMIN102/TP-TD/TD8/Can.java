package waterGame;

public class Can {
	private int level;
	private int capacity;
	// true if full else (empty) false 
	
	public Can(int l,int c) {
		level=l;
		capacity=c;
	}

	public int getLevel() {
		return level;
	}

	public void setLevel(int level) {
		this.level = level;
	}

	public int getCapacity() {
		return capacity;
	}

	public void setCapacity(int capacity) {
		this.capacity = capacity;
	}

	public boolean isFull() {
		return (this.level == this.capacity);
	}
	
	public void fill() {
		this.level=this.capacity;
	}
	
	public void drain() {
		this.level=0;
	}
	
	public void takeWaterFrom(int l) {
		this.level-=l;
	}

	public void action() {
		
	}
	
}
