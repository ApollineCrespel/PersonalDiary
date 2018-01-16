#include <iostream>
#include <string.h>
#include <fstream>
//#include <ncurses.h>
#include "client.h"
#include "record.h"
#include "journal.h"
#include "DataBase.h"


using namespace std;



int main() {
    char another;
    std::string user;
    std::string password;
    int choice;



    std::cout << "Welcome in your personal diary management platform" << std::endl;
    std::cout << "Please specify your creditentials" << std::endl;
    std::cout << "User: ";
    std::cin >> user;
    std::cout << "Password: ";

    //initscr();
    //noecho();
    std::cin>>password;
    //echo();

    Client client(user, password);
    client.login();

    do{
    if (client.islogged()){

        Journal J("AllRecord");

        std::cout << "Welcome in the main menu " << std::endl;
        std::cout << "\t 1. View record" << std::endl;
        std::cout << "\t 2. Add record" << std::endl;
        std::cout << "\t 3. Edit record"<< std::endl;
        std::cout << "\t 4. Delete record" << std::endl;
        std::cout << "\t 5. Change Password" << std::endl;
        std::cout << "\t 6. Exit \n" << std::endl;

        std::cout << "Please specify your choice by entering the number \n"<<std::endl;
        std::cout<<"Go to:";
        std::cin>>choice;


        switch(choice){
            case 1:
                J.printrecords(1);
                break;

            case 2:
                J.addrecord();
                break;

            case 3:
                J.printrecords(2);
                break;

            case 4:
                J.printrecords(3);
                break;

            case 5:
                client.changepassword();
                break;

            case 6:
                std::cout<<"Thank you for using the diary provided by Apolline "<<std::endl;
                return 0;

            default:
                std::cout<<"You entered a wrong key. Please try again."<<std::endl;


        }
        cout<<"Do you want to return to the main menu ? (Y/N)"<<endl;
        cin>>another;
    }

    else {
        cout<< "ERROR. You are not logged in" << endl;
    }
    } while (another == 'Y' || another =='y');
    return 0;

}

