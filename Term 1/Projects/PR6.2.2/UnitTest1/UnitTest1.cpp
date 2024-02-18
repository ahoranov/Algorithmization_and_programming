#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.2.2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int arr[] = { 4, 5, -7,15, 4, -5, 6, 7 };
			int res[] = { 7, 6, -5, 4, 15, -7, 5, 4 };
			reverse(arr, 0, 8);
			for (int i = 0; i < 8; i++) {
				Assert::IsTrue(arr[i] == res[i]);
			}

		}


	};
}