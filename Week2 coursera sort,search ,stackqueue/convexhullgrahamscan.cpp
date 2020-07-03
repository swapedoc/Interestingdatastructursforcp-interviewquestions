struct pt {
	double x, y;
};

bool cmp (pt a, pt b) {
	return ax <bx || ax == bx && ay <by;
}

bool cw (pt a, pt b, pt c) {
	return ax * (by-cy) + bx * (cy-ay) + cx * (ay-by) <0;
}

bool ccw (pt a, pt b, pt c) {
	return ax * (by-cy) + bx * (cy-ay) + cx * (ay-by)> 0;
}

void convex_hull (vector <pt> & a) {
	if (a.size () == 1) return;
	sort (a.begin (), a.end (), & cmp);
	pt p1 = a [0], p2 = a.back ();
	vector <pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i = 1; i <a.size (); ++ i) {
		if (i == a.size () - 1 || cw (p1, a [i], p2)) {
			while (up.size ()> = 2 &&! cw (up [up.size () - 2], up [up.size () - 1], a [i]))
				up.pop_back ();
			up.push_back (a [i]);
		}
		if (i == a.size () - 1 || ccw (p1, a [i], p2)) {
			while (down.size ()> = 2 &&! ccw (down [down.size () - 2], down [down.size () - 1], a [i]))
				down.pop_back ();
			down.push_back (a [i]);
		}
	}
	a.clear ();
	for (size_t i = 0; i <up.size (); ++ i)
		a.push_back (up [i]);
	for (size_t i = down.size () - 2; i> 0; --i)
		a.push_back (down [i]);
}