#include <iostream>
#include <string>
#include "client.h"
#include "journal.h"
#include <fstream>

using namespace std;



int main() {
    std::string user;
    std::string password;
    char choice;

    Journal record;

    std::cout << "Welcome in your personal diary management platform" << std::endl;
    std::cout << "Please specify your creditentials" << std::endl;
    std::cout << "User: ";
    std::cin >> user;
    std::cout << "Password: ";
    std::cin >> password;

    Client client(user, password);

    std::cout << "Welcome in the main menu " << std::endl;
    std::cout << "1. View Journal" << std::endl;
    std::cout << "2. Add Journal" << std::endl;
    std::cout << "3. Edit Journal" << std::endl;
    std::cout << "4. Delete Journal" << std::endl;
    std::cout << "5. Change Password" << std::endl;
    std::cout << "6. Exit" << std::endl;

    std::cout << "Please specify your choice by entering the number"<<std::endl;
    std::cout<<"Go to: ";
    std::cin>>choice;
    choice=int(choice);

    switch(choice){
        case 1:
            record.viewrecord();
            break;

        case 2:
            record.addrecord();
            break;

        case 3:
            record.editrecord();
            break;

        case 4:
            record.deleterecord();
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







    return 0;
}
