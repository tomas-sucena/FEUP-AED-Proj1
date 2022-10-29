#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

#include "UC.h"
#include "Class.h"

using namespace std;

int main(){
    /*-----LER FICHEIROS-----*/
    // ler o 1º ficheiro
    ifstream classes_per_uc("../classes_per_uc.csv");

    string line; getline(classes_per_uc, line); // ignorar o cabeçalho

    map<string, set<string>> mappy;
    
    while (getline(classes_per_uc, line)){
        istringstream line_(line);

        string ucCode, classCode;

        // ler o UcCode
        getline(line_, ucCode, ',');

        // ler o ClassCode
        getline(line_, classCode, '\r');

        mappy[ucCode].insert(classCode);
    }

    vector<UC> all_UCs;
    for (auto it = mappy.begin(); it != mappy.end(); it++){
        UC uc(it->first, it->second);

        all_UCs.push_back(uc);
    }

    // ler o 2º ficheiro
    ifstream classes("../classes.csv");

    getline(classes, line); // ignorar o cabeçalho

    map<string, set<Block>> uc_blocks, class_blocks;

    while (getline(classes, line)){
        istringstream line_(line);

        string classCode, ucCode, weekday, 
               startHour, duration, type;

        // ler a ClassCode
        getline(line_, classCode, ',');

        // ler o UcCode
        getline(line_, ucCode, ',');

        // ler o Weekday
        getline(line_, weekday, ',');

        // ler a StartHour
        getline(line_, startHour, ',');

        // ler a Duration
        getline(line_, duration, ',');

        // ler o Type
        getline(line_, type, '\r');

        uc_blocks[ucCode].insert(Block(classCode, weekday, startHour, duration, type));
        class_blocks[ucCode].insert(Block(ucCode, weekday, startHour, duration, type));
    }

    // atualizar o vetor de UCs
    for (UC uc : all_UCs){
        ;
    }



    /*-----LER COMANDOS-----*/
    vector<string> command = {"display", "print", "show"};
    vector<string> target = {"all", "student", "UC"};
    vector<string> what = {"student", "UC", "classes"}; 

    cout << "Hello! How can I be of assistance?" << endl;

    string s1, s2, s3; 
    cin >> s1 >> s2 >> s3;

    if (s2 == "UC" && s3 == "classes"){
        cout << endl << "Understood. Please select the desired UC." << endl;

        string uc; cin >> uc;
        
        bool valid = false;
        for (UC u : all_UCs){
            if (u.get_UcCode() == uc){
                cout << endl << "The UC " << "\033[1m" << uc << 
                "\033[0m" << " has the following classes:" << endl;

                u.print_classes();
                valid = true;
            } 
        }

        if (!valid){
            cout << "I'm sorry, but that UC does not exist." << endl;
        }
    }
    else{
        cout << "Invalid command! Please, type another command.";
    }

    /*
    if (it1 != command.end() && it2 != target.end() && it3 != what.end()){
        if (s2 == "UC"){
            if (s3 == "classes"){
                cout << "Understood. Please select the desired UC.";

                string uc; cin >> uc;
                
                cout << "\033[1" + uc +  "\033[0m";

                bool valid = false;
                for (UC u : all_UCs){
                    if (u.get_UcCode() == uc){
                        u.print_classes();
                        valid = true;
                    } 
                }

                if (!valid){
                    cout << "I'm sorry, but that UC does not exist.";
                }
            }
        }
    }
    else{
        cout << "Invalid command! Please, type another command.";
    }
    */
}