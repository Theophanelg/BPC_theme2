#include <stdio.h>

static int put_digit(int entier) {
    if (entier >= 0 && entier <= 9) {
        int ascii_value = entier + '0';  
        int result = putchar(ascii_value);  
        return (result == ascii_value) ? 0 : -1;  
    } else {
        return -1;  
    }
}

static int put_hdigit(int entier) {
    if (entier >= 0 && entier <= 15) {
        char hex_char;
        if (entier < 10) {
            hex_char = '0' + entier;  // Convertir le nombre hexadécimal en code ASCII
        } else {
            hex_char = 'A' + (entier - 10);  // Convertir le nombre hexadécimal en code ASCII
        }

        int result = putchar(hex_char);  // Afficher le caractère hexadécimal
        return (result == hex_char) ? 0 : -1;  // Vérifier si l'affichage a réussi
    } else {
        return -1;  // Retourner -1 en cas d'argument invalide
    }
}

int putdec(int d) {
   
    if (d < 0) {
        putchar('-');
        d = -d;
    }

    int power = 1;
   
    while (power * 10 <= d) {
        power *= 10;
    }

    while (power > 0) {
        int digit = d / power;
        putchar('0' + digit);
        d %= power;
        power /= 10;
    }
    return 0;
}

int putbin(int bin) {
 if (bin == 0) {
    putchar('0');
    return 0;
 } else if (bin < 0) {
    return -1; 
 }

 int masque = 1 << 31;

 while ((masque & bin) == 0) {
    masque >>= 1;
 }

 while (masque != 0) {
    putchar((bin & masque) ? '1' : '0');
    masque >>= 1;
 }

 return 0;
}

int puthex(int h) {
 if (h == 0) {
    putchar('0');
    return 0;
 } else if (h < 0) {
    printf("Nombres négatifs non pris en charge.\n");
    return -1;
 }
 
 int shift = sizeof(int) * 2 - 4; 

 while (shift >= 0) {
    int hex_digit = (h >> shift) & 0xF; 
    putchar(hex_digit < 10 ? '0' + hex_digit : 'A' + (hex_digit - 10));
    shift -= 4; 
 }
 return 0;
}

