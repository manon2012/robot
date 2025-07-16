#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <stdexcept>

class TestFramework
{
public:
    using TestCase = std::function<void()>;

    void addTest(const std::string &name, TestCase test)
    {
        tests.push_back({name, test});
    }

    void runTests()
    {
        int passed = 0;
        for (const auto &[name, test] : tests)
        {
            std::cout << "Running test: " << name << "... ";
            try
            {
                test();
                std::cout << "PASSED\n";
                passed++;
            }
            catch (const std::exception &e)
            {
                std::cout << "FAILED: " << e.what() << "\n";
            }
        }
        std::cout << "Tests passed: " << passed << "/" << tests.size() << "\n";
    }

    static TestFramework &getInstance()
    {
        static TestFramework instance;
        return instance;
    }

private:
    std::vector<std::pair<std::string, TestCase>> tests;
};

#define TEST_CASE(name)                                        \
    void name();                                               \
    struct TestRegister_##name                                 \
    {                                                          \
        TestRegister_##name()                                  \
        {                                                      \
            TestFramework::getInstance().addTest(#name, name); \
        }                                                      \
    } testRegister_##name;                                     \
    void name()

#define ASSERT(condition)                                          \
    if (!(condition))                                              \
    {                                                              \
        throw std::runtime_error("Assertion failed: " #condition); \
    }

TEST_CASE(testAddition)
{
    int result = 2 + 2;
    ASSERT(result == 4);
}

TEST_CASE(testSubtraction)
{
    int result = 5 - 3;
    ASSERT(result == 2);
}

TEST_CASE(testFailure)
{
    int result = 1 + 1;
    ASSERT(result == 3); // This test will fail
}

// int main()
// {
//     TestFramework::getInstance().runTests();
//     return 0;
// }