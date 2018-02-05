# Judge Route Circle

Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to **the original place**.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are *R* (Right), *L* (Left), *U* (Up) and *D* (down). The output should be true or false representing whether the robot makes a circle.

###Example 1:
```
Input: "UD"  Output: true
```

###Example 2:
```
Input: "LL"  Output: false
```

## Breakdown
1. El robot puede moverse horizontal y verticalmente
2. Sólo cuando el robot regresa a la posición inicial (0,0) es cuando se considera que ha hecho un círculo
3. *U* representaría un movimiento positivo y *D* representaría un movimiento negativo en *y*
4. *R* representaría un movimiento negatio y *L* representaría un movimiento positivo en *x*
5. Solo cuando el valor final de *x* & *y* sea 0, el robot habrá regresado al origen.

## Algoritmo

```
-> Inicializar los valores x & y en 0
-> Se lee el string de entrada y se hace un loop por cada caracter del string
-> si el caracter es U, se le suma 1 a y.
-> si el caracter es D, se le resta 1 a y.
-> si el caracter es L, se le resta 1 a x.
-> si el caracter es R, se le suma 1 a x.
-> Al terminar el loop revisar si x & y son 0, si es así regresar true, si no lo es, regresar false.
```

## Análisis del Algoritmo

La complejidad de este algoritmo es aproximadamente 2n.
Leer cada caracter del string es n y agregar el valor corresponidente a x o y es 1 cada vez, resultando en n + n.
