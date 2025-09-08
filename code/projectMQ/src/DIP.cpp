#include <iostream>
#include <string>
#include <memory>

// Abstraction (Interface)
class IDatabase
{
public:
    virtual ~IDatabase() = default;
    virtual void saveData(const std::string &data) = 0;
};

// Low-level module 1
class MySQLDatabase : public IDatabase
{
public:
    void saveData(const std::string &data) override
    {
        std::cout << "Saving data to MySQL: " << data << std::endl;
    }
};

// Low-level module 2
class PostgreSQLDatabase : public IDatabase
{
public:
    void saveData(const std::string &data) override
    {
        std::cout << "Saving data to PostgreSQL: " << data << std::endl;
    }
};

// Low-level module 3 (for testing)
class MockDatabase : public IDatabase
{
public:
    void saveData(const std::string &data) override
    {
        std::cout << "Mock save (for testing): " << data << std::endl;
    }
};

// High-level module (depends on abstraction, not concrete implementations)
class DataService
{
private:
    std::unique_ptr<IDatabase> database;

public:
    // Constructor injection
    DataService(std::unique_ptr<IDatabase> db) : database(std::move(db)) {}

    void processData(const std::string &data)
    {
        // Business logic remains unchanged
        std::cout << "Processing data: " << data << std::endl;

        // Uses abstraction, not concrete implementation
        database->saveData(data);
    }

    // Optional: Setter injection
    void setDatabase(std::unique_ptr<IDatabase> db)
    {
        database = std::move(db);
    }
};

// Factory for creating database instances
class DatabaseFactory
{
public:
    static std::unique_ptr<IDatabase> createDatabase(const std::string &type)
    {
        if (type == "mysql")
        {
            return std::make_unique<MySQLDatabase>();
        }
        else if (type == "postgresql")
        {
            return std::make_unique<PostgreSQLDatabase>();
        }
        else if (type == "mock")
        {
            return std::make_unique<MockDatabase>();
        }
        throw std::runtime_error("Unknown database type");
    }
};

int main()
{
    // Using different database implementations
    std::cout << "=== Using MySQL ===" << std::endl;
    auto mysqlService = DataService(DatabaseFactory::createDatabase("mysql"));
    mysqlService.processData("MySQL data");

    std::cout << "\n=== Using PostgreSQL ===" << std::endl;
    auto postgresService = DataService(DatabaseFactory::createDatabase("postgresql"));
    postgresService.processData("PostgreSQL data");

    std::cout << "\n=== Using Mock (for testing) ===" << std::endl;
    auto testService = DataService(DatabaseFactory::createDatabase("mock"));
    testService.processData("Test data");

    return 0;
}

// Key Benefits of DIP Implementation:

//     Decoupling: DataService depends on IDatabase interface, not concrete implementations

//     Testability: Easy to inject mock implementations for testing

//     Extensibility: Can add new database types without modifying DataService

//     Flexibility: Database implementation can be changed at runtime

//     Maintainability: Changes to database implementations don't affect the high-level module

// Alternative with Dependency Injection Container
// cpp

// #include <iostream>
// #include <string>
// #include <memory>
// #include <unordered_map>
// #include <functional>

// // Interface and implementations (same as above)
// class IDatabase
// { /* ... */
// };
// class MySQLDatabase : public IDatabase
// { /* ... */
// };
// class PostgreSQLDatabase : public IDatabase
// { /* ... */
// };

// // Simple dependency injection container
// class DIContainer
// {
// private:
//     std::unordered_map<std::string, std::function<std::unique_ptr<IDatabase>()>> factories;

// public:
//     template <typename T>
//     void registerType(const std::string &name)
//     {
//         factories[name] = []()
//         { return std::make_unique<T>(); };
//     }

//     std::unique_ptr<IDatabase> resolve(const std::string &name)
//     {
//         if (factories.find(name) != factories.end())
//         {
//             return factories[name]();
//         }
//         throw std::runtime_error("Service not registered: " + name);
//     }
// };

// int main()
// {
//     // Setup DI container
//     DIContainer container;
//     container.registerType<MySQLDatabase>("mysql");
//     container.registerType<PostgreSQLDatabase>("postgresql");

//     // Create services with different databases
//     DataService service1(container.resolve("mysql"));
//     DataService service2(container.resolve("postgresql"));

//     service1.processData("Data with MySQL");
//     service2.processData("Data with PostgreSQL");

//     return 0;
// }

// This implementation demonstrates how DIP makes your code more flexible, testable, and maintainable by inverting the dependency direction.