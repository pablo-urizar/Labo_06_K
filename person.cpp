#include "person.h"

#include <utility>
#include <iomanip>

// DÉFINITION DES FONCTIONS MEMBRES
// Getters
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

// Initialisation des éléments statiques
unsigned Person::nextId = 0;
unsigned Person:: nbre = 0;

// Constructeur par défaut
Person::Person(string lastName, string firstName, string date) : lastName(lastName), firstName(firstName),
date(date), id(++nextId) {++nbre;}

// Constructeur de copie
Person::Person(const Person& p) : lastName(p.lastName), firstName(p.firstName), date(p.date), id(p.id) {++nbre;}

// Constructeur d'affectation
void Person::operator=(const Person& p) {}

ostream& operator<<(ostream& os, const Person& p) {
    os  << p.lastName
        << '\t' << p .firstName
        << '\t' << p.date
        << '\t' << "(id=" << to_string(p.id) << ')';

    return os;
}