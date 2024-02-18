#include "pch.h"
#include "CppUnitTest.h"
#include "..\7.3IT\7.3IT.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n;
			n = 3;

			int a[3][3] = { {-1,2,1}, {7,6,10}, {-10,-7,-4} };
			int* pa[3] = { a[0],a[1],a[2] };


			Assert::AreEqual(13, sum(pa, n));
		}
	};
}
