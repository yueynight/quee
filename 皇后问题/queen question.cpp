#include <iostream>
using namespace std;
void printQueen(int* result, int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
           if (result[i] == j)
           {
               cout << "X";
           }
           else {
               cout << "O";
           }
           
        }
        cout << endl;
    }
    cout << endl;
    
}
bool isOk(int size, int *result, int row, int lie) {
    int left = lie - 1;
    int right = lie + 1;
    for (int r = row - 1; r >= 0; r--)
    {
        if(result[r] == lie)
        {
            return false;
        }

        if (left >= 0 && result[r] == left)
        {
            return false;
        }

        if (right < size && result[r] == right )
        {
            return false;
        }

        
        left--;
        right++;
    }

    return true;
    
}
void queen(int size, int* result, int row, int &count) {
    if (size == row) {
        ++count;
        printQueen(result, size);
        return;
    }
    for (int lie = 0; lie < size; lie++)
    {
        if (isOk(size, result, row, lie))
        {
            result[row] = lie;
            queen(size, result, row + 1, count);
        }
    }

}

int main() {
    int size = 0;
 cout << "请输入棋盘上的棋子数：" << endl;
        cin >> size;
        if (size <= 0)
        {
            cout << "输入错误！" << endl;
        }

        int *result = new int[size]();
        int count = 0;

        queen(size, result, 0, count);  

        cout <<"在"<<size<<"*"<<size<<"的棋盘上，"<< "我们有 " << count << " 种方法" << endl;

    
}
