// Hangman.cpp 
// I added in a level selector; experimenting with enums, switch, and functions to break it up
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

string getWord(int userChoice); //gets the word from the list
vector<string> getList(int userChoice); //gets the list of words based on difficulty chosen

int main() {
    //setup
    
    const int MAX_WRONG = 8; //maximum number of incorrect guesses allowed
    enum class Difficulty : int {EASY = 1, MEDIUM, HARD};
    Difficulty userDifficulty;
    int userChoice;
    
    cout << "Welcome to Hangman. Please type the number of the level you'd like to play:\n";
    cout << "\t1. Easy\n";
    cout << "\t2. Medium\n";
    cout << "\t3. Hard\n";  
    cin >> userChoice;

    switch (userChoice) {
    case 1:
        cout << "You picked easy. Good luck!\n";
        userDifficulty = Difficulty::EASY;
        break;
    case 2:
        cout << "You picked medium. You got this.\n";
        userDifficulty = Difficulty::MEDIUM;
        break;
    case 3:
        cout << "You picked hard. Think you got what it takes? We'll see.\n";
        userDifficulty = Difficulty::HARD;
    default:
        cout << "You did not pick a valid selection. \n";
    }


    string THE_WORD = getWord(userChoice);
    int wrong = 0;
    string soFar(THE_WORD.size(), '-');
    string used = "";

    //main loop
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        if ((MAX_WRONG - wrong) == 1) {
            cout << " incorrect guess left!!!\n";
        }
        else {
            cout << " incorrect guesses left\n";
        }
        
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "So far, the word is:\n" << soFar << endl;

        //get guess
        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess);

        while (used.find(guess) != string::npos) {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (THE_WORD.find(guess) != string::npos) {
            cout << "That's right! " << guess << " is in the word\n";

            //update soFar to include newly guessed letter
            for (int i = 0; i < THE_WORD.length(); ++i) {
                if (THE_WORD[i] == guess) {
                    soFar[i] = guess;
                }
            }
        }
        else {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }
    //game over if the player makes too many incorrect guesses
    if (wrong == MAX_WRONG) {
        cout << "\nYou've been hanged!";
    }
    else {
        cout << "\nYou guessed it!";
    }
    cout << "\nThe word was " << THE_WORD << endl;
    

    return 0;
}
string getWord(int userChoice) {
    vector<string> words = getList(userChoice);
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    string pickedWord = words[0];
    return pickedWord;
}
vector<string> getList(int userChoice) {
    vector<string> wordsEasy;
    wordsEasy.push_back("SQUIRREL");
    wordsEasy.push_back("PINEAPPLE");
    wordsEasy.push_back("PENGUIN");

    vector<string> wordsMedium;
    wordsMedium.push_back("GUESS");
    wordsMedium.push_back("HANGMAN");
    wordsMedium.push_back("DIFFICULT");

    vector<string> wordsHard;
    wordsHard.push_back("FRAZZLED");
    wordsHard.push_back("LUXURY");
    wordsHard.push_back("SYNDROME");
    
    switch (userChoice) {
    case 1:
        return wordsEasy;
        break;

    case 2:
        return wordsMedium;
        break;

    case 3:
        return wordsHard;
        break;

    default:
        cout << "You get hard words\n";
        return wordsHard;
    }
}
