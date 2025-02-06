#include <iostream>
#include <random>
#include <limits>

void playGame() {
    // Generate a random number between 1 and 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);
    int randomNumber = dist(gen);

    int playerGuess = 0;
    int attempts = 0;
    int currentPlayer = 1; // Start with Player 1

    std::cout << "I have picked a number between 1 and 100. Players will take turns guessing." << std::endl;

    // Main game loop
    while (true) {
        std::cout << "Player " << currentPlayer << ", enter your guess: ";
        std::cin >> playerGuess;

        // Input validation
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input! Please enter a number." << std::endl;
            continue;
        }

        attempts++;
        if (playerGuess < randomNumber) {
            std::cout << "Too low! Player " << currentPlayer << ", try again in your next turn." << std::endl;
        } else if (playerGuess > randomNumber) {
            std::cout << "Too high! Player " << currentPlayer << ", try again in your next turn." << std::endl;
        } else {
            std::cout << "Congratulations, Player " << currentPlayer << "! You guessed the number in " << attempts << " attempts." << std::endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
}

int main() {
    char playAgain = 'y';

    std::cout << "Welcome to the Two-Player Number Guessing Game!" << std::endl;

    do {
        playGame();
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thank you for playing! Goodbye!" << std::endl;

    return 0;
}
