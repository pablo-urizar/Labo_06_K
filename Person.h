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
    Person& operator=(const Person& p);

    // Destructeur
    ~Person();

    static unsigned nbrePerson();

    // Getters
    unsigned getID() const;
    string getFirstName() const;
    string getLastName() const;
    string getDate() const;

    friend ostream& operator<<(ostream& os, const Person& p);

private:
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
