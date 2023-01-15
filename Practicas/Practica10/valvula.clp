(deftemplate valvula
    (slot nombre)
    (slot presion (default 0))
    (slot estado  (allowed-values abierta cerrada)(default cerrada))
    (slot T1 (default 0))
    (slot T2 (default 0))
)

(deffacts Iniciales
    (valvula (nombre Entrada) (T1 101) (T2 35) (presion 1))
    (valvula (nombre Salida) (T1 101) (T2 155) (presion 5))
    (valvula (nombre Pasillo1) (T1 99) (T2 37) (estado cerrada))

)

(defrule R1
    (valvula (estado abierta ))
)