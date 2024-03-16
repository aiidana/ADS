#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Date {
    int day, month, year;
};

void bubbleSort(vector<Date>& dates) {
    int n = dates.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (dates[j].year > dates[j + 1].year || 
               (dates[j].year == dates[j + 1].year && dates[j].month > dates[j + 1].month) ||
               (dates[j].year == dates[j + 1].year && dates[j].month == dates[j + 1].month && dates[j].day > dates[j + 1].day)) {
                swap(dates[j], dates[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Ignore newline after n

    vector<Date> dates(n);

    // Read dates
    for (int i = 0; i < n; ++i) {
        string dateStr;
        getline(cin, dateStr);
        stringstream ss(dateStr);
        char discard;
        ss >> dates[i].day >> discard >> dates[i].month >> discard >> dates[i].year;
    }

    // Sort dates
    bubbleSort(dates);

    // Print sorted dates
    for (const Date& date : dates) {
        cout << (date.day < 10 ? "0" : "") << date.day << "-"
             << (date.month < 10 ? "0" : "") << date.month << "-"
             << date.year << endl;
    }

    return 0;
}

