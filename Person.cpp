#include "Person.h"

#include <utility>
#include <iomanip>
#include <algorithm>

// DÉFINITION DES FONCTIONS MEMBRES

// Initialisation des éléments statiques
unsigned Person::nextId = 0;
unsigned Person:: nbre = 0;

unsigned Person::getID() const {
    return this->id;
}

string Person::getLastName() const {
    return this->lastName;
}

string Person::getFirstName() const {
    return this->firstName;
}

// "String date" - temporaire
string Person::getDate() const {
    return this->date;
}

unsigned Person::nbrePerson() {
    return nbre;
};

// Constructeur par défaut
Person::Person(string lastName, string firstName, string date) : lastName(lastName), firstName(firstName),
date(date), id(++nextId) {++nbre;}

// Constructeur de copie
Person::Person(const Person& p) : lastName(p.lastName), firstName(p.firstName), date(p.date), id(p.id) {++nbre;}

// Constructeur d'affectation
Person& Person::operator=(const Person& p) {
    if (this != &p) {
        (string&) lastName = p.getLastName();
        (string&) firstName = p.firstName;
        (string&) date = p.date;
        (unsigned&) id = p.id;
    }
    return *this;
}

// Destructeur
Person::~Person() {--nbre;}

//-----------------------------------------------------------------------------------------------------------//
ostream& operator<<(ostream& os, const Person& p) {
    os  << p.lastName
        << '\t' << p .firstName
        << '\t' << p.date
        << '\t' << "(id=" << to_string(p.id) << ')';

    return os;
}
//-----------------------------------------------------------------------------------------------------------//

SortBy::SortBy(PERSON type) : type(type){this->type = type;}

bool SortBy::operator() (const Person& p1, const Person& p2) {
    switch (type) {
        case PERSON::NO_ID:
            return p1.getID() < p2.getID();

        case PERSON::LASTNAME:
            return (p1.getLastName() < p2.getLastName());

        case PERSON::FIRSTNAME:
            return (p1.getFirstName() < p2.getFirstName());

        case PERSON::DATE:
            return p1.getDate() < p2.getDate();

    }
}

FindBy::FindBy(const PERSON &type, const string str) : type(type){

    switch (type) {
        case PERSON::NO_ID:
            break;

        case PERSON::FIRSTNAME:
            break;

        case PERSON::LASTNAME:
            break;

        case PERSON::DATE:
            break;
    }

}

bool FindBy::operator()(Person p){

}