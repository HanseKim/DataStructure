//이건 잘못 돌아감

#include<bits/stdc++.h>

using namespace std;

int n;
map<int,vector<int>> city;
void input(){
    int i;
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

int get_shortest(int i,int j){
    queue<int> q;
    int visited[n+1] = {0,};
    int count[n+1] = {0,};
    visited[i] = -1;
    for(int idx=0;idx<city[i].size();idx++) {
        q.push(city[i][idx]);
        visited[city[i][idx]] = 1;
        count[city[i][idx]] = 1;
    }

    int cnt=1;
    while(!q.empty()){
        //q.size() 만큼 돌리고 다 돌면 cnt++
        int size = q.size();
        for(int i=0;i<size;i++){
            int node = q.front();
            for(int idx=0;idx<city[node].size();idx++){
                if(visited[city[node][idx]] == 1) continue;
                if(visited[city[node][idx]] == 0 && city[node][idx] != i){ //idx번 째 노드가 방문하지 않은 node 일 때
                    visited[city[node][idx]] = visited[node] + city[node].size();
                    count[city[node][idx]] = cnt;
                    if(city[node][idx]!=j) q.push(city[node][idx]);
                }
                else{
                    if(/*cnt <= count[city[node][idx]] &&*/ visited[city[node][idx]] > visited[node] + city[node].size()){ //최대값이 아니라면
                        visited[city[node][idx]] = visited[node] + city[node].size();
                        count[city[node][idx]] = cnt;
                    }   
                }
            }
            q.pop();
        }
        cnt++;
    }
    return visited[j];
}

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