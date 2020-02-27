Mocanu-Prejma Vladimir-Georgian

Cerinta1
Se citeste si se salveaza propozitia initiala, vedem daca caracterul este litera mare sau mica. Daca este litera mare o transformam in litera mica.
Parcurgem literele de pe tastatura. Daca gasim doua litere de pe aceeasi tasta punem #. Pentru spatiu punem 0 si pentru litera mare punem. Returnam mesajul codificat.

Cerinta2
Se citeste si se salveaza propozitia(codificare). Parcurgem codificarea si vedem daca caracterul respectiv este cifra intre 2-9. Verificam daca caracterul este 7 sau 9, pentru ca are mai multe litere pe tasta. Daca e gasim 1 printam litera mare, pentru 0 spatiu si pentru # ne oprim.


Cerinta 3

    Se citeste si se salveaza propozitia initiala. Se citeste dictionarul si se salvaza intr-un vector de structuri. Se verifica fiecare cuvant din propozitia initiala, adica se cauta in dictionar si se inlocuieste daca este gasit, formandu-se o noua propozitie. Se aplica Cerinta 1 pentru a se codifica noua propozitie.

    
Cerinta 4

    Se citeste propozitia data si se codifica. Se elimina toate simbolurile '#', se numara zerourile pentru a afla numerul de componente si in acelasi timp se
calculeaza suma cifrelor codificarii. Se imparte codificarea in componente, adica in elementele unui vector de tip long long. Se afla componenta maxima si 
pozitia acesteia si se afiseaza. Se verifica toate elementele doua cate doua daca sunt prime intre ele prin calcularea celui mai mare divizor comun. Daca toate
elementele, doua cate doua sunt prime, se afiseaza 1, altfel 0.
    Suma cifrelor se imparte cu rest la 9. In cazul in care restul (N) e 0 se afiseaza 0, altfel, in cazul in care codificarea nu se imparte perfect in grupuri 
N cifre, se afiseaza 0. In ultimul caz, cand codificarea se imparte perfect, se face impartirea in elemente de N cifre, se salveaza intr-un vector, se sorteaza
descrescator si se afiseaza. 
