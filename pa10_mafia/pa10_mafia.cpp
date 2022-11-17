/**
 * @file pa10_mafia.cpp
 * @author sehankim (kimbird2002@naver.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
#define F(N) for(int i=0;i<N;i++)
#define FOR(M) for(auto member :M)
using namespace std;
int n;
string root;
map< string,vector< pair<string,int> > > tree;
map< string,int > depth;
map< string,int > child_num;
map< string,int > under;
bool comp(string a,string b){
    if(child_num[a] > child_num[b]) return true;
    if(child_num[a] == child_num[b] && depth[a] < depth[b]) return true;
    if(child_num[a] == child_num[b] && depth[a] == depth[b] && under[a] > under[b]) return true;
    if(child_num[a] == child_num[b] && depth[a] == depth[b] && under[a] == under[b]) return a < b;
    else return false;
}
vector<string> v;
void initialize(){
    FOR(tree){
        depth[member.first] = 0;
        child_num[member.first] = 0;
        under[member.first] = 0;
    }
}
void input(){
    cin>>n;
    F(n-1){
        string per,boss;
        cin>>per>>boss;
        if(tree.find(boss)!=tree.end())
            tree[boss].push_back(pair<string,int>(per,0));
        else {
            vector< pair<string,int> >child;
            child.push_back(make_pair(per,0));
            tree[boss] = child;
        }
        child_num[boss]=0;
    }
}
int sum_child_num(string name){
    int sum=0,size = tree[name].size();
    if(size==0) {
        child_num[name] = 1;
        return 1;
    }
    F(size){
        if(child_num[tree[name][i].first] != 0) sum += child_num[tree[name][i].first];
        else
            sum += sum_child_num(tree[name][i].first);
    }
    child_num[name] = sum+1;
    return sum+1;
}
void get_child_num(){
    FOR(tree) child_num[member.first] = sum_child_num(member.first);
}
void find_root(){
    int max=0;
    FOR(child_num)
        if(max < member.second){
            root = member.first;
            max = member.second;
        }
}
void find_depth(string name,int dep){
    depth[name] = dep;
    int size = tree[name].size();
    if(size==0) return ;
    F(size){
        find_depth(tree[name][i].first,dep+1);
    }
}
int find_under_depth(string name){
    int size = tree[name].size(),max=0;
    if(size==0){
        under[name] = 1;
        return 1;
    }
    F(size){
        if(under[tree[name][i].first] != 0){
            if(max < under[tree[name][i].first]+1)
                max = under[tree[name][i].first]+1;
        }
        else{
            int und =find_under_depth(tree[name][i].first)+1; 
            if(max < und){
                max = und;
            }
        }
    }
    under[name] = max;
    return max;
}
void print(){   
    FOR(tree) v.push_back(member.first);
    sort(v.begin(),v.end(),comp);
    F(n) cout<<v[i]<<"\n";
}
int main(){
    input();
    initialize();
    get_child_num();
    find_root();
    find_depth(root,0);
    under[root] = find_under_depth(root);
    print();
}