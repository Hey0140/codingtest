#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int c[100001];
bool v[100001] = {};
vector<pair<int, int>> f;

int clop(pair<int,int> p, int co){
    int count = 0;
    stack<pair<int, int>> s;
    pair<int,int> com;
    auto it = find(f.begin(), f.end(), p);
    if(it == f.end() ){
        s.push(p);
        while(!s.empty()) {
            com = s.top();
            s.pop();
            for (int e = 0; e < f.size(); e++) {
                if (v[com.first] == true && v[com.second] == true) break;
                else if (f[e].first == com.first && v[f[e].first] != true && v[f[e].second] != true) {
                    v[com.first] = true;
                    if (c[f[e].first] == co && c[f[e].second] != co) {
                        count++;
                        com.first = f[e].second;
                        s.push(com);
                    }
                } else if (f[e].second == com.first && v[f[e].second] != true && v[f[e].first] != true) {
                    v[com.second] = true;
                    if (c[f[e].first] != co & c[f[e].second] == co) {
                        count++;
                        com.first = f[e].first;
                        s.push(com);
                    }
                }
            }
        }
    }
    return count;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    char s;
    int n, a;
    int q1, q2;
    cin >> n >> a;
    for(int i =0; i < n; i++){
        cin >> c[i];
    }
    for(int i = 0; i < n-1; i++){
        cin >> q1 >> q2;
        if(q1 < q2) f.push_back(make_pair(q1-1, q2-1));
        else f.push_back(make_pair(q2-1, q1-1));
    }
    sort(f.begin(), f.end());
    for(int e = 0; e< f.size(); e++){
        cout <<  "sort" << f[e].first << " " << f[e].second << "\n";
    }
    for(int i = 0; i < a; i++){
        int A, B, C;
        cin >> s;
        if(s == 'U'){
            cin >> A >> C;
            c[A-1] = C;
        }
        if(s == 'Q'){
            int dis;
            for(int i = 0; i < n; i++){
                v[i] = false;
            }
            cin >> A >> B >> C;
            pair<int,int> pp = make_pair(A-1, B-1);
            dis = clop(pp, C);
            if(dis == 0) cout << "-1";
            else cout << dis;
        }
    }

}