package tpTest.foobar;

import org.junit.Before;
import org.junit.Test;


public class Mytest {
	SUT sut;

	@Before
	public void setUp() throws Exception {
		sut=new SUT();
	}
	
	@Test(expected = FooBarException.class)
	public void foobarTest() throws FooBarException
	{
		sut = new SUT(-1,2,3);
		sut.foobar();
	}
	
}
