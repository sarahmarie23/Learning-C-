// Word Jumble
//A game where the player must unscramble the word. Hints are available.
//The game continues until the player chooses to quit, or the player has guessed all of the words available

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] = {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."}
    };
    int alreadyPlayed[NUM_WORDS];
    int points{ 0 };
    string playAgain{ "y" };
    int roundsPlayed{ 1 };


    while (playAgain == "y" || playAgain == "Y") {

        //pick a random word
        srand(static_cast<unsigned int>(time(0)));
        //if choice is equal to a word that has already been played, get a different one
        int choice = (rand() % NUM_WORDS);
        while (std::any_of(std::begin(alreadyPlayed), std::end(alreadyPlayed), [=](int n) {return n == choice;})) {
            choice = (rand() % NUM_WORDS);
        }

        string theWord = WORDS[choice][WORD];
        string theHint = WORDS[choice][HINT];

        //jumble up the word
        string jumble = theWord;
        int length = jumble.size();
        for (int i = 0; i < length; ++i) {
            int index1 = (rand() % length);
            int index2 = (rand() % length);
            char temp = jumble[index1];
            jumble[index1] = jumble[index2];
            jumble[index2] = temp;
        }

        //welcome screen
        cout << "\t\tWelcome to Word Jumble!\n\n";
        cout << "Unscramble the letters to make a word.\n";
        cout << "Enter 'hint' for a hint. You lose a point if you use a hint!\n";
        cout << "Enter 'quit' to quit the game.\n\n";
        cout << "The jumble is: " << jumble;

        //player's guess
        string guess;
        cout << "\n\nYour guess: ";
        cin >> guess;

        while ((guess != theWord) && (guess != "quit")) {
            
            if (guess == "hint") {
                cout << theHint;
                points--;
            }
            else {
                cout << "Sorry, that's not it.";
            }
            cout << "\n\nYour guess: ";
            cin >> guess;
        }
        if (guess == "quit") {
            cout << "\nThanks for playing. You scored " << points << " points.";
            break;
        }

        //ending the game
        if (guess == theWord) {
            cout << "\nThat's it! You guessed it!\n";
            points += length;
            alreadyPlayed[roundsPlayed - 1] = choice;
            
        }
        cout << "\nThanks for playing. Your score is " << points << " points!\n";
        //if you already guessed all the words, you can't play any more rounds
        if (roundsPlayed == NUM_WORDS) {
            playAgain == "n";
            cout << "\nYou have guessed all the words and you have beat the game! Congrats!\n\n";
            break;
        }
        else {
            cout << "\nPlay again? Enter 'y' for yes or any other key to quit: \n";
            cin >> playAgain;
            cout << "\n";
            if (playAgain == "y" || playAgain == "Y") {
                roundsPlayed++;
            }
        }
    }
    return 0;
}
