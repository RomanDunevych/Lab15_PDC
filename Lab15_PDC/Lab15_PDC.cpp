#include <iostream>
#include <vector>
using namespace std;

bool isSafe(const vector<int>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        int queenCol = board[i];
        if (queenCol == col || abs(queenCol - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<int>& board, int row, int n, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;
            solveNQueens(board, row + 1, n, solutions);
            board[row] = -1;
        }
    }
}

void printSolutions(const vector<vector<int>>& solutions, int n) {
    for (const auto& board : solutions) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row] == col) {
                    cout << "F ";
                }
                else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "UKR");
    int n;
    cout << "Введiть розмiр шахiвницi (n): ";
    cin >> n;

    vector<int> board(n, -1);
    vector<vector<int>> solutions;
    solveNQueens(board, 0, n, solutions);

    cout << "Кiлькiсть можливих розмiщень: " << solutions.size() << endl;
    printSolutions(solutions, n);

    return 0;
}
