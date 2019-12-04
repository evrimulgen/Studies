type form =
  | Top | Bot | Var of string | Neg of form
  | Et of form * form| Ou of form * form|Imp of form * form;;


let rec string_of_form = function
  | Var a ->  a    
  | Et(a,b) ->  "(" ^ (string_of_form a) ^ " /\" ^ (string_of_form b) ^ ")"
  | Ou(a,b) ->  "(" ^ (string_of_form a) ^ " \" ^ (string_of_form b) ^ ")"
  | Imp(a,b) ->  "(" ^ (string_of_form a) ^ "->" ^ (string_of_form b) ^ ")"
  | Top -> "true"
  | Bot -> "false"
  | Neg a -> "!"^(string_of_form a)
 ;;
