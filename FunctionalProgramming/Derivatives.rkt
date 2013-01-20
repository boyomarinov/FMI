;define simple test function x^3*y^3
(define (productcube x y)
 (* (* x x x) (* y y y))
)

;normal derivative
(define (derive f dx)
  (lambda(x)
    (/ (- (f (+ x dx)) (f x)) dx)
   )
)

;partial derivative by X
(define (deriveX f dx)
  (lambda(x y)
    (/ (- (f (+ x dx) y) (f x y)) dx)
  )
)

;partial derivative by Y
(define (deriveY f dy)
  (lambda(x y)
    (/ (- (f x (+ y dy)) (f x y)) dy)
  )
)

;calculate n-th partial derivative by X
(define (deriveX_nth f n dx)
  (lambda (x y)
    (if(= n 1) ((deriveX f dx) x y)
       ((deriveX (deriveX_nth f (- n 1) dx) dx) x y)
    )
  )
)

;calculate n-th partial derivative by Y
(define (deriveY_nth f n dy)
  (lambda (x y)
    (if(= n 1) ((deriveY f dy) x y)
       ((deriveY (deriveY_nth f (- n 1) dy) dy) x y)
    )
  )
)

;calculate n-th mixed partial derivative (by X and Y)
(define (mixed_derive f m n dx dy)
  (deriveX_nth (deriveY_nth f n dy) m dx)
)