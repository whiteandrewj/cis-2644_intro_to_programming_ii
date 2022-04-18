#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

struct MonthWeather {
    month monthName;
    double rainfall;
    double highTemp;
    double lowTemp;
    double avgTemp;
};

int main() { 

    const int MNTH = 12;
    bool isInvaidTemp;
    double totalRainfall = 0;
    double highestTemp = -100;
    month highestTempMonthName;
    double lowestTemp = 140;
    month lowestTempMonthName;
    double totalAvgTemp = 0;

    MonthWeather yearWeather[MNTH];

    cout << "---Weather Calculator---" << endl;
    for (int i = 0; i < MNTH; i++) {
        yearWeather[i].monthName = month{unsigned(i+1)};
        cout << "Please enter weather data for " << yearWeather[i].monthName << endl;
        
        cout << "Rainfall: ";
        cin >> yearWeather[i].rainfall;

        do {
            cout << "High temp: ";
            cin >> yearWeather[i].highTemp;
            //cout << yearWeather[i].highTemp;    
            isInvaidTemp = (yearWeather[i].highTemp > 140.0 || yearWeather[i].highTemp < -100.0);
            if (isInvaidTemp) {
                cout << "Invalid temp. Please enter a value between -100 and 140" << endl;
            }
        } while (isInvaidTemp);
        
        do {
            cout << "Low temp: ";
            cin >> yearWeather[i].lowTemp;
            //cout << yearWeather[i].lowTemp;    
            isInvaidTemp = (yearWeather[i].lowTemp > 140.0 || yearWeather[i].lowTemp < -100.0);
            if (isInvaidTemp) {
                cout << "Invalid temp. Please enter a value between -100 and 140" << endl;
            }
        } while (isInvaidTemp);
        
        yearWeather[i].avgTemp = (yearWeather[i].highTemp + yearWeather[i].lowTemp)/2;
        //cout << "avg temp" << yearWeather[i].avgTemp << endl;
    }

    for (MonthWeather m : yearWeather) {
        totalRainfall += m.rainfall;
        totalAvgTemp += m.avgTemp;
        if (highestTemp < m.highTemp) {
            highestTemp = m.highTemp;
            highestTempMonthName = m.monthName;
        }
        if (lowestTemp > m.lowTemp) {
            lowestTemp = m.lowTemp;
            lowestTempMonthName = m.monthName;
        }
    }

    cout << endl << "---Weather Summary---" << endl;
    cout << "Avg monthly rainfall: " << totalRainfall/MNTH << " inches" << endl;
    cout << "Total rainfall: " << totalRainfall << " inches" << endl;
    cout << "Highest temperature: " << highestTemp << " degrees (" << highestTempMonthName << ")" << endl;
    cout << "Lowest temperature: " << lowestTemp << " degrees (" << lowestTempMonthName << ")" << endl;
    cout << "Avg monthly temperature: " << totalAvgTemp/MNTH << " degrees" << endl;


    return 0;
}