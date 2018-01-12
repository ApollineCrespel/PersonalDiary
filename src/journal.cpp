#include <iostream>
#include "journal.h"
#include "client.h"
#include"record.h"
#include <ctime>

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
    cout << "Enter the date of the record [jj_mm_aaaa]" << endl;
    cin >> date_str;

    while(!regex_match(date_str, regex("\\d{2}_\\d{2}_\\d{4}"))){
        cout<<"ERROR. Date is not in the right format"<<endl;
        cout<<"Enter the new date [jj_mm_aaaa]"<<endl;
        cin>> date_str;
    }


    struct tm d;
    strptime(date_str.c_str(), "%d_%m_%Y",&d);
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

    list.push_back(newRecord);
    newRecord.save();


}



void Journal::viewrecord(int index) {

    Record toView = list[index];
    toView.print();


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
            for (unsigned int i=0; i<=allLines.size(); i++){
                printf("Record n° %d dated: %s", i, allLines[i]);
            }

            cout<< "Enter the number of the record you want to use"<<endl;
            cin>>index;

            std::string date_str = allLines[index];

            ifstream r("/Users/apolline/Documents/PersonalDiary/src/Fichiers" + date_str);

/*
            if (0<=index<=allLines.size()){
                switch(option){
                    case 1:
                        j.viewrecord(index);

                    case 2:
                        j.editrecord(index);

                    case 3:
                        j.deleterecord(index);
                    }
                }

            else {
                cout<<"ERROR. You entered an invalid number"<<endl;
                }

        }
  */  }
}



/*
    for (unsigned int i=0; i<=list.size(); i++){

        char* date_str;
        struct tm date_tm=list[i].getdate();
        strftime(date_str, 12, "%d_%m_%Y", &date_tm);
        printf ("Record n° %d dated: %s", i, date_str);

    }
*/








void Journal::editrecord(int index) {
    struct tm lastedit0;
    time_t temps;

    char choice;
    Record toEdit = list[index];
    cout<<"Your record was:"<<endl;
    toEdit.print();

    struct tm d;
    std::string w, p, n, date_str;

    cout<<"Change date ? (Y/N)"<<endl;
    cin>>choice;

    if (choice == 'Y'|| choice=='y'){
        cout<<"Enter the new date [jj_mm_aaaa]"<<endl;
        cin >> date_str;
        while(!regex_match(date_str, regex("\\d{2}_\\d{2}_\\d{4}"))){
            cout<<"ERROR. Date is not in the right format"<<endl;
            cout<<"Enter the new date [jj_mm_aaaa]"<<endl;
            cin>> date_str;
    }
        strptime(date_str.c_str(), "%d_%m_%Y",&d);
        toEdit.setdate(d);
    }

    cout<<"Change person met ? (Y/N)"<<endl;
    cin>>choice;

    if (choice == 'Y' || choice=='y'){
        cout<<"Enter the new name"<<endl;
        cin>>w;
        toEdit.setwho(w);
    }

    cout<<"Change place ? (Y/N)"<<endl;
    cin>>choice;

    if (choice == 'Y' || choice=='y'){
        cout<<"Enter the new place"<<endl;
        cin>>p;
        toEdit.setplace(p);
    }

    cout<<"New note ? (Y/N)"<<endl;
    cin>>choice;

    if (choice == 'Y' || choice=='y'){
        cout<<"Enter the new note"<<endl;
        cin>>n;
        toEdit.setnote(n);
    }

    cout<<"Your record has been modified. The new record is:"<<endl;

    time(&temps);
    lastedit0 = *localtime(&temps);
    toEdit.setLastEdit(lastedit0);

    toEdit.save();
    toEdit.print();
}


void Journal::deleterecord(int index) {
    list.erase(list.begin() + index);
}


void Journal::close() {
    currentclient=nullptr;

}





