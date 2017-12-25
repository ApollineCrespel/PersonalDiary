#ifndef PERSONALDIARY_RECORD_H
#define PERSONALDIARY_RECORD_H

#include <string>

class Journal {

public: // on met toutes les methodes de la classe
    Journal();



    void lock();
    void unlock(std::string user, std::string password);

    void viewrecord();
    void addrecord();
    void editrecord();
    void deleterecord();

private: // on met tout les attributs de la classe
    std::string date; // mettre le vrai format date natif de Cpp

    std::string time;
    std::string who;
    std::string place;
    std::string note;


};


#endif //PERSONALDIARY_RECORD_H
