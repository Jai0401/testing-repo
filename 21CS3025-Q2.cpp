#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int calculateNotifications(int n, int d, vector<int>& expenditures) {
    int notificationsCount = 0;
    vector<int> dailyMedians;


    for (int i = 0; i < n; i++) {
        
        if (i >= d) {
            
            vector<int> precedingDays(expenditures.begin() + i - d, expenditures.begin() + i);
            sort(precedingDays.begin(), precedingDays.end());
            double median;
            if (d % 2 == 0) {
                median = (precedingDays[d / 2 - 1] + precedingDays[d / 2]) / 2.0;
            } else {
                median = precedingDays[d / 2];
            }


            
            if (expenditures[i] >= 2 * median) {
                notificationsCount++;
            }
        }


        dailyMedians.push_back(expenditures[i]);
    }


    return notificationsCount;
}


int main() {
    int n, d;
    cout << "Enter the total number of days (n): ";
    cin >> n;
    cout << "Enter the number of trailing days (d): ";
    cin >> d;


    vector<int> expenditures;
    cout << "Enter daily spending data for " << n << " days:" << endl;
    for (int i = 0; i < n; i++) {
        int expenditure;
        cin >> expenditure;
        expenditures.push_back(expenditure);
    }


    int alerts = calculateNotifications(n, d, expenditures);
    cout << "Total number of alerts: " << alerts << endl;


    return 0;
}
