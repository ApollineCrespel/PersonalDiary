#ifndef PERSONALDIARY_RECORD_H
#define PERSONALDIARY_RECORD_H
#include <string>
#include <ctime>
#include "client.h"

class Record {
public:
    Record(struct tm date0, std::string who0, std::string place0, std::string note0, Client *author0);
    void setdate(struct tm date);
    void setwho(std::string who);
    void setplace(std::string place);
    void setnote(std::string note);


private:
    struct tm date;
    std::string who;
    std::string place;
    Client *author_ptr;
    std::string note;
    struct tm lastedit;



};


#endif //PERSONALDIARY_RECORD_H
