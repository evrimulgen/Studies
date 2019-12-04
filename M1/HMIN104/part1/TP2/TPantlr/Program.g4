grammar Program;


prgm returns[Program value] : 'var' vars=varDecl funcs=listFunction code=instruction
								  { $value=new Program($vars.value,$funcs.value,$code.value);} ;


listFunction returns [ ArrayList <Function> value ]
@init { $value = new ArrayList <Function>();}:
( e=function {$value.add($e.value);})*;								  

varDecl returns [ArrayList<Pair<String,Type>> value] 
@init { $value =new ArrayList<Pair<String,Type>>();}:
(name=Char+ ':' kind=type)+{$value.add(new Pair($name,$kind.value));} ; 

function returns [Function value] : (name=funCall '(' args=arguments ')' ':' ret=type) localVars=varDecl code=instruction
{$value = new Function($name.text,$args.value,$localVars.value,$code.value,$ret.value);};


arguments returns [ArrayList<Pair<String,Type>> value] 
@init { $value =new ArrayList<Pair<String,Type>>();}:
(name=Char+ ':' kind=type)*{$value.add(new Pair($name,$kind.value));} ; 

expressions returns [ArrayList <Expr> value]
@init{$value =new ArrayList<Expr>();}:
(expression= expr{ $value.add($expression.value);})*;

instruction returns [Instruction value]:
			  name=Char+ ':=' x1=expr 									{$value = new Assign($name.text,$x1.value); }
			| x2=expr '[' x3=expr ']' ':=' x4=expr 						{$value = new ArraySet($x2.value,$x3.value,$x4.value); }
			| 'if' x5=expr 'then' i1=instruction 'else' i2=instruction  {$value = new Cond($x5.value,$i1.value,$i2.value); }
			| 'while' x6=expr 'do' i3=instruction 						{$value = new While($x6.value,$i3.value); }
			| c1=call '(' x7=expressions ')'							{$value = new ProcCall($c1.value,$x7.value);}
			|  WS                                                       {$value = new Skip();}                 
			| i4=instruction ';' i5=instruction 						{$value = new Seq($i4.value,$i5.value);};

/*
expr returns [Expr value] : 
	  '-'   e1 = expr {$value = new Inv($e1.value);}
	| 'not' e2 = expr {$value = new Not($e2.value);}
	| e3  = expr '+'   e4  = expr {$value = new Add($e3.value, $e4.value);}
	| e5  = expr '-'   e6  = expr {$value = new Sub($e5.value, $e6.value);}
	| e7  = expr '*'   e8  = expr {$value = new Mul($e7.value, $e8.value);}
	| e9  = expr '/'   e10 = expr {$value = new Div($e9.value, $e10.value);}
	| e11 = expr 'and' e12 = expr {$value = new And($e11.value, $e12.value);}
	| e13 = expr 'or'  e14 = expr {$value = new Or($e13.value, $e14.value);}
	| e15 = expr '<'   e16 = expr {$value = new Lt($e15.value, $e16.value);}
	| e17 = expr '<='  e18 = expr {$value = new Le($e17.value, $e18.value);}
	| e19 = expr '='   e20 = expr {$value = new Eq($e19.value, $e20.value);}
	| e21 = expr '!='  e22 = expr {$value = new Ne($e21.value, $e22.value);}
	| e23 = expr '>='  e24 = expr {$value = new Gt($e23.value, $e24.value);}
	| e25 = expr '>'   e26 = expr {$value = new Ge($e25.value, $e26.value);}
	| Number  { $value= new Cte(Integer.parseInt($Number.text)) ;}
	| c2 = Boolean { if($c2.text == "true") $value = new Tre();else $value=new Fls();} 
	| c3 = Char    {$value = new Var($c3.text);}
	| d1=call '(' (d2=expr)* ')'
	 {	ArrayList<Expr> args = new ArrayList<Expr>();
	 	args.add($d2.value);
	 	$value=new FunCall(new User($d1.text),args);
	 }
	 | e27=expr '[' e28=expr ']' {$value=new ArrayGet($e27.value,$e28.value);}
	 | 'new array of' t1=type '[' e29=expr ']'
	 {  Type newType; 
	 	if ($t1.text == "integer")newType = new Integer();
        else newType = new Boolean();
	    $value=new ArrayAlloc(newType,$e29.value);
	 };
*/

expr returns [Expr value] :
  e = additionExpr {$value = $e.value;} ;

comparaisonExpr  returns [Expr value] :
	e1=atomExpr {$value = $e1.value;}
	('<'  e2 = atomExpr {$value = new Lt($value, $e2.value);}
	 |'<='e3 = atomExpr {$value = new Le($value, $e3.value);}
	 |'>' e4 = atomExpr {$value = new Gt($value, $e4.value);}
	 |'>='e5 = atomExpr {$value = new Ge($value, $e5.value);}
	 |'=='e6 = atomExpr {$value = new Eq($value, $e6.value);}
	 |'!='e7 = atomExpr {$value = new Ne($value, $e7.value);})*;

logicalExpr returns [Expr value] :
e1=atomExpr {$value = $e1.value;}
	('and'  e2 = atomExpr {$value = new And($value, $e2.value);}
	 |'or'e3 = atomExpr {$value = new Or($value, $e3.value);})*;


additionExpr returns [Expr value] :
  e1 = multiplyExpr {$value = $e1.value;}
  ('+' e2 = multiplyExpr {$value = new Add($value, $e2.value);}
  | '-' e2 = multiplyExpr {$value = new Sub($value, $e2.value);})* ;


multiplyExpr returns [Expr value] :
  e1 = atomExpr {$value = $e1.value;}
  ('*' e2 = atomExpr {$value = new Mul($value, $e2.value);}
  | '/' e2 = atomExpr {$value = new Div($value, $e2.value);})* ;


atomExpr returns [Expr value] 
  : c=Number {$value = new Cte($c.int);}
  | '('  e1 = additionExpr ')' {$value = $e1.value;}
  | 'not'e2 = atomExpr {$value = new Not($e2.value);}
  | '-'  e3 = atomExpr {$value = new Inv($e3.value);} ;

call returns [Call value]: 'read'   {$value = new Read();}
						 | 'write'  {$value = new Write();}
						 | funCall  {$value = new User($funCall.text);};

funCall  : Char ;

type returns[Type value]  : 'integer'{$value = new Integer();}
 							| 'boolean'{$value = new Boolean();}
 							| 'array of' t=type{$value = new Array($t.value);}; 
Boolean : 'true'|'false';

Char    : 'a'..'z' | 'A'..'Z' ;
Number  : '0'..'9'+ ;

// Ignore all white space characters
WS : [\t\r\n]+ -> skip ; 