#include <iostream>
#include "record.h"
#include <fstream>
using namespace std;


Journal::Journal(){


}


void Journal::addrecord() {
    Journal record;
    std::string date;
    std::string time;
    std::string who;
    std::string place;
    std::string note;

    std::cout<< "You are creating a new record to your diary." << std::endl;
    std::cout<< "Please enter the filename jj/mm/yyyy: " << std::endl;
    std::cin >>date;
    record.date=&date;

    ofstream file(*record.date, ios::out);









}
