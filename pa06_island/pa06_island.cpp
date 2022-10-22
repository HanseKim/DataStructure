/**
 * @file pa06_island.cpp
 * @author SehanKim (kimbird2002@naver.com)
 * @brief find island area by queue
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<string>
#include<queue>
using namespace std;

int** matrix,**visited; //입력을 저장하기 위한 matrix, 방문했는지 체크하기 위한 visited 배열이다.
int m,n,cnt_zero=0;     //배열의 크기를 저장하기 위한 m,n
queue<pair<int,int>> q;

//matrix 생성, visited 생성,초기화
void make_matrix(){
    matrix = new int*[n];
    visited = new int*[n];
    for(int i=0;i<n;i++){
        matrix[i] = new int[m];
        visited[i] = new int[m];
        for(int j=0;j<m;j++){
            visited[i][j] = 0;
        }
    }
}

//island 외부의 0의 갯수를 전체 요소 수에서 빼준다
void find(){
    q.push({0,0});
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        //방문한 0이면 뛰어 넘는다. 방문하지 않은 점일 때
        if(visited[x][y] == 0){
            cnt_zero++;
            visited[x][y] = 1; //방문으로 만들어준다.
            if(y+1<m && matrix[x][y+1] == 0){ //right
                q.push({x,y+1});
            }
            if(y-1>=0 && matrix[x][y-1] == 0){ //left
                q.push({x,y-1});
            }
            if(x-1>=0 && matrix[x-1][y] == 0 ){ //up
                q.push({x-1,y});
            }
            if(x+1<n && matrix[x+1][y]== 0){ //down
                q.push({x+1,y});
            }
        }
        q.pop();
    }
}

//matrix를 입력 받는다.
void put_matrix(){
    int i=0,j=0;
    while(1){
        //한줄로 입력받기 때문에 string으로 입력받고 char 배열로 바꿔준다.
        string str;
        cin>>str;
        int idx=0;
        if(str=="-1") break;
        int len = str.length();
        char c[len];
        str.copy(c,len);
        while(idx<len){
            //한 줄의 배열을 matrix에 넣어준다. 문자이기 때문에 '0'을 빼서 숫자로 만들어서 저장한다.
            matrix[i][j++] = c[idx++] - '0';
            if(j>=m){
                j=0;i++;
            }
        }
    }
}

//matrix가 잘 들어왔는지 확인하기 위해 사용
void print_matrix(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j];
        }
        cout<<"\n";
    }
}


int main(){
    cin>>m>>n;
    make_matrix(); //matrix를 만들고
    put_matrix(); //입력받고
    find(); // 섬 외부 0 갯수를 구한다.
    //print_matrix();
    cout<<m*n - cnt_zero;
}