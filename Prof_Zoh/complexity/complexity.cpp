#include<bits/stdc++.h>

using namespace std;

string fun;

void input(){
    string str;
    int index=0;
    while(1){
        getline(cin,str);
        if(str.find("main")!=string::npos)break;
        index=0;
        while((index = str.find("{",index)) != string::npos ){
            fun.append("{");
            index+=1;
        }
        index=0;
        while((index = str.find("}",index)) != string::npos ){
            fun.append("}");
            index+=1;
        }
    }
    index=0;
    int left=0,right=0;
    while((index = str.find("{",index)) != string::npos ){
        fun.append("{");
        index+=1;left++;
    }
    do{
        getline(cin,str);
        index=0;
        while((index = str.find("{",index)) != string::npos ){
            fun.append("{");
            index+=1;left++;
        }
        index=0;
        while((index = str.find("}",index)) != string::npos ){
            fun.append("}");
            index+=1;right++;
        }
    }
    while(left!=right);
}

int complexity(){
    int count=0,result=0;
    for(int i=0;i<fun.length();i++){
        if(fun[i] == '{') count++;
        else if(fun[i] =='}') result+=count--;
    }
    return result;
}

int main(){
    input();
    //cout<<fun<<"\n";
    cout<<complexity();
}