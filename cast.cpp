#include "Cast.h"

using namespace std;

Cast::Cast() : Person(){}

Cast::Cast(const string& name) : Person(name){}

Cast::Cast(const string& name, int age) : Person(name, age){}

Cast::Cast(const string& name, const string& nationality, int age) : Person(name, nationality, age){}

Cast::Cast(const string& name, const string& nationality, int age, const vector<Movie>& projects) : Person(name, nationality, age, projects){}

string Cast::describeRole()
{
    return "I'm a cool person that acts in some cool movies";
}