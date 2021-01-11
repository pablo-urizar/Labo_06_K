/*-------------------------------------------------------------------------------
 Laboratory     : 07 - Person / Date
 File           : Person.h
 Authors        : Sarah Jallon, Pablo Urizar
 Date           : 11.01.2021
 Objective      : Class member functions' prototypes

 Comments       : Functions implemented in library:
                    - Create person
                        Usage : Person person (string lastName, string firstName, Date date)

                    - Sort the list of people by any of its attributes
                        Usage : SortBy(PERSON type)

                    - Find a person by any of its attributes
                        Usage : FindBy(PERSON type, const string strToFind)

 Compiler       : MinGW-g++ 8.1.0
 -------------------------------------------------------------------------------*/

#ifndef LABO_06_K_PERSON_H
#define LABO_06_K_PERSON_H

#include <string>
#include "Date.h"

enum class PERSON {LASTNAME, FIRSTNAME, DATE, NO_ID};

// Friend classes used in class Person
class SortBy;
class FindBy;

//-------------------------------- Class Person ---------------------------------//
class Person {
public:
    // Default constructor
    Person(std::string lastName, std::string firstName, Date date);

    // Copy constructor
    Person(const Person& p);

    // Assignment constructor
    Person& operator=(const Person& p);

    // Destructor
    ~Person();

    // Returns number of 'active' Person's objects
    static unsigned nbrePerson();

    // Getters
    std::string getLastName() const;
    std::string getFirstName() const;
    Date getDate() const;
    unsigned getID() const;

    // Display person's attributes
    friend std::ostream& operator<<(std::ostream& os, const Person& p);

private:
    // Class attributes
    const std::string lastName;
    const std::string firstName;
    const Date date;
    const unsigned id;

    static unsigned nextId;
    static unsigned nbre;

    // Friend classes
    friend SortBy;
    friend FindBy;
};

//-------------------------------- Class SortBy ---------------------------------//
class SortBy {
public:
    SortBy(PERSON type);
    bool operator() (const Person& p1, const Person& p2);

private:
    // Class attribute
    PERSON type;
};

//-------------------------------- Class FindBy ---------------------------------//
class FindBy {
public:
    FindBy(PERSON type, const std::string valeur);
    bool operator()(Person p);

private:
    // Class attributes
    PERSON type;
    const std::string findByStr;
};

#endif //LABO_06_K_PERSON_H
