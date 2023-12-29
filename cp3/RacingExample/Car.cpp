#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;

void Car::InitMembers(char * ID, int fuel)
{
  strcpy(gamerID, ID);
  fuelGauge=fuel;
  curSpeed=0;
}

void Car::ShowCarState()
{
  cout<<"소유자ID: "<<gamerID<<endl;
  cout<<"연료량: "<<fuelGauge<<"%"<<endl;
  cout<<"현재속도: "<<curSpeed<<"km/s"<<endl; 

void Car::Accel()
{

}
