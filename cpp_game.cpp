#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(0)));
    int randomNumber = std::rand() % 100 + 1; // Random number between 1 and 100

    int playerGuess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have picked a number between 1 and 100. Can you guess it?" << std::endl;

    // Main game loop
    while (playerGuess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> playerGuess;
        attempts++; 

        if (playerGuess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (playerGuess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
        }
    }

    return 0;
}
