#ifndef LABO_06_K_DATE_H
#define LABO_06_K_DATE_H

#include <string>

enum class Months { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
                     AUGUST, SEPTEMBER, OCTOBRER, NOVEMBRER, DECEMBRER};



class Date {
public:
   //constructeurs
   Date();
   Date(unsigned int day, unsigned int month, unsigned int year);
   Date(std::string string);
   Date(const Date& date) : day(date.day), month(date.month), year(date.year){}

   unsigned int getDay() const;

   void setDay(unsigned int day);

   unsigned int getMonth() const;

   void setMonth(unsigned int month);

   void setMonth(std::string month);

   void setMonth(Month);


   unsigned int getYear() const;

   void setYear(unsigned int year);

   bool isCorrect() const;

   void setCorrect(bool correct);;
private:

   unsigned day,
      month,
      year;
   bool     correct = true;
};

#endif //LABO_06_K_DATE_H
