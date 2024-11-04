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

			// ������������ ����� �� ������� (0, 1)
			board[0] = 1;

			// ����������, �� �������� ��������� ����� �� ���� �������
			Assert::IsTrue(isSafe(board, 1, 3, n)); // ������� (1, 3) ��������
			Assert::IsFalse(isSafe(board, 1, 1, n)); // ������� (1, 1) ���������� (�� � �������)
			Assert::IsFalse(isSafe(board, 2, 0, n)); // ������� (2, 0) ���������� (�� �������)
		}

		TEST_METHOD(TestSolveNQueens)
		{
			int n = 4;
			vector<int> board(n, -1);
			vector<vector<int>> solutions;

			// �������� ������� solveNQueens
			solveNQueens(board, 0, n, solutions);

			// ���������� ������� ����'���� ��� n = 4
			Assert::AreEqual((int)solutions.size(), 2);

			// ���������� ������� ����'���� ��� n = 1
			solutions.clear();
			n = 1;
			board.resize(n, -1);
			solveNQueens(board, 0, n, solutions);
			Assert::AreEqual((int)solutions.size(), 1);

			// ���������� ������� ����'���� ��� n = 8 (������� ���� 92)
			solutions.clear();
			n = 8;
			board.resize(n, -1);
			solveNQueens(board, 0, n, solutions);
			Assert::AreEqual((int)solutions.size(), 92);
		}
	};
}
