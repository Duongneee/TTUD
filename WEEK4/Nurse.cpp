/*
Giám đốc một bệnh viện muốn sắp xếp kế hoạch làm việc cho một y tá trong khoảng thời gian nhất định là N ngày liên tục 1,..., N. Do chính sách của bệnh viện nên mỗi y tá không được làm việc cả ngày 1,... , N. Thay vào đó, phải có những ngày nghỉ mà y tá cần phải nghỉ ngơi. Kế hoạch làm việc là một chuỗi các giai đoạn làm việc rời rạc. Thời gian làm việc của người điều dưỡng được xác định là dãy ngày liên tục mà người điều dưỡng phải làm việc và thời gian làm việc là số ngày liên tục của thời gian làm việc đó. Bệnh viện áp đặt hai hạn chế:
Mỗi y tá chỉ được nghỉ một ngày giữa hai đợt làm việc liên tiếp. nghĩa là hôm nay y tá nghỉ thì ngày mai phải đi làm 
(1)
Độ dài của mỗi khoảng thời gian làm việc phải lớn hơn hoặc bằng K1và nhỏ hơn hoặc bằng K2
(2)
Giám đốc bệnh viện muốn biết có bao nhiêu phương án làm việc có thể thỏa mãn ràng buộc trên?

Đầu vào
Dữ liệu vào gồm một dòng chứa 3 số nguyên dương N, K1, K2
(2 <= N <= 1000, K1<K2<= 400)

đầu ra
Đầu ra chỉ bao gồm một số nguyên duy nhất M modulo 109+7 trong đó M là tổng kế hoạch làm việc thỏa mãn các ràng buộc trên.

Ví dụ
Đầu vào
6 2 3
đầu ra
4
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009
 
int n, k1, k2;
int s0[1001]; // s0[i] la so cach xep den ngay thu i va ngay thu i la ngay nghi
int s1[1001]; // s1[i] la so cach xep den ngay thu i va ngay thu i la ngay lam viec
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= n; i++)
    {
        s0[i] = s1[i] = 0;
    }
 
    s0[0] = 1;
    s1[0] = 1;
 
    for (int i = 1; i <= n; i++)
    {
        s0[i] = s1[i - 1];
        for (int j = k1; j <= k2; j++)
        {
            if (i - j >= 0)
            {
                s1[i] = s1[i] + s0[i - j];
            }
        }
    }
    cout<<s0[n]+s1[n];
    
    return 0;
}