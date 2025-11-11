// Headers
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
#include <limits>

using namespace std;

// Globals
int murdererID;
string murdererName;
int energy = 100; // starting energy points
int SEGMENT_DELAY = 1200;// 1200;

// Function Declarations
void SetupMurderer();
void LetterPrint(string txt, int delay = 25);
void inspecting();
int random(int val = 10, int base = 1);

int GetInt(string prompt = "Enter an int: ", int min = -2000000, int max = 2000000);
int ques();

string maid_s1(); string maid_s2();
string chef_s1(); string chef_s2();
string but_s1(); string but_s2();
string gardener_s1(); string gardener_s2();
string driver_s1(); string driver_s2();
string study_rm(); string garden(); string kitchen(); string bedroom(); string garage();
string final_statements(string name);


// Main
int main() {
    srand(time(0));
    SetupMurderer();

    int question, location1, location2, extra_loc, location3, last_loc, location4, guess;
    string final_1, final_2;

    LetterPrint("Hello Detective! You are needed for a murder investigation!");
    cout << "\nPress ENTER to start.\n";
    cin.get();

    LetterPrint("\nBRIEF:\nMr. Jack, a resident of Beverly Hills, was found murdered in his mansion.\n");
    LetterPrint("\nAreas of Interest:\n1. The Study Room\n2. The Kitchen\n3. The Garden\n4. The Bedroom\n5. The Garage\n\n");

    LetterPrint("There are 5 people under suspicion: \nThe Maid, The Chef, The Butler, The Gardener, and The Driver.\n");
    LetterPrint("\nAs a renowned detective, you decide to challenge yourself and limit the actions you take.\nThis includes asking few questions and visiting few places.\nPress ENTER to continue.\n");
    cin.get();

    Sleep(SEGMENT_DELAY);

    // Locations
    cout << "==========================\n";
    LetterPrint("Investigate locations [2] for clues.\n1. The Study Room\n2. The Kitchen\n3. The Garden\n4. The Bedroom\n5. The Garage\n");
    
    location1 = GetInt("Choose first location: ", 1, 5);

    Sleep(500);

    inspecting();

    switch (location1) {
    case 1: LetterPrint(study_rm(), 10); break;
    case 2: LetterPrint(kitchen(), 10); break;
    case 3: LetterPrint(garden(), 10); break;
    case 4: LetterPrint(bedroom(), 10); break;
    case 5: LetterPrint(garage(), 10); break;
    default: cout << "Invalid choice.\n"; break;
    }
    energy -= 8;

    cout << "Energy: " << energy << "\n";

    location2 = GetInt("Choose second location: ", 1, 5);
    
    if (location1 == location2)
         cout << "You decide to visit the previous location again.";

    inspecting();

    switch (location2) {
    case 1: LetterPrint(study_rm(), 10); break;
    case 2: LetterPrint(kitchen(), 10); break;
    case 3: LetterPrint(garden(), 10); break;
    case 4: LetterPrint(bedroom(), 10); break;
    case 5: LetterPrint(garage(), 10); break;
    default: cout << "Invalid choice.\n"; break;
    }

    energy -= 8;

    cout << "Energy: " << energy << "\n";
    
    do {
    extra_loc = GetInt("\nCheck one more location? (1 = Yes, 0 = No): ", 0, 1);
    
    } while (!(extra_loc == 1 || extra_loc == 0));

    if (extra_loc) {
        location3 = GetInt("Enter Location 3: ", 1, 5);

        if (location3 == location1 || location3 == location2 || location2 == location1)
            cout << "You decide to inspect an area once again.";

        inspecting();

        switch (location3) {
        case 1: LetterPrint(study_rm(), 10); break;
        case 2: LetterPrint(kitchen(), 10); break;
        case 3: LetterPrint(garden(), 10); break;
        case 4: LetterPrint(bedroom(), 10); break;
        case 5: LetterPrint(garage(), 10); break;
        default: cout << "Invalid choice.\n"; break;
        }
        energy -= 8; // extra location costs effort
        cout << "Energy after extra search: " << energy << "\n";
    }

    Sleep(SEGMENT_DELAY);

    LetterPrint("\nYou now go to interrogate the suspects: ");

    // S1: Maid
    cout << "\n====================================================\n";
    LetterPrint("Suspect #1: Maid\nClaim: I have worked here for 10 years, I could never hurt Mr. Jack.\n");
    question = ques();
    LetterPrint("Maid: " + (question == 1 ? maid_s1() : maid_s2()));
    cout << "\n";
    energy += (question == 1 ? 4 : 2);
    cout << "Energy: " << energy << "\n";

    // S2: Chef
    cout << "\n====================================================\n";
    LetterPrint("Suspect #2: Chef\nClaim: Dinner does not cook itself, detective.\n");
    question = ques();
    LetterPrint("Chef: " + (question == 1 ? chef_s1() : chef_s2()));
    cout << "\n";
    energy += (question == 1 ? 4 : 2);
    cout << "Energy: " << energy << "\n";

    // S3: Butler
    cout << "\n==========================\n";
    LetterPrint("Suspect #3: Butler\nClaim: I handle all of Mr. Jack's business matters.\n");
    question = ques();
    LetterPrint("Butler: " + (question == 1 ? but_s1() : but_s2()));
    cout << "\n";
    energy += (question == 1 ? 4 : 2);
    cout << "Energy: " << energy << "\n";

    // S4: Gardener
    cout << "\n==========================\n";
    LetterPrint("Suspect #4: Gardener\nClaim: My hands are only dirty from soil, not blood.\n");
    question = ques();
    LetterPrint("Gardener: " + (question == 1 ? gardener_s1() : gardener_s2()));
    cout << "\n";
    energy += (question == 1 ? 4 : 2);
    cout << "Energy: " << energy << "\n";

    // S5: Driver
    cout << "\n==========================\n";
    LetterPrint("Suspect #5: Driver\nClaim: I was on standby all night, waiting for his call.\n");
    question = ques();
    LetterPrint("Driver: " + (question == 1 ? driver_s1() : driver_s2()));
    cout << "\n";
    energy += (question == 1 ? 4 : 2);
    cout << "Energy: " << energy << "\n";

    Sleep(SEGMENT_DELAY);
    LetterPrint("\nEven after hearing out the suspects, you hesitate on casting the blame.\n");
    last_loc = GetInt("Do you want to visit one last location? (1 = Yes, 0 = No): ", 0, 1);

    if (last_loc) {
        location4 = GetInt("Enter Location 4: ", 1, 5);

        inspecting();

        switch (location4) {
        case 1: LetterPrint(study_rm(), 10); break;
        case 2: LetterPrint(kitchen(), 10); break;
        case 3: LetterPrint(garden(), 10); break;
        case 4: LetterPrint(bedroom(), 10); break;
        case 5: LetterPrint(garage(), 10); break;
        default: cout << "Invalid choice.\n"; break;
        }

        energy -= 18; // This extra location costs even more effort
        cout << "Energy after extra search: " << energy << "\n";
    }

    Sleep(SEGMENT_DELAY);

    // Final interrogation
    cout << "\n==========================\n";
    cout << "Now choose two main suspects (type names exactly):\n";
    cout << "Enter first suspect: ";
    cin >> final_1;
    cout << "Enter second suspect: ";
    cin >> final_2;

    cout << "\nInterrogating " << final_1 << "...\n";
    LetterPrint(final_statements(final_1), 50);
    cout << endl;

    cout << "\nInterrogating " << final_2 << "...\n";
    LetterPrint(final_statements(final_2), 50);
    cout << endl;

    energy += 5;
    cout << "Energy: " << energy << "\n";


    cout << "\nFinal Guess:\nWho was the murderer?\n1. Maid\n2. Chef\n3. Butler\n4. Gardener\n5. Driver\n";
    guess = GetInt("", 1, 5);

    if (guess == murdererID) {
        cout << "\nCorrect! The murderer was the " << murdererName << "!\nYou solved the case!\n";
        energy += 20;
    }
    else {
        cout << "\nWrong! The murderer was actually the " << murdererName << "!\n";
        energy -= 20;
    }

    cout << "\nFinal Energy Points: " << energy << "\n";
    if (energy >= 120)
        cout << "Excellent detective! You were sharp and efficient.\n";
    else if (energy >= 80)
        cout << "Good job! You solved it with decent energy left.\n";
    else if (energy >= 50)
        cout << "You barely made it, detective. Tough case.\n";
    else
        cout << "You ran out of energy... the case took its toll.\n";

    return 0;
}


