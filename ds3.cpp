#include <iostream>
#include <stack>
#include <string>
using namespace std;
 
int main() {
    string text, reversed = "";
    stack<char> letters;
 
    cout << "Enter a string: ";
    getline(cin, text);
 
    // Push every character into the stack.
    for (int i = 0; i < (int)text.length(); i++)
        letters.push(text[i]);
 
    // Pop characters to make the reversed string.
    while (!letters.empty()) {
        reversed += letters.top();
        letters.pop();
    }
 
    cout << "Reversed string: " << reversed << endl;
 
    if (text == reversed)
        cout << "String is a palindrome." << endl;
    else
        cout << "String is not a palindrome." << endl;
 
    return 0;
}
