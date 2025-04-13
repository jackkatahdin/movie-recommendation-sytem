#include <string>
#include <vector>
#include "Movie.h"
#include "Person.h"

using namespace std;

Person::Person()
{
    name = "N/A";
    nationality = "N/A";
    age = 0;
    projects = {};
}

Person::Person(const string& name)
{
    this->name = name;
    nationality = "N/A";
    age = 0;
    projects = {};
}

Person::Person(const string& name, int age)
{
    this->name = name;
    this->nationality = "N/A";
    this->age = age;
    projects = {};
}

Person::Person(const string& name, const string& nationality, const int age)
{
    this->name = name;
    this->nationality = nationality;
    this->age = age;
}

Person::Person(const string& name, const string& nationality, const int age, const vector<Movie>& projects)
{
    this->name = name;
    this->nationality = nationality;
    this->age = age;
    this->projects = projects;
}

int Person::getNumProjects() const
{
    return projects.size();
}

string Person::getName() const
{
    return name;
}

string Person::getNationality() const
{
    return nationality;
}

int Person::getAge() const
{
    return age;
}

/**
vector<Movie> Person::getProjects()
{
    return projects;
}
*/


ostream& operator<<(ostream& outs, const Person& person)
{
    outs << person.getName();
    return outs;
}

bool Person::operator==(const Person& other) const
{
    return (name == other.name && age == other.getAge());
}

/**
ostream& operator<<(ostream& outs, const vector<Person>& people)
{
    for (int i = 0; i < people.size(); i++)
    {
        outs << people[i];
        if (i < people.size() - 1)
        {
            outs << ", ";
        }
    }
    return outs;
}
*/
