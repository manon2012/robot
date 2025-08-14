#include <iostream>

// Step 1: Define the Subject interface
class Image {
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

// Step 2: Implement the RealSubject (actual heavy object)
class RealImage : public Image {
private:
    std::string filename;

    void loadFromDisk() {
        std::cout << "Loading image: " << filename << " (expensive operation)\n";
    }

public:
    RealImage(const std::string& filename) : filename(filename) {
        loadFromDisk();
    }

    void display() override {
        std::cout << "Displaying image: " << filename << "\n";
    }
};

// Step 3: Implement the Proxy
class ProxyImage : public Image {
private:
    RealImage* realImage = nullptr;
    std::string filename;

public:
    ProxyImage(const std::string& filename) : filename(filename) {}

    void display() override {
        if (realImage == nullptr) {
            realImage = new RealImage(filename);  // Create object only when needed
        }
        realImage->display();
    }

    ~ProxyImage() {
        delete realImage;
    }
};

// Step 4: Client code
int main() {
    // Proxy creates the real object only when needed
    Image* image = new ProxyImage("test_image.jpg");

    // RealImage not loaded yet
    std::cout << "Image object created (real image not loaded yet)\n";

    // Now the real image gets loaded
    image->display();

    // Subsequent calls use the already loaded image
    image->display();

    delete image;
    return 0;
}
