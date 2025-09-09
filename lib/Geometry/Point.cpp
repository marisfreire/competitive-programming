#include <bits/stdc++.h>
#define ll long long
#define ld double
using namespace std;

struct PT {
	ll x, y;
	PT(ll x=0, ll y=0) : x(x), y(y) {}

	PT operator+(const PT&a)const{return PT(x+a.x, y+a.y);}
	PT operator-(const PT&a)const{return PT(x-a.x, y-a.y);}
	ll operator*(const PT&a)const{return  (x*a.x + y*a.y);} //DOT
	ll operator%(const PT&a)const{return  (x*a.y - y*a.x);} //Cross
	PT operator*(ll c) const{ return PT(x*c, y*c); }
	PT operator/(ll c) const{ return PT(x/c, y/c); }
	bool operator==(const PT&a) const{ return x == a.x && y == a.y; }
	bool operator< (const PT&a) const{ return x != a.x ? x < a.x : y < a.y; }
	
	// utils
	ld len() const { return hypot(x,y); } // sqrt(p*p)
	ll cross(const PT&a, const PT&b) const{ return (a-*this) % (b-*this); } // (a-p) % (b-p)
	int quad() { return (x<0)^3*(y<0); } //cartesian plane quadrant |0++|1-+|2--|3+-|
	bool ccw(PT q, PT r){ return (q-*this) % (r-q) > 0;}
};

ld dist(PT p, PT q){ return sqrtl((p-q)*(p-q)); }
ld proj(PT p, PT q){ return p*q / q.len(); }      
//Projection size from A to B

const ld PI = acos(-1.0L);
ld angle(PT p, PT q){ return atan2(p%q, p*q); } // Angle between vectors p and q [-pi, pi] | acos(a*b/a.len()/b.len()))
ld polarAngle(PT p){  return atan2(p.y, p.x); } // Angle to x-axis [-pi, pi]
bool cmp_ang(PT p, PT q){ return p.quad() != q.quad() ? p.quad()<q.quad() : q.ccw(PT(0,0), p); }

PT rotateCCW90(PT p){ return PT(-p.y, p.x); } // perp
PT rotateCW90(PT p){ return PT(p.y, -p.x); }
PT rotateCCW(PT p, ld t){
	ld c = cos(t), s = sin(t);
	return PT(p.x*c - p.y*s, p.x*s + p.y*c); 
}