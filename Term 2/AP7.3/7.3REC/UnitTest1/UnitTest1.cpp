#include "pch.h"
#include "CppUnitTest.h"
#include "..\7.3REC\7.3REC.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n, kilk;
			n = 3;
			kilk = 0;

			int a[5][5] = { {11,11,11,11,11}, {11,5,3,0,11}, {11,-9,4,7,11}, {11,-3,8,3,11}, {11,11,11,11,11} };
			int* pa[5] = { a[0],a[1],a[2],a[3],a[4] };

			min(pa, n + 2, kilk, 1, 1);

			Assert::AreEqual(kilk, 3);
		}
	};
}
