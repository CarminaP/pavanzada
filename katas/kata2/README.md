# Strong Password Checker

A password is considered strong if below conditions are all met:
1. It has at least 6 characters and at most 20 characters.
2. It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
3. It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).

Write a function *strongPasswordChecker(s)*, that takes a string *s* as input, and return the **MINIMUM** change required to make *s* a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.

## Breakdown
1. La contraseña debe ser de más de 6 caracteres, en caso de que se repitan letras, se pueden agregar otras entre ellas, si son más de 20 caracteres, se pueden quitar letras que se repitan, por lo que se puede revisar por los dos casos y hacer solo una incercion o borrado por coincidencia.
2. Se debe revisar que cumpla con el punto dos, si ya no se pueden agregar letras, se tendrían que reemplazar hasta que se cumpla.

## Algoritmo

```
-> Leer el string, habrá un contador para el numero de letras seguidas, el numero de incidencias de este caso.
-> Trás leer el string se asignará un valor booleano de acuerdo a que si tiene minusculas, mayusculas y al menos un digito.
-> Con la información previa se evaluara si es menor que 6 o mayor que 20 el tamaño del string.
-> Según lo anterior se agregara al contador de cambio por cada cambio necesarios.
-> Se regresa la respuesta del contador de cambio.
```

## Análisis del Algoritmo

La complejidad de este algoritmo es aproximadamente 2n.
Leer cada elemento de *s* es n y el analizis de la contraseña se hace durante la misma lectura.
Cada operación de analisis y cambio es de 1, en el peor de los casos el numero de cambios sería de n, por lo que nuestra complejidad es de n + n = 2n.
