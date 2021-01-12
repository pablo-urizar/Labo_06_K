/*-------------------------------------------------------------------------------
 Laboratory     : 07 - Person / Date
 File           : Date.cpp
 Authors        : Sarah Jallon, Pablo Urizar
 Date           : 08.01.2021
 Objective      : Class member functions' definition
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
   if (date.isValid()) {
      std::cout << std::setfill('0') << std::setw(2) << date.getDay() << "-"
                << std::setfill('0') << std::setw(2) << date.getMonthNo() << "-"
                << date.getYear();
   }
   else {
      std::cout << "Invalid date";
   }
   return os;
}

//comparison operators

bool operator<(const Date& lhs, const Date& rhs) {
      return lhs.isValid() && rhs.isValid() && (
                  (lhs.getYear() < rhs.getYear()) ||
                  (lhs.getYear() == rhs.getYear() && lhs.getMonthNo() < rhs.getMonthNo()) ||
                  (lhs.getMonthNo() == rhs.getMonthNo() && lhs.getDay() < rhs.getDay())
              );
}

bool operator>(const Date& lhs, const Date& rhs) {
   return lhs.isValid() && rhs.isValid() && rhs < lhs;
}

bool operator<=(const Date& lhs, const Date& rhs) {
   return lhs.isValid() && rhs.isValid() && !(lhs > rhs);
}

bool operator>=(const Date& lhs, const Date& rhs) {
      return lhs.isValid() && !(lhs < rhs);
}

bool operator==(const Date& lhs, const Date& rhs) {
   return lhs.isValid()    && rhs.isValid()    &&
          lhs.getYear()    == rhs.getYear()    &&
          lhs.getMonthNo() == rhs.getMonthNo() &&
          lhs.getDay()     == rhs.getDay();
}

bool operator!=(const Date& lhs, const Date& rhs) {
   return lhs.isValid() && rhs.isValid() && !(lhs == rhs);
}

//arithmetic operators

Date operator+(Date lhs,int rhs){
   return lhs.isValid() ? lhs += rhs : lhs;    //invalid date -> lhs is unchanged
}

Date operator-(Date lhs, int rhs){
   return lhs.isValid() ? lhs -= rhs : lhs;
}

//commutativity of the arithmetic operators

Date operator+(int lhs,Date rhs){
   return rhs.isValid() ? rhs += lhs : rhs;
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
   isValid() ? setCorrect(true) : setCorrect(false);
}
Date::Date(const std::string& string){
   day   = stoi(string.substr(0,2));
   month = stoi(string.substr(3,2));
   year  = stoi(string.substr(6,4));
   isValid() ? setCorrect(true) : setCorrect(false);
}

// getter and setters
unsigned int Date::getDay() const {
   return day;
}

void Date::setDay(unsigned int day) {
   Date::day = day;
   isValid() ? setCorrect(true) : setCorrect(false);
}

unsigned int Date::getMonthNo() const {
   return month;
}

Month Date::getMonthEnum() const {
   return Month(getMonthNo());
}

std::string Date::getMonthString() const{
   return monthArray[getMonthNo()-1];
}

void Date::setMonth(unsigned int month) {
   this->month = month;
   isValid() ? setCorrect(true) : setCorrect(false);
}

void Date::setMonth(const std::string& monthString) {
   auto it = std::find(monthArray.begin(), monthArray.end(), monthString);
   if ( it != monthArray.end()){
      setMonth(it - monthArray.begin() + 1);
   } else {
      std::cout << "enter a correct month name" << std::endl;
      assert(false);
   }
   isValid() ? setCorrect(true) : setCorrect(false);
}

void Date::setMonth(Month month){
   this->month = unsigned(month);
   isValid() ? setCorrect(true) : setCorrect(false);
}

unsigned int Date::getYear() const {
   return year;
}

void Date::setYear(unsigned int year) {
   this->year = year;
   isValid() ? setCorrect(true) : setCorrect(false);
}

bool Date::isCorrect() const {
   return correct;
}

void Date::setCorrect(bool correct) {
   Date::correct = correct;
}

//compound assignement operators

Date& Date::operator++(){
   return isValid() ? *this += 1 : *this;
}

Date& Date::operator++(int) {
   Date& temp = *this;
   if(isValid()) ++*this;
   return temp;
}

Date& Date::operator--(){
   return isValid() ? *this-= 1 : *this;
}

Date& Date::operator--(int) {
   Date &temp = *this;
   if(isValid()) --*this;
   return temp;
}

Date& Date::operator+=(const int& rhs) {
   if(isValid()) {
      unsigned temp = rhs;
      while (temp) {
         if (getDay() + temp < numberDaysInMonth()) {
            setDay(getDay() + temp);
            temp = 0;
         } else {
            temp -= numberDaysInMonth() - getDay() + 1;
            incrementMonth();
            setDay(1);
         }
      }
   }
   return *this;
}

Date& Date::operator-=(const int& rhs){
   if (isValid()) {
      int temp = rhs;
      while (temp) {
         if (int(day) - temp >= 1) {
            day -= temp;
            temp = 0;
         } else {
            temp -= day;
            decrementMonth();
            day = numberDaysInMonth();
         }
      }
   }
   return *this;
}

//increment/decrement month

void Date::incrementMonth(){
   if ( getMonthNo() == 12 ){
      month = 1;
      year += 1;
   }
   else {
      month += 1;
   }
}

void Date::decrementMonth() {
   if ( month == 1 ){
      month = 12;
      year -= 1;
   }
   else {
      month -= 1;
   }
}

//assignement operator

Date& Date::operator=(const Date&rhs){
   year  = rhs.getYear();
   month = rhs.getMonthNo();
   day   = rhs.getDay();
   isValid() ? setCorrect(true) : setCorrect(false);
   return *this;
}

//string cast

Date::operator std::string() const{
   if (isValid()) {
      std::stringstream convert;
      convert << std::setfill('0') << std::setw(2) << day << "-"
              << std::setfill('0') << std::setw(2) << month << "-"
              << std::setw(4) << year;
      std::string string = convert.str();
      return string;
   }
   else {
      return "Invalid date";
   }
}

//validation

bool Date::isValid() const{
   return isValid(day,month,year);
}

bool Date::isValid(unsigned day, unsigned month, unsigned year){
   return month <= 12 && month >= 1 && day <= numberDaysInMonth(month, year) && day >= 1;
}

//leap year

bool Date::isLeapYear() const {
   return isLeapYear(year);
}

bool Date::isLeapYear(unsigned year){
   return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//number of day in month

unsigned Date::numberDaysInMonth() const{
   return numberDaysInMonth(month, year);
}
unsigned Date::numberDaysInMonth(unsigned month, unsigned year){
   return month == int(Month::FEBRUARY) ? Date::isLeapYear(year) ? 29 : 28 : 31 - (month-1) % 7 % 2;
}