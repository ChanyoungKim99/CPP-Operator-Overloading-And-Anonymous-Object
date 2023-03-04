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
	
	return MyClass(left.mValue + right.mValue);  // 무명 객체
}

int Square(const MyClass& c)	// 리터럴 표기를 위해 const 추가
{
	return c.mValue * c.mValue;
}

int main()
{
	MyClass c1(1);
	MyClass c2(2);

	std::cout << "-----------------" << std::endl;
	// const가 아닌 참조에 대한 초기값은 l-value여야 합니다.
	// 따라서 const를 붙이면 된다

	Square(c1 + c2);		// c1 + c2의 결과값은 이름이 없다
							// = l-value가 아니다!!

	// 마치 "Hello" 를 가리키는 포인터를
	// 리터럴 const char* 로 표기했었다.
	// 이름이 없기 때문에 const를 붙였던 것이다.
}


/*
ex)

void PrintValue(const int& x)
{
	std::cout << x << std::endl;
}

int main()
{
	PrintValue(30);   => 이름이 없는 무명 객체, 리터럴 30을 받기 위해서, 
}						 const를 위에 붙인다.				
*/