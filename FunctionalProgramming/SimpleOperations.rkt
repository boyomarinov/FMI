;define a by power of b
(define (pow a b)
  (define (iter i res)
    (if (> i b) res
        (iter (+ i 1) (* res a)))
  )(iter 1 1)
)

;division of two number
(define (divide? a b)
  (= (remainder a b) 0)
)

;count divisors of a number
(define (divisors_count num)
  (define (iter i res)
    (cond((> i (/ num 2)) res)
         ((= (remainder num i) 0) (iter (+ i 1) (+ res 1)))
         (else (iter (+ i 1) res))
    )
  )(iter 1 1)
)

;count divisort of a number in a specific interval
(define (div_count_interval num a b)
  (define (iter i res)
    (cond((> i b) res)
         ((divide? num i) (iter (+ i 1) (+ res 1)))
         (else (iter (+ i 1) res))
    )
  )(iter a 1)
)

;check if number is prime
(define (prime? num)
  ( = (divisors_count num) 2)
)

;write prime numbers from a to b
(define (list_primes a b)
  (define (iter i res))
)
