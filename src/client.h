#ifndef CLIENT_H
#define CLIENT_H

#include <string>


class Client {
public:
    Client(std::string &user, std::string &password);
    ~Client();

private:
    static std::string db;
};


#endif // CLIENT_H
