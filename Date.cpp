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
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <array>
#include <cassert>

std::array<std::string,12> monthArray = {"January", "February", "March", "April", "May", "June", "July",
"August", "September", "October", "November", "December"};

//stream operator

std::ostream& operator<<(std::ostream& os, const Date& date){
   std::cout << std::setfill('0') << std::setw(2) << date.getDay() << "-"
             << std::setfill('0') << std::setw(2) << date.getMonthNo() << "-"
             << date.getYear();
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
   return lhs += rhs;
}

Date operator-(Date lhs, int rhs){
   return lhs -= rhs;
}

//commutativity of the arithmetic operators

Date operator+(int lhs,Date rhs){
   return rhs += lhs;
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
Date::Date(const std::string& string){
   this->day   = stoi(string.substr(0,2));
   this->month = stoi(string.substr(3,2));
   this->year  = stoi(string.substr(6,4));
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

Month Date::getMonthEnum() const {
   return Month(getMonthNo());
}

std::string Date::getMonthString() const{
   return monthArray[this->getMonthNo()-1];
}

void Date::setMonth(unsigned int month) {
   Date::month = month;
}

void Date::setMonth(const std::string& monthString) {
   auto it = std::find(monthArray.begin(), monthArray.end(), monthString);
   if ( it != monthArray.end()){
      setMonth(it - monthArray.begin() + 1);
   } else {
      std::cout << "enter a correct month name" << std::endl;
      assert(false);
   }
}

void Date::setMonth(Month month){
   this->setMonth(unsigned(month));
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
   return *this += 1;
}

Date& Date::operator++(int) {
   Date& temp = *this;
   ++*this;
   return temp;
}

Date& Date::operator--(){
   return *this-= 1;
}

Date& Date::operator--(int) {
   Date& temp = *this;
   --*this;
   return temp;
}

Date& Date::operator+=(const int& rhs) {
   unsigned temp = rhs;
   while (temp){
      if (this->getDay() + temp < this->numberDaysInMonth()) {
         this->setDay(this->getDay() + temp);
         temp = 0;
      }
      else {
         temp -= numberDaysInMonth() - getDay() + 1;
         incrementMonth();
         setDay(1);
      }
   }
   return *this;
}

Date& Date::operator-=(const int& rhs){
   int temp = rhs;
   while (temp){
      if (int(this->getDay()) - temp >= 1) {
         this->setDay(this->getDay() - temp);
         temp = 0;
      }
      else {
         temp -= this->getDay();
         this->decrementMonth();
         this->setDay(numberDaysInMonth());
      }
   }
   return *this;
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
   year  = rhs.getYear();
   month = rhs.getMonthNo();
   day   = rhs.getDay();
   return *this;
}

//string cast

Date::operator std::string() const{
   std::stringstream convert;
   convert << std::setfill('0') << std::setw(2) << day   << "-"
           << std::setfill('0') << std::setw(2) << month << "-"
           << std::setw(4) << year;
   std::string string = convert.str();
   return string;
}

//validation functions
bool Date::isValid() const{
   return isValid(day,month,year);
}

bool Date::isValid(unsigned day, unsigned month, unsigned year){
   //todo
   return true;
}

//leap year functions

bool Date::isLeapYear() const {
   return isLeapYear(this->getYear());
}

bool Date::isLeapYear(unsigned year){
   return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//number of day  in months functions

unsigned Date::numberDaysInMonth() const{
   return numberDaysInMonth(this->getMonthNo(), this->getYear());
}
unsigned Date::numberDaysInMonth(unsigned month, unsigned year){
   return month == int(Month::FEBRUARY) ? Date::isLeapYear(year) ? 29 : 28 : 31 - (month-1) % 7 % 2;
}