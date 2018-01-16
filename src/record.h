#ifndef PERSONALDIARY_RECORD_H
#define PERSONALDIARY_RECORD_H
#include <string>
#include <ctime>
#include "client.h"

class Record {
public:
    Record(struct tm date0, std::string who0, std::string place0, std::string note0);
    void setdate(struct tm d);
    void setwho(std::string w);
    void setplace(std::string p);
    void setnote(std::string n);
    struct tm getdate();
    void setLastEdit(struct tm lastedit0);
    void print();

    void editrecord();

    void save();

private:
    struct tm date;
    std::string who;
    std::string place;
    std::string note;
    struct tm lastedit;

};


#endif //PERSONALDIARY_RECORD_H
