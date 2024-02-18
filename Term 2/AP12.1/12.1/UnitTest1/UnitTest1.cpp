#include "pch.h"
#include "CppUnitTest.h"
#include "..\12.1\12.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Elem* p = new Elem;

            p->info = 1;
            p->link1 = new Elem;
            p->link1->info = 2;

            p->link1->link1 = p;
            p->link1->link2 = new Elem;
            p->link1->link2->info = 3;

            // Чек p
            assert(p->info == 1);
            assert(p->link1->info == 2);

            // Чек p->link1
            assert(p->link1->link1 == p);
            assert(p->link1->link2->info == 3);

            // Клін
            delete p->link1->link2;
            delete p->link1;
            delete p;    
		}
	};
}
