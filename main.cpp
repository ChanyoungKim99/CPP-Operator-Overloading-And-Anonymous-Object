#include <iostream>

class Point2D
{
private:
	int mX;
	int mY;

public:
	Point2D() : mX{ 0 }, mY{ 0 }
	{
	}

	Point2D(int x, int y) : mX{ x }, mY{ y }
	{
	}

	void Print()
	{
		std::cout << "(" << mX << ", " << mY << ")" << std::endl;
	}

	friend Point2D operator+(Point2D left, Point2D right);
};

Point2D operator +(Point2D left, Point2D right)
{
	// ������ �����ε�
	// ������ �����ε��� ���� ���ϱ� �����ڸ� Ŭ������ ���缭 ����غ���

	Point2D pt;
	pt.mX = left.mX + right.mX;
	pt.mY = left.mY + right.mY;
	// ģ���� �����Ǿ��ֱ� ������, private�� mX, mY ��밡��
	return pt;
}

int main()
{
	Point2D pt1(2, 3);
	Point2D pt2(4, 5);

	pt1.Print();
	pt2.Print();


	Point2D pt3;
	pt3 = pt1 + pt2;	// ������ �����ε��� �Ͼ ������ +�� �ƴ�, �Լ� +�� �۵���
	pt3.Print();


	Point2D pt4;
	pt4 = (pt1 + pt2) + pt3;
	pt4.Print();
}