#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.3.2(rec).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(sumOfPositiveTest)
		{
			int arr[] = { 1, -2, -4,12, 1, -2, -3, 4 };
			Assert::IsTrue(sumOfPositive(arr, 8) == 18);


			int arr1[] = { -1, -2, -4,-12, -1, -2, -3, -4 };
			Assert::IsTrue(sumOfPositive(arr1, 8) == 0);

			int arr2[] = { 1, 2, 4,12, 1, 2, 3, 4 };
			Assert::IsTrue(sumOfPositive(arr2, 8) == 29);
		}
	};
}
