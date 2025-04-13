#include "Writer.h"

using namespace std;

Writer::Writer() : Person(){}

Writer::Writer(const string& name) : Person(name){}

Writer::Writer(const string& name, int age) : Person(name, age){}

Writer::Writer(const string& name, const string& nationality, int age) : Person(name, nationality, age){}

Writer::Writer(const string& name, const string& nationality, int age, const vector<Movie>& projects) : Person(name, nationality, age, projects){}

string Writer::describeRole()
{
    return "I'm a person that writes for some cool movies";
}