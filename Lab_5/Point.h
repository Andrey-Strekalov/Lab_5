///////////////////////////////////////////////////////////
// Point.h
#ifndef POINT_H
#define POINT_H

// ������������ ��� ���������������� �����
enum ORIENT { LEFT, RIGHT, AHEAD, BEHIND, BETWEEN };
class Triangle;

class Point {
public:
	Point(double x = 0.0, double y = 0.0);
	void Show() const; // ����� ���������

	// ��������� ��� ������ � �������
	void operator +=(const Point& p);
	Point operator +(const Point& p) const;
	Point operator -(const Point& p) const;

	double Length() const; // ����� ������� �� ������ ���������
	ORIENT Classify(const Point& beg_p, const Point& end_p) const; // ������������� ���������
	bool InTriangle(const Triangle& tria) const; // �������� ���������� � ������������

	double x, y; // ���������� �����
};

#endif // POINT_H
