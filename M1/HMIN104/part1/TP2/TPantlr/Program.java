import java.util.*;
import java.lang.System;
import static java.lang.Integer.parseInt;

/**********/
/*  TYPE  */
/**********/

abstract class Type {
    abstract Object eval();
}

class Integer extends Type {
    Object eval(){
        return 0;
    }
}

class Boolean extends Type {
    Object eval(){
        return false;
    }
}

class Array extends Type {
	Type elements;
    int size;

	Array (Type elements) {
		this.elements = elements;
        this.size=0;
	}

    void ArraySetSize(int n){
        this.size=n;
    } 


    int ArrayGetSize(){
        return this.size;
    } 

    Object eval(){
        return elements; 
    }
}

/**********/
/*  EXPR  */
/**********/

abstract class Expr {
    abstract Object eval();	
}

class Cte extends Expr {
	int val;

	Cte (int val) {
		this.val = val;
	}

	Object eval() {
	   return val;
	}
}

class Fls extends Expr{
    Object eval(){
        return 0;
    }
}

class Tre extends Expr{
    Object eval(){
        return 1;
    }
}

class Var extends Expr{
    String name;
     Var(String name){
        this.name = name;
     }

     Object eval(){
        return name;
     }
}

/*********/
/*  UOP  */
/*********/

class Not extends Expr {
	Expr e;

	Not (Expr e) {
		this.e = e;
	}

	Object eval() {
	   return !(boolean)e.eval();
	}
}

class Inv extends Expr {
	Expr e;

	Inv (Expr e) {
		this.e = e;
	}

	Object eval() {
	   return -(int)e.eval();
	}
} 

/*********/
/*  BOP  */
/*********/

abstract class BinOp extends Expr {
    Expr e1, e2;
}

/*abstract class BinOPArth extends BinOp{
    int eval();
}

abstract class BinOpComp extends BinOp{
    boolean eval();
}
*/
class Add extends BinOp {
    Add (Expr e1, Expr e2) {
        this.e1 = e1;
        this.e2 = e2;
    }

    Object eval () {
        return (int)e1.eval() + (int)e2.eval();
    }
}

class Sub extends BinOp {
    Sub (Expr e1, Expr e2) {
        this.e1 = e1;
        this.e2 = e2;
    }

     Object eval () {
         return (int)e1.eval() - (int)e2.eval();
    }
}

class Mul extends BinOp {
    Mul (Expr e1, Expr e2) {
        this.e1 = e1;
        this.e2 = e2;
    }

     Object eval () {
         return (int)e1.eval() * (int)e2.eval();
     }
}

class Div extends BinOp {
    Div (Expr e1, Expr e2) {
        this.e1 = e1;
        this.e2 = e2;
    }

     Object eval () {
         return (int)e1.eval() / (int)e2.eval();
    }
}

class And extends BinOp {
    And (Expr e1, Expr e2) {
        this.e1 = e1;
        this.e2 = e2;
    }

     Object eval () {
         return ((boolean)e1.eval() && (boolean)e2.eval());
     }
}

class Or extends BinOp {
    Or (Expr e1, Expr e2) {
        this.e1 = e1;
        this.e2 = e2;
    }

     Object eval () {
         return ((boolean)e1.eval() || (boolean)e2.eval());
     }
}

class Lt extends BinOp {
    Lt (Expr e1, Expr e2) {
        this.e1 = e1;
        this.e2 = e2;
    }

     Object eval () {
         return ((int)e1.eval() < (int)e2.eval());
     }
}

class Le extends BinOp {
    Le (Expr e1, Expr e2) {
        this.e1 = e1;
        this.e2 = e2;
    }

     Object eval () {
         return ((int)e1.eval() <= (int)e2.eval());
     }
}

class Eq extends BinOp {
    Eq (Expr e1, Expr e2) {
        this.e1 = e1;
        this.e2 = e2;
    }

     Object eval () {
         return ((int)e1.eval() == (int)e2.eval());
     }
}

class Ne extends BinOp {
    Ne (Expr e1, Expr e2) {
        this.e1 = e1;
        this.e2 = e2;
    }

     Object eval () {
         return ((int)e1.eval() != (int)e2.eval());
     }
}

class Gt extends BinOp {
    Gt (Expr e1, Expr e2) {
        this.e1 = e1;
        this.e2 = e2;
    }

     Object eval () {
         return (int)e1.eval() > (int)e2.eval();
     }
}

class Ge extends BinOp {
    Ge (Expr e1, Expr e2) {
        this.e1 = e1;
        this.e2 = e2;
    }

    Object eval () {
        return (int)e1.eval() >= (int)e2.eval();
    }
}

/*****************/
/*  CALLS  */
/*****************/

abstract class Call {
    abstract void eval();
}

class Read extends Call {
    void eval(){
        System.in.read();
    }
}

class Write extends Call {
    void eval(){
        System.out.println();
    }
}
class User extends Call {

