/**
* Class representing a Writer
 * Derived from Person class
 */

#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "Movie.h"
#include "Person.h"

using namespace std;

/**
 * Class representing a Writer
 * Derived from Person class
 */
class Director : public Person
{
private:

public:
    Director();

    explicit Director(const string& name);

    explicit Director(const string& name, int age);

    explicit Director(const string& name, const string& nationality, int age);

    explicit Director(const string& name, const string& nationality, int age, const vector<Movie>& projects);

    string describeRole() override;
};
#endif //DIRECTOR_H
