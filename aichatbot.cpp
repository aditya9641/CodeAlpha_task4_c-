#include <iostream>
#include <string>
#include <algorithm>

// Function to convert input to lowercase for easier comparison
std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to handle user input and generate responses
std::string getResponse(const std::string& input) {
    std::string response;

    // Convert input to lowercase for case-insensitive matching
    std::string lowerInput = toLower(input);

    // Simple if-else logic for responding to certain inputs
    if (lowerInput.find("hello") != std::string::npos || lowerInput.find("hi") != std::string::npos) {
        response = "Hi there!";
    } else if (lowerInput.find("how are you") != std::string::npos) {
        response = "I'm just a chatbot. How can I assist you?";
    } else if (lowerInput.find("bye") != std::string::npos) {
        response = "Goodbye!";
    } else {
        response = "I'm sorry, I didn't understand that.";
    }

    return response;
}

int main() {
    std::string userInput;

    // Welcome message
    std::cout << "Welcome! How can I help you?\n";

    // Main loop for interaction
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, userInput);

        // Check if user wants to quit
        if (toLower(userInput) == "quit" || toLower(userInput) == "exit") {
            std::cout << "Goodbye!";
            break;
        }

        // Get response and display it
        std::string response = getResponse(userInput);
        std::cout << response << std::endl;
    }

    return 0;
}
