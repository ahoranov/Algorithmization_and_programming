#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2REC/7.2REC.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			int q[5][6] = { {1,1,1,1,1,1},{2,2,2,2,2,2},{3,7,3,3,3,3},{4,4,4,4,4,4},{5,5,5,5,5,5} };
			int* q1[5] = { q[0], q[1], q[2], q[3], q[4] };
			int s = sum(q1, 5, 6, 1, 0);
			Assert::AreEqual(17, s);
		}
	};
}
