/**
 * @file pa05_train.cpp
 * @author sehankim (kimbird2002@naver.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<list>
using namespace std;

int check(int front, int back, int train){
    if(train <back || train >front) return 1;
    else return 0;
}

int where(int front,int back,int B,int train){
    if(check(front,back,B) && check(front,back,train)){
        if(B < back && train > front) return 1;
        if(B < back && train < back) return 2;
        if(B > front && train > front) return 3;
        if(B > front && train < back) return 4;
    }
    else if(!check(front,back,B) && check(front,back,train)){
        if(train < back) return 5;
        if(train > front) return 6;
    }
    else if(check(front,back,B) && !check(front,back,train)){
        if(B < back) return 7;
        if(B > front) return 8;
    }
    else if(!check(front,back,B) && !check(front,back,train)){return -1;}
}

int main(){
    int n,train,B=0,cnt=0,state=0;
    cin>>n;
    list<int> ls;
    for(int i=0;i<n;i++){
        cin>>train;
        //이거 넣고 55점
        if(B==0 &&(train==1 || train==n)){
            B = train;
            continue;
        }
        if(ls.empty()) ls.push_back(train);
        else if(B==0) B = train;
        else{
            int front = ls.front();
            int back = ls.back();

            switch(where(front,back,B,train)){
                case 1:
                    if(back-B <= train-front){
                        ls.push_back(B);
                        B=train;
                    }
                    else{
                        ls.push_front(train);
                    }
                    break;
                case 2:
                    if(back-B <= back-train){
                        ls.push_back(B);
                        B = train;
                    }
                    else{
                        ls.push_back(train);
                    }
                    break;
                case 3:
                    if(B-front <= train-front){
                        ls.push_front(B);
                        B = train;
                    }
                    else{
                        ls.push_front(train);
                    }
                    break;
                case 4:
                    if(B-front <= back-train){
                        ls.push_front(B);
                        B = train;
                    }
                    else{
                        ls.push_back(train);
                    }
                    break;
                case 5:
                    ls.push_back(train);
                    break;
                case 6:
                    ls.push_front(train);
                    break;
                case 7:
                    ls.push_back(B);
                    B = train;
                    break;
                case 8:
                    ls.push_front(B);
                    B = train;
                    break;
                default: 
                    state=1;
            }
            if(state) break;
        }
    }
    
    list<int>::iterator it;
    for(it = ls.begin();it!=ls.end();it++){
        cout<<*it<<" ";
    }
    
    
    
    cout<<ls.size();
}