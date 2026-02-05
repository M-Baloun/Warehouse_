#include <stdio.h>
#include <string.h>

struct Produkt {
    char nazev[50];
    float cena;
    int skladem;
};

int main() {
    struct Produkt sklad[100];
    int aktualniPocet = 0;
    char volba;

    for (int i = 0; i < 100; i++) {
        sklad[i].cena = 0;
    }

    strcpy(sklad[0].nazev, "Rohlik");
    sklad[0].cena = 3;
    sklad[0].skladem = 50;
    aktualniPocet = 1;

    while (1) {
        printf("\n--- SKLAD (Max 100) ---\n");
        printf("1. Vsechny produkty\n");
        printf("2. Vyhledat podle nazvu\n");
        printf("3. Upravit / Pridat produkt\n");
        printf("X. Konec\n");
        printf("Vase volba: ");
        scanf(" %c", &volba);

        if (volba == 'x' || volba == 'X') break;

        if (volba == '1') {
            printf("\nID / Nazev / Cena / Kusy\n");
            for (int i = 0; i < 100; i++) {
                if (sklad[i].cena > 0) {
                    printf("%d / %s / %.2f Kc / %d ks\n", i, sklad[i].nazev, sklad[i].cena, sklad[i].skladem);
                }
            }
        }
        else if (volba == '2') {
            char hledany[50];
            printf("Zadej presny nazev: ");
            scanf("%s", hledany);
            for (int i = 0; i < 100; i++) {
                if (sklad[i].cena > 0 && strcmp(sklad[i].nazev, hledany) == 0) {
                    printf("Najito: ID %d, Cena %.2f Kc, Pocet %d ks\n", i, sklad[i].cena, sklad[i].skladem);
                }
            }
        }
        else if (volba == '3') {
            int id;
            printf("Zadejte ID (0-99): ");
            scanf("%d", &id);
            if (id >= 0 && id < 100) {
                if (sklad[id].cena == 0) aktualniPocet++;
                printf("Nazev: ");
                scanf("%s", sklad[id].nazev);

                float pomocnaCena = 0;
                while (pomocnaCena < 0.1) {
                    printf("Cena (min 0.1 Kc): ");
                    scanf("%f", &pomocnaCena);
                    if (pomocnaCena < 0.1) {
                        printf("Chyba: Cena musi byt aspon 0.1 Kc!\n");
                    }
                }
                sklad[id].cena = pomocnaCena;

                printf("Pocet: ");
                scanf("%d", &sklad[id].skladem);
            }
        }
    }

    return 0;
}
