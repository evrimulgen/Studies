package td1;

public class ExpressionComplexe extends Expression {

	private Expression c1,c2;
	private String op;
	
	public ExpressionComplexe(Expression n1,String o,Expression n2){
		this.c1=n1;
		this.c2=n2;
		this.op=o;
		
	}
	
	public double eval(){
		switch  (op){
		case "+":return c1.eval()+c2.eval();
		case "-":return c1.eval()-c2.eval();
		case "*":return c1.eval()*c2.eval();
		case "/":if(c2.eval() != 0.0) return c1.eval()/c2.eval();
		default : return 0.0;
		}
		
	}
	
	
}
