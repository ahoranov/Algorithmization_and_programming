#include "pch.h"
#include "CppUnitTest.h"
#include "../PR-6.1/PR-6.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61
{
	TEST_CLASS(UnitTest61)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			const int n = 3;
			int b[n] = { -2, -4, -6 };
			t = Sum(b, n);
			Assert::AreEqual(t, -12);

		}
	};
}
