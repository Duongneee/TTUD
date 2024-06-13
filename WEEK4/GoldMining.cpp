#include <bits/stdc++.h>
using namespace std;

int vang[1000001],n,L1,L2;
int mem[1000001];
deque<int> oke;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>> n>> L1>>L2;
    for(int i=1;i<=n;i++)
        cin>> vang[i];

    for(int i=1;i<=L1;i++)
    {
        mem[i]=vang[i];
    }
    
    oke.push_back(1);
    //***********************************

    /*int ket_thuc=1;
    for(int i=L1+1;i<=L2;i++){
        for(int j=1;j<=ket_thuc;j++){
            mem[i]=max(mem[i], vang[i]+mem[j]);
        }
        ket_thuc++;
    }*/
    // giai *****************.

    //int kt=L2-L1+1;
    int day=2;

    for(int i=L1+1;i<=n;i++){
        if(i-oke.front()>L2)
            oke.pop_front();
        deque<int>::iterator vi_tri_xoa;
        int max_hien_tai=vang[i];

        for(deque<int>::iterator j=oke.begin(); j!=oke.end(); j++){
        if(mem[*j]+vang[i]>=max_hien_tai){
            max_hien_tai=mem[*j]+vang[i];
            vi_tri_xoa=j;
        }
        }
        oke.erase(oke.begin(), vi_tri_xoa);
        oke.push_back(day);
        day++;
        mem[i]=max_hien_tai;
    }


    int res=0;
    for(int i=1;i<=n;i++)
        res=max(res,mem[i]);
    cout<< res;
    return 0;
}
