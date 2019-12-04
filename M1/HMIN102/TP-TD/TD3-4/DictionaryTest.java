package dicoTest;

import static org.junit.Assert.assertTrue;

import org.junit.Before;
import org.junit.Test;

public abstract class DictionaryTest {
	
	AbstractDictionary myDictionnary;
	@Before
	public abstract void setUp();
	
	@Test
	public void testAddOneElementToEmptyDico(){
		System.out.println("testAddOneElementToEmptyDico");
		assertTrue(myDictionnary.isEmpty());
		myDictionnary.put("key1","value1");
	    assertTrue(1==myDictionnary.size());
	}
	
	
	@Test
	public void testisEmpty() {
		System.out.println("testisEmpty");
		myDictionnary.put("key2","value2");
		assertTrue(!myDictionnary.isEmpty());
	}
	
	@Test
	public void testContainsKeys() {
		System.out.println("testContainsKeys");
		myDictionnary.put("key3","value3");
		assertTrue(myDictionnary.containsKey("key3"));
	}
	
	@Test
	public void testGet() {
		System.out.println("testGet");
		myDictionnary.put("key4","value4");
		Object stuff = myDictionnary.get("key4");
		assertTrue(stuff.equals("value4"));
	}
}
