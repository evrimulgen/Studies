package storage;

import java.util.ArrayList;
import java.util.Collection;

public class Link extends ElementStorage {
	private ArrayList<ElementStorage> references;
	
	public Link (){
		super.basicSize = 0;
		references = new ArrayList<ElementStorage>();
	}
}
