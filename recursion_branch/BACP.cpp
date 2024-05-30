#include<bits/stdc++.h>
using namespace std;
#define MAX 30

int n, m; // n là số môn học, m là số học kì
int x[MAX]; // lưu môn học được học trong kì học nào
int c[MAX]; //số tín chỉ của môn học i
//bool visited[MAX]; // lưu các môn đã được thêm vào học kì trước
int dd[MAX][MAX]; // lưu ràng buộc môn học. môn học i phải đứng trước môn học j
int load[MAX]; // ghi tổng số tín chỉ trong học kì i
int res = 100; // lưu kết quả tốt nhắt

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++ ) {
        cin >> c[i];
    //    visited[i] = false;
    }
    for( int i = 1; i <=n ; i++) {
        for(int j = 1; j <=n ; j++) {
            cin >> dd[i][j]; // các môn học tiên quyết với nhau . phải học i mới được học j
        }
    }
}

bool check(int monhoc, int hocki) { // môn k có thể gán vào học kì v hay không?
    for(int i = 1; i <= monhoc - 1; i++){ // duyệt các môn đã phân bổ trước nó
        if(dd[i][monhoc] == 1){ // nếu mà có môn học nào mà là điều kiện tiên quyết
            if(x[i] >= hocki) return false;
        }
        if(dd[monhoc][i]) {
            if(x[i] <= hocki) return false;
        }
    }
    return true;
}

void solution() { // xem học kì nào là lớn nhất thì cho là bé nhất
int max1 = 0;
    for(int i = 1; i <= m; i++) {
        max1 = max(max1, load[i]);
    }
    res = min(res, max1);
}

void TRY(int k) { // thử cho từng x[k];
    for(int i = 1; i <= m; i++){
        if(check(k , i)) {
            load[i] = load[i] + c[k];
            x[k] = i;
            if(k==n) solution();
            else{
                TRY(k+1);
            }
            load[i] = load[i] - c[k];
            x[k]=0;
        }
    }
}

int main() {
    input();
    TRY(1);
    cout << res;
    return 0;
}