#include "..\include\funkcijos.h"

double vidurkis(vector<int> v, int e) {
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
    do {
        cin >> arAtsitiktinai;
        if (arAtsitiktinai == "a") {
            //atsitiktiniai namu darbu pazymiai ir egzamino rezultatas
            random_device rd; 
            mt19937 gen(rd());
            uniform_int_distribution<> dis(1, 10);
            for (int j = 0; j < dis(gen); j++) {
                studentas.pazymiai.push_back(dis(gen));
            }
            studentas.egz = dis(gen);
        } else if (arAtsitiktinai == "r") {
            //pazymiu ivedimas su enter
            cout << "Namų darbų pažymiai (baigti 2 kartus paspaudus ENTER): " << endl;
            int pazymys;
            while (true) {
                string p;
                getline(cin, p);
                if (p.empty()) {
                    if (cin.peek() == '\n') {
                        break;
                    }
                } else {
                    try {
                        int pazymys = stoi(p);
                        if (pazymys < 1 || pazymys > 10) {
                            cerr << "Netinkamas pažymys. Įveskite pažymį nuo 1 iki 10. " << endl;
                        } else {
                            studentas.pazymiai.push_back(pazymys);
                        }
                    } catch (const invalid_argument& e) {
                        cerr << "Netinkamas pažymys. Įveskite skaičių." << endl;
                    }
                }
            }
            do {
                cout << "Egzamino rezultatas: ";
                cin >> studentas.egz;
                if (cin.fail() || studentas.egz < 1 || studentas.egz > 10) {
                    cerr << "Netinkamas pažymys. Iveskite skaičių nuo 1 iki 10." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break;
                }
            } while (true);
        } else {
            cerr << "Įveskite 'a' arba 'r' ";
        }
    } while (arAtsitiktinai != "a" && arAtsitiktinai != "r");
    studentas.galvid = vidurkis(studentas.pazymiai, studentas.egz);
    studentas.galmed = mediana(studentas.pazymiai, studentas.egz);
}