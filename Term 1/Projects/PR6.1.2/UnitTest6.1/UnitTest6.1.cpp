#include "pch.h"
#include "CppUnitTest.h"
#include "../PR-6.1-rec/PR-6.1-rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61
{
	TEST_CLASS(UnitTest61)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			const int k = 3;
			int b[k] = { -2, -4, -6 };
			t = Sum(b, k, 0);
			Assert::AreEqual(t, -12);

		}
	};
}
