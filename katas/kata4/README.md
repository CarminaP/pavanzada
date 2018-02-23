# Valid Number

Validate if a given string is numeric.

Some examples:

```
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
```

## Breakdown
1. Se puede usar el punto una sola vez y tiene que tener números después.
2. No puede haber espacio entre numeros.
3. Se puede usar e una sola vez, tiene que tener números antes y despues y no puede haber punto despues o justo antes de el.
4. Solo puede haber comas despues de cada 3 numeros consecutivos (se puede usar un count de numeros y mod 3)

## Algoritmo

```
-> Se tiene un booleano que revisa si ya hubo un punto o e, si se dejan de admitir comas y si lo que se tiene en cierto punto es numero o no
-> Se lee el string de entrada y se hace un loop por cada caracter del string
-> Por cada numero, mientras se admitan comas, se cuentan para revisar al final las comas, en este punto el valor se considera numero.
-> Si el caracter es un punto, es el primero en aparecer, no le precede una e y no esta justo despues de una coma, cambiar el valor que revisa el punto a true, dejar de permitir comas y en este punto no es un numero, debe ser seguido por un numero.
-> Si el caracter es una e, es el primero en aparecer, le precede un numero y no esta justo despues de una coma o punto, cambiar el valor que revisa e a true, dejar de permitir comas y en este punto no es un numero, debe ser seguido por un numero.
-> Si el caracter es una coma, le precede un numero y esta permitido que existan comas en este punto, contar para revisar al final, en este punto no es numero, debe ser seguido por un numero.
-> Si ninguno de los casos aplican, el string no es numero y se regresa 'False'
-> Al terminar el loop revisar si hubo comas, si este fue el caso se revisa si el numero de comas contadas es congruente con el valor del numero.
-> Si no hubo comas, revisar el valor que revisa si es numero y regresar 'False' o 'True' acorde.
```

## Análisis del Algoritmo

La complejidad de este algoritmo es aproximadamente 3n.
Leer cada caracter del string es n y en cada caso, si aplica hace al menos 2 operaciones, resultando en n + 2n.
