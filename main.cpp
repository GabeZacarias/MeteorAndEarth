
#include <iostream>
#include <iomanip>
#include "MeteorP3Multi.h"


int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    double meteorSize;
    double meteorDistanceFromEarth;
    double speedMPH;
    double timeToImpact;
    double missileInterceptRange;
    char restartKey = 'y';

    while (restartKey == 'y' || restartKey == 'Y')
    {
        user_input(meteorSize, meteorDistanceFromEarth);

            while (meteorSize <= 0 || meteorDistanceFromEarth <= 0)
                {
                    validate_input(meteorSize, meteorDistanceFromEarth);
                    Sleep(2000);
                    system("CLS");
                    user_input(meteorSize, meteorDistanceFromEarth);
                }

            if (meteorSize > 0 && meteorDistanceFromEarth > 0)
                {
                    calculations(meteorSize, meteorDistanceFromEarth, speedMPH, timeToImpact, missileInterceptRange);
                    meteor_data(meteorSize, meteorDistanceFromEarth, speedMPH, timeToImpact);

                    if (meteorDistanceFromEarth <= 110 && meteorSize < 1 || meteorDistanceFromEarth <= 220 && meteorSize >= 1 || meteorDistanceFromEarth <= 330 && meteorSize >= 2 || meteorDistanceFromEarth <= 440 && meteorSize >= 3)
                        {
                            engagement_data(meteorSize, meteorDistanceFromEarth, speedMPH, timeToImpact, missileInterceptRange);
                        }
                    else
                        {
                            wrong_engagement_data(timeToImpact);
                        }
                    restart_program(restartKey);
                    system("CLS");

                }
    }

	return 0;
}
