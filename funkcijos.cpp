#include "funkcijos.h"

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

int failoGeneravimas(int kiek) {
    srand(time(0));
    string pavadinimas = "kursiokai" + to_string(kiek) + ".txt";
    ofstream outputFile(pavadinimas);
    outputFile << "Vardas Pavardė";
    int nd = randomInt(1, 15);
    for (int i = 1; i <= nd; ++i) {
        outputFile << " ND" << i;
    }
    outputFile << " Egz." << endl;
    for (int i = 1; i <= kiek; ++i) {
        outputFile << "Vardas" << to_string(i) << " " << "Pavardė" << to_string(i);
        for (int j = 1; j <= nd; ++j) {
            int pazymys = randomInt(0, 10);
            outputFile << " " << pazymys;
        }
        outputFile << " " << randomInt(0, 10) << endl;
    }
    outputFile.close();
    cout << "Failas sugeneruotas. " << endl;
    return 0;
}
