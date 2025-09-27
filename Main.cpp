#include <iostream>
#include "Array.h"

// Helper function to check if array contents match expected values
bool CheckArrayContents(const Array& arr, const int expected[], int expectedSize) 
{
    if (arr.Size() != expectedSize) return false;
    for (int i = 0; i < expectedSize; i++) 
    {
        try 
        {
            if (arr.GetAt(i) != expected[i]) return false;
        } 
        catch (...) 
        {
            return false;
        }
    }
    return true;
}

void RunAllTests() {
    std::cout << "Starting Array Tests...\n";

    Array arr(5);

    // Test 1: Add elements until capacity reached
    std::cout << "Test 1: Add elements\n";
    bool addResult;
    addResult = arr.Add(10);
    std::cout << "Add 10: " << (addResult ? "Passed" : "Failed") << "\n";
    addResult = arr.Add(20);
    std::cout << "Add 20: " << (addResult ? "Passed" : "Failed") << "\n";
    addResult = arr.Add(30);
    std::cout << "Add 30: " << (addResult ? "Passed" : "Failed") << "\n";
    addResult = arr.Add(40);
    std::cout << "Add 40: " << (addResult ? "Passed" : "Failed") << "\n";
    addResult = arr.Add(50);
    std::cout << "Add 50: " << (addResult ? "Passed" : "Failed") << "\n";

    // Adding beyond capacity should fail
    addResult = arr.Add(60);
    std::cout << "Add beyond capacity (60): " << (!addResult ? "Passed" : "Failed") << "\n";

    // Check size and capacity
    std::cout << "Size (expect 5): " << (arr.Size() == 5 ? "Passed" : "Failed") << "\n";
    std::cout << "Capacity (expect 5): " << (arr.Capacity() == 5 ? "Passed" : "Failed") << "\n";

    // Verify contents after additions
    int expectedAdd[] = {10, 20, 30, 40, 50};
    std::cout << "Contents after Add: " 
              << (CheckArrayContents(arr, expectedAdd, 5) ? "Passed" : "Failed") << "\n";

    // Test 2: InsertAt valid positions
    std::cout << "\nTest 2: InsertAt\n";
    Array arr2(5);
    arr2.Add(1);
    arr2.Add(2);
    arr2.Add(3);

    bool insertResult;
    insertResult = arr2.InsertAt(0, 10); // Insert at front
    std::cout << "InsertAt front: " << (insertResult ? "Passed" : "Failed") << "\n";

    int expectedInsertFront[] = {10, 1, 2, 3};
    std::cout << "InsertAt front content: "
              << (CheckArrayContents(arr2, expectedInsertFront, 4) ? "Passed" : "Failed") << "\n";

    insertResult = arr2.InsertAt(2, 20); // Insert in middle
    std::cout << "InsertAt middle: " << (insertResult ? "Passed" : "Failed") << "\n";

    int expectedInsertMiddle[] = {10, 1, 20, 2, 3};
    std::cout << "InsertAt middle content: "
              << (CheckArrayContents(arr2, expectedInsertMiddle, 5) ? "Passed" : "Failed") << "\n";

    insertResult = arr2.InsertAt(arr2.Size(), 30); // Insert at end (should fail, full)
    std::cout << "InsertAt end (should fail): " << (!insertResult ? "Passed" : "Failed") << "\n";

    // Insert out of bounds (negative index)
    insertResult = arr2.InsertAt(-1, 100);
    std::cout << "InsertAt negative index: " << (!insertResult ? "Passed" : "Failed") << "\n";

    // Insert out of bounds (index > size)
    insertResult = arr2.InsertAt(arr2.Size() + 1, 100);
    std::cout << "InsertAt index > size: " << (!insertResult ? "Passed" : "Failed") << "\n";

    std::cout << "Final array after InsertAt tests: ";
    arr2.Print();

    // Test 3: DeleteAt valid and invalid positions
    std::cout << "\nTest 3: DeleteAt\n";
    bool deleteResult;
    deleteResult = arr2.DeleteAt(0); // delete first element
    std::cout << "DeleteAt index 0: " << (deleteResult ? "Passed" : "Failed") << "\n";

    int expectedAfterDelete0[] = {1, 20, 2, 3};
    std::cout << "DeleteAt index 0 shifts elements: "
              << (CheckArrayContents(arr2, expectedAfterDelete0, 4) ? "Passed" : "Failed") << "\n";

    deleteResult = arr2.DeleteAt(arr2.Size() - 1); // delete last element
    std::cout << "DeleteAt last index: " << (deleteResult ? "Passed" : "Failed") << "\n";

    int expectedAfterDeleteLast[] = {1, 20, 2};
    std::cout << "DeleteAt last element content: "
              << (CheckArrayContents(arr2, expectedAfterDeleteLast, 3) ? "Passed" : "Failed") << "\n";

    deleteResult = arr2.DeleteAt(1); // delete middle element
    std::cout << "DeleteAt middle: " << (deleteResult ? "Passed" : "Failed") << "\n";

    int expectedAfterDeleteMiddle[] = {1, 2};
    std::cout << "DeleteAt middle shifts elements: "
              << (CheckArrayContents(arr2, expectedAfterDeleteMiddle, 2) ? "Passed" : "Failed") << "\n";

    // Delete out of bounds (negative)
    deleteResult = arr2.DeleteAt(-1);
    std::cout << "DeleteAt negative index: " << (!deleteResult ? "Passed" : "Failed") << "\n";

    // Delete out of bounds (>= size)
    deleteResult = arr2.DeleteAt(arr2.Size());
    std::cout << "DeleteAt index >= size: " << (!deleteResult ? "Passed" : "Failed") << "\n";

    std::cout << "Array after deletes: ";
    arr2.Print();

    // Test 4: UpdateAt valid and invalid positions
    std::cout << "\nTest 4: UpdateAt\n";
    bool updateResult;

    updateResult = arr2.UpdateAt(0, 111);
    std::cout << "UpdateAt index 0: " << (updateResult ? "Passed" : "Failed") << "\n";

    updateResult = arr2.UpdateAt(arr2.Size() - 1, 222);
    std::cout << "UpdateAt last index: " << (updateResult ? "Passed" : "Failed") << "\n";

    int expectedAfterUpdate[] = {111, 222};
    std::cout << "UpdateAt content check: "
              << (CheckArrayContents(arr2, expectedAfterUpdate, 2) ? "Passed" : "Failed") << "\n";

    updateResult = arr2.UpdateAt(-1, 999);
    std::cout << "UpdateAt negative index: " << (!updateResult ? "Passed" : "Failed") << "\n";

    updateResult = arr2.UpdateAt(arr2.Size(), 999);
    std::cout << "UpdateAt index >= size: " << (!updateResult ? "Passed" : "Failed") << "\n";

    std::cout << "Array after updates: ";
    arr2.Print();

    // Test 5: GetAt valid and invalid positions
    std::cout << "\nTest 5: GetAt\n";
    try 
    {
        int val = arr2.GetAt(0);
        std::cout << "GetAt index 0: Passed (Value: " << val << ")\n";
    } 
    catch (...) 
    {
        std::cout << "GetAt index 0: Failed\n";
    }

    try 
    {
        int val = arr2.GetAt(arr2.Size() - 1);
        std::cout << "GetAt last index: Passed (Value: " << val << ")\n";
    } 
    catch (...) 
    {
        std::cout << "GetAt last index: Failed\n";
    }

    try 
    {
        arr2.GetAt(-1);
        std::cout << "GetAt negative index: Failed\n";
    } 
    catch (...)
    {
        std::cout << "GetAt negative index: Passed\n";
    }

    try 
    {
        arr2.GetAt(arr2.Size());
        std::cout << "GetAt index >= size: Failed\n";
    } 
    catch (...) 
    {
        std::cout << "GetAt index >= size: Passed\n";
    }

    std::cout << "\nAll tests complete.\n";
}

int main() {
    RunAllTests();
    return 0;
}
