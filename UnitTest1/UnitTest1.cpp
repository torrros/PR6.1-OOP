#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\vladt\source\repos\PR6.1 OOP\PR6.1 OOP\Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Array a(10);
			a.assign(10);
			Assert::AreEqual((int)a[1], 10);
			
		}
	};
}
