#include "Director.h"

using namespace std;

Director::Director() : Person(){}

Director::Director(const string& name) : Person(name){}

Director::Director(const string& name, int age) : Person(name, age){}

Director::Director(const string& name, const string& nationality, int age) : Person(name, nationality, age){}

Director::Director(const string& name, const string& nationality, int age, const vector<Movie>& projects) : Person(name, nationality, age, projects){}

string Director::describeRole()
{
    return "I'm a coolio that directs some cool movies";
}