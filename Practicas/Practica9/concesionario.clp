(deftemplate Preferencia
    (field MaxPrecio (default 13000))
    (field Maletero (allowed-values Pequeño Mediano Grande) (default Grande))
    (field MinCaballos)
    (field ABS (allowed-values Sí No))
    (field MaxConsumo)
)

(deftemplate Modelo
    (field Modelo)
    (field Precio )
    (field Maletero (allowed-values Pequeño Mediano Grande) )
    (field Caballos)
    (field ABS (allowed-values Sí No))
    (field Consumo)
)

(deffacts iniciales
    (Modelo (Modelo 1) (Precio 12000) (Maletero Pequeño) (Caballos 65) (ABS No) (Consumo 4.7))
    (Modelo (Modelo 2) (Precio 12500) (Maletero Pequeño) (Caballos 80) (ABS Sí) (Consumo 4.9))
    (Modelo (Modelo 3) (Precio 13000) (Maletero Mediano) (Caballos 100) (ABS Sí) (Consumo 7.8))
    (Modelo (Modelo 4) (Precio 14000) (Maletero Grande) (Caballos 125) (ABS No) (Consumo 6.0))
    (Modelo (Modelo 5) (Precio 15000) (Maletero Pequeño) (Caballos 147) (ABS Sí) (Consumo 8.5))

     
)

(defrule buscarModelo
    (Preferencia (MaxPrecio ?maxprecio) (Maletero ?maletero) (MinCaballos ?minCaballos) (ABS ?abs) (MaxConsumo ?maxConsumo))
    (Modelo (Modelo ?m) (Precio ?p) (Maletero ?maletero) (Caballos ?caballos) (ABS ?abs) (Consumo ?consumo))
    (test (<= ?p ?maxprecio))
    (test (>= ?caballos ?minCaballos))
    (test (<= ?consumo ?maxConsumo))
    =>
    (printout t "Modelo recomendado " ?m crlf)
)