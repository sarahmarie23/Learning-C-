//MadLib.cpp 
//The classic create your own story game. It also validates for user input
//If the program requires a number, it will make sure to get one from the user
//I added in the ability for the user to type an answer with whitespace

#include <iostream>
#include <string>

using namespace std;

string askText(string prompt);
int askNumber(string prompt);
bool isNumber(string num);
void tellStory(string name, string noun, int number, string bodyPart, string verb);

int main() {
    //introduction
    cout << "Welcome to Mad Lib.\n\n";
    cout << "Answer the following questions to help create a new story.\n\n";

    //collecting items to be filled in
    string name = askText("Please enter a name: ");
    string noun = askText("Please enter a plural noun: ");
    int number = askNumber("Please enter a number: ");
    string bodyPart = askText("Please enter a body part: ");
    string verb = askText("Please enter a verb: ");

    //build a story
    tellStory(name, noun, number, bodyPart, verb);
   
    return 0;
}
string askText(string prompt) {
    //whitespace is now allowed
    string text;
    cout << prompt;
    getline(cin >> ws, text);
    return text;
}   
int askNumber(string prompt) {
    string num;
    //make sure you're actually getting a number from the user
    do {
        cout << prompt;
        cin >> num;

    } while (!isNumber(num));

    int number = std::stoi(num);
    return number;
}
bool isNumber(string num) {
    for (int i = 0; i < num.length(); i++) {
        if (isdigit(num[i]) == false) {
            return false;
        }
    }
    return true;
}
void tellStory(string name, string noun, int number, string bodyPart, string verb) {
    cout << "\nHere's your story:\n";
    cout << "The famous explorer ";
    cout << name;
    cout << " had nearly given up a life-long quest to find\n";
    cout << "The Lost City of ";
    cout << noun;
    cout << " when one day, the ";
    cout << noun;
    cout << " found the explorer.\n";
    cout << "Surrounded by ";
    cout << number;
    cout << " " << noun;
    cout << ", a tear came to ";
    cout << name << "'s ";
    cout << bodyPart << ".\n";
    cout << "After all this time, the quest was finally over. ";
    cout << "And then, the ";
    cout << noun << "\n";
    cout << "promptly devoured ";
    cout << name << ". ";
    cout << "The moral of the story? Be careful what you ";
    cout << verb;
    cout << " for.";
}
