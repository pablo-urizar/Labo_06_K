/*-------------------------------------------------------------------------------
 Laboratory     : 07 - Person / Date
 File           : Person.cpp
 Authors        : Sarah Jallon, Pablo Urizar
 Date           : 08.01.2021
 Objective      : Class member functions' definition

 Comments       :

 Compiler       : MinGW-g++ 8.1.0
 -------------------------------------------------------------------------------*/

#include "Date.h"
#include <iostream>

//stream operator

std::ostream& operator<<(std::ostream& os, const Date& date){
   std::cout << date.getDay() << "-" << date.getMonthNo() << "-" << date.getYear();
   return os;
}

//comparison operators
bool operator<(const Date& lhs, const Date& rhs) {
   return (lhs.getYear() < rhs.getYear())                                               ||
          (lhs.getYear() == rhs.getYear()       && lhs.getMonthNo() < rhs.getMonthNo()) ||
          (lhs.getMonthNo() == rhs.getMonthNo() && lhs.getDay() < rhs.getDay());
}

bool operator>(const Date& lhs, const Date& rhs) {
   return rhs < lhs;
}

bool operator<=(const Date& lhs, const Date& rhs) {
   return !(lhs > rhs);
}

bool operator>=(const Date& lhs, const Date& rhs) {
   return !(lhs < rhs);
}

bool operator==(const Date& lhs, const Date& rhs) {
   return lhs.getYear() == rhs.getYear()       &&
          lhs.getMonthNo() == rhs.getMonthNo() &&
          lhs.getDay() == rhs.getDay();
}

bool operator!=(const Date& lhs, const Date& rhs) {
   return !(lhs == rhs);
}

//arithmetic operators

Date operator+(Date lhs,int rhs){

}

Date operator-(Date lhs, int rhs){

}

//commutativity of the arithmetic operators

Date operator+(int lhs,Date rhs){

}
Date operator-(int lhs, Date rhs){

}

//constructors

Date::Date(){
   this->day = 1;
   this->month = 1;
   this->year = 1900;
}
Date::Date(unsigned day, unsigned month, unsigned year){
   this->day = day;
   this->month = month;
   this->year = year;
}
Date::Date(std::string string){

}

// getter and setters
unsigned int Date::getDay() const {
   return day;
}

void Date::setDay(unsigned int day) {
   Date::day = day;
}

unsigned int Date::getMonthNo() const {
   return month;
}

void Date::setMonth(unsigned int month) {
   Date::month = month;
}
void Date::setMonth(std::string monthString) {
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

//compound assignement operators

Date& Date::operator++(){

}

Date& Date::operator++(int) {

}

Date& Date::operator--(){

}

Date& Date::operator--(int) {

}

Date& Date::operator+=(const int& rhs) {
   //ne pas faire de switch
   unsigned temp = rhs;
   while (temp){
      if (this->getDay() + temp < this->numberDaysInMonth()) {
         this->setDay(this->getDay() + rhs);
         temp = 0;
      }
      else {
         temp -= this->numberDaysInMonth() - this->getDay() - 1;
         this->incrementMonth();
         this->setDay(1);
      }
   }
}

Date& Date::operator-=(const int& rhs){
   unsigned temp = rhs;
   while (temp){
      if (this->getDay() - temp > 1) {
         this->setDay(this->getDay() - rhs);
         temp = 0;
      }
      else {
         temp -= this->getDay();
         this->decrementMonth();
         this->setDay(numberDaysInMonth());
      }
   }
}

//increment/decrement month

void Date::incrementMonth(){
   if ( this->getMonthNo() == 12 ){
      this->setMonth(1);
      this->setYear(this->getYear() + 1);
   }
   else {
      this->setMonth(this->getMonthNo() + 1);
   }
}

void Date::decrementMonth() {
   if ( this->getMonthNo() == 1 ){
      this->setMonth(12);
      this->setYear(this->getYear() - 1);
   }
   else {
      this->setMonth(this->getMonthNo() - 1);
   }
}

//assignement operator

Date& Date::operator=(const Date&rhs){
   this->setYear(rhs.getYear());
   this->setMonth(rhs.getMonthNo());
   this->setDay(rhs.getDay());
}

//string cast

//explicit operator std::string() const{

//}

//validation functions
bool Date::isValid(){

}

bool Date::isValid(unsigned day, unsigned month, unsigned year){

}

//leap year functions

bool Date::isLeapYear(){
   return (this->getYear() % 4 == 0 && this->getYear() % 100 != 0) || (this->getYear() % 400 == 0);
}

bool Date::isLeapYear(unsigned year){
   return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//number of day  in months functions

unsigned Date::numberDaysInMonth(){
   return this->getMonthNo() == int(Month::FEBRUARY) ? this->isLeapYear() ? 28 : 29 : 31 - this->getMonthNo() % 7 % 2;
}

static unsigned numberDaysInMonth(unsigned month, unsigned year){
   return month == int(Month::FEBRUARY) ? Date::isLeapYear(year) ? 28 : 29 : 31 - month % 7 % 2;
}