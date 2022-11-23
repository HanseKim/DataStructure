/**
 * @file pa11_citypath2.cpp
 * @author sehankim (kimbird2002@naver.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int n;
map<int,vector<int>> city;
/**
 * @brief input node and connected nodes
 * 0 is end of connected nodes
 * 
 */
void input(){
    cin>>n;
    int j;
    for(int i=1;i<=n;i++){
        while(1){
            cin>>j;
            if(j==0) break;
            if(i==j) continue;
            city[i].push_back(j);
        }
    }
}
/**
 * @brief print all node with connected nodes
 * 
 */
void print_city(){
    cout<<"\n";
    for(int i=1;i<=n;i++) {
        cout<<i<<" connected node : ";
        for(auto it=city[i].begin();it!=city[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<"\n";
    }
}
/**
 * @brief Get the shortest path from i to j
 * 
 * @param i -> start node
 * @param j -> end node
 * @return int 
 */
int get_shortest(int i,int j){
    queue<int> q;
    int visited[n+1] = {0,};
    visited[i] = -1;
    for(int idx=0;idx<city[i].size();idx++) {
        q.push(city[i][idx]);
        visited[city[i][idx]] = 1;
    }

    while(!q.empty()){
        int node = q.front();
        for(int idx=0;idx<city[node].size();idx++){
            if(visited[city[node][idx]] == 1) continue; 
            if(visited[city[node][idx]] == 0 && city[node][idx] != i){ //idx번 째 노드가 방문하지 않은 node 일 때
                visited[city[node][idx]] = visited[node] + city[node].size();
                if(city[node][idx]!=j) q.push(city[node][idx]);
            }
            else{
                if(visited[city[node][idx]] > visited[node] + city[node].size()){ //최솟값이 아니라면
                    visited[city[node][idx]] = visited[node] + city[node].size();
                }   
            }
        }
        q.pop();
    }
    return visited[j];
}
/**
 * @brief Get the max path
 * 
 * @return max path
 */
int get_max(){
    int i,max=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int s = get_shortest(i,j);
            if(s>max) {
                max = s;
            }
        }
    }
    return max;
}

int main(){
    input();
    //print_city();
    cout<<get_max();
}