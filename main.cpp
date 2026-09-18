
#include <fstream>
#include "BST.h"
void showMenu() {
    cout<< "1. Schedule an appointment \n";
    cout << "2. Display all appointments \n";
    cout << "3. Search for an appointment \n";
    cout << "4. Cancel an appointment \n";
    cout << "5. Display more urgent than\n";
    cout << "6. Display less urgent than\n";
    cout << "0 . Exit...";
}

int main() {
    BST tree;

    ifstream inFile("input.txt");

    if (!inFile) {
        cout << "Error opening file\n";
        return 1;
    }

    int n;
    inFile >> n;
    inFile.ignore();

    for (int i = 0; i < n; i++) {
        string name, dept;
        int priority;

        getline(inFile, name);
        inFile >> priority;
        inFile.ignore();
        getline(inFile, dept);

        tree.schedule(appointment(name, priority, dept));
    }

    inFile.close();

    int choice;
    while (true) {
        showMenu();
        cout << "\nEnter number of choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0)
            break;
        if (choice == 1) {
            string name, dept;
            int p;
            cout << "Enter patient name: ";
            getline(cin, name);
            cout << "Enter priority level: ";
            cin >> p;
            cin.ignore();
            cout << "Enter department name: ";
            getline(cin, dept);
            tree.schedule(appointment(name, p, dept));
        }
        else if (choice == 2) {
            tree.DisplayAll();
        }
        else if (choice == 3) {
            int p;
            cout << "Enter priority level: ";
            cin >> p;
            tree.searchPriority(p);
        }
        else if (choice == 4) {
            int p;
            cout << "Enter priority level: ";
            cin >> p;
            tree.cancelPriority(p);
        }
        else if (choice == 5) {
            int p;
            cout << "Display more urgent than: ";
            cin >> p;
            tree.displayMoreUrgent(p);
        }
        else if (choice == 6) {
            int p;
            cout << "Display less urgent than: ";
            cin >> p;
            tree.displayLessUrgent(p);
        }
    }
    return 0;
}
