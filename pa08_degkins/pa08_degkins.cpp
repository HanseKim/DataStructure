/**
 * @file pa08_degkins.cpp
 * @author SehanKim (kimbird2002@naver.com)
 * @brief      
 * @version 0.1
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>

using namespace std;

multimap<string,string> ms;
queue<string> q;
map<string,bool> visited;
void insert(string a,string b){
    ms.insert(pair<string,string>(a,b));
    ms.insert(pair<string,string>(b,a));
}

int bfs(string a,string b){
    int degkins=0;
    q.push(a);

    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            string fir = q.front();
            if(fir.compare(b)==0) return degkins;
            for(auto it = ms.lower_bound(fir);it!=ms.upper_bound(fir);){
                if(visited.find(it->second) != visited.end()) it++;
                else{
                    for(auto it_ = ms.lower_bound(it->second);it_!=ms.upper_bound(it->second);){
                        if(it_->second.compare(fir)==0) {
                            ms.erase(it_);
                            break;
                        }
                        else it_++;
                    }
                    q.push(it->second);
                    
                    visited.insert(make_pair(it->second,true));
                    it = ms.erase(it);
                }
            }
            q.pop();
        }
        degkins++;
    }
}

void print(){
    for(auto it = ms.begin();it!=ms.end();it++)
    cout<<"first="<<it->first<<", second="<<it->second<<"\n";
}

int main(){
    int n;
    cin>>n;
    string a,b;
    for(int i=0;i<n;i++){
        cin>> a>>b;
        insert(a,b);
    }
    cin>>a>>b;
    //print();
    cout<<bfs(a,b);

    return 0;
}