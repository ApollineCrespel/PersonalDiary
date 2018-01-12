#include "record.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <time.h>
#include <string>


using namespace std;


Record::Record(struct tm date0, std::string who0, std::string place0, std::string note0) {
    date = date0;
    who = who0;
    place = place0;
    //author_ptr = author0;
    note = note0;
    time_t nbsec = time(nullptr);
    lastedit = *localtime(&nbsec);

// on initialise les valeurs de record lors de sa création;
    // pour les modifier par la suite on utilise les fonctions set depuis le main

}

void Record::setdate(struct tm d) {
    date = d;
}

void Record::setwho(std::string w) {
    who = w;
}

void Record::setplace(std::string p) {
    place = p;
}

void Record::setnote(std::string n) {
    note = n;
}

struct tm Record::getdate() {
    return date;
}

void Record::print(){
    printf("Meeting with %s at %s. \n Note : %s", who.c_str(), place.c_str(), note.c_str());
}


void Record::setLastEdit(struct tm lastedit0){
    lastedit=lastedit0;
}

void Record::save() {

    char date_str[12];
    char lastedit0[12];

    strftime(date_str, 12, "%d-%m-%Y", &date);
    strftime(lastedit0, 12, "%d/%m/%Y", &lastedit);

    cout<<date_str<<endl;
    std::string nomfichier=date_str;
    nomfichier+=".txt";


    ofstream File ("/Users/apolline/Documents/PersonalDiary/src/Fichiers/" + nomfichier , ios::out);


    if (File){

        File << "Meeting with :" << who << " at:"<< place << endl;
        File << "Report:" << note << endl;
        File << "" << endl;
        File << "Last edit : " << lastedit0 << endl ;

        //File.close();

        cout<<"Your file has been successfully saved"<<endl;

    }

    else {
        cout << "ERROR. Your record cannot be saved."<< endl;
    }

}




