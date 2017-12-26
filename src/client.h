#ifndef CLIENT_H
#define CLIENT_H

#include <string>

/*
 * Cette classe permet d'avoir une interaction entre utilisateur et BDD.
 */

class Client {
public:
    Client(std::string &user, std::string &password);
    void login(std::string user, std::string password);
    void logout();
    void changepassword(std::string user, std::string password);

private:
    std::string user;
    std::string password;
    bool logged;

};


#endif // CLIENT_H
