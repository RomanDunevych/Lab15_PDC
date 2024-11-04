#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../Lab15_PDC/Lab15_PDC.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestIsSafe)
		{
			int n = 4;
			vector<int> board(n, -1);

			// Встановлюємо ферзя на позицію (0, 1)
			board[0] = 1;

			// Перевіряємо, чи безпечно поставити ферзя на інші позиції
			Assert::IsTrue(isSafe(board, 1, 3, n)); // Позиція (1, 3) безпечна
			Assert::IsFalse(isSafe(board, 1, 1, n)); // Позиція (1, 1) небезпечна (та ж колонка)
			Assert::IsFalse(isSafe(board, 2, 0, n)); // Позиція (2, 0) небезпечна (по діагоналі)
		}

		TEST_METHOD(TestSolveNQueens)
		{
			int n = 4;
			vector<int> board(n, -1);
			vector<vector<int>> solutions;

			// Виконуємо функцію solveNQueens
			solveNQueens(board, 0, n, solutions);

			// Перевіряємо кількість розв'язків для n = 4
			Assert::AreEqual((int)solutions.size(), 2);

			// Перевіряємо кількість розв'язків для n = 1
			solutions.clear();
			n = 1;
			board.resize(n, -1);
			solveNQueens(board, 0, n, solutions);
			Assert::AreEqual((int)solutions.size(), 1);

			// Перевіряємо кількість розв'язків для n = 8 (повинно бути 92)
			solutions.clear();
			n = 8;
			board.resize(n, -1);
			solveNQueens(board, 0, n, solutions);
			Assert::AreEqual((int)solutions.size(), 92);
		}
	};
}
