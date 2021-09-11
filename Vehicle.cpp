#include<iostream>
#include<ctime>
#include<string.h>
using namespace std;

class VehicleType
{
    private:
        string type;
    public:
        VehicleType()
        {
            type="vehicle";
        }
        void SetVehicleType(int i)
        {
            switch(i)
            {
                case 0://unknown vehicle
                this->type="Vehicle";
                break;
                case 1://2 wheeler
                this->type="2 wheeler";
                break;
                case 2://4 wheeler
                this->type="4 wheeler";
                break;
                case 3://heavy vehicle
                this->type="heavy vehicle";
                break;

            }
        }
        string showVehicleType()
        {
            return type;
        }


};

class Vehicle
{
    private:
        string regid;
        tm *start;
        tm *end;
        VehicleType vtype;

        
    public:
    tm * getTime()
    {
        time_t t=time(0);//returns current time
        return localtime(&t);

    }
    Vehicle()
    {
        this->regid="null";
        this->start=getTime();
        this->end=getTime();
        this->vtype.SetVehicleType(0);
    }
    void showVehicle()
    {
        
        cout<< "Reg ID: "<<this->regid<<endl;
        cout<< "Arrival time: " << this->start->tm_hour << ":" << this->start->tm_min << ":" << this->start->tm_sec << endl;
        cout<< "Departure time: " << this->end->tm_hour << ":"<< this->end->tm_min << ":" << this->end->tm_sec << endl;
        cout<< "Vehicle type: " <<this->vtype.showVehicleType() << endl;
    }
        

};


int main()
{
    Vehicle v1;
    v1.showVehicle();
    return 0;
}
