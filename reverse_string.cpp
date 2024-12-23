#include <iostream>
#include <string>
using namespace std;

void reverseString(string &str) {
    int left = 0, right = str.length() - 1;

    while (left < right) {
        // Swap characters at left and right
        swap(str[left], str[right]);
        // Move pointers towards the center
        left++;
        right--;
    }
}

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    reverseString(str);

    cout << "Reversed string: " << str << endl;

    return 0;
}
