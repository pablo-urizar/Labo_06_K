#include "Date.h"

Date::Date(){
   day = 1;
   month = 1;
   year = 1900;
}
Date::Date(unsigned day, unsigned month, unsigned year){
   this->day = day;
   this->month = month;
   this->year = year;
}
Date::Date(std::string string){

}

unsigned int Date::getDay() const {
   return day;
}

void Date::setDay(unsigned int day) {
   Date::day = day;
}

unsigned int Date::getMonth() const {
   return month;
}

void Date::setMonth(unsigned int month) {
   Date::month = month;
}
void Date::setMonth(std::string month) {
   Date::month = month;
}

unsigned int Date::getYear() const {
   return year;
}

void Date::setYear(unsigned int year) {
   Date::year = year;
}

bool Date::isCorrect() const {
   return correct;
}

void Date::setCorrect(bool correct) {
   Date::correct = correct;
}


