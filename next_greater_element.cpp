// A Stack based C++ program to find next
// greater element for all array elements.
#include <bits/stdc++.h>
using namespace std;

/* prints element and NGE pair for all
elements of arr[] of size n */
vector<int> printNGE(vector<int>& arr) {
        vector<int> ans;
        stack<int> s;
        
        for(int i=arr.size()-1;i>=0;i--){
            if(s.size() == 0)ans.push_back(-1);
            else if(s.size()>0 && s.top()>arr[i]) ans.push_back(s.top());
            else{
                while(s.size()>0 && s.top()<=arr[i]){
                    s.pop();
                }
                if(s.size()==0)ans.push_back(-1);
                else ans.push_back(s.top());
            }
            s.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        // code here
    }

/* Driver code */
int main()
{
    vector<int> arr = { 11, 13, 21, 3 };
    //int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nge = printNGE(arr); // Capture the returned vector
    for(int i = 0; i < nge.size(); i++) {
        cout << nge[i] << " ";
    }
    return 0;
}