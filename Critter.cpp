// Critter.cpp 
// a virtual pet simulator. validates for user input

#include <iostream>

using namespace std;

class Critter {
public:
    static int s_Total;

    Critter(int hunger = 0, int boredom = 0);
    static int GetTotal();
    int GetHunger() const;
    void SetHunger(int hunger);
    int GetBoredom() const;
    void SetBoredom(int boredom);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);

private:
    int m_Hunger;
    int m_Boredom;
    int GetMood() const;
    void PassTime(int time = 1);
};

int Critter::s_Total = 0;

Critter::Critter(int hunger, int boredom) : 
    m_Hunger(hunger),
    m_Boredom(boredom) {
    cout << "A new critter has been born!" << endl;
    ++s_Total;
}

int Critter::GetTotal() {
    return s_Total;
}

int Critter::GetHunger() const {
    return m_Hunger;
}

void Critter::SetHunger(int hunger) {
    if (hunger < 0) {
        cout << "You can't set a critter's hunger to a negative number\n\n";
    }
    else {
        m_Hunger = hunger;
    }
}

int Critter::GetBoredom() const {
    return m_Boredom;
}

void Critter::SetBoredom(int boredom) {
    m_Boredom = boredom;
}


inline int Critter::GetMood() const{
    return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time) {
    m_Hunger += time;
    m_Boredom += time;
}

void Critter::Talk() {
    cout << "I'm a critter and I feel ";

    int mood = GetMood();
    if (mood > 15) {
        cout << "mad.\n";
    }
    else if (mood > 10) {
        cout << "frustrated.\n";
    }
    else if (mood > 5) {
        cout << "okay.\n";
    }
    else {
        cout << "happy.\n";
    }

    PassTime();
}

void Critter::Eat(int food) {
    cout << "Brruppp.\n";
    m_Hunger -= food;

    if (m_Hunger < 0) {
        m_Hunger = 0;
    }

    PassTime();
}

void Critter::Play(int fun) {
    cout << "Wheee!\n";

    m_Boredom -= fun;
    if (m_Boredom < 0) {
        m_Boredom = 0;
    }

    PassTime();
}

int main() {
    
    Critter crit;
    crit.Talk();

    bool play = true;
    string choice;

    do {
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter \n";
        cout << "3 - Play with your critter\n";
        cout << "4 - Get your critter's stats\n\n";

        cout << "Choice: ";
        cin >> choice;
        char selection = choice.at(0);

        switch (selection) {
        case '0':
            cout << "Good-bye.\n";
            play = false;
            break;
        case '1':
            crit.Talk();
            break;
        case '2':
            crit.Eat();
            break;
        case '3':
            crit.Play();
            break;
        case '4':
            cout << "Your critter's hunger level is " << crit.GetHunger() << " and its boredom level is " << crit.GetBoredom() << endl;
            break;
        default:
            cout << "Sorry, but " << choice << " isn't a valid choice.\n";
            break;
        }
    } while (play);
    
    return 0;
}
