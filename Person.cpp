/*---------------------------------------------------------------------------------
 Laboratory     : 07 - Person / Date
 File           : Person.cpp
 Authors        : Sarah Jallon, Pablo Urizar
 Date           : 11.01.2021
 Objective      : Class members' definition
 Compiler       : MinGW-g++ 8.1.0
 ---------------------------------------------------------------------------------*/

#include "Person.h"
#include <iomanip>
#include <algorithm>

// Static variables initialization
unsigned Person::nextId = 0;
unsigned Person:: nbre = 0;

// Getters
std::string Person::getLastName() const {
    return this->lastName;
}

std::string Person::getFirstName() const {
    return this->firstName;
}

Date Person::getDate() const {
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
Person::Person  (std::string lastName, std::string firstName, Date date) : lastName(lastName),
                firstName(firstName), date(date), id(++nextId) {++nbre;}

// Copy constructor
Person::Person  (const Person& p) : lastName(p.lastName), firstName(p.firstName), date(p.date),
                id(p.id) {++nbre;}

// Assignment constructor
Person& Person::operator=(const Person& p) {
    if (this != &p) {
        (std::string&) lastName = p.getLastName();
        (std::string&) firstName = p.getFirstName();
        (Date&) date = p.getDate();
        (unsigned&) id = p.getID();
    }
    return *this;
}

// Destructor
Person::~Person() {--nbre;}

// Display person's attributes
std::ostream& operator<<(std::ostream& os, const Person& p) {
    os  <<p.lastName
        << '\t' << p .firstName
        << '\t' << p.date
        << '\t' << "(id=" << std::to_string(p.id) << ')';

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
FindBy::FindBy(PERSON type, const std::string str) : findByStr(str){ this->type = type;}

bool FindBy::operator()(Person p){
    switch (type) {
        case PERSON::LASTNAME:
            return (findByStr == p.getLastName());

        case PERSON::FIRSTNAME:
            return (findByStr == p.getFirstName());

        case PERSON::DATE:
            return (findByStr == std::string(p.getDate()));

        case PERSON::NO_ID:
            return (stoi(findByStr) == p.getID());

        default:
            return false;
    }
}