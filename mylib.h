#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstdlib> 
#include <time.h>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;

struct studentas {
    string vardas, pavarde;
    int egz;
    vector<int> pazymiai;
    double galvid, galmed;
};

vector<studentas> isFailo(string);
void iFaila(vector<studentas>, string);
vector<vector<studentas>> skirstymas(vector<studentas>);
void timer();