// Helpers
void LetterPrint(string txt, int delay) {

    for (char a : txt) {
        cout << a << flush;

        if (a == '!' || a == '.' || a == '?' || a == ',' || a == ':' || a == ';' || a == '\n')
            Sleep(5 * delay);
        else
            Sleep(delay);
    }

}

void inspecting() {
    LetterPrint("Inspecting");
    LetterPrint("..........", 100);
    cout << '\n';
}

void SetupMurderer() {
    murdererID = rand() % 5 + 1;
    switch (murdererID) {
    case 1: murdererName = "Maid"; break;
    case 2: murdererName = "Chef"; break;
    case 3: murdererName = "Butler"; break;
    case 4: murdererName = "Gardener"; break;
    case 5: murdererName = "Driver"; break;
    }
}

int random(int val, int base) {
    return rand() % val + base;
}

int GetInt(string prompt, int min, int max) {

    int n;

    do {
        cout << prompt << flush;

        if (!(cin >> n)){
            cout << "Invalid input.\n" << std::endl;
            cin.clear();
            cin.ignore(max + 1, '\n');
            continue;
        }

    } while (n < min || n > max);

    return n;

}

inline int ques() { return GetInt("1. What were you doing?\n2. Any grudges?\n", 1, 2); }

string maid_s1() { return (murdererID == 1) ? "I was cleaning the bedroom... near Mr. Jack's safe." : "I was folding laundry in the guest room."; }
string maid_s2() { return (murdererID == 1) ? "He was always yelling at me for mistakes. I lost patience!" : "No! He was kind to me."; }
string chef_s1() { return (murdererID == 2) ? "I was in the kitchen preparing a broth for the next day." : "I was preparing dinner."; }
string chef_s2() { return (murdererID == 2) ? "He cut my pay last week. I was furious!" : "He sometimes complained, but we got along."; }
string but_s1() { return (murdererID == 3) ? "I was in his study sorting papers..." : "I was in my quarters reviewing schedules."; }
string but_s2() { return (murdererID == 3) ? "He planned to fire me!" : "We had disagreements, but nothing serious."; }
string gardener_s1() { return (murdererID == 4) ? "I was trimming hedges near the back window." : "I was watering the plants outside."; }
string gardener_s2() { return (murdererID == 4) ? "He wanted to replace me with machines!" : "He was strict but fair."; }
string driver_s1() { return (murdererID == 5) ? "I was cleaning the car... near the entrance." : "I was refueling the car."; }
string driver_s2() { return (murdererID == 5) ? "He threatened to replace me." : "No grudge. He treated me well."; }

