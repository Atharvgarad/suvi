#include <iostream>
#include <string>
using namespace std;
 
const int SIZE = 10;
 
struct Contact {
    string name;
    string phone;
    bool used;
};
 
int hashName(string name) {
    int total = 0;
    for (int i = 0; i < (int)name.length(); i++)
        total += name[i];
    return total % SIZE;
}
 
int main() {
    Contact table[SIZE];
    for (int i = 0; i < SIZE; i++)
        table[i].used = false;
 
    int n;
    cout << "How many contacts (maximum 10)? ";
    cin >> n;
 
    if (n < 0 || n > SIZE) {
        cout << "Please enter a number from 0 to 10.\n";
        return 0;
    }
 
    // Insert contacts using linear probing.
    for (int i = 0; i < n; i++) {
        Contact c;
        cout << "Enter name (one word): ";
        cin >> c.name;
        cout << "Enter phone number: ";
        cin >> c.phone;
 
        int index = hashName(c.name);
        int tries = 0;
        while (table[index].used && tries < SIZE) {
            index = (index + 1) % SIZE;
            tries++;
        }
 
        if (tries == SIZE) {
            cout << "Table is full. Contact not added.\n";
        } else {
            table[index].name = c.name;
            table[index].phone = c.phone;
            table[index].used = true;
        }
    }
 
    string searchName;
    cout << "Enter name to search: ";
    cin >> searchName;
 
    int index = hashName(searchName);
    int checked = 0;
    bool found = false;
 
    while (checked < SIZE && table[index].used) {
        if (table[index].name == searchName) {
            cout << "Phone number: " << table[index].phone << endl;
            found = true;
            break;
        }
        index = (index + 1) % SIZE;
        checked++;
    }
 
    if (!found) cout << "Contact not found.\n";
    return 0;
}
