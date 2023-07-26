#include <bits/stdc++.h>
using namespace std;
#define cl() cerr << endl;
#define debugptr(x, y)cerr << "(Line " << __LINE__ << "):" << #x << " ";_print_(x, y);cerr << endl;
#define debug(x...)cerr << "(Line " << __LINE__ << "):[" << #x << "]=>";_print_(x);cerr << endl;
#define graph(x, y)cerr << "(Line " << __LINE__ << "):[" << #x << "]=>" << endl;__print(x, y);cerr << endl;
template <class T>void _print_(T &x);
template <class T>void _print_(T *x, int n = 0);
template <class T1, class T2>void _print_(pair<T1, T2> x);
template <class T>void _print_(vector<T> &x);
template <class T>void _print_(vector<vector<T>> &x);
template <class T1, class T2>void _print_(map<T1, T2> &x);
template <class T>void _print_(queue<T> x);
template <class T>void _print_(deque<T> x);
template <class T>void _print_(set<T> &x);
template <class T>void _print_(multiset<T> &x);
template <class T>void _print_(unordered_set<T> &x);
template <class T>void _print_(priority_queue<T>x);
template <class T>void _print_(priority_queue<T,vector<T>,greater<T>>x);
template <class T>void _print_(stack<T> x);
template <class T>void _print_(T &x){
    if(sizeof(x)==sizeof(ll)){
        if(abs(x)>=INF){
            if(x<0)cerr<<'-';
            cerr<<'I';
        }
        else cerr<<x;
    }
    else{
        cerr<<x;
    }
}
template <class T>void _print_(T *x, int &n){
    cerr << "{ ";
    for (int i = 0; i < n; i++)
        cerr << *(x++) << " ";
    cerr << "}";
}
template <class T1, class T2>void _print_(pair<T1, T2> x){
    cerr << "{";
    _print_(x.first);
    cerr << ",";
    _print_(x.second);
    cerr << "}";
}
template <class T>void _print_(vector<T> &x){
    cerr << "{ ";
    int j = 0;
    for (T i : x){
        cerr << j++ << ":";
        _print_(i);
        cerr << ' ';
    }
    cerr << "}";
}
template<class T>void _print_(vector<vector<T>>&v){
    cerr<<'{'<<endl;int j=0;
    for(vector<T> &arr:v){
        cerr<<'\t'<<j++<<':';
        _print_(arr);
        cl();
    }
    cerr<<'}';
}
template <class T1, class T2>void _print_(map<T1, T2> &x){
    cerr << "[ ";
    for (auto i : x){
        cerr << "{";
        _print_(i.first);
        cerr << ":";
        _print_(i.second);
        cerr << "} ";
    }
    cerr << "]";
}
template <class T>void _print_(queue<T> x){
    if(x.empty()){
        cerr<<"THIS QUEUE IS EMPTY.";return;
    }
    cerr<<"{ FRONT:";_print_(x.front());cerr<<' ';x.pop();
    int j=1,y=x.size();
    while(x.size()>1){
        cerr<<j++<<':';
        _print_(x.front());x.pop();
        cerr<<' ';
    }
    if(y){cerr<<"BACK:";_print_(x.front());cerr<<' ';}
    cerr<<'}';
}
template <class T>void _print_(deque<T> x){
    if(x.empty()){
        cerr<<"THIS DEQUE IS EMPTY.";return;
    }
    cerr<<"{ FRONT:";_print_(x.front());cerr<<' ';x.pop_front();
    int j=1,y=x.size();
    while(x.size()>1){
        cerr<<j++<<':';
        _print_(x.front());x.pop_front();
        cerr<<' ';
    }
    if(y){cerr<<"BACK:";_print_(x.front());cerr<<' ';}
    cerr<<'}';
}
template <class T>void _print_(set<T> &x){
    cerr << "{ ";
    int j = 0;
    for (T i : x){
        cerr << j++ << ":";
        _print_(i);
        cerr << " " ;
    }
    cerr << "}";
}
template <class T>void _print_(multiset<T> &x){
    cerr << "{";
    int j = 0;
    for (T i : x){
        cerr << j++ << ":";
        _print_(i);
        cerr << " ";
    }
    cerr << "}";
}
template <class T>void _print_(unordered_set<T> &x){
    cerr << "{";
    int j = 0;
    for (T i : x){
        cerr << j++ << ":";
        _print_(i);
        cerr << " ";
    }
    cerr << "}";
}
template <class T>void _print_(priority_queue<T> x){
    if(x.empty()){
        cerr<<"THIS HEAP IS EMPTY.";return;
    }
    cerr<<"{ VALUE:";_print_(x.top());cerr<<' ';x.pop();
    int j=1,y=x.size();
    while(!x.empty()){
        cerr<<j++<<':';
        _print_(x.top());x.pop();
        cerr<<' ';
    }
    cerr<<'}';
}
template <class T>void _print_(priority_queue<T,vector<T>,greater<T>> x){
    if(x.empty()){
        cerr<<"THIS HEAP IS EMPTY.";return;
    }
    cerr<<"{ VALUE:";_print_(x.top());cerr<<' ';x.pop();
    int j=1,y=x.size();
    while(!x.empty()){
        cerr<<j++<<':';
        _print_(x.top());x.pop();
        cerr<<' ';
    }
    cerr<<'}';
}

template <class T>void _print_(stack<T> x){
    int y=x.size(),j=1;
    if(!y)cerr<<"THIS STACK IS EMPTY!";
    else{
        cerr<<"{ TOP:";_print_(x.top());cerr<<' ';x.pop();
        y--;
        while(y--){
            cerr<<++j<<':';_print_(x.top());cerr<<' ';x.pop();
        }
        cerr<<'}';
    }
}
template <class T1, class... T2>void _print_(T1 &x, T2... y){
    _print_(x);
    if (sizeof...(y))cerr << ",";
    _print_(y...);
}
template <class T>void __print(vector<vector<T>> &adj, T source) {
    int N = 10000010;
    vector<bool> vis(N);
    vector<int> dis(N);
    queue<T> q;
    q.push(source);
    vis[source] = true;
    while (!q.empty()){
        T v = q.front();
        string s(4 * dis[v], ' ');
        cerr << s;
        _print_(v);
        cerr << "-->";
        q.pop();
        for (auto child : adj[v]){
            if (vis[child])continue;
            _print_(child);
            cerr << " ";
            vis[child] = true;
            q.push(child);
            dis[child] = dis[v] + 1;
        }
        cerr << endl;
    }
}
