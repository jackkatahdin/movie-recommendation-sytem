/**
* Created by Charles Walsh
 * CS2300A
*/

#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

using namespace std;

class Movie;

/**
 * Abstract class representing a Person
 * Fields:
 *     name: Name of person
 *     nationality: Nationality of person
 *     age: Age of person
 *     projects: Movies the person has been a part of
 */
class Person
{
protected:
    string name, nationality;
    int age;
    vector<Movie> projects;
public:
    /**
     * Default constructor
     * Requires: nothing
     * Modifies: nothing
     * Defaults all values to 0, empty, or "N/A" respectively
     */
    Person();

    /**
     * Constructor taking name
     * Requires: name
     * Modifies: nothing
     * Takes name value for movie, defaulting all others to 0, empty, or "N/A" respectively
     */
    explicit Person(const string& name);

    /**
     * Constructor taking name and age
     * Requires: name, age
     * Modifies: nothing
     * Takes name and age values for a Person, defaulting all others to empty, or "N/A" respectively
     */
    explicit Person(const string& name, int age);

    /**
     * Constructor taking name, nationality, and age
     * Requires: name, nationality, age
     * Modifies: nothing
     * Takes name, nationality, and age values for a Person, defaulting projects to empty
     */
    explicit Person(const string& name, const string& nationality, int age);

    /**
     * Constructor taking name, nationality, age, and projects
     * Requires name, nationality, age, projects
     * Modifies: nothing
     * Takes name, nationality, age, and project values for a Person
     */
    explicit Person(const string& name, const string& nationality, int age, const vector<Movie>& projects);

    // Destructor
    virtual ~Person() = default;

    // Getters
    /**
     * Get respective value
     * Requires: nothing
     * Modifies: nothing
     * Effects: Retrieves respective value
     */
    int getNumProjects() const;
    string getName() const;
    string getNationality() const;
    int getAge() const;
    vector<Movie> getProjects();

    /**
     * Describe the work a Person does
     * Requires: nothing
     * Modifies: nothing
     * Effects: Returns string describing job based on the child class
     */
    virtual string describeRole() = 0;


    // Overloaded operators
    /**
     * Overload equivalence operator for two Persons
     * Requires: nothing
     * Modifies: equivalence operator
     * Effects: Checks for equivalence between two Persons by their name, and their age
     */
    bool operator==(const Person& other) const;

    /**
     * Overload left shift operator for Persons
     * Requires: nothing
     * Modifies: left shift operator
     * Effects: Allows object of type Person to be printed in format:
     * name
     */
    friend ostream& operator<<(ostream& outs, const Person& person);

    // add left shift overload for printing that will be overwritten in child classes in the future
};
#endif //PERSON_H
