bool ccw(pii a, pii b, pii c) {
	return (c.s - a.s) * (b.f - a.f) > (b.s - a.s) * (c.f - a.f);
}
bool isect(pii a, pii b, pii c, pii d) { // checks if segment ab intersects segment cd
	bool isect_at_all = (ccw(a,c,d) != ccw(b,c,d) && ccw(a,b,c) != ccw(a,b,d)); 
	bool isect_endpt = (a == c || a == d || b == c || b == d);
	return isect_at_all; // change to isect_at_all && !isect_endpt if don't want to include endpoints
}
