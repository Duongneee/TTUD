#include<bits/stdc++.h>
using namespace std;
 

map<string, int> number_call_from;
map<string, int> number_call_to;
map<string, int> count_time_calls_from;
string date;
string from_time;
string end_time;
int number_total_calls = 0;
set<string> phone_numbers;
 
string number_call_fr;
string number_call_en;
 
int call_number_error = 0;
 
 
int convert_to_second(string time) {
         //  HH:MM:SS
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));
    return h*3600 + m*60 + s;
}
 
void input() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string querry;
    cin >> querry;
    while(querry == "call"){
        cin >> number_call_fr >> number_call_en >> date >> from_time >> end_time ;
 
        if(number_call_fr.length() != 10) {
            call_number_error +=1;
        }
        if(number_call_en.length() != 10) {
            call_number_error +=1;
        }
        number_call_from[number_call_fr] += 1;
        number_call_to[number_call_en] += 1;
 
        number_total_calls +=1 ;
        count_time_calls_from[number_call_fr] = count_time_calls_from[number_call_fr] + ( convert_to_second(end_time) - convert_to_second (from_time) );

        cin >> querry;
    }
}
int main () {
     input();
    string que ;
    cin >> que;
    while (que != "#") {
        if (que == "?check_phone_number") {
            if(call_number_error != 0) {
                cout << "0" << "\n";
            }
            else cout << "1" << "\n";
        }
        if(que == "?number_calls_from" ) {
                cin >> number_call_fr;
                cout << number_call_from[number_call_fr] << "\n";
        }
        if(que == "?number_total_calls") {
            cout << number_total_calls << "\n"; 
        }
        if(que == "?count_time_calls_from") {
            cin >> number_call_fr;
          cout <<  count_time_calls_from[number_call_fr] << "\n";
        }

        cin >> que;
    }


    return 0;
}