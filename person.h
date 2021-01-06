#ifndef LABO_06_K_PERSON_H
#define LABO_06_K_PERSON_H

#include <string>

using namespace std;

enum class PERSON {NO_ID, LASTNAME, FIRSTNAME, DATE};

// CLASSES ET PROTOTYPES DES FONCTIONS MEMBRES
//-----------------------------------------------------------------------------------------------------------//
class Person {
public:
    // Constructeur par défaut
    Person(string firstName, string lastName, string date);

    // Constructeur de copie
    Person(const Person& p);

    // Constructeur d'affectation
    void operator=(const Person& p);

    static unsigned nbrePerson() {return nbre;};
    //static unsigned nbreCrees() {return nextId;};

    // Getters
    unsigned getID() const;
    string getFirstName() const;
    string getLastName() const;
    string getDate() const;

private:
    friend ostream& operator<<(ostream& os, const Person& p);

    const string lastName;
    const string firstName;
    const string date;
    const unsigned id;

    static unsigned nextId;
    static unsigned nbre;
};

//-----------------------------------------------------------------------------------------------------------//
class SortBy {
public:
    SortBy(PERSON type);
    bool operator() (const Person& p1, const Person& p2);
    bool sortFirstName(const Person& p1, const Person& p2);

private:
    PERSON type;
};

//-----------------------------------------------------------------------------------------------------------//


#endif //LABO_06_K_PERSON_H
