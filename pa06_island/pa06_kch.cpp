#include<iostream>
#include<string>
#include<queue>

using namespace std;

queue<int> q;

int main(){
    int m,n,cnt=0;
    cin>>m>>n;
    int island[n][m],visited[n][m],i=0,j=0;
    //initialize
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            visited[i][j] = 0;
    i=0;j=0;
    //input
    while(true){
        string s;
        cin>>s;
        if(s=="-1") break;
        char c[s.length()];
        s.copy(c,s.length());
        for(int index=0;index<s.length();index++){
            island[i][j++] = c[index++]-'0';
            if(j>=m){
                j=0;
                i=i+1;
            }
        }
    }
    //find
    q.push(0); //x
    q.push(0); //y
    while(!q.empty()){
        int x = q.front();
        q.pop(); //pop x
        int y = q.front();

        if(!visited[x][y]){
            visited[x][y] = 1; 
            if(y+1<m && !island[x][y+1]){
                q.push(x);
                q.push(y+1);
            }
            if(y-1>=0 && !island[x][y-1]){
                q.push(x);
                q.push(y-1);
            }
            if(x-1>=0 && !island[x-1][y]){
                q.push(x-1);
                q.push(y);
            }
            if(x+1<n && !island[x+1][y]){
                q.push(x+1);
                q.push(y);
            }
            cnt = cnt+1;
            q.pop(); //pop y
        }
        else
            q.pop(); //pop y
    }
    cout<<m*n - cnt;
}