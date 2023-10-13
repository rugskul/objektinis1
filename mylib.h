#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstdlib> 
#include <time.h>
#include <fstream>
#include <ctime>

using namespace std;

struct studentas {
    string vardas, pavarde;
    int egz;
    vector<int> pazymiai;
    double galvid, galmed;
};