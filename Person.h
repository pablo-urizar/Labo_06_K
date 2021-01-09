/*-------------------------------------------------------------------------------
 Laboratory     : 07 - Person / Date
 File           : Person.h
 Authors        : Sarah Jallon, Pablo Urizar
 Date           : 08.01.2021
 Objective      : Class members' prototypes

 Comments       :

 Compiler       : MinGW-g++ 8.1.0
 -------------------------------------------------------------------------------*/
#ifndef LABO_06_K_PERSON_H
#define LABO_06_K_PERSON_H

#include <string>
#include "Date.h"

using namespace std;

enum class PERSON {LASTNAME, FIRSTNAME, DATE, NO_ID};

// Friend classes used in class Person
class SortBy;
class FindBy;


//------------------------------- Class Person --------------------------------//
class Person {
public:
    // Default constructor
    Person(string lastName, string firstName, Date date);

    // Copy constructor
    Person(const Person& p);

    // Assignment constructor
    Person& operator=(const Person& p);

    // Destructor
    ~Person();

    // Returns number of 'active' Person's objects
    static unsigned nbrePerson();

    // Getters
    string getLastName() const;
    string getFirstName() const;
    Date getDate() const;
    unsigned getID() const;

    // Display person's attributes
    friend ostream& operator<<(ostream& os, const Person& p);

private:
    // Class attributes
    const string lastName;
    const string firstName;
    const Date date;
    const unsigned id;

    static unsigned nextId;
    static unsigned nbre;

    // Friend classes
    friend SortBy;
    friend FindBy;
};

//------------------------------- Class SortBy --------------------------------//
class SortBy {
public:
    SortBy(PERSON type);
    bool operator() (const Person& p1, const Person& p2);

private:
    // Class attribute
    PERSON type;
};

//------------------------------- Class FindBy --------------------------------//
class FindBy {
public:
    FindBy(PERSON type, const string valeur);
    bool operator()(Person p);

private:
    // Class attributes
    PERSON type;
    const string findByStr;
};

#endif //LABO_06_K_PERSON_H
