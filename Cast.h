/**
* Class representing a Writer
 * Derived from Person class
 */

#ifndef CAST_H
#define CAST_H
#include "Movie.h"
#include "Person.h"

using namespace std;

/**
 * Class representing a Writer
 * Derived from Person class
 */
class Cast : public Person
{
private:

public:
    Cast();

    explicit Cast(const string& name);

    explicit Cast(const string& name, int age);

    explicit Cast(const string& name, const string& nationality, int age);

    explicit Cast(const string& name, const string& nationality, int age, const vector<Movie>& projects);

    string describeRole() override;
};
#endif //CAST_H
