;1Paramètres optionnels et APPLY
(defun test (x y)
	(eql x y)
)

(defun member_test (x l &key (test #'eql))	
	(cond
			((null l) '())
			((apply #'test  x  (CAR l)) (CDR l))
			(T (member_test x (CDR l) ) )
	)
)

(defun assoc_test (x l)
	(cond
		((null l) '())
		((eql (CAR (CAR l)) x) (CAR l))
		(T (assoc_test x (CDR l)))
	)
)

(defun assoc_test (x l &key test)
	(cond
		((null l) '())
		((apply #'test (CAR (CAR l)) x) (CAR l))
		(T (assoc_test x (CDR l)))
	)
)

	
 (assoc 'b (list (cons 'a 1) (cons 'b 2) (cons 'c 3) (cons 'd 4) (cons 'e 5)))

;2fonctions d'arité variable et APPLY
(defun append_test1 (l &rest ll)
	(if (null ll)
		l
		(if (null l)
			(apply #'append_test ll)
			(cons (car l)	(apply #'append_test (cdr l) ll))
		)
	)
)

(defun append_test2 (l &rest ll)
		(labels ((app_r (l ll)
			(if (null ll)              ; test d’arrêt sur ll
				l
				(if (atom l)
					(app_r (car ll) (cdr ll))						; test d’arrêt sur l
					(cons (car l) (app_r (cdr l) ll))
				)
			)))
		(app_r l ll))
)

(defun list_test (l &rest ll)
	(if(null ll)	
		l
		(if (null l)
			(apply #'list_test ll)
			(cons (car l)	(apply #'list_test (cdr l) ll))	
		)
	)	
)	

;3Fonctions destructives sur les listes
;version destructive de remove --- delete_test 
(defun delete_test (x ll)
	(if (atom ll)
		ll
		(if (eql x (car ll))
			(delete_test x (cdr ll))
			(progn (setf (cdr ll) (delete_test x (cdr ll))) ll)
		)

	)
)
;version destructive de subst --nsubst
;version destructive de reverse --nreverse


;en 1 er implementer la VM et l tester avec de l'assembleur génété à la main puis il faut faire la génération de code
