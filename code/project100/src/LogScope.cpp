#include <iostream> 

class LogScope 
{ 
    public: 
    LogScope(const char* scope, const char* file, int line = 0) 
    : m_scope(scope), m_file(file), m_line(line) 
    { 
     std::clog << "[Begin] " << m_scope << ", " << m_file << ", " << m_line << std::endl; 
    } 

    ~LogScope() { 
     std::clog << "[End] " << m_scope << ", " << m_file << ", " << m_line << std::endl; 
    } 

    private: 
    const char* m_scope; 
    const char* m_file; 
    int m_line; 
}; 

#define NAME_AT_LINE_2(Name, Line) Name##_##Line 
#define NAME_AT_LINE_1(Name, Line) NAME_AT_LINE_2(Name, Line) 
#define NAME_AT_LINE(Name) NAME_AT_LINE_1(Name, __LINE__) 

#define LOG_SCOPE \ 
    ::LogScope NAME_AT_LINE(log_scope)(__FUNCTION__, __FILE__, __LINE__) 

void f() { 
    LOG_SCOPE; 
} 



int main1() { 
    LOG_SCOPE; 
    f(); 
} 