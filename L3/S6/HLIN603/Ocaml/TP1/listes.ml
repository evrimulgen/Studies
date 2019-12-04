let l=[2;3;8;1;5;4;9];;
let rec rev = function
  | [] -> []
  | e :: tl -> (rev tl) @ [e];;

let rec size = function
  | [] -> 0
  | _ :: tl -> 1 + (size tl);;

let rec qtrier = function
  | [] -> true
  | [e]-> true
  | e::lt -> (e < (List.hd lt)) && (qtrier(lt)) ;;

let rec insertion_liste n = function
  | [] -> [n]
  | e::lt ->if (qtrier(lt) && n <= e) then n::e::lt else [e]@(insertion_liste n lt) ;;

let rec tri_insertion = function
 | [] -> []
 | e::lt -> if ((qtrier lt) = true)then insertion_liste e lt else insertion_liste e (tri_insertion lt);;
