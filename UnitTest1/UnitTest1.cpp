#include "pch.h"
#include "CppUnitTest.h"
#include "../laba2_aisd/laba2_aisd.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodCountSort)
		{
			int num(10);

			char Arr[255];
			for (int j = 0; j < num; j++) {
				Arr[j] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand()%256];
				
			}
			 countSort(Arr);
			Assert::IsTrue(countSort(Arr) == 1);
		}
		TEST_METHOD(TestMethodQuickSort) {
			int size = 10;
			int Arr[255];
			for (int i = 0; i < size; i++)
			{
				Arr[i] = rand() % 10;
			}
			quickSort(Arr, 0, size - 1);
			Assert::IsTrue(quickSort(Arr, 0, size - 1) == 1);
		}
		TEST_METHOD(TestMethodBogoSort) {
			int size = 10;
			int Arr[255];
			for (int i = 0; i < size; i++)
			{
				Arr[i] = rand() % 10;
			}
			bogoSort(Arr, size);
			Assert::IsTrue(bogoSort(Arr, size) == 1);

		}
		TEST_METHOD(TestMethodInsertionSort) {
			int size = 10;
			int Arr[255];
			for (int i = 0; i < size; i++)
			{
				Arr[i] = rand() % 10;
			}
			insertionSort(Arr, size);
			Assert::IsTrue(insertionSort(Arr, size) == 1);
		}
		TEST_METHOD(TestMethodSearchBinary) {
			int size = 10, index;
			const int SIZE = 5;
			int Arr[255];
			for (int i = 0; i < size; i++)
			{
				if (i==2)
				{
					Arr[2] = 6;
					continue;
				}
				
				Arr[i] = rand() % 10;

			}
			index = Search_Binary(Arr, 0, SIZE, 6);
			Assert::IsTrue(index >= 0);
		}
	};
}
