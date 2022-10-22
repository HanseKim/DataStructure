/**
 * @file pa06_island.cpp
 * @author SehanKim (kimbird2002@naver.com)
 * @brief find island area by recursion
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int** matrix,**visited;
int m,n;

void make_matrix(){
    matrix = new int*[m];
    visited = new int*[m];
    for(int i=0;i<m;i++){
        matrix[i] = new int[n];
        visited[i] = new int[n];
        for(int j=0;j<n;j++){
            visited[i][j] = 1;
        }
    }
}

int cnt_zero=0;

void find(int i,int j){
    if(i==m) return;
    if(j==n) return;
    if(!matrix[i][j]){
        if(visited[i][j]){
            cnt_zero++;
            visited[i][j] = 0; //visited
            if(i>0 && j>=0 && i<m &&j<n){
                find(i-1,j); //up
                find(i,j-1); //left
                find(i,j+1); //right
                find(i+1,j); //down
            }
            else if(i==m-1){
                find(i,j+1); //right
            }
            else if(j==n-1){
                find(i+1,j); //down
            }
            else if(i==0){
                find(i,j+1); //right
                find(i+1,j); //down
            }
        }
    }
}

void put_matrix(){
    int i=0,j=0;
    while(1){
        string str;
        cin>>str;
        int idx=0;
        if(str=="-1") break;
        int len = str.length();
        char c[len];
        str.copy(c,len);
        while(idx<len){
            matrix[i][j++] = c[idx++] - '0';
            if(j>=n){
                j=0;i++;
            }
        }
    }
}

void print_matrix(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j];
        }
        cout<<"\n";
    }
}

int main(){
    cin>>m>>n;
    make_matrix();
    put_matrix();
    find(0,0);
    //print_matrix();
    cout<<m*n - cnt_zero;
}