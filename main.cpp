#include "mylib.h"

double vidurkis(vector<int>& v, int e) {
    double suma = 0;
    for (int i=0; i < v.size(); i++) {
        suma += v[i];
    }
    return 0.4*(suma/v.size())+0.6*e;
}
double mediana(vector<int> v, int e) {
    double mediana;
    sort(v.begin(), v.end());
    int n = v.size();
    if (n % 2 == 0) {
        mediana = (v[(n - 1) / 2] + v[n / 2]) / 2.0;
    } else {
        mediana = v[n / 2];
    }
    return mediana*0.4+e*0.6;
}
void apieStudenta(studentas &studentas) {
    cout << endl << "Vardas ir pavardė: ";
    cin >> studentas.vardas >> studentas.pavarde;
    string arAtsitiktinai;
    cout << "Ar namų darbai generuojami atsitiktinai (spausti 'a'), ar įvedami ranka (spausti 'r')? ";
    cin >> arAtsitiktinai;
    if (arAtsitiktinai == "a") {
        //atsitiktiniai namu darbu pazymiai
        srand(time(0));
        for (int j = 0; j < rand()%10+1; j++) {
            studentas.pazymiai.push_back(rand() % 10 + 1);
        }        
    } else if (arAtsitiktinai == "r") {
        //pazymiu ivedimas su enter
        cout << "Namų darbų pažymiai (baigti 2 kartus paspaudus ENTER): " << endl;
        int pazymys;
        string p;
        while (true) {
            getline(cin, p);
            if (p.empty()) {
                if (cin.peek() == '\n') {
                    break;
                }
            } else {
                pazymys = stoi(p);
                while (pazymys < 1 || pazymys > 10) {
                    cerr << "Netinkamas pažymys. Įveskite pažymį nuo 1 iki 10. " << endl;
                    cin >> pazymys;
                }
                studentas.pazymiai.push_back(pazymys);
            }
        }
    }
    cout << "Egzamino rezultatas: ";
    cin >> studentas.egz;
    while (studentas.egz < 1 || studentas.egz > 10) {
        cerr << "Netinkamas pažymys. Įveskite egzamino rezultatą nuo 1 iki 10. ";
        cin >> studentas.egz;
    }
    studentas.galvid = vidurkis(studentas.pazymiai, studentas.egz);
    studentas.galmed = mediana(studentas.pazymiai, studentas.egz);
}
vector<studentas> isFailo(string pavadinimas) {
    vector<studentas> studentai;
    ifstream file(pavadinimas);
    if (!file.is_open()) {
        cerr << "Nepavyko atidaryti failo." << endl;
    }
    string pirma;
    getline(file, pirma);
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        studentas studentas;
        int pazymys;
        if (iss >> studentas.vardas >> studentas.pavarde) {
            while (iss >> pazymys) {
                studentas.pazymiai.push_back(pazymys);
            }
            if (!studentas.pazymiai.empty()) {
                studentas.egz = studentas.pazymiai.back();
                studentas.pazymiai.pop_back();
                studentas.galvid = vidurkis(studentas.pazymiai, studentas.egz);
                studentas.galmed = mediana(studentas.pazymiai, studentas.egz);
            }
            studentai.push_back(studentas);
        }
    }
    file.close();
    return studentai;
}
vector<vector<studentas>> skirstymas(vector<studentas> studentai) {
    vector<studentas> vargsiukai;
    vector<studentas> kietekai;
    for (int i = 0; i < studentai.size(); i++) {
        if (studentai[i].galvid > 5) {
            kietekai.push_back(studentai[i]);
        } else {
            vargsiukai.push_back(studentai[i]);
        }
    }
    vector<vector<studentas>> suskirstyti = {vargsiukai, kietekai};
    return suskirstyti;
}
void iFaila(vector<studentas> v, string pavadinimas) {
    ofstream outFile(pavadinimas);
    outFile << "Vardas Pavardė";
    for (int i = 1; i <= v[0].pazymiai.size(); ++i) {
        outFile << " ND" << i;
    }
    outFile << " Egz." << endl;
    for (int i = 0; i < v.size(); i++) {
        outFile << v[i].vardas << " " << v[i].pavarde << " ";
        for (int j = 0; j < v[i].pazymiai.size(); j++) {
            outFile << v[i].pazymiai[j] << " ";
        }
        outFile << v[i].egz << endl;
    }
    outFile.close();
}
int main() {
    vector<studentas> studentai;
    string duomenys;
    cout << "Duomenys bus įvedami ranka (spausti 'r') ar skaitomi iš failo (spausti 'f')? ";
    cin >> duomenys;
    if (duomenys == "r") {
        int kiek;
        cout << "Studentų skaičius: ";
        cin >> kiek;
        cout << endl << "Įveskite studentų informaciją." << endl;
        for (int i = 0; i < kiek; i++) {
            studentas s;
            apieStudenta(s);
            studentai.push_back(s);
        }
        string vidmed;
        cout << "Galutinis balas pagal vidurkį (spausti 'v') ar medianą (spausti 'm')? ";
        cin >> vidmed;
        //printina lentele
        if (vidmed == "v") {
            cout << left << setw(15) << "Vardas" << setw(15) << "Pavardė" << setw(10) << "Galutinis (vid.)" << endl << 
            "---------------------------------------------" << endl;
            for (int i = 0; i < studentai.size(); i++) {
                cout << left << setw(15) << studentai[i].vardas << setw(15) << studentai[i].pavarde << setprecision(2) << studentai[i].galvid;
                cout << endl;
            }
        } else if (vidmed == "m") {
            cout << left << setw(15) << "Vardas" << setw(15) << "Pavardė" << setw(10) << "Galutinis (med.)" << endl << 
            "---------------------------------------------" << endl;
            for (int i = 0; i < studentai.size(); i++) {
                cout << left << setw(15) << studentai[i].vardas << setw(15) << studentai[i].pavarde << setprecision(2) << studentai[i].galmed;
                cout << endl;
            }
        }
    } else if (duomenys == "f") {
        string pavadinimas, time, testi;
        cout << "Failo pavadinimas: ";
        cin >> pavadinimas;
        cout << endl << "Ar rodyti programos veikimo greicio analize? Jei taip - spausti 't', o jei ne - spausti bet ką kitą. ";
        cin >> time;
        if (time == "t") {
            cout << endl << "PROGRAMOS VEIKIMO GREIČIO ANALIZĖ: " << endl;
            timer();
        }
        cout << endl << "Spauskite 't', jei norite testi. ";
        cin >> testi;
        cout << endl;
        if (testi == "t") {
            studentai = isFailo(pavadinimas);
            cout << left << setw(15) << "Vardas" << setw(15) << "Pavardė" << setw(15) << "Galutinis(vid.) " << setw(15) << "Galutinis(med.) " << endl << 
            "--------------------------------------------------------------" << endl;
            for (int i = 0; i < studentai.size(); i++) {
                cout << left << setw(15) << studentai[i].vardas << setw(15) << studentai[i].pavarde 
                << setw(15) << setprecision(2) << studentai[i].galvid << setw(15) << setprecision(2) << studentai[i].galmed;
                cout << endl;
            }
        }
    }
}