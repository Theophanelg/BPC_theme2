# Compilation modulaire

# SEMAINE 4

## Exerice 15

### TD 

Fait en TD

### TP

gcc -c put_numbers.c

Ce fichier ne peut être lancer du fait que c'est un fichier objet et non executable

## Exerice 16

### TD 

Fait en TD

### TP

On utilise le static du fait que l'on fait seulement un appel de fonction sur ses deux méthodes : 
```bash
    static int put_digit(int entier) {}
    static int put_hdigit(int entier) {}
```

## Exerice 17

### TD 

Compilation de test_numbers.c :
- gcc -c test_numbers.c

### TP

- La compilation provoques des warnings du fait que la déclaration de la fonction est implicite :

warning: implicit declaration of function ‘putdec’

Pour éviter les warnings dans le fichier numbers_test on fait :
```bash
    int putdec(int d);
    int putbin(int b);
    int puthex(int h);
```

## Exerice 18

### TD 



### TP

Pour implementez la solution on fait un fichier .h qui contient :

```bash
#ifndef PUT_NUMBERS_H
#define PUT_NUMBERS_H

extern int putdec(int d);
extern int putbin(int b);
extern int puthex(int h);

#endif
```

puis dans le fichier numbers_test.c on fait :

```bash
    #include <stdio.h>
    #include "put_numbers.h"

    int main(){
        putdec(123);
        putchar('\n');
        putbin(123);
        putchar('\n');
        puthex(123);
        return 0;
    }
```

## Exerice 19

### TD 

- gcc put_numbers.o numbers_test.o -o test_numbers

## Exerice 20

### TD 
### TP

Dans le fichier compile_test_numbers.sh :

gcc -c put_numbers.c -o o/put_numbers.o
gcc -c numbers_test.c -o o/numbers_test.o
gcc o/put_numbers.o o/numbers_test.o -o o/test_numbers


Commande pour avoir la permission de l'execution du fichier

```bash
    chmod +x compile_test_numbers.sh
```


## Exercice 21

### TD
```bash
test_numbers : put_numbers.o numbers_test.o
	gcc o/put_numbers.o o/numbers_test.o -o o/test_numbers

put_numbers.o : put_numbers.c
	gcc -c put_numbers.c -o o/put_numbers.o

numbers_test.o : numbers_test.c
	gcc -c numbers_test.c -o o/numbers_test.o

clean : 
	rm -f o/*.o o/test_numbers
```

### TP
```bash
    make
    make test_numbers
    make put_numbers.o
    make numbers_test.o
    make clean
```

## Exercice 22

### TD
```bash
numbers-test: numbers-test.o put_numbers.o
    $(CC) $(CFLAGS) $^ -o @$
```

signifie que la cible numbers-test dépend des fichiers numbers-test.o et put_numbers.o. Lorsque cette règle est exécutée, la commande $(CC) $(CFLAGS) $^ -o $@ est exécutée pour créer l'exécutable numbers-test.


### TP
```bash
CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic

all : numbers_test

numbers_test: numbers_test.o put_numbers.o
	$(CC) $(CFLAGS) $ˆ -o $@

put_numbers.o: put_numbers.c
	$(CC) $(CFLAGS) -c $^ -o o/$@

numbers_test.o: numbers_test.c
	$(CC) $(CFLAGS) -c $^ -o o/$@

clean:
	rm -f numbers-test o/*.o
```



## Exercice 23

### TD
### TP

Scénario 1 :

- Liste des unités de compilation :
    main.c
    foo.c

- Pour chaque unité de compilation, liste des fichiers .h inclus :
    main.c : "foo.h"

- Pour chaque fonction :
    Fonction "foo" :
    Déclarée dans "foo.h"
    Définie dans "foo.c"

- Vérification de chaque fonction utilisée :
    Dans "main.c", la fonction "foo" est utilisée et elle est bien déclarée au préalable dans "foo.h".

- Vérification des fichiers exécutables créés par le Makefile :
    Un fichier exécutable nommé "main" est créé.
    Commande de création : cc -o main main.o
    Chaque fonction utilisée ("foo" et "main") est définie exactement une fois.
    Il existe exactement une définition de la fonction "main".

Il n'y a pas d'anomalie dans le code

Scénario 2 :

- Liste des unités de compilation :
    main.c
    foo.c

- Pour chaque unité de compilation, liste des fichiers .h inclus :
    main.c : "foo.h"
    foo.c : "foo.h"

- Pour chaque fonction :
    Fonction "foo" :
        Définie dans "foo.h" : A

- Vérification de chaque fonction utilisée :
    Dans "main.c", la fonction "foo" est utilisée : A

- Vérification des fichiers exécutables créés par le Makefile :
    Un fichier exécutable nommé "main" est créé.
    Commande de création : cc -o main main.o foo.o
    La fonction "foo" est définie exactement une fois.
    Il existe exactement une définition de la fonction "main".

Il y'a des anomalie : 

- la définition dans le fichier foo.h n'est pas dans le bon fichier, il devrais être dans le fichier foo.c
- la fonction foo utilisé dans le main n'est pas déclaré dans ce fichier 

Scénario 3

- Liste des unités de compilation :
    main.c
    foo.c

- Pour chaque unité de compilation, liste des fichiers .h inclus :
    Aucune inclusion de fichier d'en-tête dans les fichiers source.

- Pour chaque fonction :
    Fonction "foo" :
        Déclarée dans "foo.h"
        Définie dans "foo.c"

- Vérification de chaque fonction utilisée :
    Dans "main.c", la fonction "foo" est utilisée : A

- Vérification des fichiers exécutables créés par le Makefile :
    Un fichier exécutable nommé "main" est créé.
    Commande de création : cc -o main main.o foo.o
    Chaque fonction utilisée ("foo" et "main") est définie exactement une fois.
    Il existe exactement une définition de la fonction "main".

Il y'a une anomalie :
la fonction foo utilisée dans main n'est pas déclarée dans ce fichier

## Exercice 24

### TP

gcc -O0 -g -o exo24 exo24.c





