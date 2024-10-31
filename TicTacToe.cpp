#include <iostream>
#include <vector>

using namespace std;

// Function to draw the Tic Tac Toe board
void drawBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---------" << endl;
    }
}

// Function to check if there is a winner
char checkWinner(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
    }
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];
    return ' ';
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize the board with empty spaces
    int row, col;
    char currentPlayer = 'X';
    char winner = ' ';

    // Game loop
    while (winner == ' ') {
        // Draw the board
        drawBoard(board);

        // Get input from the current player
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        // Check if the input is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check if there is a winner
        winner = checkWinner(board);

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Draw the final board
    drawBoard(board);

    // Announce the winner
    if (winner != ' ')
        cout << "Player " << winner << " wins!" << endl;
    else
        cout << "It's a draw!" << endl;

    return 0;
}
