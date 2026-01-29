//Ques.1)
#include <iostream>
using namespace std;

int main() {
    int n = 6;
    int start[]  = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    cout << "Selected activities:\n";

    int count = 1;
    int lastFinish = finish[0];

    cout << "(" << start[0] << ", " << finish[0] << ") ";

    for (int i = 1; i < n; i++) {
        if (start[i] >= lastFinish) {
            cout << "(" << start[i] << ", " << finish[i] << ") ";
            lastFinish = finish[i];
            count++;
        }
    }

    cout << "\nMaximum number of activities = " << count;

    return 0;
}
//Output:
//Maximum number of activities = 4
//Selected activities: (1, 2), (3, 4), (5, 7), (8, 9)

//--------------------------------------------------------------------

//Ques.2)
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 5;

    int arrival[] = {900, 910, 920, 1100, 1120};
    int departure[] = {940, 1200, 950, 1130, 1140};
    bubbleSort(arrival, n);
    bubbleSort(departure, n);
    int platforms = 1;
    int maxPlatforms = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }

        if (platforms > maxPlatforms)
            maxPlatforms = platforms;
    }

    cout << "Minimum number of platforms required = "
         << maxPlatforms;

    return 0;
}
//Output: Minimum number of platforms required = 3

//--------------------------------------------------------------------




