#include <iostream> 
#include <string> 
#include <sstream> 

using namespace std; 

// 分數結構體
struct Fraction { 
    int numerator; 
    int denominator; 
}; 

// 輸出 Stern-Brocot tree 的路徑
string stern_brocot(Fraction F) { 
    // 初始化左、中、右三個分數
    Fraction L = {0, 1}; 
    Fraction M = {1, 1}; 
    Fraction R = {1, 0}; 

    // 轉換目標分數和中間分數的小數形式，便於比較大小
    double Fd = (double) F.numerator / F.denominator; 
    double Md = (double) M.numerator / M.denominator; 

    // 記錄 Stern-Brocot tree 的路徑
    string res = ""; 

    // 不斷進行 Stern-Brocot 運算，直到中間分數等於目標分數
    while (M.numerator != F.numerator || M.denominator != F.denominator) { 
        if (Fd > Md) {  // 目標分數比中間分數大，則往右子樹移動
            // 左節點變成中間節點
            L.numerator = M.numerator; 
            L.denominator = M.denominator; 
            // 中間節點變成右節點的左附屬節點
            M.numerator = M.numerator + R.numerator; 
            M.denominator = M.denominator + R.denominator; 
            // 記錄往右子樹移動的路徑
            res += "R"; 
        } else {  // 目標分數比中間分數小，則往左子樹移動
            // 右節點變成中間節點
            R.numerator = M.numerator; 
            R.denominator = M.denominator; 
            // 中間節點變成左節點的右附屬節點
            M.numerator = M.numerator + L.numerator; 
            M.denominator = M.denominator + L.denominator; 
            // 記錄往左子樹移動的路徑
            res += "L"; 
        } 
        // 更新中間分數的小數形式
        Md = (double) M.numerator / M.denominator; 
    } 

    return res; 
} 

int main() { 
    string line; 
    bool first_case = true; 
    while (getline(cin, line)) { 
        // 讀取分子和分母
        stringstream ss(line); 
        int numerator, denominator; 
        ss >> numerator >> denominator; 
        Fraction F = {numerator, denominator}; 

        // 如果不是第一組測試數據，輸出空行
        if (first_case) { 
            first_case = false; 
        } else { 
            cout << endl; 
        } 
		cout << stern_brocot(F); 
    } 
    return 0; 
}  