#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check the left side of the row
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;

    // Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check the lower diagonal on the left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueensUtil(vector<vector<int>>& board, int col, int n) {
    // Base case: If all queens are placed
    if (col >= n)
        return true;

    // Try placing a queen in each row of the current column
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1; // Place the queen

            // Recur to place queens in the next columns
            if (solveNQueensUtil(board, col + 1, n))
                return true;

            board[i][col] = 0; // Backtrack and remove the queen
        }
    }
    return false; // If no placement is possible in this column
}

// Function to print the board
void printBoard(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Main function to solve the N-Queens problem
void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize N x N board with 0s

    if (!solveNQueensUtil(board, 0, n)) {
        cout << "Solution does not exist" << endl;
    } else {
        printBoard(board, n); // Print one possible solution
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    solveNQueens(n);
    return 0;
}
