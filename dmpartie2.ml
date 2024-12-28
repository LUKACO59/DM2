(*question 7*)
let rec int_of_array l i=
  try
    match l.(i) with
    |true -> 1 + 2* (int_of_array l (i+1))
    |false -> 2* (int_of_array l (i+1)) 
  with
  | _-> 0
;;
(*test
  let l= [|true;false;false;true;true|];;
 int_of_array l 0
*)

let clef k l =
  (k,int_of_array l 0) 
  
  
let l= [|true;false;false;true;true|];;
(*test
  clef 4 l *)