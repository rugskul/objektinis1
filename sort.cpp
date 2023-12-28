#include "..\include\funkcijos.h"

bool sortVardas(studentas a, studentas b) {
    return a.vardas < b.vardas;
}
bool sortPavarde(studentas a, studentas b) {
    return a.pavarde < b.pavarde;
}
bool sortGalvid(studentas a, studentas b) {
    return a.galvid < b.galvid;
}
void sortStudentai(vector<studentas>& studentai, string pagal) {
    if (pagal == "1") {
        sort(studentai.begin(), studentai.end(), sortVardas);
    } else if (pagal == "2") {
        sort(studentai.begin(), studentai.end(), sortPavarde);
    } else if (pagal == "3") {
        sort(studentai.begin(), studentai.end(), sortGalvid);
    } else {
        cout << "Įvestas netinkamas rūšiavimo kriterijus. Bus rūšiuojama pagal pavardę. " << endl;
        sort(studentai.begin(), studentai.end(), sortPavarde);
    }
}
void sortStudentai(list<studentas>& studentai, string pagal) {
    if (pagal == "1") {
        studentai.sort(sortVardas);
    } else if (pagal == "2") {
        studentai.sort(sortPavarde);
    } else if (pagal == "3") {
        studentai.sort(sortGalvid);
    } else {
        cout << "Įvestas netinkamas rūšiavimo kriterijus. Bus rūšiuojama pagal pavardę. " << endl;
        studentai.sort(sortPavarde);
    }
}