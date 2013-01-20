;find length of a decimal number
(define (num_length x counter)
  (if (= (remainder x (expt 10 counter)) x) counter
     (num_length x (+ counter 1))
  )
)

;alternative function
(define (numlen x counter)
  (if (= (quotient x (expt 10 counter)) 0) counter
     (numlen (quotient x 10) (+ counter 1))
  )
)

;check if number is a palindrome
(define (palindrome? x)
  (define x_length (num_length x 0))
  (define (palindromecheck x counter)
    (cond((and (= counter 1)(not(= (quotient x (expt 10 (- x_length counter))) (remainder x (expt 10 counter))))) #f)
         ((and (> counter 1)(not(= (remainder (quotient x (expt 10 (- x_length counter))) (expt 10 (- counter 1)))
                 (quotient (remainder x (expt 10 counter)) (expt 10 (- counter 1)))))) 
          #f)
         ((= counter (floor(/ x_length 2))) #t)
         (else (palindromecheck x (+ counter 1)))
    )
  )(palindromecheck x 1)
)
