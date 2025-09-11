struct PT {
	ll x, y;
	PT(ll x=0, ll y=0) : x(x), y(y) {}

	PT operator+(const PT&a)const{return PT(x+a.x, y+a.y);}
	PT operator-(const PT&a)const{return PT(x-a.x, y-a.y);}
	ll operator*(const PT&a)const{return  (x*a.x + y*a.y);} 
	ll operator%(const PT&a)const{return  (x*a.y - y*a.x);} 
	PT operator*(ll c) const{ return PT(x*c, y*c); }
	PT operator/(ll c) const{ return PT(x/c, y/c); }
	bool operator==(const PT&a) const{ return x == a.x && y == a.y; }
	bool operator< (const PT&a) const{ return x != a.x ? x < a.x : y < a.y; }
	
	ld len() const { return hypot(x,y); } 
	ll cross(const PT&a, const PT&b) const{ return (a-*this) % (b-*this); } 
	int quad() { return (x<0)^3*(y<0); } 
	bool ccw(PT q, PT r){ return (q-*this) % (r-q) > 0;}
};

ld dist(PT p, PT q){ return sqrtl((p-q)*(p-q)); }
ld proj(PT p, PT q){ return p*q / q.len(); }      


const ld PI = acos(-1.0L);
ld angle(PT p, PT q){ return atan2(p%q, p*q); } 
ld polarAngle(PT p){  return atan2(p.y, p.x); } 
bool cmp_ang(PT p, PT q){ return p.quad() != q.quad() ? p.quad()<q.quad() : q.ccw(PT(0,0), p); }

PT rotateCCW90(PT p){ return PT(-p.y, p.x); } 
PT rotateCW90(PT p){ return PT(p.y, -p.x); }
PT rotateCCW(PT p, ld t){
	ld c = cos(t), s = sin(t);
	return PT(p.x*c - p.y*s, p.x*s + p.y*c); 
}


/*LATEX_DESC_BEGIN***************************
	len() -> O(sqrt(p*p))
	cross() ->  (a-p) % (b-p)
	quad() -> Cartesian plane quadrant |0++|1-+|2--|3+-|
	proj() -> projection size from A to B
	angle( ) -> Angle between vectors p and q [-pi, pi] | acos(a*b/a.len()/b.len())
	polarAngle() -> Angle to x-axis [-pi, pi]
*****************************LATEX_DESC_END*/