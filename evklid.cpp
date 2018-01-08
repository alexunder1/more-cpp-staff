#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b, int &x, int &y){
    if(a == 0){
        x = 0, y = 1;
        return b;
    }
    int _x, _y;
    int d = gcd (b%a, a, _x, _y);
    x = _y-(b/a)*_x;
    y = _x;
    return d;
}
int main(){
    int a, b, x, y, c, g;
    cin >> a >> b >> c;
    gcd(a, b, x, y);
    g=gcd(a, b, x, y);
    if (c % g != 0)
		return false;
    y=y*c/g;
    x=x*c/g; 
if (x>0 && x>b/g && b>0){
	while (x>0 && x>b/g){
	x-=b/g;
	y+=a/g;
	}
x-=b/g;
y+=a/g;
}
while (abs(x) > abs(b/g)/2 && abs(y) > abs(a/g)/2 && x>=0 && y>=0) {
	x+=b/g;
	y-=a/g;
} 
while (abs(x) > abs(b/g)/2 && abs(y) > abs(a/g)/2 && x<=0 && y<=0) {
	x-=b/g;
	y+=a/g;
} 
while (abs(x) > abs(b/g)/2 && abs(y) > abs(a/g)/2 && x<=0 && y>=0) {
	x+=b/g;
	y-=a/g;
}    
while (abs(x)*2 > abs(b/g) && abs(y)*2 > abs(a/g) && y<=0 && x>=0) {
	y+=a/g;
	x-=b/g;
} 
    cout << g << " " << x << " " << y;

}
