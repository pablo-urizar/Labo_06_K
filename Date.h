/*-------------------------------------------------------------------------------
 Laboratory     : 07 - Person / Date
 File           : Date.h
 Authors        : Sarah Jallon, Pablo Urizar
 Date           : 08.01.2021
 Objective      : Class member functions' declaration

 Comments       : This class overrides:
                  - the stream operator,
                  - the comparison operators,
                  - some arithmetic operators ( +=, -=, +, - , ++, --),
                  - the assignation operator,
                  It also describes:
                  - The getter and setters of the class,
                  - incrementMonth(), decrementMonth(),
                  - isLeapYear()
                  - numberOfDaysInMonth(),
                  - a function to know if an instance of a class is valid

 Compiler       : MinGW-g++ 8.1.0
 -------------------------------------------------------------------------------*/


#ifndef LABO_06_K_DATE_H
#define LABO_06_K_DATE_H

#include <string>
#include <array>

 enum class Month { JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
                     AUGUST, SEPTEMBER, OCTOBRER, NOVEMBRER, DECEMBRER};

class Date {
   //stream operator

   friend std::ostream& operator<<(std::ostream& os, const Date& date);

   //comparison operators

   friend bool operator<(const Date& lhs, const Date& rhs);
   friend bool operator>(const Date& lhs, const Date& rhs);
   friend bool operator<=(const Date& lhs, const Date& rhs);
   friend bool operator>=(const Date& lhs, const Date& rhs);
   friend bool operator==(const Date& lhs, const Date& rhs);
   friend bool operator!=(const Date& lhs, const Date& rhs);

   //arithmetic operators

   friend Date operator+(Date lhs,int rhs);
   friend Date operator-(Date lhs, int rhs);

   //commutativity of the arithmetic operators

   friend Date operator+(int lhs,Date rhs);

public:

   //constructeurs

   Date();
   Date(unsigned int day, unsigned int month, unsigned int year);
   explicit Date(const std::string& string);
   Date(const Date& date) : day(date.day), month(date.month), year(date.year){
      isValid() ? setCorrect(true) : setCorrect(false);
   }

   //getter and setter

   unsigned int getDay() const;
   void         setDay(unsigned int day);

   unsigned int getMonthNo() const;
   Month        getMonthEnum() const;
   std::string  getMonthString() const;
   void         setMonth(unsigned int month);
   void         setMonth(const std::string& monthString);
   void         setMonth(Month month);

   unsigned int getYear() const;
   void setYear(unsigned int year);

   bool isCorrect() const;
   void setCorrect(bool correct);

   //compound assignement operators

   Date& operator++();       //ante incr.
   Date& operator++(int);    //post incr.
   Date& operator--();       //ante decr.
   Date& operator--(int);    //post decr.
   Date& operator+=(const int& rhs);
   Date& operator-=(const int& rhs);

   //increment/decrement month

   void incrementMonth();
   void decrementMonth();

   //assignement operator

   Date& operator=(const Date&rhs);

   //string cast

   explicit operator std::string() const;

   //validation functions

   bool isValid() const;
   static bool isValid(unsigned day, unsigned month, unsigned year);

   //leap year functions

   bool isLeapYear() const;
   static bool isLeapYear(unsigned year);

   //number of day  in months functions

   unsigned numberDaysInMonth() const;
   static unsigned numberDaysInMonth(unsigned month, unsigned year);

private:

   unsigned day,
            month,
            year;
   bool     correct = true;
};

#endif //LABO_06_K_DATE_H
