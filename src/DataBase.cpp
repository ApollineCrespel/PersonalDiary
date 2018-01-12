#include "DataBase.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "client.h"

using namespace std ;

DataBase::DataBase(std::string filename) {
    ifstream file("/Users/apolline/Documents/PersonalDiary/src/"+ filename + ".txt");

    if (file){


        std::string line;
        std::vector<string> allLines;

        while(!file.eof()){
            getline(file,line);
            allLines.push_back(line);
        }

        for (unsigned int i=0; i<allLines.size(); i++){
            std::string useri;
            std::string passwordi;
            std::size_t sep = allLines[i].find(':');
            useri = allLines[i].substr(0,sep);    // user:password à chaque ligne
            passwordi = allLines[i].substr(sep+1,allLines[i].size());
            Client c(useri,passwordi);
            clients.push_back(c);
        }

        }

    else {
        cout<<"ERROR. File couldn't be read"<<endl;
    }
}


std::vector<Client> DataBase::getClients() {
    return clients;
}