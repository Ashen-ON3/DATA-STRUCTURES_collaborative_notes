#include <iostream>
#include <vector>


using namespace std;
void InsertAt()
{
    int n;
    cout << "\nEnter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "The array without inserted value: ";
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            cout << "{ ";
        }
        
        cout << arr[i];
        if(i + 1 != n)
        {
            cout << ", ";
        }
        
        if(i + 1 == n)
        {
            cout << " }";
        }
    }

    int index, value;
    cout << "\nEnter the index to insert at: ";
    cin >> index;
    
    if(index > n)
    {
        cout << "Invalid index." << endl;
        return;
    }
    
    cout << "Enter the value to insert: ";
    cin >> value;
    
    

    if(arr[index] != 0 || arr[index] == 0)
    {
        arr[index] = value;
    }
    
    cout << "The array with inserted value: ";
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            cout << "{ ";
        }
        
        cout << arr[i];
        if(i + 1 != n)
        {
            cout << ", ";
        }
        
        if(i + 1 == n)
        {
            cout << " }";
        }
    }
}

void removeAt()
{
    int n;
    cout << "\nEnter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "The array without removed value: ";
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            cout << "{ ";
        }
        
        cout << arr[i];
        if(i + 1 != n)
        {
            cout << ", ";
        }
        
        if(i + 1 == n)
        {
            cout << " }";
        }
    }
    
    int index;
    cout << "\nEnter the index you want to remove: ";
    cin >> index;
    
    if(index > n)
    {
        cout << "Invalid index." << endl;
        return;
    }
    
    for(int i = index; i < n; i++)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        
    }
    n--;
    
    cout << "The array with removed index: ";
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            cout << "{ ";
        }
        
        cout << arr[i];
        if(i + 1 != n)
        {
            cout << ", ";
        }
        
        if(i + 1 == n)
        {
            cout << " }";
        }
    }
}
void removeOccurances()
{
    int n;
    cout << "\nEnter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "The array before removing Occurances: ";
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            cout << "{ ";
        }
        
        cout << arr[i];
        if(i + 1 != n)
        {
            cout << ", ";
        }
        
        if(i + 1 == n)
        {
            cout << " }";
        }
    }
    
     
    int value, count;
    cout << "\nEnter the value you want to remove: ";
    cin >> value;
    
    cout << "How many do you wish to remove?: ";
    cin >> count;
    
    for(int i = 0; i < n && count > 0;)
    {
        if(count <= 0)
        {
            return;
        }
        
        if(arr[i] == value)
        {
            for(int j = i; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            n--;
            count--;
        }
        else
        {
            i++;
        }
    }
}
void removeAllOccurances()
{
    int n;
    cout << "\nEnter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    
    cout << "The array before removing All Occurances: ";
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            cout << "{ ";
        }
        
        cout << arr[i];
        if(i + 1 != n)
        {
            cout << ", ";
        }
        
        if(i + 1 == n)
        {
            cout << " }";
        }
    }
    
     
    int value;
    cout << "\nEnter the value you want to remove: ";
    cin >> value;
    
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == value)
        {
            for(int j = i; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            n--;
            i--;
        }
    }
    
    cout << "The array after removing all occurances: ";
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            cout << "{ ";
        }
        
        cout << arr[i];
        if(i + 1 != n)
        {
            cout << ", ";
        }
        
        if(i + 1 == n)
        {
            cout << " }";
        }
    }
}
void Swap()
{
    int n;
    cout << "\nEnter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "The array before swap: ";
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            cout << "{ ";
        }
        
        cout << arr[i];
        if(i + 1 != n)
        {
            cout << ", ";
        }
        
        if(i + 1 == n)
        {
            cout << " }";
        }
    }
    
    int index1, index2;
    cout << "\nEnter the two index's you want to swap: ";
    cin >> index1 >> index2;
    
    if(index1 > n || index2 > n)
    {
        cout << "Invalid index." << endl;
        return;
    }
    else
    {
        int temp = 0;
        temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    
    cout << "The array after the swap: ";
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            cout << "{ ";
        }
        
        cout << arr[i];
        if(i + 1 != n)
        {
            cout << ", ";
        }
        
        if(i + 1 == n)
        {
            cout << " }";
        }
    }
}
int main()
{
    int choice;

    cout << "Menu: " << endl;
    cout << "1. InsertAt" << endl;
    cout << "2. removeAt" << endl;
    cout << "3. Remove Occurances" << endl;
    cout << "4. Remove All Occurances" << endl;
    cout << "5. Replace All Occurances" << endl;
    cout << "6. Insert After" << endl;
    cout << "7. Swap" << endl;
    cout << "8. Print" << endl;
    cout << "9. Print Even/Odd" << endl;
    cout << "10. Sum Of Array" << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    
    
    switch(choice)
    {
        case 1:
            InsertAt();
            break;
        case 2:
            removeAt();
            break;
        case 3:
            removeOccurances();
            break;
        case 4:
            removeAllOccurances();
            break;
        case 7:
            Swap();
            break;
        default:
            cout << "Invalid choice." << endl;
    }
    
    return 0;
}