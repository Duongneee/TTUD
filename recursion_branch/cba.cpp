// đầu học kỳ, trưởng bộ môn khoa học máy tính D phải phân công các môn học cho giáo viên một cách cân đối.
// Khoa D có m giáo viên T={1,2,...,m} và n khóa học C={1,2,...,n}.
// Mỗi giáo viên t∈T có một danh sách ưu tiên, đó là danh sách các khóa học mà anh/cô ấy có thể dạy tùy theo chuyên môn của mình.
// Chúng tôi đã biết danh sách các cặp khóa học xung đột nhau không thể được giao cho cùng một giáo viên vì các khóa học này đã được sắp xếp vào cùng một khoảng thời gian biểu.
// Khối lượng công việc của một giáo viên là số lượng khóa học được giao cho cô ấy/anh ấy. Làm thế nào để chỉ định nn khóa học cho giáo viên mm sao cho mỗi khóa học được giao cho một giáo viên nằm trong danh sách ưu tiên của họ,
//  không có hai khóa học xung đột nào được giao cho cùng một giáo viên và thời lượng tối đa là tối thiểu.
// Đầu vào
// Đầu vào bao gồm các dòng sau
// Dòng 1: chứa hai số nguyên m và n (1<m<10, 1<n<30)
// Dòng i+1: chứa số nguyên dương k và k số nguyên dương chỉ các môn học mà giáo viên tôi có thể dạy (∀i=1,…,m)
// Dòng m+2: chứa số nguyên k
// Dòng i+m+2: chứa hai số nguyên i và j biểu thị hai hướng xung đột nhau (∀i=1,…,k)
// đầu ra
// Đầu ra chứa một số duy nhất là mức tải tối đa của giáo viên trong giải pháp được tìm thấy và giá trị -1 nếu không tìm thấy giải pháp.
// Ví dụ
// Đầu vào
// 4 12
// 5 1 3 5 10 12
// 5 9 3 4 8 12
// 6 1 2 3 4 9 7
// 7 1 2 3 5 6 10 11
// 25
// 1 2
// 1 3
// 1 5
// 2 4
// 2 5
// 2 6
// 3 5
// 3 7
// 3 10
// 4 6
// 4 9
// 5 6
// 5 7
// 5 8
// 6 8
// 6 9
// 7 8
// 7 10
// 7 11
// 8 9
// 8 11
// 8 12
// 9 12
// 10 11
// 11 12

// đầu ra
// 3

#include<bits/stdc++.h>
using namespace std;
#define MAX 1009

int m, n; // m giáo viên và n khóa học qs
int dd[MAX][MAX]; // lưu danh sách bị xung đột với nhau
vector<int> teacher_can_teach[MAX]; // khai báo giáo viên có thể dạy môn học này
int load[MAX] = {}; // các môn học mà giáo viên này có thể dạy
int res = 100009; // kết quả
int t[MAX]; // lưu trữ giáo viên cho từng môn học

bool check(int monhoc, int giaovien) { // check môn học với giáo viên
    for(int i = 1; i <= monhoc; i++) { // duyêtj tất cả các môn học trước đó
    if(t[i] == giaovien) // nếu giáo viên đã dạy môn học nào đó trước đây
        if(dd[i][monhoc] == 1) // check xem môn học đó có xung đột hay không
        return false;
    }
    return true;
}


int up_ketqua() { // xem giáo viên nào có số lượng môn lớn nhất , tìm min kết quả vừa tìm được với giá trị nhỏ nhất đã tìm ra
    int max_load = 0; 
    for(int i = 1; i <= m; i++) {
        max_load = max(load[i],max_load);
    }
    return res = min(max_load, res);
}

 void TRY(int i) { // thử từng môn học
    for(int teacher : teacher_can_teach[i]) {
        if(check(i, teacher)) {
            t[i] = teacher;
            load[teacher] += 1;
            if(i == n) {
                up_ketqua();
            }
            else if(load[teacher] < res){
                TRY(i + 1);
            }
                load[teacher] -= 1;
                t[i] = 0;
        }
    }
}


int main() {
    cin >> m >> n;
    for(int i =  1; i <= m; i++) {
        int sl_sub;
        cin >> sl_sub;
        int course_id;
        for(int j = 1; j <= sl_sub; j++) {
            cin >> course_id; 
            teacher_can_teach[course_id].push_back(i); // thêm vào list các giaó viên có thể dạy môn học này
        }
    }

    int k;
    cin >> k;
    for(int i = 1; i <=k ; i++) {
        int u, v;
        cin  >> u >> v;
        dd[u][v] = dd[v][u] = 1;
    }

    TRY(1);
    cout << res;
    return 0;
}