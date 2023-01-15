(deffacts iniciales
    (ubicacion A norte D)
    (ubicacion B norte E)
    (ubicacion C norte F)
    (ubicacion D norte G)
    (ubicacion E norte H)
    (ubicacion F norte I)
    

    (ubicacion A oeste B)
    (ubicacion B oeste C)
    (ubicacion D oeste E)
    (ubicacion E oeste F)
    (ubicacion G oeste H)
    (ubicacion H oeste I)


    
)

(defrule inicio
    (declare (salience -9))
    ?f1 <- (situacion ?x ?y)
    (ubicacion ?x ?u ?y)
    =>
    (printout t ?x " esta al " ?u " de " ?y crlf)
    (retract ?f1)
)

(defrule inversoNorte
    (ubicacion ?x norte ?y)
    =>
    (assert(ubicacion ?y sur ?x))
)

(defrule inversoOeste
    (ubicacion ?x oeste ?y)
    =>
    (assert(ubicacion ?y este ?x))
)

(defrule transitividad
    (declare (salience -2))
    (ubicacion ?x ?u ?y)
    (ubicacion ?y ?u ?z)
    =>
    (assert(ubicacion ?x ?u ?z))
)

(defrule norOeste

    (ubicacion ?x norte ?y)
    (ubicacion ?y oeste ?z)
    =>
    (assert(ubicacion ?x noroeste ?z))
    (assert(ubicacion ?z sureste ?x))
)

(defrule norEste
    (declare (salience -1))
    (ubicacion ?x norte ?y)
    (ubicacion ?y este ?z)
    =>
    (assert (ubicacion ?x noreste ?z))
    (assert (ubicacion ?z suroeste ?x))
)
