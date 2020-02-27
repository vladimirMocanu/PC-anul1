
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dictionar {
    char *de_inlocuit;
    char *inlocuitor;
};

typedef struct dictionar Dictionar;

char* Cerinta1(char litere[][4], int nrApariti[], int taste[], char *line) {

    char* codificare = calloc(1, 301);
    int tasta = 0;
    int contor = 0;
    int i, j, t, y;
    char cifra[3];

    //parcurgem linia
    for (i = 0; i < strlen(line); i++) {
        contor = 0;
        //daca e litera intram in functie
        if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) {

            if (line[i] >= 'A' && line[i] <= 'Z') {
                //pentru litere mici
                line[i] = line[i] + 32;
                contor = 1;
            }
            //pornim de la j = 2 ca sa sarim peste spatiu
            for ( j = 2; j < 10; j++) {
                for (t = 0; t < 4; t++) {

                    if (line[i] == litere[j][t]) {
                        //verificam daca tasta curenta este egala cu cea din urma
                        //daca da puneam #
                        if (tasta == j && contor == 0) {
                            
                            strcat(codificare, "#");


                        } else
                            tasta = j;

                        //daca e litera mare afisam 1
                        if (contor == 1) {

                            strcat(codificare, "1");
                        }
                        // printam de cate ori sa apese pe tasta, si tasta respectiva
                        for ( y = -1; y < t; y++) {
                            sprintf(cifra, "%d", taste[j]);
                            strcat(codificare, cifra);
                        }
                        break;
                    }
                }
            }
        } else {
            //daca e spatiu afisam 0
            if (line[i] == 32) {
                strcat(codificare, "0");
                tasta = 0;
                contor = 0;
            }
        }
    }


    return codificare;

}

void Cerinta2(char litere[][4], int nrApariti[], int taste[], char *line1) {

    int contor1 = 0;
    int literaMare = 0;
    int i;

    for ( i = 0; i < strlen(line1); i++) {
        if (line1[i] >= 50 && line1[i] <= 57) {
            //cd
            if (line1[i] == line1[i + 1]) {
                contor1++;
                if (line1[i] == 55 || line1[i] == 57) {
                    if (contor1 == 4) {
                        contor1 = 0;
                    }
                } else if (contor1 == 3) {
                    contor1 = 0;
                }
            } else {
                if (literaMare == 1) {
                    printf("%c", litere[line1[i] - 48][contor1] - 32);
                    literaMare = 0;
                    contor1 = 0;
                } else {
                    printf("%c", litere[line1[i] - 48][contor1]);
                    contor1 = 0;
                }
            }
        } else if (line1[i] == 48 || line1[i] == 49) {
            if (line1[i] == 48) {
                printf(" ");

            } else if (line1[i] == 49) {
                literaMare = 1;
            }
        }
    }
}

void Cerinta3(char litere[][4], int nrAparitii[], int taste[]) {

    char *prop = NULL;
    char *dupa_corectare = NULL;
    size_t len = 0;
    getline(&prop, &len, stdin);

    char *nrCuvinte = NULL;
    int i;

    getline(&nrCuvinte, &len, stdin);
    int nr = atoi(nrCuvinte);
    Dictionar *vector = (Dictionar*)calloc(nr , sizeof (Dictionar));

    char *de_inl = NULL;
    char *inloc = NULL;
    char *line = NULL;
     //  vector.de_inlocuit = calloc(1,strlen(de_inl) + 1);
      //  vector->inlocuitor = calloc(1, strlen(inloc) + 1);


    for (i = 0; i < nr; i++) {

        getline(&line, &len, stdin);
        de_inl = strtok(line, " ");
        inloc = strtok(NULL, " \n");

        vector[i].de_inlocuit = calloc(1,strlen(de_inl) + 1);
        vector[i].inlocuitor = calloc(1,strlen(inloc) + 1);

        strcpy(vector[i].de_inlocuit, de_inl);
        strcpy(vector[i].inlocuitor, inloc);

       
        // se introduc cuvintele in dictionar
    
    }


    dupa_corectare = calloc(2,strlen(prop));
    char *token = strtok(prop, " \n");
    while (token != NULL) {

        for (i = 0; i < nr; i++) {
            // se cauta cuvantul din propozitia initiala in dictionar
            if (strcmp(token, vector[i].de_inlocuit) == 0) {
                token = vector[i].inlocuitor;
                break;
            }
        }

        strcat(dupa_corectare, token);
        token = strtok(NULL, " \n");
        // se formeaza noua propozitie
        if (token != NULL)
            strcat(dupa_corectare, " ");
    }

    for (i = 0; i < nr; i++) {
        free(vector[i].de_inlocuit);
        free(vector[i].inlocuitor);
    }
    // se codifica noua propozitie
    char* codificare = Cerinta1(litere, nrAparitii, taste, dupa_corectare);
    printf("%s\n", codificare);
    free(codificare);
    free(dupa_corectare);
    free(prop);
    free(nrCuvinte);

    free(vector);
}
//algoritmul lui Euclid pentru cmmdc

