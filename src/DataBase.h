#ifndef PERSONALDIARY_DATABASE_H
#define PERSONALDIARY_DATABASE_H

#include "record.h"
#include "client.h"
#include <string>
#include <vector>

class DataBase {

public:
    explicit DataBase(std::string filename);
    std::vector<Client> getClients();

private:
    std::vector<Client> clients;

};


#endif //PERSONALDIARY_DATABASE_H
