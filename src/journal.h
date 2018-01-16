#ifndef JOURNAL_H
#define JOURNAL_H

#include <string>
#include <vector>
#include "record.h"
#include "client.h"

class Journal {

public:
    Journal(std::string title0);
    void open(Client *c);
    void addrecord();


    void deleterecord(int index);
    void printrecords(int option);
    void close();
    void settitle(std::string t);

private:

    //std::vector<Record> list;
    std::string title;
    Client *currentclient;

};


#endif //JOURNAL_H
