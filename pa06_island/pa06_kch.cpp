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
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            visited[i][j] = 0;
        } 
    }
        
    i=0;j=0;
    //input
    while(true){
        //string으로 받아와서 char배열로 복사
        //string이 cin으로 받을때 한줄 단위로 받아서
        string s;
        cin>>s;
        if(s=="-1") break;
        char c[s.length()];
        s.copy(c,s.length());
        //island에 int로 넣어야 하므로 -'0'을 해준다(ascii값 변환)
        //length만큼 루프
        for(int index=0;index<s.length();index++){
            island[i][j++] = c[index]-'0';
            if(j>=m){
                j=0;
                i=i+1;
            }
        }
    }
    //1 밖에 있는 0의 갯수를 count하기 위해 queue가 empty가 될 때까지 와일루프
    //x,y를 넣고 하나씩 빼면서 가져온다.
    //루프의 마지막에 y를 빼줌으로써 q가 중간에 비는 걸 방지한다.
    q.push(0); //x
    q.push(0); //y
    while(!q.empty()){
        int x = q.front();
        q.pop(); //pop x
        int y = q.front();
        //x,y가 방문하지 않은 곳이라면
        if(!visited[x][y]){
            //x,y를 방문했다고 바꿔준다.
            visited[x][y] = 1; 
            //오른쪽 y가 island의 인덱스 범위를 넘으면 안되므로 체크해주고
            // (x,y+1)이 0일때 x,y+1을 queue에 push해준다.
            if(y+1<m && !island[x][y+1]){
                q.push(x);
                q.push(y+1);
            }
            //왼쪽
            if(y-1>=0 && !island[x][y-1]){
                q.push(x);
                q.push(y-1);
            }
            //위쪽
            if(x-1>=0 && !island[x-1][y]){
                q.push(x-1);
                q.push(y);
            }
            //아래쪽
            if(x+1<n && !island[x+1][y]){
                q.push(x+1);
                q.push(y);
            }
            //0인 곳을 방문했으므로 cnt를 하나 증가시킨다.
            cnt = cnt+1;
            q.pop(); //pop y
        }
        else
            q.pop(); //pop y
    }
    //전체 갯수에서 1로 둘러싸인 섬의 외부에 있는 0의 갯수를 빼주면
    //섬 내부의 넓이가 나온다.
    cout<<m*n - cnt;
}