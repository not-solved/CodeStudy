#include <iostream>
#include <vector>
using namespace std;

int Sudoku[9][9];

void print_sudoku() {
    for (int i = 0.; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << Sudoku[i][j];
            if (j != 8)
                cout << ' ';
        }
        cout << '\n';
    }
}
void fill_sudoku(int y, int x) {
    int nums[9] = { 0, };
    vector<int> key_num;

    // 가로, 세로 체크
    for (int i = 0; i < 9; i++) {
        if (Sudoku[y][i] != 0)
            nums[Sudoku[y][i] - 1] = 1;
        if (Sudoku[i][x] != 0)
            nums[Sudoku[i][x] - 1] = 1;
    }

    // 그룹 체크
    int x_square = (x / 3) * 3;
    int y_square = (y / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Sudoku[i + y_square][j + x_square] != 0)
                nums[Sudoku[i + y_square][j + x_square] - 1] = 1;
        }
    }

    // 후보 숫자들 채우기
    for (int i = 0; i < 9; i++)
        if (nums[i] == 0)
            key_num.push_back(i + 1);

    // 후보가 없으면 종료
    if(key_num.empty())
        return;

    int new_x = x, new_y = y;
    while (new_y < 9) {
        
        if ((++new_x) >= 9) {
            new_y++;
            new_x = 0;
            if (new_y >= 9) {
                Sudoku[y][x] = key_num[0];
                print_sudoku();
                exit(0);
            }
        }
        if (Sudoku[new_y][new_x] == 0)
            break;
    }
    
    for (int i = 0; i < key_num.size(); i++) {
        Sudoku[y][x] = key_num[i];
        fill_sudoku(new_y, new_x);
        Sudoku[y][x] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> Sudoku[i][j];
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (Sudoku[i][j] == 0) {
                fill_sudoku(i, j);
            }
        }
    }
    return 0;
}