// C++ program to generate a random number and ask the user to guess it

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    std::cout << "Welcome to the number guessing game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;

    int userGuess;
    while (true) {
        // Ask the user to guess the number
        std::cout << "Guess a number: ";
        std::cin >> userGuess;

        // Check if the user's guess is correct
        if (userGuess == secretNumber) {
            std::cout << " Congratulations! You guessed the correct number." << std::endl;
            break;
        } else if (userGuess < secretNumber) {
            std::cout << "Your guess is too low. Try again!" << std::endl;
        } else {
            std::cout << "Your guess is too high. Try again!" << std::endl;
        }
    }

    return 0;
}