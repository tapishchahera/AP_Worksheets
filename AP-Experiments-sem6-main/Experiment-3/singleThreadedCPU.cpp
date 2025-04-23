/*
 You are given n tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, 
 where tasks[i] = [enqueueTime[i], processingTime[i]]. You have a single-threaded CPU 
 that can process at most one task at a time
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    for(int i=0; i<n; i++) tasks[i].push_back(i); 
    sort(tasks.begin(),tasks.end());
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //min heap
    vector<int> ans;
    
    int i =0;
    long long t = tasks[0][0]; // current time
    
    while(!pq.empty() or i<n) {
        while(i<n && t>=tasks[i][0]) {
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
        
        if(pq.empty()) { //queue is empty and we have to wait for the next task to come
                t = tasks[i][0];
            }
            
        else { //queue is not empty
            pair<int,int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
            t += p.first; 
        }  
    }
    return ans;
}

int main() {
    vector<vector<int>> tasks = {{1,2},{2,4},{3,2},{4,1}};
    vector<int> ans = getOrder(tasks);
    for(auto x: ans) cout<<x<<" ";
    return 0;
}