#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libgen.h>


// Functia `dump` - Afi?eaza con?inutul fi?ierului
void dump(const char *fisier, char format) {
    FILE *file = fopen(fisier, "rb");
    if (file == NULL) {
        perror("Nu s-a putut deschide fi?ierul");
        return;
    }

    int ch;
    if (format == 'C') {  // Afi?are �n format caracter
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
    } else if (format == 'X') {  // Afi?are �n format hexazecimal
        while ((ch = fgetc(file)) != EOF) {
            printf("%02X ", ch);
        }
    } else {
        printf("Format necunoscut. Folosi?i 'C' pentru caractere sau 'X' pentru hexazecimal.\n");
    }
    fclose(file);
}

// Functia `info` - Determina atributele ?i lungimea fi?ierului
void info(const char *fisier, char *atrib, long *lg) {
    struct stat st;
    if (stat(fisier, &st) != 0) {
        perror("Nu s-a putut ob?ine informa?iile fi?ierului");
        return;
    }

    // Seteaza dimensiunea fi?ierului
    *lg = st.st_size;

    // Seteaza atributele fi?ierului
    if (st.st_mode & S_IFDIR) {
        strcpy(atrib, "Director");
    } else if (st.st_mode & S_IFREG) {
        strcpy(atrib, "Fi?ier normal");
    } else {
        strcpy(atrib, "Alt tip");
    }
}

// Functia `parinte` - Determina directorul parinte al fi?ierului
void parinte(const char *fisier, char *par) {
    char path_copy[256];
    strncpy(path_copy, fisier, sizeof(path_copy) - 1);
    path_copy[sizeof(path_copy) - 1] = '\0';

    char *dir = dirname(path_copy);
    strncpy(par, dir, 256);
}
