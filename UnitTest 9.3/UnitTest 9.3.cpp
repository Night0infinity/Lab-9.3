#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 9.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest93
{
	TEST_CLASS(UnitTest93)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string surname = "a";
			Student* p = new Student[2];
			p[0].prizv = "b";
			p[0].bal1 = 5;
			p[0].bal2 = 5;
			p[0].bal3 = 5;

			p[1].prizv = "a";
			p[1].bal1 = 4;
			p[1].bal2 = 4;
			p[1].bal3 = 4;
			Sortprizv(p, 2);
			Assert::AreEqual(p[0].prizv, surname);
			Assert::AreEqual(p[0].bal1, 4.);
			Assert::AreEqual(p[0].bal2, 4.);
			Assert::AreEqual(p[0].bal3, 4.);
		}
	};
}
