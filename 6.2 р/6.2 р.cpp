#include "pch.h"
#include "CppUnitTest.h"
#include "../6.2 рек/6.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My62р
{
	TEST_CLASS(My62р)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int size = 5;
			int a[size];
			int Low = -50;
			int High = 50;

			Create(a, size, Low, High, 0);

			for (int i = 0; i < size; i++) {
				Assert::IsTrue(a[i] >= Low && a[i] <= High);
			}
		}
	};
}
