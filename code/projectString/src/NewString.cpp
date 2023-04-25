#include "NewString.h"

NewString::NewString(const char *str )
{
    if(str)
    {
        int len = strlen(str);
        m_data = new char[len + 1];
        strcpy(m_data, str);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }

}
NewString::NewString(const NewString &other)
{
    int len = strlen(other.m_data);
    m_data = new char[len + 1];
    strcpy(m_data, other.m_data);
}
NewString &NewString::operator=(const NewString &other)
{
    if(this != &other)
    { 
        delete [] m_data;
        int len = strlen(other.m_data);
        m_data = new char[len + 1];
        strcpy(m_data, other.m_data);
    }
    return *this;
}
NewString::~NewString()
{
    if(m_data)
    {
        delete[] m_data;
        m_data = nullptr;
    }
}
ostream &operator<<(ostream &cout, const NewString &other)
{
    std::cout<< other.m_data << std::endl;
    return cout;
}