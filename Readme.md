# TP d'introduction à la pratique du lanange C

# SEMAINE 1
## Exercice 1

### TD

* Il ne peut pas fonctionner car la fonction T n'est pas défini avant son utilisation

## Exercice 2

### TD
* Cela indique au préprocesseur du compilateur C que les symboles T doivent être remplacés par 65. Le programme sera donc préprocesseur avec cette substitution, et ensuite compilé normalement.

### TP
- gcc -o macro1 macro1.c -DT=65
- ./macro1

## Exercice 3

### TD
* En ajoutant #define T (65+1), le resultat est : DB 

### TP
- gcc -E macro1.c

## Exercice 4

### TD
- gcc -E macro1.c

### TP
- grep -v "#"

extern int putchar(int c);

int main()
{
    int u=68;
    putchar(u);
    putchar((65+1));
}

## Exercice 5

### TD

### TP
int main() 
{
    int u=68;
    putchar(u);                 /* premier char */
    putchar(T);                 /* deuxième char */
    putchar('\n');
}

## Exercice 6

### TD

### TP

## Exercice 7

### TD

Fait en TD

### TP

- gcc -DNO_LOG=1 compcond.c -o compcond

cette ligne de compilation compile le code en excluant la partie de log si la macro NO_LOG est définie à 1

## Exercice 8

### TD

Pour que l'affichage n'ait pas lieu lorsque la macro NO_LOG est définie :

extern int putchar(int c);

#ifdef NO_LOG
#define logchar(c) 0
#else
int logchar(int c) {
    return putchar(c);
}
#endif

int main() {
    int i = 1;
    i = 3 * i;
    logchar('0' + i);
    return i;
}

### TP

Avec 'NO_LOG' defini

- gcc -DNO_LOG=1 compcond.c -o compcond

Sans 'NO_LOG' defini

- gcc compcond.c -o compcond

## Exercice 9
### TD
Quand on essaie de compiler sans definir SIZE on obtient une erreur car #error s'activera quand SIZE n'est pas défini 

### TP
- gcc compchk.c

## Exercice 10
### TD
### TP

Le programme se compilera sans erreur, mais #warning sera activée car SIZE n'est pas une puissance de 2, cela donnera un avertissement mais le programme pourra toujours être executé :

- gcc compchk.c -DSIZE=5 -o comchk

## Exercice 11
### TP

echo | gcc -E -Wp,-v -

Dans le manuel, on trouve que putchar() se trouve dans #include <stdio.h>

## Exercice 12
### TD
### TP

En modifiant le code :

int f(int x)
{
    return 2*x;
}

int main() {
    putchar('0' + f(3));
    return 0;
}

Commande pour l'executer :

- gcc -E include_file.c -o include_file

## Exercice 13

### TD

On ne peut définir une entité qu'une seul fois dans un programme et donc peut produire des erreurs si cela est appeller plusieurs fois dans le meme programme, on s'apperçois qu'une entité est défini plusieurs fois dans les fichiers cela posera donc des erreurs.

### TP

Pour corriger les erreurs on fait des directives préprocesseur :

```bash
#ifndef ABS_H
#define ABS_H
static inline int abs(int x) { return (x<0)?-x:x; }

#endif
```


```bash
#ifndef MINMAX_H
#define MINMAX_H

#include "abs.h"

static inline int min(int x,int y) { return (x+y-abs(x-y))/2; }
static inline int max(int x,int y) { return (x+y+abs(x-y))/2; }

#endif
```

# SEMAINE 4

DANS COMPIL MODULAIRE






