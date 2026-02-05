#include <stdio.h>
#include <string.h>

struct Produkt {
    char nazev[50];
    float cena;
    int pocet;
};

int main() {
    struct Produkt sklad[100];
    int aktualniPocet = 0;
    char volba;

    strcpy(sklad[0].nazev, "Rohlik");
    sklad[0].cena = 3;
    sklad[0].pocet = 50;
    aktualniPocet = 1;

    while (1) {
        printf("\n--- SKLAD (%d/100) ---\n", aktualniPocet);
        printf("1. Vsechny produkty\n");
        printf("2. Vyhledat podle nazvu\n");
        printf("3. Upravit / Pridat produkt\n");
        printf("X. Konec\n");
        printf("Vase volba: ");
        scanf(" %c", &volba);

        if (volba == 'x' || volba == 'X') break;

        if (volba == '1') {
            printf("\nID / Nazev / Cena / Kusy\n");
            for (int i = 0; i < aktualniPocet; i++) {
                printf("%d | %s | %.2f Kc | %d ks\n", i, sklad[i].nazev, sklad[i].cena, sklad[i].pocet);
            }
        }
        else if (volba == '2') {
            char hledany[50];
            printf("Zadej presny nazev: ");
            scanf("%s", hledany);
            for (int i = 0; i < aktualniPocet; i++) {
                if (strcmp(sklad[i].nazev, hledany) == 0) {
                    printf("Najito: ID %d, Cena %.2f, Pocet %d\n", i, sklad[i].cena, sklad[i].pocet);
                }
            }
        }
        else if (volba == '3') {
            int id;
            printf("Zadejte ID (0-100): ");
            scanf("%d", &id);
            if (id >= 0 && id < 100) {
                printf("Nazev: "); scanf("%s", sklad[id].nazev);
                printf("Cena: ");  scanf("%f", &sklad[id].cena);
                printf("Pocet: "); scanf("%d", &sklad[id].pocet);
                if (id == aktualniPocet) aktualniPocet++;
            }
        }
    }

    return 0;
}
