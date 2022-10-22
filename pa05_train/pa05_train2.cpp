/**
 * @file pa05_train2.cpp
 * @author sehankim (kimbird2002@naver.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>

using namespace std;

int n,*train,m=0;

void connect(int front,int back,int i,int B,int cnt){
    m = max(m,cnt);
    if(i>=n){
        if(B!=0){
            if(B<back||B>front) 
                m = max(m,cnt+1);
        }
        return;
    }
    int t = train[i];
    if(front==0&&back==0) connect(t,t,i+1,B,cnt+1);
    else if(t>front) connect(t,back,i+1,B,cnt+1);
    else if(t<back) connect(front,t,i+1,B,cnt+1);
    if(B==0) connect(front,back,i+1,t,cnt);
    else if(B>front) connect(B,back,i+1,t,cnt+1);
    else if(B<back) connect(front,B,i+1,t,cnt+1);
    return ;
}

int main(){
    cin>>n;
    train = new int[n];
    for(int i=0;i<n;i++) cin>>train[i];
    connect(0,0,0,0,0);
    cout<<m;
}