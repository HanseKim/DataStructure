#include<bits/stdc++.h>
#define L for(auto it=m.begin();it!=m.end();it++)
#define fir it->second.first
#define sec it->second.second
#define MF(s) m[s].first
#define MS(s) m[s].second
using namespace std;
map<string,pair<string,string>> m;
int n; string root;
void pn(string p, string s){
    if(p.compare(s) > 0){
        if(MF(p)==""){
            MF(p) = s;
            m[s] = make_pair("","");
        }else pn(MF(p),s);
    }else if(p.compare(s) < 0){
        if(MS(p)==""){
            MS(p) = s;
            m[s] = make_pair("","");
        }else pn(MS(p),s);
    }
}
void cn(string s, string d){
    L{if(fir == s) fir = d;
    else if(sec == s) sec = d;
    else if(fir == d) fir = s;
    else if(sec == d) sec = s;
    }
    pair<string,string> p = m[s];
    m[s] = m[d];
    m[d] = p;
}
string fmax(string s){
    while(MS(s)!="") s = MS(s);
    return s;
}
void l_(string s){
    if(MF(s)=="") return;
    cn(s,fmax(MF(s)));
    if(MF(s)!=""||MS(s)!="") l_(s);
}
string fmin(string s){
    while(MF(s)!="") s = MF(s);
    return s;
}
void r_(string s){
    if(MS(s)=="") return;
    cn(s,fmin(MS(s)));
    if(MF(s)!=""||MS(s)!="") r_(s);
}
int main(){
    cin>>n;
    while(n--){
        string cmd; cin>>cmd;
        if(cmd == "+"){
            string str; cin>>str;
            if(m.empty() || root=="") {
                m[str] = make_pair("","");
                root = str;
            }
            else if(m.find(str)==m.end()) pn(root, str);
        }
        else if(cmd == "-") {
            string str; cin>>str;
            if(m.find(str) != m.end()){ 
                if(MS(str)==""){
                    if(str==root) root = fmax(MF(str));
                    l_(str);
                }else{
                    if(str==root) root = fmin(MS(str));
                    r_(str);
                }L{
                    if(fir == str) fir="";
                    if(sec == str) sec="";
                }m.erase(m.find(str));
            }
        }
        else if(cmd == "leaf") {
            L if(fir == "" && sec == "") cout<<it->first<<" ";
            cout<<"\n";
        }
        else{
            int dep; cin>>dep;
            queue<string> q;
            q.push(root);
            int cnt=1;
            if(dep==1) cout<<root;
            while(cnt!=dep){
                int size = q.size();
                for(int i=0;i<size;i++){
                    string par = q.front();
                    if(MF(par)!="") q.push(MF(par));
                    if(MS(par)!="") q.push(MS(par));
                    q.pop();
                }cnt++;
            }if(q.empty()) cout<<"NO";
            while(!q.empty()){
                if(q.front() == root) {
                    q.pop();
                    continue;
                }cout<<q.front()<<" ";q.pop();
            }cout<<"\n";
        }
    }
}