/**
 * @file pa11_citypath3.cpp
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

int main(){
    int n;
    cin>>n;
    int city[n+1][n+1]={{0}};
    for(int i=1;i<=n;i++){
        int j=0,node;
        while(1){
            cin>>node;
            if(node==0) break;
            if(node==i) continue;
            city[i][j++] = node;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" -> ";
        for(int j=0;j<n;j++) cout<<city[i][j]<<", ";
        cout<<"\n";
    }
}