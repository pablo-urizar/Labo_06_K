#ifndef LABO_06_K_PERSON_H
#define LABO_06_K_PERSON_H

#include <string>

using namespace std;

enum class PERSON {NO_ID, LASTNAME, FIRSTNAME, DATE};

// CLASSES ET PROTOTYPES DES FONCTIONS MEMBRES
class SortBy;
class FindBy;

class Person {
public:
    // Constructeur par défaut
    Person(string firstName, string lastName, string date);

    // Constructeur de copie
    Person(const Person& p);

    // Constructeur d'affectation
    //void operator=(const Person& p);
    Person& operator=(const Person& p);

    static unsigned nbrePerson();
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

    friend SortBy;
    friend FindBy;
};

class SortBy {
public:
    SortBy(PERSON type);
    bool operator() (const Person& p1, const Person& p2);

    /*
    static bool sortLastName(const Person& p1, const Person& p2);
    static bool sortFirstName(const Person& p1, const Person& p2);
    static bool sortDate(const Person& p1, const Person& p2);
    static bool sortId(const Person& p1, const Person& p2);
    */

private:
    PERSON type;
};

class FindBy {
public:
    FindBy(const PERSON& type, const string valeur);
    bool operator()(Person p);

private:
    PERSON type;
    string findFirstName;
    string findLastName;
    string findDate;
    unsigned findId;
};

#endif //LABO_06_K_PERSON_H
