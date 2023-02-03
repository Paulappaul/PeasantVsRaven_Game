#pragma once
#include <iostream>
#include <time.h>
#include <random>
#include <vector>
#include<algorithm>
#include <set>

//global variables

//time variables
float chance_of_head = 0.5; // Initial chance of getting a head
std::mt19937 generator(time(0));
std::uniform_real_distribution<float> distribution(0,1); // values set between 0 and 1
std::uniform_real_distribution<float> enumdistribution(0,7); // values set between 0 and 7
std::uniform_int_distribution<int> random(1,3);
std::set<int> generatedNumbers;
std::vector<int> RavenList;


bool plantbool = false;
bool fruitbool = false;
bool vegetablebool = false;
bool leafyVegbool = false;
bool rootVegbool = false;

bool intro = false;

//structs

const char* produce[] = {"Apple", "Pear", "Strawberry", "Tomato", "Carrot", "Ginger","Arugula", "Celery"};

struct Plant{

    Plant();
    virtual ~Plant();
    virtual void description() = 0;

};

struct fruit : public Plant{

    fruit();
    ~fruit();
    void description(); 
};

struct vegetable : public Plant{

    vegetable();
    ~vegetable();
    virtual void vegetable_List();
    void description();

};

struct leafyVegetable : public vegetable {

    leafyVegetable();
    ~leafyVegetable();
    void description();
};

struct rootVegetable : public vegetable {

    rootVegetable();
   ~rootVegetable();
    void description();
    virtual void vegetable_List();

};

//Classes

class Character {

public:
    Character(){}
    Character(std::string username, std::string password) : Username(username), Password(password) {}
    void setUsername();
    std::string getUsername();
    void setPassword();
    std::string getPassword();

    void addItem(std::string item);
    void removeItem(const std::string deleteItem);
    bool checkItem();
    void printItems();
    std::string vectorsize();

    int returnPoints();
    void addPoints();
    void deductPoints(); 



private:
    int points =1;
    std::vector<std::string> bag = {};
    std::string Username;
    std::string Password;
};

void mainMenu();

void ravenEncounter(Character*);

std::string coinToss(bool coinCheck);    //generates the random logic

void produce_encounter(Character*); // produce logic 

int ravenChoice(int vectorsize);

std::string RandomEnum();

std::vector<Plant*> my_vector;
