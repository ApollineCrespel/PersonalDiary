#include "record.h"

Record::Record(struct tm date0, std::string who0, std::string place0, std::string note0, Client *author0) {
    date = date0;
    who = who0;
    place = place0;
    author_ptr = author0;
    note = note0;
    time_t nbsec = time(nullptr);
    lastedit = *localtime(&nbsec);



}

void Record::setdate(struct tm date) {

}