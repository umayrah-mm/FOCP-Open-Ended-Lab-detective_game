#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int murdererID;
string murdererName;
int energy = 100; // starting energy points

// Function declarations
void setupMurderer();
string maid_s1(); string maid_s2();
string chef_s1(); string chef_s2();
string asst_s1(); string asst_s2();
string gardener_s1(); string gardener_s2();
string driver_s1(); string driver_s2();
string study_rm(); string garden(); string kitchen(); string bedroom();
string final_statements(string name);
string sus();

int main() {
    srand(time(0));
    setupMurderer();

    int question, location1, location2, extra_loc, location3, guess;
    string final_1, final_2;

    cout << "Hello Detective! You are needed for a murder investigation!\nPress ENTER to start.\n";
    cin.get();

    cout << "\nOverview:\nMr. Jack, owner of a million-dollar mansion, was found murdered.\n";
    cout << "Possible crime scenes:\n1. Study Room\n2. Kitchen\n3. Garden\n4. Bedroom\n\n";

    cout << "You will interrogate 5 suspects:\nMaid, Chef, Assistant, Gardener, Driver.\n";
    cout << "Each has two possible answers. Choose wisely to get clues.\nPress ENTER to continue.\n";
    cin.get();

    // S1: Maid
    cout << "\n==========================\n";
    cout << "Suspect #1: Maid\nClaim: I have worked here for 10 years, I could never hurt Mr. Jack.\n";
    cout << "1. What were you doing?\n2. Any grudges?\n";
    cin >> question;
    cout << "Maid: " << (question == 1 ? maid_s1() : maid_s2()) << "\n";
    energy += (question == 1 ? 5 : 2);
    cout << "Energy: " << energy << "\n";

    // S2: Chef
    cout << "\n==========================\n";
    cout << "Suspect #2: Chef\nClaim: Dinner does not cook itself, detective.\n";
    cout << "1. What were you doing?\n2. Any grudges?\n";
    cin >> question;
    cout << "Chef: " << (question == 1 ? chef_s1() : chef_s2()) << "\n";
    energy += (question == 1 ? 5 : 2);
    cout << "Energy: " << energy << "\n";

    // S3: Assistant
    cout << "\n==========================\n";
    cout << "Suspect #3: Assistant\nClaim: I handle all of Mr. Jack's business matters.\n";
    cout << "1. What were you doing?\n2. Any grudges?\n";
    cin >> question;
    cout << "Assistant: " << (question == 1 ? asst_s1() : asst_s2()) << "\n";
    energy += (question == 1 ? 5 : 2);
    cout << "Energy: " << energy << "\n";

    // S4: Gardener
    cout << "\n==========================\n";
    cout << "Suspect #4: Gardener\nClaim: My hands are only dirty from soil, not blood.\n";
    cout << "1. What were you doing?\n2. Any grudges?\n";
    cin >> question;
    cout << "Gardener: " << (question == 1 ? gardener_s1() : gardener_s2()) << "\n";
    energy += (question == 1 ? 5 : 2);
    cout << "Energy: " << energy << "\n";

    // S5: Driver
    cout << "\n==========================\n";
    cout << "Suspect #5: Driver\nClaim: I was on standby all night, waiting for his call.\n";
    cout << "1. What were you doing?\n2. Any grudges?\n";
    cin >> question;
    cout << "Driver: " << (question == 1 ? driver_s1() : driver_s2()) << "\n";
    energy += (question == 1 ? 5 : 2);
    cout << "Energy: " << energy << "\n";

    // Locations
    cout << "\n==========================\n";
    cout << "Investigate two locations for clues.\n1. Study Room\n2. Kitchen\n3. Garden\n4. Bedroom\n";
    cout << "Choose first location: ";
    cin >> location1;

    switch (location1) {
    case 1: cout << study_rm(); energy += 10; break;
    case 2: cout << kitchen(); energy += 5; break;
    case 3: cout << garden(); energy += 10; break;
    case 4: cout << bedroom(); energy += 5; break;
    default: cout << "Invalid choice.\n"; break;
    }
    cout << "Energy: " << energy << "\n";

    cout << "Choose second location: ";
    cin >> location2;
    while (location2 == location1 || location2 < 1 || location2 > 4) {
        cout << "Invalid or duplicate choice. Choose a different one: ";
        cin >> location2;
    }

    switch (location2) {
    case 1: cout << study_rm(); energy += 10; break;
    case 2: cout << kitchen(); energy += 5; break;
    case 3: cout << garden(); energy += 10; break;
    case 4: cout << bedroom(); energy += 5; break;
    }
    cout << "Energy: " << energy << "\n";

    cout << "Check one more location? (1=Yes 0=No): ";
    cin >> extra_loc;
    if (extra_loc == 1) {
        cout << "Enter location: ";
        cin >> location3;
        while (location3 == location1 || location3 == location2 || location3 < 1 || location3 > 4) {
            cout << "Already checked or invalid! Choose another: ";
            cin >> location3;
        }
        switch (location3) {
        case 1: cout << study_rm(); energy += 10; break;
        case 2: cout << kitchen(); energy += 5; break;
        case 3: cout << garden(); energy += 10; break;
        case 4: cout << bedroom(); energy += 5; break;
        }
        energy -= 5; // extra location costs effort
        cout << "Energy after extra search: " << energy << "\n";
    }

    // Final interrogation
    cout << "\n==========================\n";
    cout << "Now choose two main suspects (type names exactly):\n";
    cout << "Enter first suspect: ";
    cin >> final_1;
    cout << "Enter second suspect: ";
    cin >> final_2;

    cout << "\nInterrogating " << final_1 << "...\n" << final_statements(final_1) << "\n";
    cout << "\nInterrogating " << final_2 << "...\n" << final_statements(final_2) << "\n";

    energy += 5;
    cout << "Energy: " << energy << "\n";

    cout << "\nA suspicious event unfolds...\n" << sus() << "\n";
    energy -= 5;
    cout << "Energy: " << energy << "\n";

    cout << "\nFinal Guess:\nWho was the murderer?\n1. Maid\n2. Chef\n3. Assistant\n4. Gardener\n5. Driver\n";
    cin >> guess;

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

// ---------------- Function Definitions ----------------

void setupMurderer() {
    murdererID = rand() % 5 + 1;
    switch (murdererID) {
    case 1: murdererName = "Maid"; break;
    case 2: murdererName = "Chef"; break;
    case 3: murdererName = "Assistant"; break;
    case 4: murdererName = "Gardener"; break;
    case 5: murdererName = "Driver"; break;
    }
}

string maid_s1() { return (murdererID == 1) ? "I was cleaning the bedroom... near Mr. Jack's safe." : "I was folding laundry in the guest room."; }
string maid_s2() { return (murdererID == 1) ? "He was always yelling at me for mistakes. I lost patience!" : "No! He was kind to me."; }
string chef_s1() { return (murdererID == 2) ? "I was in the kitchen... but went to the garden for herbs." : "I was preparing dinner."; }
string chef_s2() { return (murdererID == 2) ? "He cut my pay last week. I was furious!" : "He sometimes complained, but we got along."; }
string asst_s1() { return (murdererID == 3) ? "I was in his study sorting papers..." : "I was in my quarters reviewing schedules."; }
string asst_s2() { return (murdererID == 3) ? "He planned to fire me!" : "We had disagreements, but nothing serious."; }
string gardener_s1() { return (murdererID == 4) ? "I was trimming hedges near the back window." : "I was watering the plants outside."; }
string gardener_s2() { return (murdererID == 4) ? "He wanted to replace me with machines!" : "He was strict but fair."; }
string driver_s1() { return (murdererID == 5) ? "I was cleaning the car... near the entrance." : "I was refueling the car."; }
string driver_s2() { return (murdererID == 5) ? "He threatened to replace me." : "No grudge. He treated me well."; }

string study_rm() { return "\nYou found torn papers and a missing key on the desk.\n"; }
string kitchen() { return "\nThere are muddy footprints near the back door.\n"; }
string garden() { return "\nYou notice a glove buried under fresh soil.\n"; }
string bedroom() { return "\nA blood-stained cloth is hidden under the bed.\n"; }

string final_statements(string name) {
    if (name == "Maid" && murdererName == "Maid") return "I did not mean to do it. It just happened!";
    if (name == "Chef" && murdererName == "Chef") return "I was so angry... I could not control myself!";
    if (name == "Assistant" && murdererName == "Assistant") return "He was going to ruin my life!";
    if (name == "Gardener" && murdererName == "Gardener") return "He wanted to replace me with machines!";
    if (name == "Driver" && murdererName == "Driver") return "He insulted me for the last time!";
    return "You are wasting time, detective! I did not do anything!";
}

string sus() {
    return "Suddenly, the lights flicker. A figure dashes through the hall! You catch a glimpse - it is the " + murdererName + "!";
}
