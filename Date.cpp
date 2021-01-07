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

}

Date& Date::operator-=(const int& rhs){

}

//assignement operator

Date& Date::operator=(const Date&rhs){
   this->setYear(rhs.getYear());
   this->setMonth(rhs.getMonthNo());
   this->setDay(rhs.getDay());
}

//string cast

explicit operator std::string() const{

}

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