#ifndef PERSONALDIARY_RECORD_H
#define PERSONALDIARY_RECORD_H

#include <string>
#include <vector>
#include "record.h"
#include "client.h"

class Journal {

public: // on met toutes les methodes de la classe
    Journal();
    void open(Client);
    void addrecord();
    void viewrecord(int index);
    void editrecord(int index);
    void deleterecord(int index);
    void printrecords();
    void close();



private: // on met tout les attributs de la classe

    std::vector<Record> list;
    std::string title;
    Client *currentclient;

};


#endif //PERSONALDIARY_RECORD_H
