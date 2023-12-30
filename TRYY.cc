#include <iostream>
#include <stdexcept>

class AgeException : public std::exception {
public:
    AgeException(const char* message) noexcept : msg(message) {}

    // Override what() to provide a custom error message
    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;
};

int main() {
    while(1){
    try {
        int age;

        // Assume age is user input or obtained from somewhere
        std::cout << "Enter age: ";
        std::cin >> age;

        if (age > 90 || age < 18) {
            throw AgeException("Invalid age. Age must be between 18 and 90.");
        }

        // Your code for processing a valid age goes here

        std::cout << "Age is valid: " << age << std::endl;
    } catch (const AgeException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    }

    return 0;
}