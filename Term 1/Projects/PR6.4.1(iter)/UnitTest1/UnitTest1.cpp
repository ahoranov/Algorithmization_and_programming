#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.4.1(iter).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int arr[] = { 1, 2, -4,12, 1, -2, 3, 4 };
			Assert::IsTrue(sum(arr, 8) == 13);
		}
	};
}
