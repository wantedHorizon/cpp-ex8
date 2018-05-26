#pragma once

struct Coordinate {
	int y,x;
	Coordinate(int y, int x): x(x), y(y) {}
};

inline ostream& operator<< (ostream& out, const Coordinate& c) {
	return (out << c.x << "," << c.y);
}
