#include "..\include\funkcijos.h"

void printr(vector<studentas> studentai, string vidmed) {
   cout << left << setw(15) << "Vardas" 
        << setw(15) << "Pavardė" << setw(10);
        if (vidmed == "v") {
           cout << "Galutinis (vid.)" << endl;
        } else if (vidmed == "m") {
           cout << "Galutinis (med.)" << endl;
        }
   cout << "---------------------------------------------" << endl;
   for (int i = 0; i < studentai.size(); i++) {
      cout << left << setw(15) << studentai[i].vardas 
           << setw(15) << studentai[i].pavarde;
           if (vidmed == "v") {
              cout << setprecision(2) << studentai[i].galvid;
           } else if (vidmed == "m") {
              cout << setprecision(2) << studentai[i].galmed;
           }
      cout << endl;
   }
}

void printf(vector<studentas> studentai) {
   cout << left << setw(15) << "Vardas" 
        << setw(15) << "Pavardė" 
        << setw(15) << "Galutinis(vid.) " 
        << setw(15) << "Galutinis(med.) " << endl 
        << "--------------------------------------------------------------" << endl;
   for (int i = 0; i < studentai.size(); i++) {
      cout << left << setw(15) << studentai[i].vardas 
           << setw(15) << studentai[i].pavarde 
           << setw(15) << setprecision(2) << studentai[i].galvid 
           << setw(15) << setprecision(2) << studentai[i].galmed << endl;
   }
}