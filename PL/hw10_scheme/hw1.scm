(define (T n)
	(
		if(= (modulo n 2) 1) ( / (+ (* 3 n) 1) 2 ) (/ n 2)
	)
)


(define (T-iterate k n)
	(
		if(= k 0) n 
		(	
			T( T-iterate (- k 1)  n ) 
		)
	)
)


(define (Trajectory-head n k)
	(
		if (= k 0) (list n)
		(
			cons n (Trajectory-head (T n)(- k 1))
		)
	)
)

(define (Trajectory-to-1 n)
	(
		if (= (T n) 1) (cons n (list (T n))) 
		(
			cons n (Trajectory-to-1(T n))
		)
	)
)    
