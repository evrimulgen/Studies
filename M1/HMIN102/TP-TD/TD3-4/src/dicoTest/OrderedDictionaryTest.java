package dicoTest;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;




/*
 * @Test
 * public void tes1(){
 * 	try{
 * 		a.m(); // méthode qui doit lever une exception
 * 		fail("should catch an exception");	
 * 	}catch(Exception e){
 * 		AssertTrue(e.getMessage().contains("issue in m()..."));
 * 		}
 * }
 * 
 * 
 */
public class OrderedDictionaryTest extends DictionaryTest {


	@Before
	public void setUp() {
		super.myDictionnary = new OrderedDictionary(1);
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
