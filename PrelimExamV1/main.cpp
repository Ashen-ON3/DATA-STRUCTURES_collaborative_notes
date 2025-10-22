#include "Array.h"

int main() {
    Array arr;
    int choice;

    do {
        cout << "\nMenu (Version 1):\n";
        cout << "1. Insert\n";
        cout << "2. RemoveAt\n";
        cout << "3. Rotate Left\n";
        cout << "4. Sort Ascending\n";
        cout << "5. Move Odd Left\n";
        cout << "6. Insert Before\n";
        cout << "7. Delete Before\n";
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
            int k;
            cout << "Enter positions to rotate left: ";
            cin >> k;
            arr.rotateLeft(k);
        }
        else if (choice == 4) {
            arr.sortArrayAsc();
        }
        else if (choice == 5) {
            arr.moveOddLeft();
        }
        else if (choice == 6) {
            int target, val;
            cout << "Enter target and value to insert before: ";
            cin >> target >> val;
            arr.insertBefore(target, val);
        }
        else if (choice == 7) {
            int target;
            cout << "Enter target to delete before: ";
            cin >> target;
            arr.deleteBefore(target);
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
