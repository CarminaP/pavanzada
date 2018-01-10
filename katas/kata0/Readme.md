------------------------------------------------Two Sum-----------------------------------------------------

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

Reference: https://leetcode.com/problems/two-sum/description/

------------------------------------------------Breakdown---------------------------------------------------

1. ¿El arreglo está ordenado?
  Según los ejemplos no, pero se debe tener en cuenta el caso en el que lo estén
2. Se debe restringir a solo números positivos para facilitar las operaciones
3. En el caso más sencillo dónde el tamaño del arreglo es de 2, la solución es trivial (1,0)
4. En los demás casos al empezar se lee el primer dato y buscar en el arreglo una respuesta complementaria

-------------------------------------------Primer Algoritmo-------------------------------------------------

-> Seleccionar primer elemento
-> Buscar valor que lo complemente para llegar al target
-> Si no se encuentra, seguir con el siguiente elemento y repetir la busqueda
-> Si se encuentra regresar los índices de ambos (asegurarse que no sea el mismo índice)

-------------------------------------Análisis del Primer Algoritmo-------------------------------------------

La complejidad de este algoritmo es aproximadamente n².
Leer el arreglo es n y realizar la busqueda es de n log n más ordenar los elementos.
Resultando en n x (n log n + ordenar) ≃ n²
En el caso de un arreglo muy grande esto sería muy tardado y costoso.

-------------------------------------------Segundo Algoritmo-------------------------------------------------

-> Leer los elementos de el arreglo y agregarlos en un Hash Table
-> En el Hash Table, los números seran la llave y el índice será el valor
-> Empezar con el primer elemento
-> Buscar en el Hash Table un valor que lo complemente para llegar al target
-> Si no se encuentra, seguir con el siguiente elemento y repetir la busqueda
-> Si se encuentra regresar los índices de ambos (asegurarse que no sea el mismo índice)

-------------------------------------Análisis del Segundo Algoritmo-------------------------------------------

La complejidad de este algoritmo es aproximadamente n.
En un Hash Table las busquedas tienen complejidad de n.
Esto resulta en n x n = 2n ≃ n.
Esta es la complejidad más baja ya que se tiene que leer el arreglo al menos una vez y esto resulta en n.
