#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure for a Human
struct Human {
    string name;
    string gender;
    string adharNo; // Unique ID
};

// Function to add a new human to the system
void addHuman(vector<Human> &humans) {
    Human newHuman;
    cout << "Enter name: ";
    cin >> newHuman.name;
    cout << "Enter gender: ";
    cin >> newHuman.gender;

    // Generating a dummy Adhar number for simplicity
    newHuman.adharNo = "ADH" + to_string(humans.size() + 1);
    
    humans.push_back(newHuman);
    cout << "New human added successfully with Adhar number: " << newHuman.adharNo << endl;
}

// Function to search for a human by Adhar number
void searchByAdhar(const vector<Human> &humans) {
    string adharNo;
    cout << "Enter Adhar number to search: ";
    cin >> adharNo;

    bool found = false;
    for (const auto &human : humans) {
        if (human.adharNo == adharNo) {
            cout << "Details of the human:" << endl;
            cout << "Name: " << human.name << endl;
            cout << "Gender: " << human.gender << endl;
            cout << "Adhar number: " << human.adharNo << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Human with Adhar number " << adharNo << " not found." << endl;
    }
}

// Function to list all humans with details
void listAll(const vector<Human> &humans) {
    cout << "List of all humans:" << endl;
    for (const auto &human : humans) {
        cout << "Name: " << human.name << ", Gender: " << human.gender << ", Adhar number: " << human.adharNo << endl;
    }
}

// Function to edit/update human details by Adhar number
void updateByAdhar(vector<Human> &humans) {
    string adharNo;
    cout << "Enter Adhar number to update details: ";
    cin >> adharNo;

    bool found = false;
    for (auto &human : humans) {
        if (human.adharNo == adharNo) {
            cout << "Enter new name: ";
            cin >> human.name;
            cout << "Enter new gender: ";
            cin >> human.gender;
            cout << "Details updated successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Human with Adhar number " << adharNo << " not found." << endl;
    }
}

int main() {
    vector<Human> humans;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add/Create New Human" << endl;
        cout << "2. Search Human by Adhar No." << endl;
        cout << "3. List All Humans" << endl;
        cout << "4. Edit/Update Human Details by Adhar No." << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addHuman(humans);
                break;
            case 2:
                searchByAdhar(humans);
                break;
            case 3:
                listAll(humans);
                break;
            case 4:
                updateByAdhar(humans);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}

