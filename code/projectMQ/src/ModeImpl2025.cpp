// Car.h
#include <memory>

class Car
{
public:
    Car();
    ~Car();

    void start();
    void stop();
    int getSpeed() const;

private:
    // Forward declaration of implementation class
    struct Impl;

    // Opaque pointer to implementation
    std::unique_ptr<Impl> pImpl;
};

// Car.cpp
#include <iostream>

// Define the implementation class
struct Car::Impl
{
    bool isRunning = false;
    int currentSpeed = 0;

    void engineSound()
    {
        std::cout << "Vroom vroom!" << std::endl;
    }
};

// Implement public interface
Car::Car() : pImpl(std::make_unique<Impl>()) {}

Car::~Car() = default; // Must be in .cpp where Impl is complete

void Car::start()
{
    pImpl->isRunning = true;
    pImpl->engineSound();
    pImpl->currentSpeed = 10;
}

void Car::stop()
{
    pImpl->isRunning = false;
    pImpl->currentSpeed = 0;
    std::cout << "Engine stopped" << std::endl;
}

int Car::getSpeed() const
{
    return pImpl->currentSpeed;
}

int main(int argc, char const *argv[])
{
    Car myCar;
    myCar.start();
    std::cout << "Current speed: " << myCar.getSpeed() << std::endl;
    myCar.stop();
}