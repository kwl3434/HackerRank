#include<iostream>
#include<algorithm>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
typedef struct _Workshops {
    int start_time;
    int duration;
    int end_time;
}Workshops;
typedef struct _Available_Workshops {
    int signup_size;
    Workshops* pworkshops;
}Available_Workshops;

Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* a_w = new Available_Workshops();
    a_w->signup_size = n;
    a_w->pworkshops = new Workshops[a_w->signup_size](); //배열 free 해줘야한다.

    for (int i = 0; i < n;i++) {
        a_w->pworkshops[i].start_time = start_time[i];
        a_w->pworkshops[i].duration = duration[i];
        a_w->pworkshops[i].end_time = start_time[i] + duration[i];
    }
    return a_w;
}
void finalize(Available_Workshops* pa_w) {
    delete[] pa_w->pworkshops;
    delete pa_w;
}
int CalculateMaxWorkshops(Available_Workshops* a_w) {
    auto comp = [](Workshops a, Workshops b) -> bool {
        if (a.end_time == b.end_time) {
            return a.start_time < b.start_time;
        }
        else {
            return a.end_time < b.end_time;
        }
    };
    auto print = [a_w]() {
        for (int i = 0; i < a_w->signup_size; i++) {
            cout << a_w->pworkshops[i].start_time << " " << a_w->pworkshops[i].end_time << endl;
        }
    };
    print();
    sort(a_w->pworkshops, a_w->pworkshops + a_w->signup_size, comp);
    print();

    int MAX = 0;
    int end_prev = 0;
    for (int i = 0; i < a_w->signup_size; i++) {
        if (end_prev <= a_w->pworkshops[i].start_time) {
            MAX++;
            end_prev = a_w->pworkshops[i].end_time;
        }
    }
    finalize(a_w);
    return MAX;
}
int main(int argc, char* argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}