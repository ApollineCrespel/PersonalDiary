#ifndef CLIENT_H
#define CLIENT_H

#include <string>

/*
 * Cette classe permet d'avoir une interaction entre utilisateur et BDD.
 */

class Client {
public:
    Client(std::string user0, std::string password0);
    void login();
    void logout();
    void changepassword();
    bool islogged();

private:
    std::string user;
    std::string password;
    bool logged;

};


#endif // CLIENT_H
