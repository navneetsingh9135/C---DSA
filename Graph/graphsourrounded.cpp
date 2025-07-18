#include <bits/stdc++.h>
using namespace std;

void change(vector<vector<char>> &A, int x, int y) {
    A[x][y] = '*';
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx >= 0 && cx < A.size() && cy >= 0 && cy < A[0].size() && A[cx][cy] == 'O') {
            change(A, cx, cy);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> A(n, vector<char>(m));

    // Input the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    // Perform flood-fill from boundary cells containing 'O'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && A[i][j] == 'O') {
                if(A[i][j]=='O')
                change(A, i, j);
            }
        }
    }

    // Convert remaining 'O' to 'X' and '*' back to 'O'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'O') {
                A[i][j] = 'X';
            } else if (A[i][j] == '*') {
                A[i][j] = 'O';
            }
        }
    }

    // Output the modified matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
