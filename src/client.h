#ifndef CLIENT_H
#define CLIENT_H

#include <string>

/*
 * Cette classe permet d'avoir une interaction entre utilisateur et BDD.
 */

class Client {
public:
    Client(std::string &user, std::string &password);
    ~Client();

    void changepassword();

private:
    static std::string db;
};


#endif // CLIENT_H
