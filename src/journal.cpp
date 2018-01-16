#include <iostream>
#include "journal.h"
#include "client.h"
#include"record.h"
#include <ctime>
#include <stdio.h>
#include <fstream>
#include <regex>
#include <string>

using namespace std;


Journal::Journal(std::string title0){
    currentclient=nullptr;
    title=title0;
}

void Journal::settitle(std::string t) {
    title=t;
}


void Journal::open(Client *c){
    if (c->islogged()){
        currentclient = c;

    }
    else {
        cout<< "ERROR. Client is not logged in." <<endl;
    }
}



void Journal::addrecord() {
    struct tm lastedit0;
    time_t temps;

    std::string date_str;
    cout << "You are creating a new record" << endl;
    cout << "Enter the date of the record [jj-mm-aaaa]" << endl;
    cin >> date_str;

    while(!regex_match(date_str, regex("\\d{2}-\\d{2}-\\d{4}"))){
        cout<<"ERROR. Date is not in the right format"<<endl;
        cout<<"Enter the new date [jj-mm-aaaa]"<<endl;
        cin>> date_str;
    }


    struct tm d;
    strptime(date_str.c_str(), "%d-%m-%Y",&d);
    std::string w;
    std::string p;
    std::string n;


    cout<<"Enter the meeting organizer name"<<endl;
    cin>>w;
    cout<<"Enter the place"<<endl;
    cin>>p;
    cout<<"Enter the note"<<endl;
    cin>>n;

    Record newRecord(d,w,p,n);
    time(&temps);
    lastedit0 = *localtime(&temps);
    newRecord.setLastEdit(lastedit0);

    ofstream List("/Users/apolline/Documents/PersonalDiary/src/List.txt",ios::app);
    List<<date_str<<endl;
    newRecord.save();


}



void Journal::printrecords(int option) {

    fstream list ("/Users/apolline/Documents/PersonalDiary/src/List.txt");
    std::string title;
    cout<<"To proceed your action please enter the Journal's name"<<endl;
    cin>>title;

    if (list){
        Journal j(title);
        std::string line;
        std::vector<string> allLines;


        int index;

        while(!list.eof()){
            getline(list,line);
            allLines.push_back(line);
        }

        if (allLines.empty()){
            cout<<"You have not saved any record yet."<<endl;
        }


        else {
            for (unsigned int i=0; i<allLines.size(); i++){
                printf("Record n° %d dated: %s \n", i, allLines[i].c_str());
            }

            cout<< "Enter the number of the record you want to use"<<endl;
            cin>>index;

            struct tm d;
            std::string date_str = allLines[index];

            ifstream r("/Users/apolline/Documents/PersonalDiary/src/Fichiers/" + date_str + ".txt");

            strptime(date_str.c_str(), "%d-%m-%Y",&d);

            std::string element;
            std::vector<string> full;

            while(!r.eof()){
                getline(r, element);
                full.push_back(element);
            }

            std::size_t sep = full[0].find(':');
            std::string w = full[0].substr(sep+1,full[0].size());

            sep = full[1].find(':');
            std::string p = full[1].substr(sep+1,full[1].size());

            std::string n;
            for (unsigned int i=2; i<full.size()-1; i++){
                n+=full[i];
            }

            Record toPrint(d,w,p,n);

            if (0<=index<=allLines.size()){

                switch(option){
                    case 1:
                        toPrint.print();
                        break;

                    case 2:
                        toPrint.editrecord();
                        break;

                    case 3:
                        j.deleterecord(index);
                        break;

                    default:
                        std::cout<<"ERROR"<<std::endl;
                }
            }

            else {
                cout<<"ERROR. You entered an invalid number"<<endl;
                }

        }
    }
}




void Journal::deleterecord(int index) {
    fstream list ("/Users/apolline/Documents/PersonalDiary/src/List.txt");
    std::string line;
    std::vector<string> allLines;
    while(!list.eof()){
        getline(list,line);
        allLines.push_back(line);
    }

    std::string date_str = allLines[index];
    std::string nomfichier= "/Users/apolline/Documents/PersonalDiary/src/Fichiers/" + date_str + ".txt";
    const char* f=nomfichier.c_str();
    std::remove(f);

    list.close();
    ofstream List("/Users/apolline/Documents/PersonalDiary/src/List.txt",ios::out|ios::trunc);

    for (unsigned int i=0; i<=allLines.size(); i++){
        if (i!=index){
            List<<allLines[i]<<endl;
        }
    }
}


void Journal::close() {
    currentclient=nullptr;

}





