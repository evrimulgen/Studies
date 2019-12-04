package dicoTest;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class FastDictionaryTest  extends DictionaryTest {


	@Before
	public void setUp() {
		super.myDictionnary = new FastDictionary(1);
	}
	
	@Test
	public void testAddOneElementToEmptyDico(){
		super.testAddOneElementToEmptyDico();
	}

	@Test
	public void testisEmpty() {
		super.testisEmpty();
	}
	
	@Test
	public void testContainsKeys() {
		super.testContainsKeys();
	}

	@Test
	public void testGet() {
		super.testGet();
	}
	
}
