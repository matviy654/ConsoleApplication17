#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name;
    int age;

public:
    Person(const char* name = "Невідомо", int age = 0) : age(age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Person(const Person& other) : age(other.age) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    Person& operator=(const Person& other) {
        if (this != &other) {
            delete[] name;
            age = other.age;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        return *this;
    }

    ~Person() {
        delete[] name;
    }

    void display() const {
        cout << "ПІБ: " << name << ", Вік: " << age << endl;
    }
};

class Apartment {
private:
    Person* people;
    int numPeople;

public:
    Apartment(int numPeople = 0) : numPeople(numPeople) {
        people = new Person[numPeople];
    }

    Apartment(const Apartment& other) : numPeople(other.numPeople) {
        people = new Person[numPeople];
        for (int i = 0; i < numPeople; i++) {
            people[i] = other.people[i];
        }
    }

    Apartment& operator=(const Apartment& other) {
        if (this != &other) {
            delete[] people;
            numPeople = other.numPeople;
            people = new Person[numPeople];
            for (int i = 0; i < numPeople; i++) {
                people[i] = other.people[i];
            }
        }
        return *this;
    }

    ~Apartment() {
        delete[] people;
    }

    void addPerson(const Person& person, int index) {
        if (index >= 0 && index < numPeople) {
            people[index] = person;
        }
    }

    void display() const {
        cout << "Квартира з " << numPeople << " людьми:" << endl;
        for (int i = 0; i < numPeople; i++) {
            people[i].display();
        }
    }
};

class House {
private:
    Apartment* apartments;
    int numApartments;

public:
    House(int numApartments = 0) : numApartments(numApartments) {
        apartments = new Apartment[numApartments];
    }

    House(const House& other) : numApartments(other.numApartments) {
        apartments = new Apartment[numApartments];
        for (int i = 0; i < numApartments; i++) {
            apartments[i] = other.apartments[i];
        }
    }

    House& operator=(const House& other) {
        if (this != &other) {
            delete[] apartments;
            numApartments = other.numApartments;
            apartments = new Apartment[numApartments];
            for (int i = 0; i < numApartments; i++) {
                apartments[i] = other.apartments[i];
            }
        }
        return *this;
    }

    ~House() {
        delete[] apartments;
    }

    void addApartment(const Apartment& apartment, int index) {
        if (index >= 0 && index < numApartments) {
            apartments[index] = apartment;
        }
    }

    void display() const {
        cout << "Дім з " << numApartments << " квартирами:" << endl;
        for (int i = 0; i < numApartments; i++) {
            apartments[i].display();
        }
    }
};

int main() {
    Person person1("Іван Петрович", 35);
    Person person2("Олена Іванівна", 30);
    Person person3("Марія Іванівна", 5);

    Apartment apt1(2);
    apt1.addPerson(person1, 0);
    apt1.addPerson(person2, 1);

    Apartment apt2(1);
    apt2.addPerson(person3, 0);

    House house(2);
    house.addApartment(apt1, 0);
    house.addApartment(apt2, 1);

    house.display();

    return 0;
}
