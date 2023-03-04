#include <iostream>

class MyClass
{
public:
	int mValue;

	MyClass(int value) : mValue{ value }
	{
		std::cout << "[ MyClass() ] : " << mValue << std::endl;
	}
};

MyClass operator +(MyClass& left, MyClass& right)
{
	
	return MyClass(left.mValue + right.mValue);  // ���� ��ü
}

int Square(const MyClass& c)	// ���ͷ� ǥ�⸦ ���� const �߰�
{
	return c.mValue * c.mValue;
}

int main()
{
	MyClass c1(1);
	MyClass c2(2);

	std::cout << "-----------------" << std::endl;
	// const�� �ƴ� ������ ���� �ʱⰪ�� l-value���� �մϴ�.
	// ���� const�� ���̸� �ȴ�

	Square(c1 + c2);		// c1 + c2�� ������� �̸��� ����
							// = l-value�� �ƴϴ�!!

	// ��ġ "Hello" �� ����Ű�� �����͸�
	// ���ͷ� const char* �� ǥ���߾���.
	// �̸��� ���� ������ const�� �ٿ��� ���̴�.
}


/*
ex)

void PrintValue(const int& x)
{
	std::cout << x << std::endl;
}

int main()
{
	PrintValue(30);   => �̸��� ���� ���� ��ü, ���ͷ� 30�� �ޱ� ���ؼ�, 
}						 const�� ���� ���δ�.				
*/