#include<iostream>
#include<ctime>
#include<string.h>
using namespace std;

class ParkingArea
{
    private:
    const int type1limit=10;
    const int type2limit=10;
    const int type3limit=10;
    static int type1cnt;
    static int type2cnt;
    static int type3cnt;
};
class VehicleType
{
    protected:
        int vtypeid;
        int priceperhour; 
        string type;
    public:
        VehicleType()
        {
            int vtypeid=0;
            type="vehicle";
            priceperhour=0;
        }
        void SetVehicleType(int i)
        {
            switch(i)
            {
                case 0://unknown vehicle
                vtypeid=0;
                this->type="Vehicle";
                priceperhour=0;
                break;
                case 1://2 wheeler
                vtypeid=1;
                priceperhour=10;
                this->type="2 wheeler";
                break;
                case 2://4 wheeler
                vtypeid=2;
                priceperhour=30;
                this->type="4 wheeler";
                break;
                case 3://heavy vehicle
                vtypeid=3;
                priceperhour=50;
                this->type="heavy vehicle";
                break;

            }
        }
        string showVehicleType()
        {
            return type;
        }


};

class Vehicle:private VehicleType
{
    private:
        string regid;
        tm *start;
        tm *end;
        //VehicleType vtype;

        
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
        this->SetVehicleType(0);
    }
    Vehicle(string rid,int vt)
    {
        this->regid=rid;
        this->start=getTime();
        this->end=getTime();
        this->SetVehicleType(vt);
    }
    void showVehicle()
    {
        
        cout<< "Reg ID: "<<this->regid<<endl;
        cout<< "Arrival time: " << this->start->tm_hour << ":" << this->start->tm_min << ":" << this->start->tm_sec << endl;
        cout<< "Departure time: " << this->end->tm_hour << ":"<< this->end->tm_min << ":" << this->end->tm_sec << endl;
        cout<< "Vehicle type: " <<this->showVehicleType() << endl;
    }
        

};


int main()
{
    int choice=99;
    while(choice!=0)
    {
        cout<<"How may I help you ? | 1.Park the vehicle 2.Remove the vehicle from parking :"<<endl;
        cin>>choice;
        if(choice==1)
        {
            int vtype;
            string regid;
            cout<<"What type of vehicle is yours ? | 1. 2-Wheeler 2. 4-Wheeler 3. Heavy Vehicle"<<endl;
            cin>>vtype;
            cout<<"Enter Registration ID of the vehicle"<<endl;
            cin>>regid;
            Vehicle v(regid,vtype);

            v.showVehicle();


        }
        else if(choice==2)
        {

        }
        else{
            cout<<"Invalid choice :("<<endl;

        }
        cout<<"Continue ? | 1.Yes 0. No :"<<endl;
        cin>>choice;
    }
    return 0;
}
