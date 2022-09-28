#include <iostream>
using namespace std;
int a [3][3]{};
bool check = true;


bool password(string s, int x, int y, bool c){
    c = true;
    for(int i = 0; i < s.length(); i++){
        if( s[i] == 'D'){
            if(y+2 < 3){
                if(a[x][y+1] == 0) {
                    a[x][y+1] = 1;
                    y = y+1;
                    if(a[x][y+1] == 0){
                        a[x][y+1] = 1;
                        y = y+1;
                    }
                }else {
                    c = false;
                    return c;
                }
            }
            else if(y+1 < 3){
                if(a[x][y+1] == 0) {
                    a[x][y + 1] = 1;
                    y = y+1;
                }else {
                    c = false;
                    return c;
                }
            }
            else {
                c = false;
                return c;
            }
        }
        else if( s[i] == 'U'){
            if(y-2 >= 0){
                if(a[x][y-1] == 0 && a[x][y-2] == 0) {
                    a[x][y-1] = 1;
                    y = y-1;
                    a[x][y-2] = 1;
                    password(s, i+1, x, y-2);
                }
                else if(a[x][y-1] == 0) {
                    a[x][y -1] = 1;
                    password(s, i + 1, x, y - 1);
                }
            }
            else if(y-1 >= 0){
                if(a[x][y-1] == 0) {
                    a[x][y - 1] = 1;
                    password(s, i + 1, x, y - 1);
                }
            }
        }
        else if( s[i] == 'L'){
            if(x-2 >= 0){
                if(a[x-2][y] == 0 && a[x-2][y] == 0) {
                    a[x-1][y] = 1;
                    a[x-2][y] = 1;
                    password(s, i+1, x-2, y);
                }
                else if(a[x-1][y] == 0) {
                    a[x-1][y] = 1;
                    password(s, i + 1, x-1, y);
                }
            }
            else if(x-1 >= 0){
                if(a[x-1][y] == 0) {
                    a[x-1][y] = 1;
                    password(s, i + 1, x-1, y);
                }
            }
        }
        else if( s[i] == 'R'){
            if(x+2 >= 0){
                if(a[x+2][y] == 0 && a[x+2][y] == 0) {
                    a[x+1][y] = 1;
                    a[x+2][y] = 1;
                    password(s, i+1, x+2, y);
                }
                else if(a[x+1][y] == 0) {
                    a[x+1][y] = 1;
                    password(s, i + 1, x+1, y);
                }
            }
            else if(x+1 >= 0){
                if(a[x+1][y] == 0) {
                    a[x+1][y] = 1;
                    password(s, i + 1, x+1, y);
                }
            }
        }
    }


}

bool find(string s, int i, int x, int y) {
    bool check = true;
    password(s, i, x, y);

    return
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    string s, sin;
    cin>> s;
    for(int y = 0; y < 3; y++){
        for(int x = 0; x< 3; x++){
            bool check = false;
            a[3][3] = {};
            password(s, 0, x, y);

        }
    }



    return 0;
}