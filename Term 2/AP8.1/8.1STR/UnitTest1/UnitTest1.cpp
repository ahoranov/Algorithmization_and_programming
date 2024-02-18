#include "pch.h"
#include "CppUnitTest.h"
#include "..\8.1STR\8.1STR.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::string s;
			s = "111aa";
			Change(s);
			Assert::AreEqual(s[3], '*');
			Assert::AreEqual(s[4], '*');
			Assert::AreEqual(s[5], '*');
		}
	};
}
