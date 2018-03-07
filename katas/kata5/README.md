# Infographic

You want to build a *word cloud*, an infographic where the size of a word corresponds to how often it appears in the body of text.

To do this, you'll need data. Write code that takes a long string and builds its word cloud data in a **hash table**, where the keys are words and the values are the number of times the words occurred.

Think about capitalized words. For example, look at these sentences:

```
"After beating the eggs, Dana read the next step:"

"Add milk and eggs, then add flour and sugar."
```

What do we want to do with "After", "Dana", and "add"? In this example, your final hash table should include one "Add" or "add" with a value of 2. Make reasonable (not necessarily perfect) decisions about cases like "After" and "Dana".
Assume the input will only contain words and standard punctuation.

## Breakdown
1. Se puede detectar cuando hay puntuaciones para hacer minusculas la letra siguiente para detectar nombres propios y no inicios de oraciones.
2. La puntuacion estandar que se tomara en cuenta es el conjunto {. : ! ?}
3. Se puede cambiar todas las letras a minusculas como otra manera de lidiar con estos casos.
4. Se tiene que detectar el string por palabras
5. Si la palabra ya existe en el hash table, se tiene que poder cambiar el valor que se tiene bajo esa llave
6. Se debe detectar si la palabra no existe antes en el hash tabe
