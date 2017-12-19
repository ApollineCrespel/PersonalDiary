#ifndef PERSONALDIARY_RECORD_H
#define PERSONALDIARY_RECORD_H

#include <string>

class Record {

public: // on met toutes les methodes de la classe
    Record();
    ~Record();

    void viewrecord();
    void addrecord();
    void editrecord();
    void deleterecord();

private: // on met tout les attributs de la classe
    std::string *date;
    std::string *time;
    std::string *who;
    std::string *place;
    std::string *note;


};


#endif //PERSONALDIARY_RECORD_H
