(define StudentList `((Ivan . (4 2 2 5))
                      (Maria . (3 5 4 6))
                      (George . (6 6 5 6)))
)

;search in asociative array
(define (SearchAnd..Evaluate key Alist)
  (define (sum L)
    (if (null? L) 0
      (+ (car L) (sum (cdr L)))
    )
)
  (let ((result (assq key AList)))
    (if(null? result) (display "Student not found")
       (/ (sum (cdr result)) (length (cdr result)))
    )
  )
)