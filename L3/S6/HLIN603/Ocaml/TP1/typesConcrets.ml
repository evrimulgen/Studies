(* Q1 *)

type form =
| Top | Bot
| Var of string 
| Neg of form
| And of form * form
| Or of form * form
| Imp of form * form
| Equ of form * form
;;

(* Q2 *)

let rec string_of_form = function
  | Var a ->  a    
  | And(a,b) ->  "(" ^ (string_of_form a) ^ " ^ " ^ (string_of_form b) ^ ")"
  | Or(a,b) ->  "(" ^ (string_of_form a) ^ " v " ^ (string_of_form b) ^ ")"
  | Imp(a,b) ->  "(" ^ (string_of_form a) ^ " -> " ^ (string_of_form b) ^ ")"
  | Equ(a,b) -> "(" ^ (string_of_form a) ^ " <-> " ^ (string_of_form b) ^ ")"
  | Top -> "true"
  | Bot -> "false"
  | Neg a -> "!"^(string_of_form a)
 ;;

(* Q3 le corrigé *)


let simplif_and = function
  | (f, Top) | (Top, f) -> f
  | (_, Bot) | (Bot, _) -> Bot
  | _ -> assert false;;

let simplif_or = function
  | (_, Top) | (Top, _) -> Top
  | (f, Bot) | (Bot, f) -> f
  | _ -> assert false;;

let simplif_imp = function
  | (_, Top) | (Bot, _) -> Top
  | (f, Bot) -> Neg f
  | (Top, f) -> f
  | _ -> assert false;;

let simplif_equ = function
  | (f, Top) | (Top, f) -> f
  | (_, Bot) | (Bot, _) -> Bot
  | _ -> assert false;;

let rec simplif_form = function
  | And (f1, f2) ->
     let f1' = simplif_form f1
     and f2' = simplif_form f2 in
     simplif_and (f1', f2')
  | Or (f1, f2) ->
     let f1' = simplif_form f1
     and f2' = simplif_form f2 in
     simplif_or (f1', f2')
  | Imp (f1, f2) ->
     let f1' = simplif_form f1
     and f2' = simplif_form f2 in
     simplif_imp (f1', f2')
  | Equ (f1, f2) ->
     let f1' = simplif_form f1
     and f2' = simplif_form f2 in
     simplif_equ (f1', f2')
  | f -> f;;

let and_eval = function 
|(true,false)|(false,false)|(false,true)-> false
|(true,true)->true;;


let or_eval = function 
|(true,false)|(false,false)|(true,true)-> true
|(false,false)->false;;


let imp_eval = function 
|(false,true)|(false,false)|(true,true)-> true
|(true,false)->false;;



let equ_eval = function 
|(false,true)|(true,true)-> false
|(true,false)|(false,false)->true;;

let neg_eval  =function
|false->true
|true->false;;


let eval_form l =function
  | And (f1, f2) ->
     let f1' = List.assoc f1 l
     and f2' = List.assoc f2 l in
     and_eval (f1', f2')
  | Or (f1, f2) ->
     let f1' = List.assoc f1 l
     and f2' = List.assoc f2 l in
     or_eval (f1', f2')
  | Imp (f1, f2) ->
     let f1' = List.assoc f1 l
     and f2' = List.assoc f2 l in
     imp_eval (f1', f2')
  | Equ (f1, f2) ->
     let f1' = List.assoc f1 l
     and f2' = List.assoc f2 l in
     equ_eval (f1', f2')
  | Neg(f) ->
      let f' = List.assoc f l in
      neg_eval f'
;;

(* Corrigé *)
(* let rec eval_form l = function
  | Top -> true
  | Bot -> false
  | Var n ->
     (try List.assoc n l
      with Not_found -> failwith (n ^ " not in the assignment!"))
  | Neg f -> not (eval_form l f)
  | And (f1, f2) ->
     let f1' = eval_form l f1
     and f2' = eval_form l f2 in
     f1' && f2'
  | Or (f1, f2) ->
     let f1' = eval_form l f1
     and f2' = eval_form l f2 in
     f1' || f2'
  | Imp (f1, f2) ->
     let f1' = eval_form l f1
     and f2' = eval_form l f2 in
     (not f1') || f2'
  | Equ (f1, f2) ->
     let f1' = eval_form l f1
     and f2' = eval_form l f2 in
     f1' = f2';;
*)


