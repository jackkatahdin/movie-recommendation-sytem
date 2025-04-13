/**
* Created by Charles Walsh
 * CS2300A
*/

#ifndef WRITER_H
#define WRITER_H
#include "Movie.h"
#include "Person.h"

using namespace std;

/**
 * Class representing a Writer
 * Derived from Person class
 */
class Writer : public Person
{
private:

public:
    Writer();

    explicit Writer(const string& name);

    explicit Writer(const string& name, int age);

    explicit Writer(const string& name, const string& nationality, int age);

    explicit Writer(const string& name, const string& nationality, int age, const vector<Movie>& projects);

    string describeRole() override;
};
#endif //WRITER_H
