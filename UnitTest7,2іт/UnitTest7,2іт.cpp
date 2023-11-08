#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.2it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72іт
{
    TEST_CLASS(UnitTest72іт)
    {
    public:

        TEST_METHOD(TestMethod1)
        {

            const int n = 4;
            int** a = new int* [n];
            for (int i = 0; i < n; i++) {
                a[i] = new int[n];
            }

            // Ініціалізація масиву для сортування
            a[0][0] = 3; a[0][1] = 2; a[0][2] = 1; a[0][3] = 4;
            a[1][0] = 9; a[1][1] = 6; a[1][2] = 7; a[1][3] = 8;
            a[2][0] = 5; a[2][1] = 10; a[2][2] = 12; a[2][3] = 11;
            a[3][0] = 14; a[3][1] = 13; a[3][2] = 15; a[3][3] = 16;

            Sort(a, n);

            // Очікуваний результат після сортування
            int expected[n][n] = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16}
            };

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++) {
                Assert:(a[i][j] == expected[i][j]);
                }
            }
        }
    };
}
