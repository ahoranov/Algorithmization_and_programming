#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.4.2(rec).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int arr[] = { 1, 2, -4,12, 1, -2, 3, 4 };
			int res[] = { 1, 1, 2,-4, 12, -2, 3, 4 };
			zavd2(arr, 8);
			for (int i = 0; i < 8; i++) {
				Assert::IsTrue(arr[i] == res[i]);
			}
		}
	};
}