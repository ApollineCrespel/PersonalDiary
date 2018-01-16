#include "client.h"
#include "DataBase.h"
#include <fstream>
#include <iostream>
using namespace std;


Client::Client(std::string user0, std::string password0) {
    user=user0;
    password=password0;
}


void Client::login(){

    DataBase Data("Donnees");
    std::vector<Client> clients = Data.getClients();

    int k = -1;

    for (int i=0; i <= clients.size(); i++) {

        if(user == clients[i].user){
            k = i;
            break;
        }

        else {
            k = -1;
        }
    }

    if (k == -1){
        cout << "ERROR. Wrong username"<< endl;
        logged=false;
    }

    else{
        if (password == clients[k].password){
            cout << "You have been successfully logged \n \n " << endl;
            logged=true;
        }

        else{
            cout<<"ERROR. Wrong password"<<endl;
            logged=false;
        }
    }

}




bool Client::islogged() {
    return logged;
}


void Client::logout(){
    logged = false;
}


void Client::changepassword() {
    DataBase Data("Donnees");
    std::vector<Client> clients = Data.getClients();

    ofstream file("/Users/apolline/Documents/PersonalDiary/src/Donnees.txt", ios::out|ios::trunc);
    std::string newpassword;

    int k = -1;

    for (int i=0; i <= clients.size(); i++) {

        if(user == clients[i].user){
            k = i;
            break;
        }

        else {
            k = -1;
        }
    }
    cout<<"Please enter your new password"<<endl;
    cin>>newpassword;

    clients[k].password=newpassword;

    for (unsigned int i=0; i<=clients.size(); i++){
        file<<clients[i].user<<":"<< clients[i].password<<endl;
    }

    cout<<"Your password have been successfully changed"<<endl;

}



