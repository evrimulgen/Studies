;1-lambda-expressions
((lambda (x) (+ (* 2 x) 3)) 4) 
;11
((lambda (x y) (* (+ x 2) (+ y 6))) 7 8) 
;126
((lambda (v) ((lambda (x) (* 3 x)) (+ v 2))) 8) 
;30
((lambda (v) ((lambda (x) (* v x)) (+ v 2))) 8)
;80
((lambda (v) ((lambda (v) (* 3 v)) (+ v 2))) 8)
;30
((lambda (x y z) (+ (* x y) (* y z))) 2 3 4)
;18
((lambda (x y) (* x x y y)) 4 )
; Too few arguments (1 instead of at least 2) given to :LAMBDA
((lambda (x) (* x x 2)) 4 5)
; trop d'arguments pour :LAMBDA
(lambda (x) (* x x 2))
;#<FUNCTION :LAMBDA (X) (* X X 2)>


;2-fonctions globales
(defun f (x) (+ 3 x))
;F
(defun g (v) (* 5 (f (+ v 2))))
;G
(g 8)
;65

;cette fois on remplace la définition de f par la suivante 
(defun f (x) (+ v x))
;F
(g 8)
; variable V has no value

;fonctions numériques courantes 
(defun fact (n)
	(if (= n 0)
		1
		(* n (fact (- n 1)))))

(defun fibo (n)
		(cond 
			((= n 0) 0) 
			((= n 1) 1)
			(T (+ (fibo (- n 1)) (fibo (- n 2)) )) 
		)	
)

;3-les listes et les cellules
(CAR ())
;NIL
(CDR ())
;NIL
(CAR (()))
;NIL
(CDR (()))
;NIL
(CAR ((())))
;NIL
(CDR ((())))
;NIL
(equal (CAR ()) (CDR ()))
;T
(equal (CAR '(())) (CDR '(())) ) 
;T
(equal (CAR '('(()))) (CDR '('(()))) )
;NIL
(CAR '(1 2 3 4))
;1
(CDR '(1 2 3 4))
;(2 3 4)
'(() . ())
;(NIL)

;de combien de cellules sont faites les listes
;(1 2 3 4)
;(1 (2 3) 4) 
;(1 (2) (3) 4) 
(cons 1 '(2 3 4))
;(1 2 3 4) 1 doublet
(cons 1 (cons '(2 3) '(4))
;(1 (2 3) 4)   2 doublets
(list 1 (cons 2 '()) (cons 3 '() ) 4) 			
(cons 1 (cons '(2) (cons '(3) '(4)) ))
;(1 (2) (3) 4) 3 doublets

;4-fonctions sur les listes plates
;(defun member (x l) 
;	(if (= (CAR l) x) (CDR l) (member x (CDR l) )) )

(defun member_test (x l) 
	(cond
		((null l) '())
		((=  x  (CAR l)) (CDR l))
		(T (member_test x (CDR l) ) )
	)
)	

(defun length_test (l)
	(cond
		((null l) 0)
		(T (+ 1 (length_test (CDR l))))
	)
)


(defun last_test (l) 
	(cond
		((null l) nil)
		((null (CDR l))  (CAR l))
		(T (last_test (CDR l) ))
	)
)	
