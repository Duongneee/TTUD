/*
Dự kiến ​​một xe tải sẽ đến một số ga trong số N trạm 1, 2, . . ., N nằm trên một đường thẳng. Trạm i (i = 1,…,N) có tọa độ i và có các thông tin sau
ai: số lượng hàng hóa
ti: thời gian lấy hàng
Lộ trình của xe tải là dãy các trạm x1 < x2 < . . . < xk (1 <= xj <= N, j = 1,…, k). Do hạn chế về mặt kỹ thuật, 
khoảng cách giữa hai bến liên tiếp mà xe tải đến xi và xi+1 nhỏ hơn hoặc bằng D và tổng thời gian lấy hàng không thể vượt quá T.
Tìm đường đi cho xe tải sao cho tổng số hàng được lấy lên là tối đa.
Đầu vào
Dòng 1: N, T, D (1 <= N <= 1000, 1 <= T <= 100, 1 <= D <= 10)
Dòng 2: a1,. . ., aN là số lượng hàng hóa
(1 <= ai <= 10)
Dòng 3: t1, . . ., tN là thời gian lấy hàng
(1 <= ti <= 10)
đầu ra
Ghi tổng số hàng hóa mà xe tải đã đón trên tuyến đường.
Ví dụ
Đầu vào
6 6 2
6 8 5 10 11 6
1 2 2 3 3 2

đầu ra
24
*/

#include <bits/stdc++.h> 
using namespace std;
#define MAX 10009

int N, T, D;
int a[MAX];
int t[MAX];
int f[MAX][MAX]; // f[i][j] là giá trị lớn nhất mà có thể lấy hàng ở điểm i với thời gian còn lại j  
                 // f[i][j] is the maximum amount of goods that can be carried at station i with remaining time j
int main() 
{   
    cin >> N >> T >> D;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= N ;i++) {
        cin >> t[i];
    }

    for(int i = 1; i < N; i++){ // chạy lần lượt từng điểm 
        for(int k = t[i]; k < T ; k++){ // chạy lần lượt từ thời gian của điểm i cho tới thời gian max
            f[i][k] = a[i]; // với thời gian còn lại là k thì số vàng lấy được là tại điểm đó
            if()
        }
    }

    return 0;
}