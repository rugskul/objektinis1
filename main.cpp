#include "..\include\funkcijos.h"

int main() {
    string time, duomenys, vectorlist;
    vector<studentas> studentai;
    cout << endl << "Ar rodyti programos veikimo greičio analizę? Jei taip - spausti 't', o jei ne - spausti bet ką kitą. ";
    cin >> time;
    if (time == "t") {
        cout << "Kokį konteinerį naudoti?" << endl << "     std::vector<studentas> (spausti 'v')" << endl << "     std:list<studentas> (spausti l)" << endl;
        do {
            cin >> vectorlist;
            if (vectorlist == "v") {
                timer<vector<studentas>>("v");
            } else if (vectorlist == "l") {
                timer<list<studentas>>("l");
            } else {
                cerr << "Įveskite 'v' arba 'l'. ";
            }
        } while (vectorlist != "v" && vectorlist != "l");
    }
    cout << "Studentų duomenys bus įvedami ranka (spausti 'r') ar nuskaitomi iš failo (spausti 'f')? ";
    do {
        cin >> duomenys;
        if (duomenys == "r") {
            int kiek;
            string vidmed;
            do {
                cout << "Studentų skaičius: ";
                if (cin >> kiek) {
                    break;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "Įveskite skaičių. " << endl;
                }
            } while (true);
            cout << endl << "Įveskite studentų informaciją." << endl;
            for (int i = 0; i < kiek; i++) {
                studentas s;
                apieStudenta(s);
                studentai.push_back(s);
            }
            cout << "Galutinis balas pagal vidurkį (spausti 'v') ar medianą (spausti 'm')? ";
            do {
                cin >> vidmed;
                if (vidmed != "v" && vidmed != "m") {
                    cerr << "Įveskite 'v' arba 'm'. ";
                }
            } while (vidmed != "v" && vidmed != "m");
            printr(studentai, vidmed);
            //pointeris
            cout << "Studentų vektoriaus saugojimo atmintyje adresas: " << &studentai << endl;
        } else if (duomenys == "f") {
            string pavadinimas;
            cout << "Failo pavadinimas: ";
            cin >> pavadinimas;
            studentai = isFailo<vector<studentas>>(pavadinimas);
            printf(studentai);
        } else {    
            cerr << "Įveskite 'r' arba 'f'. ";
        }
    } while (duomenys != "f" && duomenys != "r");
}