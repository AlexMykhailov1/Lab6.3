#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.3/Lab6.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63
{
	TEST_CLASS(UnitTest63)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[10] = { 0,-1,2,-3,-4,-5,6,7,8,9 }, CreateIter = 0, PrintIter = 0;

			MaxEvenIter(a, 10);

			Assert::AreEqual(CreateIter, 0);
			Assert::AreEqual(PrintIter, 0);
			Assert::AreEqual(a[0], 0);
			Assert::AreEqual(a[9], 9);
		}
	};
}
