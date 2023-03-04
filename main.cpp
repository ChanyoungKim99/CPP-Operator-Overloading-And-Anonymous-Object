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
	// 연산자 오버로딩
	// 연산자 오버로딩을 통해 더하기 연산자를 클래스에 맞춰서 사용해보자

	Point2D pt;
	pt.mX = left.mX + right.mX;
	pt.mY = left.mY + right.mY;
	// 친구로 지정되어있기 때문에, private인 mX, mY 사용가능
	return pt;
}

int main()
{
	Point2D pt1(2, 3);
	Point2D pt2(4, 5);

	pt1.Print();
	pt2.Print();


	Point2D pt3;
	pt3 = pt1 + pt2;	// 연산자 오버로딩이 일어나 연산자 +가 아닌, 함수 +가 작동함
	pt3.Print();


	Point2D pt4;
	pt4 = (pt1 + pt2) + pt3;
	pt4.Print();
}