/*-------------------------------------------------------------------------------
 Laboratory     : 07 - Person / Date
 File           : Person.cpp
 Authors        : Sarah Jallon, Pablo Urizar
 Date           : 08.01.2021
 Objective      : Class member functions' definition

 Comments       :

 Compiler       : MinGW-g++ 8.1.0
 -------------------------------------------------------------------------------*/
#include "Person.h"

#include <iomanip>
#include <algorithm>

// Static variables initialization
unsigned Person::nextId = 0;
unsigned Person:: nbre = 0;

string Person::getLastName() const {
    return this->lastName;
}

string Person::getFirstName() const {
    return this->firstName;
}

// "String date" - temporary
string Person::getDate() const {
    return this->date;
}

unsigned Person::getID() const {
    return this->id;
}

unsigned Person::nbrePerson() {
    return nbre;
};

//-------------------------------------- Class Person ---------------------------------------//
// Default constructor
Person::Person(string lastName, string firstName, string date) : lastName(lastName), firstName(firstName),
date(date), id(++nextId) {++nbre;}

// Copy constructor
Person::Person(const Person& p) : lastName(p.lastName), firstName(p.firstName), date(p.date), id(p.id) {++nbre;}

// Assignment constructor
Person& Person::operator=(const Person& p) {
    if (this != &p) {
        (string&) lastName = p.getLastName();
        (string&) firstName = p.getFirstName();
        (string&) date = p.getDate();
        (unsigned&) id = p.getID();
    }
    return *this;
}

// Destructor
Person::~Person() {--nbre;}

// Display person's attributes
ostream& operator<<(ostream& os, const Person& p) {
    os  <<p.lastName
        << '\t' << p .firstName
        << '\t' << p.date
        << '\t' << "(id=" << to_string(p.id) << ')';

    return os;
}

//-------------------------------------- Class SortBy ---------------------------------------//
SortBy::SortBy(PERSON type) : type(type){this->type = type;}

bool SortBy::operator() (const Person& p1, const Person& p2) {
    switch (type) {
        case PERSON::LASTNAME:
            return (p1.getLastName() < p2.getLastName());

        case PERSON::FIRSTNAME:
            return (p1.getFirstName() < p2.getFirstName());

        case PERSON::DATE:
            return p1.getDate() < p2.getDate();

        case PERSON::NO_ID:
            return p1.getID() < p2.getID();

        default:
            return false;
    }
}

//-------------------------------------- Class FindBy ---------------------------------------//
FindBy::FindBy(const PERSON &type, const string str) : findByStr(str){ this->type = type;}

bool FindBy::operator()(Person p){
    switch (type) {
        case PERSON::LASTNAME:
            return (findByStr == p.getLastName());

        case PERSON::FIRSTNAME:
            return (findByStr == p.getFirstName());

        case PERSON::DATE:
            return (findByStr == p.getDate());

        case PERSON::NO_ID:
            return (stoi(findByStr) == p.getID());
    }
}