;Collection of functions written during exercises
;[FunctionalProgramming - FMI]

;define x^3
(define (cube x)
  (expt x 3)
 )

;calculates sum of two numbers
(define (sum a b)
   (define (iter i sum)
     (cond((> i b) sum)
          (else (iter (+ i 1) (+ sum i)))
     )
   )(iter a 0)
)

;calculates product of two numbers
(define (prod a b)
   (define (iter i sum)
     (cond((> i b) sum)
          (else (iter (+ i 1) (* sum i)))
     )
   )(iter a 1)
)

;(id x)
;>x
;
(define (sum_all a b next term) 
  ;next, term - names which correspond to built-in terms
  (define (helper i res)
    (if(> i b) res
        (helper (next i) (+ res (term i))
               )
    )
  )(helper a 0)
)

;cube
;(define (next x)
;  (cond((even? x) (+ x 3))
;       (else (- x 1))
;  )
);(sum_all 1 100 next cube)


;define function accumulate
(define (accumulate null_value
                    combiner
                    term
                    a
                    next
                    b)
  (define (iter i res)
    (if (> i b) res
        (iter (next i) (combiner res (term i)))
    )
  )(iter a null_value)
)
-------------------------------------------------------------------

;sum (from 1 to 50 hops by 4): (sqrt(i+3))/((i+12)(i*3))

;define next function
(define (next x)
  (+ x 4)
)

;define the term itself
(define (term x)
  (/ (sqrt(+ x 3)) (* (+ x 12) (* x 3)))
)
(accumulate 0 + term 1 next 50)

;define iterative accumulate with predicate
(define (acc_pred null_value comb term a next b pred?)
  (define (iter i res)
    (cond((> i b) res)
         ((pred? i) (iter (next i) (comb res (term i))))
         (else (iter (next i) res))
    )
  )(iter a null_value)
)

;define accumulate with lambda function
(define (accumulate null_value comb term a next b)
  (lambda (param)
          (tialo)
  )
)
(accumulate 0 + (lambda x) a (lambda x) b)
                                (+ x 4)
----------------------------------------------------------
;(inject 5 100 term) (term a (a+1)) a=2 
;takes the first two, than gets their result with the third, etc..

(define (term x y)
  (+ (expt x 2) (sqrt y))
)
(define (next x)
  (+ x 1)
)
(define (id x)
  (+ x 0)
)
(accumulate 0 term id 5 1+ 99)
(define (inject a b term)
  (define (iter i sum)
    (if (> i b) sum
        (iter (+ i 1) (term sum i)))
  )(iter a 0)
)

;this is how we call the function itself
(inject 5 100
    (lambda (a b)
      (+ (* a a) (sqrt b))
    )
)

-------------------------------------------------------
;LET
;let us bind variables to expression before evaluating body of function
(let ((var1 (expr1))
      (var2 (expr2))
      (var3 (let (vari1 (expri1))))
     )(tialo)
)

;pri let* mojem da izpolzvame predi6nite promenlivi koito sme definirali
;LET*
;Difference between let and let* is that we can use the previous variables
;in current example: we could use var1 in expr2
(let* ((var1 (expr1))
      (var2 (expr2))
      )(tialo)












