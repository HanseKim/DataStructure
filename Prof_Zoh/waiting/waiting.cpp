#include<bits/stdc++.h>
#define ID q.front().first
#define During q.front().second
using namespace std;
queue<pair<int,int>> q;
bool comp(pair<int,int> a,pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
int main(){
    int n,time_=30;
    cin>>n;
    while(n--){
        int start,id,during;
        cin>>start>>id>>during;
        if(start>time_){
            while(During>time_){
                sort(q.front(),q.back(),comp);
                if(During <= 10){
                    time_+=During;
                    cout<<ID<<"\n";
                    q.pop();
                } 
                else{
                    time_ += During/2;
                    During -= During/2;
                }
            }
        }
        q.push(make_pair(id,during));
    }
}