long long cmmdc(long long a, long long b) {

    long long c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int comparator(const void* a, const void* b) {

    if (*(long long*) b < *(long long*) a)
        return -1;
    else if (*(long long*) b == *(long long*) a)
        return 0;
    return 1;
}

void Cerinta4(char litere[][4], int nrAparitii[], int taste[], char* line) {

    int i, zeros = 0;
    int suma_cifre = 0;
    // codificarea propozitiei
    char *codificare = Cerinta1(litere, nrAparitii, taste, line);
    char *copie_codif = NULL;

    for (i = 0; i < strlen(codificare); i++) {
        // se elimina toate #                                          
        if (codificare[i] == '#') {
            memmove(codificare + i, codificare + i + 1, strlen(codificare) - i);
            i--;
        }// se numara zerourile
        else if (codificare[i] == '0')
            zeros++;
        else// suma cifrelor
            suma_cifre += (codificare[i] - '0');
    }

    copie_codif = strdup(codificare);
    int lungime_codificare = strlen(codificare);
    // vectorul de componente
    long long *componente = calloc((zeros + 2), sizeof (long long));
    i = 0;

    char delim[] = "0\n";
    char *token = strtok(codificare, delim);
    char *aux = NULL;
    // impartirea codificarii in componente
    while (token != NULL) {
        componente[i] = strtoll(token, &aux, 10);
        i++;
        token = strtok(NULL, delim);
    }

    printf("%d\n", i);

    int j, poz;
    long long max = -1;
    for (j = 0; j < i; j++) {
        // aflarea maximului dintre componente si pozitia sa
        printf("%lld ", componente[j]);
        if (componente[j] > max) {
            max = componente[j];
            poz = j;
        }
    }

    printf("\n");
    printf("%lld %d\n", componente[poz], poz + 1);

    int k, prime = 1;
    for (j = 0; j < i; j++) // se verifica daca componentele sunt prime intre ele                                                                
        for (k = j + 1; k < i; k++)
            if (cmmdc(componente[j], componente[k]) != 1) {
                prime = 0;
                break;
            }

    printf("%d\n", prime);


    int N = suma_cifre % 9;

    if (N == 0)
        printf("0\n"); // suma cifrelor se imparte exact la 9                                                                     
    else {// codificarea nu se imparte perfect in grupuri de N cifre     
        if ((lungime_codificare % N) != 0)
            printf("0\n");
        else { // codificarea se imparte perfect                                                                          
            int index = 0;
            char* numar = calloc(1,100);

            long long* elemente = calloc((lungime_codificare + 1)
                    ,sizeof (long long)); // se realizeaza impatirea
            for (k = 0; k < lungime_codificare; k = k + N) {
                memcpy(numar, copie_codif + k, N);
                elemente[index] = atoll(numar);
                index++;
            }
            qsort(elemente, index, sizeof (long long), comparator); // se sorteaza                         
            for (j = 0; j < index; j++)
                printf("%lld ", elemente[j]); // se afiseaza elementele                                             
            free(elemente);
            free(numar);
        }
       
    }
    free(codificare);
    free(copie_codif);
}

int main(int argc, char *argv[]) {
    //am pus 2 spatii libere ca sa corespunda litere cu tasta(EX. a se afla pe tasta 2)
    char litere[10][4] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int nrAparitii[7] = {1, 2, 3, 1, 2, 3};
    int taste[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    char *line = NULL;
    char *line1 = NULL;
    char *line2 = NULL;

    size_t len = 0;

    //Citim cate o linie pentru fiecare cerinta
    getline(&line, &len, stdin);
    char* codificare = Cerinta1(litere, nrAparitii, taste, line);
    printf("%s\n", codificare);
    free(codificare);

    getline(&line1, &len, stdin);
    Cerinta2(litere, nrAparitii, taste, line1);
    printf("\n");
    

    Cerinta3(litere, nrAparitii, taste);
    

    getline(&line2, &len, stdin);
    Cerinta4(litere, nrAparitii, taste, line2);
  


    return 0;
}
