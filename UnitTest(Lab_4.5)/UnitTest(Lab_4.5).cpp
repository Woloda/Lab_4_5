#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab_4.5/FuzzyNumber.cpp"
#include "../Lab_4.5/Complex.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab45
{
	TEST_CLASS(UnitTestLab45)
	{
	public:
		
		TEST_METHOD(Test_FuzzyNumber)
		{
			Pair* A = new FuzzyNumber(1.0, 2.0, 3.0);
			Pair* B = new FuzzyNumber(3.0, 4.0, 5.0);
			Pair* C = NULL;

			C = *A + B;
			Assert::AreEqual(((FuzzyNumber*)C)->Get_x(), -2.0);
		}

		TEST_METHOD(Test_Complex)
		{
			Pair* A = new Complex(3, 5);
			Pair* B = new Complex(2, 6);
			Pair* C = NULL;

			C = *A - B;
			Assert::AreEqual(((Complex*)C)->Get_b(), -1.0);
		}
	};
}