    String name;

    User (String name) {
        this.name = name;
    }//User

    void eval(){
        System.out.println(this.name);
    }
}//User

class FunCall extends Expr {

    Call call;
    ArrayList<Expr> args;

    FunCall (Call call, ArrayList<Expr> args) {
        this.call = call;
        this.args = args;
    }

    Object eval(){
        call.eval();
        for(Expr e: args)
             e.eval();
    }
}


class ArrayGet extends Expr {

    Expr arr, index;

    ArrayGet (Expr arr, Expr index) {
        this.arr = arr;
        this.index = index;
    }

    Object eval(){
        //return (array)arr.eval()[(int)index.eval()];
        return arr.eval();
    }
}

class ArrayAlloc extends Expr {

    Type type;
    Expr size;

    ArrayAlloc (Type type,Expr size) {
        this.type = type;
        this.size = size;
    }

    Object eval(){
        Array tableau = new Array(type);
        tableau.ArraySetSize((int)size.eval());
        return tableau;
    }
}


/*****************/
/*  INSTRUCTION  */
/*****************/

abstract class Instruction {
    abstract void eval();
}

class Assign extends Instruction {
	String name;
	Expr val;

	Assign (String name, Expr val) {
		this.name = name;
		this.val  = val;
	}

    void eval(){
       Var variable = new Var(name); 
       System.out.println(variable.eval()+":="+val.eval()); 
    }
}

class ArraySet extends Instruction {
	Expr arr, index, val;

	ArraySet (Expr arr, Expr index, Expr val) {
		this.arr   = arr;
		this.index = index;
		this.val   = val;
	}

    void eval(){
        arr.eval();index.eval();val.eval(); 
    }
}

class Cond extends Instruction {
	Expr cond;
	Instruction i1, i2;

	Cond (Expr cond, Instruction i1, Instruction i2) {
		this.cond = cond;
		this.i1   = i1;
		this.i2   = i2;
	}

    void eval(){
        if((boolean)cond.eval()) i1.eval() ; else i2.eval();
    }
}

class While extends Instruction {
	Expr cond;
	Instruction i;

	While (Expr cond, Instruction i) {
		this.cond = cond;
		this.i    = i;
	}

    void eval(){
        while ((boolean)cond.eval())
            i.eval();
    }
}

class ProcCall extends Instruction{

    Call call;
    ArrayList<Expr> args;

    ProcCall(Call call, ArrayList<Expr> args){
        this.call = call;
        this.args = args;
    }

    void eval(){
        call.eval();
        for(Expr e:args)
            e.eval();
    }
}

class Skip extends Instruction {
    void eval(){
        System.out.println("Skip \n");
    }
}

class Seq extends Instruction {
	Instruction i1, i2;

	Seq (Instruction i1, Instruction i2) {
		this.i1 = i1;
		this.i2 = i2;
	}

    void eval(){
        i1.eval();
        i2.eval();
    }
}

/****************/
/*  DEFINITION  */
/****************/

class Pair<L,R> {
	final L left;
	final R right;

	public Pair(L left, R right) {
		this.left  = left;
		this.right = right;
	}
}

abstract class Definition {
    String name;
    ArrayList<Pair<String,Type>> args, locals;
    Instruction code;

    abstract void eval();

}

class Function extends Definition {
	Type ret;

	Function (String name, ArrayList<Pair<String,Type>> args,ArrayList<Pair<String,Type>> locals, Instruction code,Type ret) {
		this.name = name;
        this.args = args;
        this.locals = locals;
        this.code = code;
        this.ret = ret;
	}

    void eval(){
        User user = new User(name);
        user.eval();
        for(Pair<String,Type> e: args)
                e.right.eval();
        for(Pair<String,Type> e: locals)
                e.right.eval();  
        code.eval();
        ret.eval();
    }
}

class Procedure extends Definition {
    

     Procedure(String name, ArrayList<Pair<String,Type>> args,ArrayList<Pair<String,Type>> locals, Instruction code) {
        this.name = name;
        this.args = args;
        this.locals = locals;
        this.code = code;
    }

    void eval(){
        User user = new User(name);
        user.eval();
        for(Pair<String,Type> e: args)
                e.right.eval();
        for(Pair<String,Type> e: locals)
                e.right.eval();  
        code.eval();
    }
}

/*************/
/*  PROGRAM  */
/*************/

class Program {
	ArrayList<Pair<String,Type>> globals;
	ArrayList<Function> funcs;
	Instruction code;

	Program (ArrayList<Pair<String,Type>> globals, ArrayList<Function> funcs, Instruction code) {
		this.globals = globals;
		this.funcs   = funcs;
		this.code    = code;
	}

    Void eval(){
        for(Pair<String,Type> e :globals)
            e.right.eval();
        for(Function f: funcs)  
            f.eval();
        code.eval();
    }
} 