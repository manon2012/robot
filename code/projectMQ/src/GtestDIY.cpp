#include <iostream>
#include <vector>
#include <string>
#include <functional>

// Define a test case structure
struct TestCase
{
    std::string name;
    std::function<void()> testFunc;
};

// Define a test suite structure
struct TestSuite
{
    std::string name;
    std::vector<TestCase> testCases;
};

class TestRunner
{
public:
    void AddTestSuite(const TestSuite &suite)
    {
        testSuites.push_back(suite);
    }

    void Run()
    {
        int totalTests = 0;
        int failedTests = 0;

        for (const auto &suite : testSuites)
        {
            std::cout << "Running test suite: " << suite.name << std::endl;
            for (const auto &testCase : suite.testCases)
            {
                totalTests++;
                try
                {
                    testCase.testFunc();
                    std::cout << "  " << testCase.name << " - PASSED" << std::endl;
                }
                catch (const std::exception &e)
                {
                    failedTests++;
                    std::cout << "  " << testCase.name << " - FAILED: " << e.what() << std::endl;
                }
            }
        }

        std::cout << "Total tests: " << totalTests << std::endl;
        std::cout << "Failed tests: " << failedTests << std::endl;
    }

private:
    std::vector<TestSuite> testSuites;
};

void Assert(bool condition, const std::string &message)
{
    if (!condition)
    {
        throw std::runtime_error(message);
    }
}

void Test1()
{
    Assert(1 == 1, "1 should be equal to 1");
}

void Test2()
{
    Assert(1 == 2, "1 should be equal to 2");
}

void Test3()
{
    Assert(2 == 2, "2 should be equal to 2");
}

int main()
{
    TestSuite suite1 = {
        "Suite1",
        {{"Test1", Test1},
         {"Test2", Test2},
         {"Test3", Test3}}};

    TestRunner runner;
    runner.AddTestSuite(suite1);
    runner.Run();

    return 0;
}