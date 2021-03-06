#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

int n;

// min heap
int len;
int hp[mxN];

void shiftup(int u) {
    for(; u>1 && hp[u] < hp[u>>1]; u>>=1)
        swap(hp[u], hp[u>>1]);
}

void shiftdown(int u) {
    for(int x=u<<1; x<=len; x=u<<1) {
        int mn = x+1<=len?hp[x]<hp[x+1]?x:x+1:x;
        if(hp[u] > hp[mn]) swap(hp[u], hp[mn]), u = mn;
        else break;
    }
}

void insert(int u) {
    hp[++len] = u;
    shiftup(len);
}

int pop() {
    int x=hp[1];
    hp[1]=hp[len--];
    shiftdown(1);
    return x;
}
    
int a;
int main() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a, insert(a);

    for(int i=0; i<n; ++i)
        cout << pop() << ' ';
    cout << endl;

    return 0;
}
