#include<bits/stdc++.h>

using namespace std;

string fun;

void input(){
    string str;
    int index=0;
    while(!cin.eof()){
        getline(cin,str);
        index=0;
        for(char & it: str){
            if(it=='{') fun.append("{");
            if(it=='}') fun.append("}");
        }
    }
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