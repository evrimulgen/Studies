package tpTest.foobar;


import org.junit.runner.RunWith;
import org.junit.runners.Suite;


@RunWith(Suite.class)
@Suite.SuiteClasses ({
	TestParametreFoo.class,
	TestFooBar.class,
	Mytest.class
})
public class TestSuites{}

