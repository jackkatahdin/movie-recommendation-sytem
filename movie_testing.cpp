/**
* Created by Charles Walsh
 * CS 2300A
*/

#include "Cast.h"
#include "Director.h"
#include "Movie.h"
#include "Person.h"
#include "Writer.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * Test methods of respective classes
 * Requires: nothing
 * Modifies: nothing
 * Effects: Returns true if all respective tests passed, false otherwise
 */
bool testMovie();
bool testPeople();

/**
 * Run through each of the testing methods
 * Output will print the results of the tests
 * Hopefully it all works!
 */
int main()
{
    if (testMovie())
    {
        cout << "Passed all movie test cases" << endl;
    }
    if (testPeople())
    {
        cout << "Passed all people test cases" << endl;
    }

    return 0;
}


bool testMovie()
{
    bool passed = true;
    Movie m1 = Movie(1990, "mymovie");
    if (m1.getName() != "mymovie")
    {
        cout << "FAILED m1 name test";
        passed = false;
    }
    if (m1.getYear() != 1990)
    {
        cout << "FAILED m1 year test";
        passed = false;
    }
    Movie m1f = Movie(1991, "mymovie");
    if (m1 == m1f)
    {
        cout << "FAILED m1 equivalence test";
        passed = false;
    }
    Movie m2 = Movie(10, 1950, 1000, 12000, "movie two", "R", "this is the greatest movie youve ever seen",
        {COMEDY}, {Cast("mister cast"), Cast("mister casttwo")},
        {Director("iamthe director", 34), Director("iamthe otherdirector")}, {Writer("me writer"), Writer("me also")});
    if (m2.getBoxOffice() != 12000)
    {
        cout << "FAILED m2 box office test";
        passed = false;
    }
    vector<Genre> gen = {COMEDY};
    if (m2.getGenre() != gen)
    {
        cout << "FAILED m2 genre test";
        passed = false;
    }
    Director d1 = Director("iamNOTthe director", "American", 34);
    Director d2 = m2.getDirector()[0];
    if (d1 == d2)
    {
        cout << "FAILED d2 director test";
        passed = false;
    }

    return passed;
}

bool testPeople()
{
    bool passed = true;
    Writer w1 = Writer("mr dude", "Italian", 500);
    if (w1.getNationality() != "Italian")
    {
        cout << "FAILED w1 nationality test";
        passed = false;
    }
    Movie m2 = Movie(10, 1950, 1000, 12000, "movie two", "R", "this is the greatest movie youve ever seen",
        {COMEDY}, {Cast("mister cast"), Cast("mister casttwo")},
        {Director("iamthe director", 34), Director("iamthe otherdirector")}, {Writer("me writer"), Writer("me also")});
    Cast c1 = m2.getCast()[0];
    if (c1.describeRole() != "I'm a cool person that acts in some cool movies")
    {
        cout << "FAILED c1 describe role test";
        passed = false;
    }

    return passed;
}