string study_rm() {
    if (murdererID == 3) {
        return "\nYou see papers scattered all around.\n";
    }
    else {
        if (random(3, 1) == 3)
            return "\nYou find a box with bloody hand prints and car keys.\n";
        else
            return "\nYou see a neat and clean study.\n";
    }
}

string kitchen() {
    if (murdererID == 2) {
        return "\nYou see an empty kitchen. It seems untouched.\n";
    }
    else {
        if (random(3, 1) == 3)
            return "\nThere are water droplets and plants near the back door.\n";
        else
            return "\nYou see a half-prepared dinner.\n";
    }
}

string garden() {
    if (murdererID == 4) {
        return "\nThe garden seems a mess,over grown grass, untrimmed hedges, and the like.\n";
    }
    else {
        if (random(3, 1) == 3)
            return "\nThere is a bloody mop buried in the dirt.\n";
        else
            return "\nYou see freshly watered plants, flowers, and so on. Overall a well kept garden.\n";
    }
}

string bedroom() {
    if (murdererID == 1) {
        return "\nThe bedroom is a mess, but you find prints on Mr. Jack's safe.\n";
    }
    else {
        if (random(3, 1) == 3)
            return "\nYou find the Butler's diary. The last entry is about a fierce disagreement with Mr. Jack.\n";
        else
            return "\nYou see a standard bedroom. Nothing suspicious here.\n";
    }
}
string garage() {
    if (murdererID == 5) {
        return "\nYou find Mr. Jack's car which is quite dirtied. The garage itself seems in order.\n";
    }
    else {
        if (random(3, 1) == 3)
            return "\You find a bloodied apron beneath a table in the garage.\n";
        else
            return "\nYou find Mr. Jack's car, clean and fueled up.\n";
    }
}


string final_statements(string name) {
    if (name == "Maid" && murdererName == "Maid") return "I did not mean to do it. It just happened!";
    if (name == "Chef" && murdererName == "Chef") return "I-I said I was in the kitchen preparing the platter!";
    if (name == "Butler" && murdererName == "Butler") return "He was going to ruin my life!";
    if (name == "Gardener" && murdererName == "Gardener") return "He wanted to replace me with machines!";
    if (name == "Driver" && murdererName == "Driver") return "He insulted me for the last time!";
    return "You are wasting time, detective! I did not do anything!";
}
