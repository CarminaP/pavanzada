# Find Anagram Mappings

Given two lists **A** and **B**, and **B** is an anagram of **A**. **B** is an anagram of **A** means **B** is made by randomizing the order of the elements in **A**.

We want to find an *index mapping* **P**, from **A** to **B**. A mapping **P[i] = j** means the *ith* element in **A** appears in **B** at index *j*.

These lists **A** and **B** may contain duplicates. If there are multiple answers, output any of them.

For example, given

```
A = [12, 28, 46, 32, 50]  B = [50, 12, 32, 46, 28]  
```

We should return

```
[1, 4, 3, 2, 0]
```

as  **P[0] = 1** because the *0th* element of **A** appears at **B[1]**, and **P[1] = 4** because the *1st* element of **A** appears at **B[4]**, and so on.

### Note:

- **A**, **B** have equal lengths in range **[1, 100]**.
- **A[i]**, **B[i]** are integers in range **[0, 10^5]**.

## Breakdown
1. Como los enteros van de 0 a 100,000 y en C el rango del tipo de dato int puede ir de (2^15)-1 a (2^31)-1 dependiendo del hardware, para asegurar que se cumpla el rango sería preferible usar long.
2. Al ser anagramas tanto **A** como **B** son del mismo tamaño, por lo que P será también del mismo tamaño.
3. Como solo se pide una respuesta en caso de que existan múltiples, se debe asegurar que no se repitan los índices de B en P

## Algoritmo

```
-> Seleccionar primer elemento de A
-> Buscar valor que lo complemente en B
-> Al encontrarlo, guardar el índice de B en P como valor en el mismo índice en que se está en A y cambiar el valor de B a -1
-> Continuar con el siguiente elemento de A y repetir el proceso hasta terminar de recorrer A
-> Regresar P resultante
```

## Análisis del Algoritmo

La complejidad de este algoritmo es aproximadamente n².
Leer cada elemento de A es n y realizar la busqueda en B es de n log n más agregar los valores a P.
Resultando en n x (n log n + 1) ≃ n²
Pero como el limite del tamaño es de 100, el peor caso sería de 100²
Cambiando los valores de B que ya se han usado por -1, un valor que nunca va a aparecer en A por el rango de valores, se asegura que no se repetirán índices.
