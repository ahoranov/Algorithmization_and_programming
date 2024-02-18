#include "pch.h"
#include "CppUnitTest.h"
#include "..\8.2\8.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            char str[] = "anastas goranov";
            bool expected = true;
            bool result = FirstLetter(str);
            Assert::AreEqual(result, expected);
        }

        TEST_METHOD(TestMethod2)
        {
            char str[] = "goranov anastas";
            bool expected = true;
            bool result = FirstLetter(str);
            Assert::AreEqual(result, expected);
        }

        TEST_METHOD(TestMethod3)
        {
            char str[] = "goranov goranov";
            bool expected = false;
            bool result = FirstLetter(str);
            Assert::AreEqual(result, expected);
        }
	};
}
