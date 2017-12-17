#include <iostream>
#include <string>
#include "client.h"


int main() {
    std::string user;
    std::string password;

    std::cout << "Welcome in your personal diary management platform" << std::endl;
    std::cout << "Please specify your creditentials" << std::endl;
    std::cout << "User: ";
    std::cin >> user;
    std::cout << "Password: ";
    std::cin >> password;

    Client client(user, password);
    

    return 0;
}
