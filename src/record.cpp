#include "record.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <time.h>
#include <string>

#include <regex>


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
    printf("Meeting with %s at %s. \n %s \n", who.c_str(), place.c_str(), note.c_str());
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

        File << "Meeting with:" << who << endl;
        File << "At:"<< place << endl;
        File << "Report:" << note << endl;
        File << ""<<endl;
        File << "Last edit: " << lastedit0 << endl ;

        cout<<"Your file has been successfully saved"<<endl;

    }

    else {
        cout << "ERROR. Your record cannot be saved."<< endl;
    }

}



void Record::editrecord() {
    struct tm lastedit0;
    time_t temps;

    char want;

    cout<<"Your record was:"<<endl;
    print();

    struct tm d;
    std::string w, p, n, date_str;

    cout<<"Change date ? (Y/N)"<<endl;
    cin>>want;

    if (want == 'Y'|| want=='y'){
        cout<<"Enter the new date [jj_mm_aaaa]"<<endl;
        cin >> date_str;
        while(!regex_match(date_str, regex("\\d{2}_\\d{2}_\\d{4}"))){
            cout<<"ERROR. Date is not in the right format"<<endl;
            cout<<"Enter the new date [jj_mm_aaaa]"<<endl;
            cin>> date_str;
        }
        strptime(date_str.c_str(), "%d_%m_%Y",&d);
        setdate(d);
    }

    cout<<"Change person met ? (Y/N)"<<endl;
    cin>>want;

    if (want == 'Y' || want=='y'){
        cout<<"Enter the new name"<<endl;
        cin>>w;
        setwho(w);
    }

    cout<<"Change place ? (Y/N)"<<endl;
    cin>>want;

    if (want == 'Y' || want=='y'){
        cout<<"Enter the new place"<<endl;
        cin>>p;
        setplace(p);
    }

    cout<<"New note ? (Y/N)"<<endl;
    cin>>want;

    if (want == 'Y' || want=='y'){
        cout<<"Enter the new note"<<endl;
        cin>>n;
        setnote(n);
    }

    cout<<"Your record has been modified. The new record is:"<<endl;

    time(&temps);
    lastedit0 = *localtime(&temps);
    setLastEdit(lastedit0);

    save();
    print();
}
