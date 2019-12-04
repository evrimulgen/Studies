package td7;

import java.awt.Color;

public class FeuTricolore implements Iterable<Color> {
	private final Color[]c={Color.RED,Color.ORANGE,Color.GREEN};
	
	public FeuTricolore(){}
	
	public IterateurColor iterator()
	{
		return new IterateurColor(c);
	}

	
}
