#ifndef METEORP3MULTI_H_INCLUDED
#define METEORP3MULTI_H_INCLUDED

#include <iostream>
#include <windows.h>

using namespace std;
//void user_input(double& meteorSize, double& meteorDistanceFromEarth);
//void validate_input(double meteorSize, double meteorDistanceFromEarth);
//void calculations(double meteorSize, double meteorDistance, double& speedMPH, double& timeToImpact, double& missileInterceptRange);
//void meteor_data(double meteorSize, double meteorDistanceFromEarth, double speedMPH, double timeToImpact);
//void engagement_data(double meteorSize, double meteorDistanceFromEarth, double speedMPH, double timeToImpact, double missileInterceptRange);
//void wrong_engagement_data(double timeToImpact);
//void restart_program(char& restartKey);

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void user_input(double& meteorSize, double& meteorDistanceFromEarth)
    {
        cout << endl << endl << "  Enter the meteor size in meters: ";
        cin >> meteorSize;
        cout << endl << "  Enter the meteor's distance from Earth in miles: ";
        cin >> meteorDistanceFromEarth;
        cout << endl;
    }

void validate_input(double meteorSize, double meteorDistanceFromEarth)
{
    SetConsoleTextAttribute(hConsole, 14);
    cout << setw(45) << "ATTENTION: Invalid data has been entered." << endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void calculations(double meteorSize, double meteorDistanceFromEarth, double& speedMPH, double& timeToImpact, double& missileInterceptRange)
{
    speedMPH = (120 * meteorSize);
    timeToImpact = (meteorDistanceFromEarth / speedMPH) * 60;
    missileInterceptRange = ((timeToImpact - 3.4) / 60) * speedMPH;
}

void meteor_data(double meteorSize, double meteorDistanceFromEarth, double speedMPH, double timeToImpact)
{
    SetConsoleTextAttribute(hConsole, 15);
    cout.setf (ios:: fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "  Meteor Data:" << endl;
    cout << "    Diameter: " << meteorSize << " meters" << endl;
    cout << "    Distance from Earth: " << meteorDistanceFromEarth << " miles" << endl;
    cout << "    Speed in Miles Per Hour: " << speedMPH << " mph" << endl;
    cout << "    Time to Impact: " << timeToImpact << " Minutes" << endl;
}

void engagement_data(double meteorSize, double meteorDistanceFromEarth, double speedMPH, double timeToImpact, double missileInterceptRange)
{
    cout << endl << "  Engagement Data: " << endl;

        if (missileInterceptRange >= 0)
            {
                cout << "    Missile Intercept Range: " << missileInterceptRange << " Miles" << endl;
                SetConsoleTextAttribute(hConsole, 10);
                cout << "    MDS Status: Missile Intercept Probable" << endl;
                SetConsoleTextAttribute(hConsole, 15);
            }
        if (missileInterceptRange < 0)
            {
                cout << "    Missile Intercept Range: 0.00 Miles" << endl;
                SetConsoleTextAttribute(hConsole, 12);
                cout << "    MDS Status: Missile Intercept Not Possible" << endl;
                SetConsoleTextAttribute(hConsole, 15);
            }

    cout << endl << "  Meteor Status:" << endl;
    SetConsoleTextAttribute(hConsole, 14);
    cout << "    Meteor Inbound" << endl << endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void wrong_engagement_data(double timeToImpact)
{
    cout << endl << "  Engagement Data: " << endl;
    cout << "    Missile Intercept Range: 0.00 Miles" << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "    MDS Status: Missile Intercept Not Possible" << endl;
    cout << "    Earth Impact in " << timeToImpact << " Minutes" << endl;
    SetConsoleTextAttribute(hConsole, 15);

    cout << endl << "  Meteor Status:" << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "    Meteor cannot be tracked by the System" << endl << endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void restart_program(char& restartKey)
{
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl << "  Enter Y to run another, any other key to quit." << endl << endl;
    cout << "  ";
    cin >> restartKey;
}

#endif // METEORP3MULTI_H_INCLUDED
