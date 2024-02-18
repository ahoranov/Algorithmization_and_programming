#include "pch.h"
#include "CppUnitTest.h"
#include "..\7.1\7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			int q[3][3] = { {1,1,1},{2,2,2},{3,3,3} };
			int s = 0;
			int k = 0;
			int* q1[3] = { q[0],q[1],q[2] };

			Calc(q1, 3, 3, s, k);

			Assert::AreEqual(12, s);
			Assert::AreEqual(6, k);
		}
	};
}