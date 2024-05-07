#include<bits/stdc++.h>
using namespace std;

const int MAXIMUM = 50;

int res = 1000000, t[MAXIMUM] = {}, load[MAXIMUM] = {} ;
// load: số môn học mà giáo viên dạy, t: lưu trữ giáo viên cho từng môn học
int n, m;
vector<int> t_can_t[MAXIMUM];   // Lưu trữ giáo viên có thể dạy môn học này.
int dd[50][50];

// check giáo viên này có dạy được môn học này không
bool check(int khoahoc, int giaovien) {
    for (int i = 1; i <= khoahoc; i++) { // duyệt từ khóa học 1 tới khóa học trước khóa học đang xét
        if (t[i] == giaovien) { // xem giáo viên đã được phân công vào khóa học nào trước đó hay chưa
            if (dd[i][khoahoc] == 1) return false; // nếu có phải xét xem khóa học đó và khóa học đang xét có bị xung đôtj không
        }
    }
    return true;
}


int up_ketqua() {
    int max_load = 0;
    for (int i = 1; i <= m; i++) {
        max_load = max(max_load, load[i]); // so sánh tất cả các giáo viên xem ai lớn nhất 
    }
    res = min(max_load, res); // so sánh người lớn nhất với giá trị tốt nhất được lưu 
    return res;
}

void Try(int i) {
    for (int Teacher : t_can_t[i]) { // với mỗi giáo viên trong list có thể dạy khóa học i, ta check xem có thể dạy được không 
        if (check(i, Teacher)) {
            load[Teacher]+=1; // được thì số khóa học của giáo viên đó sẽ cộng thêm 1 
            t[i] = Teacher;
        if (i == n) {
            up_ketqua(); // nếu i là khóa học cuối cùng thì up kết quả
        }
        else if( load[Teacher] < res) { // kiểm tra xem tổng số khóa học của giáo viên đang xét + số khóa học còn lại 
            Try(i + 1);  
        }
        t[i]= 0;
        load[Teacher]-=1; // giải phóng giáo viên 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int sl_sub; // số lượng môn học
        cin >> sl_sub;
        int course_id;
        for (int j = 1; j <= sl_sub; j++) {
            cin >> course_id;
            t_can_t[course_id].push_back(i);
            // giáo viên i được thêm vào khóa học id
        }
    }

    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int s1, s2;
        cin >> s1 >> s2;
        dd[s1][s2] = dd[s2][s1] = 1;
    }
    Try(1);
    cout << res;
    return 0;
}