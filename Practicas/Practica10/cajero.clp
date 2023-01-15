(defglobal ?*YEAR* = 2023)
(defglobal ?*LIMITE* = 900)
(deffunction Dec(?num)
     (- ?num 1)
)

(deffunction Resta(?num1 ?num2)
    (- ?num1 ?num2)
)
(deftemplate Usuario
    (slot DNI)
    (slot Pin)
    (slot Dinero (default 0))
)
(deftemplate Tarjeta
    (slot Pin )
    (slot DNI)
    (slot Intentos (default 3))
    (slot LimiteDinero (default 5000))
    (slot Fecha (default 2023))
    (slot Validada (default No) (allowed-values Si No))
)

(deftemplate Cuenta
    (slot DNI)
    (slot Saldo)
    (slot Estado (allowed-values EnPantalla dineroEntregado Inicial SuperaLimite SinSaldo) (default Inicial))
)

(deffacts Iniciales
    (Tarjeta (DNI 123456) (Pin 1212) (Intentos 3) (LimiteDinero 500) (Fecha 2026))
    (Tarjeta (DNI 456456) (Pin 4545) (Intentos 3) (LimiteDinero 500) (Fecha 2026))
    (Tarjeta (DNI 000111) (Pin 0011) (Intentos 0) (LimiteDinero 500) (Fecha 2026))
    (Cuenta (DNI 123456) (Saldo 5000))
    (Cuenta (DNI 456456) (Saldo 33))
    (Cuenta (DNI 000111) (Saldo 30000))
)

(defrule Supera_Intentos
    (declare (salience 10))
    (Tarjeta (DNI ?dni) (Intentos 0) (Validada No))
    (Usuario (DNI ?dni))
    =>
    (printout t "No te quedan intentos" crlf)
)

(defrule Pin_Invalido
    ?u <-(Usuario (DNI ?dni) (Pin ?pin1))
    ?t <- (Tarjeta (DNI ?dni) (Pin ?pin2) (Intentos ?intentos) (Validada No)) 
    (test (neq ?pin1 ?pin2))
    (test (> ?intentos 0))
    =>
    (modify ?t (Intentos (Dec ?intentos)))
    (retract ?u)
    (printout t "Pin Invalido" crlf)
)

(defrule Valida_Tarjeta
    ?t<-(Tarjeta (DNI ?dni) (Intentos ?intentos)(Fecha ?fecha)(Pin ?pin) (Validada No))
    (Usuario (DNI ?dni) (Pin ?pin))
    (test (> ?intentos 0))
    (test (>= ?fecha ?*YEAR*))
    =>
    (modify ?t (Validada Si))
)

(defrule Muestra_Saldo
    (Tarjeta (DNI ?dni) (Validada Si))
    ?c<-(Cuenta (DNI ?dni)(Saldo ?saldo)(Estado Inicial))
    =>
    (printout t "Saldo de la cuenta: " ?saldo crlf)
    (modify ?c(Estado EnPantalla))
)

(defrule Saldo_NoSuficiente
    ?c<-(Cuenta (DNI ?dni)(Saldo ?saldo)(Estado EnPantalla))
    (Tarjeta (DNI ?dni) (Validada Si))
    (Usuario (DNI ?dni)(Dinero ?d))
    (test (> ?d ?saldo))
    =>
    (printout t "Sin Saldo" crlf)
    (modify ?c(Estado SinSaldo))
)

(defrule Comprueba_Limite1
    ?c<-(Cuenta (DNI ?dni) (Estado EnPantalla))
    (Tarjeta (DNI ?dni) (Validada Si))
    (Usuario (DNI ?dni)(Dinero ?d))
    (test (> ?d ?*LIMITE*))
    =>
    (printout t "Supera Limite Banco" crlf)
    (modify ?c(Estado SuperaLimite))
)

(defrule Comprueba_Limite2
    ?c<-(Cuenta (DNI ?dni) (Estado EnPantalla))
    (Tarjeta (DNI ?dni) (Validada Si) (LimiteDinero ?limite))
    (Usuario (DNI ?dni)(Dinero ?d))
    (test (> ?d ?limite))
    =>
    (printout t "Supera Limite Tarjeta" crlf)
    (modify ?c(Estado SuperaLimite))
)

(defrule Entrega_Saldo
    (declare (salience -10))
    ?c<-(Cuenta (DNI ?dni) (Estado EnPantalla) (Saldo ?saldo))
    (Tarjeta (DNI ?dni) (Validada Si))
    ?u<-(Usuario (DNI ?dni)(Dinero ?d))
    =>
    (modify ?c(Saldo (Resta ?saldo ?d)) (Estado dineroEntregado))
    (printout t "Retirado " ?d crlf)
)

(defrule Interfaz
    (declare (salience 99))
;; no hay condiciones en el antecedente
    =>
    (printout t "Escriba su DNI ")
    (bind ?id (read))
    (printout t "Escriba su PIN ")
    (bind ?pin (read))
    (printout t "Escriba el importe que desea retirar ")
    (bind ?d (read))
    (assert (Usuario (DNI ?id) (Pin ?pin) (Dinero ?d)))
)
