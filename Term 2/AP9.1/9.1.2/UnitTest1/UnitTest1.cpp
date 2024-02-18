#include "pch.h"
#include "CppUnitTest.h"
#include "..\9.1.2\9.1.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student* p = new Student[3];
			p[0].mat = 5;
			p[0].fiz = 5;
			p[0].spec = IN;
			p[0].chis_metod = 5;

			p[1].mat = 3;
			p[1].fiz = 3;
			p[1].spec = IN;
			p[1].chis_metod = 4;

			p[2].mat = 5;
			p[2].fiz = 5;
			p[2].spec = IN;
			p[2].chis_metod = 4;

			Assert::AreEqual(66.6667, percent(p, 3), 0.0001);
		}
	};
}
