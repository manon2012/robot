#ifndef _NEW_STRING
#define _NEW_STRING

#include <iostream>
using namespace std;
#include <list>
#include <string.h>

class NewString
{
    friend ostream &operator<<(ostream &cout, const NewString &other);

public:
    NewString(const char *str = 0);

    NewString(const NewString &other);

    NewString &operator=(const NewString &other);

    ~NewString();

private:
    char *m_data;
};

ostream &operator<<(ostream &cout, const NewString &other);


#endif