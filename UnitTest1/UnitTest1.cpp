#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.2rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixProcessingTests
{
    TEST_CLASS(MatrixProcessingTests)
    {
    public:

        TEST_METHOD(TestCreate)
        {
            const int k = 2;
            const int n = 3;
            const int Low = 10;
            const int High = 20;

            int** a = new int* [k];
            for (int i = 0; i < k; i++) {
                a[i] = new int[n];
            }

            Create(a, k, n, Low, High);

            Assert::IsTrue(a[0][0] >= Low && a[0][0] <= High);

            for (int i = 0; i < k; i++) {
                delete[] a[i];
            }
            delete[] a;
        }

        TEST_METHOD(TestSumMinOddRows)
        {
            const int k = 3;
            const int n = 2;

            int** a = new int* [k];
            for (int i = 0; i < k; i++) {
                a[i] = new int[n];
            }

            a[0][0] = 5; a[0][1] = 8;
            a[1][0] = 3; a[1][1] = 7;
            a[2][0] = 4; a[2][1] = 6;

            int result = SumMinOddRows(a, k, n);
            Assert::AreEqual(3, result);

            for (int i = 0; i < k; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
    };
}
