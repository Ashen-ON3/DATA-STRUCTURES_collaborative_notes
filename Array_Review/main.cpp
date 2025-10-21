#include "Array.h"

int main() {
    Array arr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. RemoveAt\n";
        cout << "3. Swap\n";
        cout << "4. RemoveOccurrences\n";
        cout << "5. InsertAfter\n";
        cout << "6. RemoveAllOccurrences\n";
        cout << "7. ReplaceAllOccurrences\n";
        cout << "8. Print Array\n";
        cout << "0. Quit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            arr.insert(val);
        }
        else if (choice == 2) {
            int idx;
            cout << "Enter index to remove: ";
            cin >> idx;
            arr.removeAt(idx);
        }
        else if (choice == 3) {
            int i, j;
            cout << "Enter indices to swap: ";
            cin >> i >> j;
            arr.swap(i, j);
        }
        else if (choice == 4) {
            int val, cnt;
            cout << "Enter value and occurrences to remove: ";
            cin >> val >> cnt;
            arr.removeOccurrences(val, cnt);
        }
        else if (choice == 5) {
            int target, newVal;
            cout << "Enter target and value to insert after: ";
            cin >> target >> newVal;
            arr.insertAfter(target, newVal);
        }
        else if (choice == 6) {
            int val;
            cout << "Enter value to remove all occurrences: ";
            cin >> val;
            arr.removeAllOccurrences(val);
        }
        else if (choice == 7) {
            int target, newVal;
            cout << "Enter target and new value: ";
            cin >> target >> newVal;
            arr.replaceAllOccurrences(target, newVal);
        }
        else if (choice == 8) {
            arr.print();
        }
        else if (choice == 0) {
            cout << "Quitting program...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}