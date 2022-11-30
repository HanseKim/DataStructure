#include <bits/stdc++.h>

using namespace std;

int num, demesion, idx = 0,n=1;
string word;
vector<char> toIMG;
vector<vector<string>> createIMG, toQTS;
vector<vector<char>> arr;


bool init() { 
  cin >> num >> word;
  n <<= num;
  createIMG.resize(n, vector<string>(n));
  if (word == "QTS") return true;   
  else return false;
}


void makeIMG(int a, int b, int max) {
  if (max== 1) {
    createIMG[b][a] = toIMG[idx];
    idx++;
  }
  else {
    makeIMG(a + max / 2, b          , max / 2);
    makeIMG(a          , b          , max / 2);
    makeIMG(a          , b + max / 2, max / 2);
    makeIMG(a + max / 2, b + max / 2, max / 2);
  }
           
}

void QTS_to_IMG() { 
   char qts;
  int current = 0;
  while (cin >> qts) {
    if (qts == '(') {
      current++;
      continue;
    } else if (qts == ')'){
      current--;
      continue;
    }
    int size = 1<<2*(num-current);
    for (int i = 0; i < size; i++) toIMG.push_back(qts);
  }
  makeIMG(0,0,n);
  
    for (auto ss : createIMG) { 
        for(auto s : ss) cout << s;
        cout << "\n";
    }
}

void IMG2TEXT(int x, int y, int size) {
  int state = 0;
  char c = arr[x][y];
  for (int i = x; i < size + x; i++) {
    for (int j = y; j < size + y; j++) {
      if (state == 0 && arr[i][j] != c) {
        cout << "(";
        IMG2TEXT(x, y + size / 2, size / 2);                //1       
        IMG2TEXT(x, y, size / 2);                           //2
        IMG2TEXT(x + size / 2, y, size / 2);                //3
        IMG2TEXT(x + size / 2, y + size / 2, size / 2);     //4
        state = 1;
        cout << ")";
      }
      if (state) break;
    }
    if (state) break;
  }
  if (!state) cout << c;
}


void IMG_to_QTS() {
  arr.resize(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  IMG2TEXT(0, 0, n);
}

int main() {
  if (init()) {     
     QTS_to_IMG();
  } else {      
    IMG_to_QTS();
  }
}