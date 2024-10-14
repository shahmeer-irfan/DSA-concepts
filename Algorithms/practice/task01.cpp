//23k-0832
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guessNumber(int number, int attempt)
{
    int guess;
    cout << "Player " << attempt << ", enter your guess (1-100): ";
    cin >> guess;

    if (guess < number)
    {
        cout << "Too low! Try again." << endl;
        guessNumber(number, attempt); // Direct recursion for the same player
    }
    else if (guess > number)
    {
        cout << "Too high! Try again." << endl;
        guessNumber(number, attempt); // Direct recursion for the same player
    }
    else
    {
        cout << "Congratulations! Player " << attempt << " wins!" << endl;
    }
}

int main()
{
    srand((time(0)));
    int number = rand() % 100 + 1;
    guessNumber(number, 1); // Start the game with Player 1
    return 0;
}
