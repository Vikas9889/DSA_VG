#include <vector>
#include <stack>
#include<iostream>
#include <utility>

using namespace std;

vector<int> calculateSpan(vector<int>& arr) {
    vector<int> span(arr.size());  // To store the result
    stack<pair<int, int>> s;       // Stack to store {element, index}
    
    for (int i = 0; i < arr.size(); i++) {
        // Pop elements from the stack while they are less than or equal to the current element
        while (!s.empty() && s.top().first <= arr[i]) {
            s.pop();
        }
        
        // If the stack is empty, all elements to the left are smaller
        if (s.empty()) {
            span[i] = i + 1;
        } else {
            // Top of the stack is the previous greater element
            span[i] = i - s.top().second;
        }
        
        // Push the current element and its index onto the stack
        s.push({arr[i], i});
    }
    
    return span;
}
int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = calculateSpan(prices);

    for (int span : result) {
        cout << span << " ";
    }

    return 0;
}
