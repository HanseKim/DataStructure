/**
 * @file pa12_BTS.cpp
 * @author sehankim (kimbird2002@naver.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;

map<string,pair<string,string>> m;
int n;
string root;

void plus_node(string par, string str){
    //cout<<"parent: "<<par<<" ";
    if(par.compare(str) < 0){ //right child
        if(m[par].first==""){
            m[par].first = str;
            //cout<<str<<"\n";
            m[str] = make_pair("","");
        }
        else plus_node(m[par].first,str);
    }
    else if(par.compare(str) > 0){ //left child
        if(m[par].second==""){
            m[par].second = str;
            //cout<<str<<"\n";
            m[str] = make_pair("","");
        }
        else plus_node(m[par].second,str);
    }
}

void insert(){
    string str; cin>>str;
    if(m.empty()) {
        m[str] = make_pair("","");
        root = str;
    }
    if(m.find(str)!=m.end()) return ;
    else{
        plus_node(root, str);
    }
}

void del(){
    string str; cin>>str;
    if(m.find(str) != m.end()) return;
    if(m[str].second==""){
        if(m[str].first=="") m.erase(str);
        {
            //왼쪽 부트리의 최대값으로 교체, leaf에 도달할 때까지 반복
        }
    }
    {
        //오른쪽 부트리의 최솟값으로 대치

    }
}

void leaf(){
    for(auto it = m.begin();it!=m.end();it++){
        if(it->second.first=="" && it->second.second=="") cout<<it->first<<" ";
    }
    cout<<"\n";
}

void depth(){
    int dep; cin>>dep;
    queue<string> q;
    q.push(root);
    int cnt=1;
    while(cnt!=dep){
        int size = q.size();
        for(int i=0;i<size;i++){
            string par = q.front();
            if(m[par].first!="") q.push(m[par].first);
            if(m[par].second!="") q.push(m[par].second);
            q.pop();
        }
        cnt++;
    }
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"\n";
}

int main(){
    cin>>n;
    while(n--){
        string cmd;
        cin>>cmd;
        if(cmd == "+"){
            insert();
        }
        else if(cmd == "-"){
            del();
        }
        else if(cmd == "leaf"){
            leaf();
        }
        else{
            depth();
        }
    }

    return 0;
}