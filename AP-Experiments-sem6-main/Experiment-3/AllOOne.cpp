/*
Design a data structure to store the strings' count with the ability to
 return the strings with minimum and maximum counts.

Time Complexity: O(1) for inc, dec, getMaxKey, and getMinKey operations.
Space Complexity: O( n ), where n is the number of keys in the data structure.
*/
#include<bits/stdc++.h>
using namespace std;

class AllOne {
    public:
        unordered_map<string, int> freq;
        set<pair<int,string>> st;
        AllOne() {}
        
        void inc(string key) {
            st.erase({freq[key],key});
            freq[key]++;
    
            st.insert({freq[key], key});
        }
        
        void dec(string key) {
            st.erase({freq[key],key});
            freq[key]--;
    
            if(freq[key] > 0){
                st.insert({freq[key], key});
            }
        }
        
        string getMaxKey() {
            if(st.size()==0){return "";}
            string ans = prev(st.end())->second;
            return ans;
        }
        
        string getMinKey() {
            if(st.size()==0){return "";}
            string ans = st.begin()->second;
            return ans;
        }
};

int main() {
    AllOne obj;
    obj.inc("a");
    obj.inc("b");
    obj.inc("b");
    obj.inc("c");
    obj.inc("c");
    cout << obj.getMaxKey() << endl;
    cout << obj.getMinKey() << endl;
    obj.inc("a");
    cout << obj.getMaxKey() << endl;
    cout << obj.getMinKey() << endl;
}