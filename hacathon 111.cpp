#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
// to format output
using namespace std;
// Functions Prototypes
int getDays(int);
void getTime(double &,double &);
double getAirfare(double);
double carRental(double);
double PrivateCarFee(double);
double TaxiFees(double);
double ParkingFee(double);
double ConferenceFee(double);
void HotelExpenses(double & ,double &);
double Breakfast(double,double&,double&,int,double&);
double Lunch(double,double&,double&,int,double&);
double Dinner(double,double&,double&,int,double&);
 
//Main function to call other functions
int main(){
cout<<"\t\t\tWELCOME\t\t\t"<<endl;
    //Variable Declaration
      
    int days=0;
    double airfareExpenses=0,rentalCarExpenses=0,privateCarExpenses=0,taxiExpenses=0,parkingExpenses=0,breakfastExpenses=0,LunchExpenses=0,dinnerExpenses=0,TotalGroupExpenses=0,TotalgroupAllowed=0,
        conferenceExpenses=0,hotel=0,HotelAllowed=0,TotalExpenses,TotalAllowed,parkingAllowed,TaxiAllowed, departureTime,arrivalTime,breakfastAllowed,lunchAllowed,dinnerAllowed,prize,debt,
        airfareDeviation;
    parkingAllowed=days*20;
        TaxiAllowed=days*30;
        double tota_allowed[10]={parkingAllowed,TaxiAllowed,HotelAllowed,airfareExpenses,rentalCarExpenses,privateCarExpenses,conferenceExpenses,breakfastAllowed,lunchAllowed,dinnerAllowed};
      
        string name;
        cout<<"\n Enter employee name\n";
        cin>>name;
        //Call Function To obtain information
        days=getDays(days);
        
        getTime(departureTime,arrivalTime);
        
        airfareExpenses=getAirfare(airfareExpenses);
        
        rentalCarExpenses=carRental(rentalCarExpenses);
        
        privateCarExpenses=PrivateCarFee(privateCarExpenses);
        
        taxiExpenses=TaxiFees(taxiExpenses);
        
        parkingExpenses=ParkingFee(parkingExpenses);
        
        conferenceExpenses=ConferenceFee(conferenceExpenses);
        
        HotelExpenses(hotel,HotelAllowed);
        breakfastExpenses=Breakfast(breakfastExpenses,departureTime,arrivalTime,days,breakfastAllowed);
        LunchExpenses=Lunch(LunchExpenses,departureTime,arrivalTime,days,lunchAllowed);
        dinnerExpenses=Dinner(dinnerExpenses,departureTime,arrivalTime,days,dinnerAllowed);
        
        
        //Calculate Totals
        
		TotalAllowed=parkingAllowed+TaxiAllowed+HotelAllowed+airfareExpenses+rentalCarExpenses+privateCarExpenses+conferenceExpenses+breakfastAllowed+lunchAllowed+dinnerAllowed; //Calculate Total Allowed Expenses
        TotalExpenses=airfareExpenses+rentalCarExpenses+privateCarExpenses+taxiExpenses+parkingExpenses+conferenceExpenses+hotel+breakfastExpenses+LunchExpenses+dinnerExpenses; //Calculate All Expenses
        TotalAllowed+=TotalAllowed;
        TotalExpenses+=TotalExpenses;
        //Calculate Dept And Prize
        if(TotalAllowed>TotalExpenses)
            prize=(TotalAllowed-TotalExpenses)*.1;
        else if(TotalAllowed<TotalExpenses)
            debt=TotalExpenses-TotalAllowed;
        else
        {
            debt=0;
            prize=50;
        }
 
 
        //Display Information
        cout<<"Employee: "<<name<<endl;
        cout<<"Total allowed "<<TotalAllowed<<endl;
        cout<<"Total Expenses "<<TotalExpenses<<endl;
         
    
    system("pause");
    return 0;
}
// function to get the data required 
int getDays(int numDays)
{
    cout<<"How many days long was the trip?\n";
    cin>>numDays;
    while(numDays<1)//Input Validation
    {    cout<<"Days on trip must be at least 1\n";
        cin>>numDays;
    }
    return numDays;
}
 // function to check the cost of the airfare
void getTime(double &depart, double &arrival)
{
    cout<<"Enter departure time in military format(HH.MM)\n";
    cin>>depart;
while (depart < 00.00 || depart > 23.59)
{
    cout << "Please enter a valid time in military format (HH.MM)\n";
    cin >> depart;
}
cout <<"enter arrival time in military format(HH.MM)";
cin>> arrival;
while (arrival < 00.00 || arrival > 23.59)
{
    cout << "Please enter a valid time in military format (HH.MM)\n";
    cin >> arrival;
}

  
    cout <<"departure time is :" << depart << endl;;
    cout <<"arrival time is: " << arrival; 
}
 

 
double getAirfare(double airfare)
{
	 char choice ;
    cout << "\nAny round-trip airfare? (Y/N): ";
    cin>>choice;
    while((choice != 'y') && (choice != 'Y') && (choice!= 'N') && (choice != 'n'))//Input Validation
    {
        cout<<"Enter Y for yes or N for no\n";
        cin>>choice;
    }
    if(choice=='Y' || choice=='y')
    {
        while(airfare<=0)//Input Validation
    {
        cout<<" Please enter airfare cost\n";
        cin>>airfare;
    }
 
    }
    else if (choice=='N' || choice=='n')
    airfare=0;
    
    return airfare;
}
 // function to check the expenses of the car rented
double carRental(double rental)
{ 
    int days;
    double fee;
    char choice ;
    cout<<" Did you rent a car? Enter Y for yes or N for no\n";
    cin>>choice;
    while((choice != 'y') && (choice != 'Y') && (choice!= 'N') && (choice != 'n'))//Input Validation
    {
        cout<<"Enter Y for yes or N for no\n";
        cin>>choice;
    }
    if(choice=='Y' || choice=='y')
    {
        cout<<"Enter  rental car cost daily fee\n";
        cin>>fee;
        cout<<"How many days did you rent the car for?\n";
        cin>> days;
        rental=fee*days;
 
    }
    else if (choice=='N' || choice=='n')
        rental=0;
     
    return rental;
}
 // function to check the expenses for private car
double PrivateCarFee(double carfee)
{
    double Km, fee=0.6;
    char choice;
    cout<<"Did you use a private vehicle? Enter Y for yes or N for no\n";
    cin>>choice;
    while((choice != 'y') && (choice != 'Y') && (choice!= 'N') && (choice != 'n'))//Input Validation
    {
        cout<<"Enter Y for yes or N for no\n";
        cin>>choice;
    }
    if(choice=='Y' || choice=='y')
    {
        cout<<"How many Km were driven?\n";
        cin>>Km;
        carfee=Km*fee;
    }
    else if (choice=='N' || choice=='n')
        carfee=0;
 
    return carfee;
}
 // function to check the expenses for parking
double ParkingFee(double parking)
{
    cout<<" Enter Parking expenses. \n";
    cin>>parking;
    return parking;
 
}
 // function to check the expenses for taxi
double TaxiFees(double taxi)
{
    char choice;
    cout<<"Did you use a taxi? Enter Y for yes or N for no.\n";
    cin>>choice;
    while((choice != 'y') && (choice != 'Y') && (choice!= 'N') && (choice != 'n'))//Input Validation
    {
        cout<<"Enter Y for yes or N for no.\n";
        cin>>choice;
    }
    if(choice=='Y' || choice=='y')
    {
        cout<<"Please Enter Taxi Expenses.\n";
        cin>>taxi;
    }
    else if (choice=='N' || choice=='n')
        taxi=0;
 
    return taxi;
}
 // function to check the cost for the seminar
double ConferenceFee(double conference)
{
	 char choice;
    cout<<"Did you join a conference or seminar ? Enter Y for yes or N for no.\n";
    cin>>choice;
    while((choice != 'y') && (choice != 'Y') && (choice!= 'N') && (choice != 'n'))//Input Validation
    {
        cout<<"Enter Y for yes or N for no.\n";
        cin>>choice;
    }
    if(choice=='Y' || choice=='y')
    {
    cout<<" Enter conference or seminar registration fees. \n";
    cin>>conference;
    while(conference<0)//Input Validation
    {
        cout<<" Enter conference or seminar registration fees. \n";
        cin>>conference;
    }
}
else if (choice=='N' || choice=='n')
     conference=0;
    return conference;
}
 // function to check the hotel expenses
void HotelExpenses(double &HotelSpent, double &HotelAllowed){

    int nights;
    double fee;
    cout<<"Enter Hotel Nightly Fee\n";
    cin>>fee;
    cout<<"How many nights did you stay at the hotel?\n";
    cin>>nights;
    HotelSpent=nights*fee;
    HotelAllowed=nights*200;
     
 
}
 // total expenses for breakfast
double Breakfast(double BreakfastExpenses, double &departure, double &arrival,int tripDays,double &allowedBreakfast)
{
    int breakfastdays;
     
    if(departure<7.00)
        breakfastdays=tripDays;
    else if(departure>7.00)
        breakfastdays=tripDays-1;
    else if(arrival>8.00)
        breakfastdays=tripDays-1;
    else if(arrival<8.00)
        breakfastdays=tripDays;
    cout<<"breakfast days\n";
    cout<<breakfastdays<<endl;
    cout<<" Enter  total Breakfast expenses for all days\n";
    cin>>BreakfastExpenses;
    allowedBreakfast=15*breakfastdays;
    cout<<" Breakfast Expenses\n";
    cout<<BreakfastExpenses;
    return BreakfastExpenses;
}
 // total expenses for lunch
double Lunch(double LunchExpenses, double &departure, double &arrival,int tripDays,double &allowedLunch){

    int lunchdays;
     
    if(departure<12.00)
        lunchdays=tripDays-1;
    else if(departure>12.00)
        lunchdays=tripDays;
    else if(arrival>13.00)
        lunchdays=tripDays;
    else if(arrival<13.00)
        lunchdays=tripDays-1;
        cout<<"lunch days\n";
    cout<<lunchdays<<endl;
    cout<<" Enter total lunch expenses for all days\n";
    cin>>LunchExpenses;
    allowedLunch=25*lunchdays;
    cout<<" lunch Expenses\n";
    cout<<LunchExpenses;
    return LunchExpenses;
}
 // total expenses for dinner
double Dinner(double DinnerExpenses, double &departure, double &arrival,int tripDays,double &allowedDinner)
{
    int dinnerdays;
     
    if(departure<18.00)
        dinnerdays=tripDays;
    else if(departure>18.00)
        dinnerdays=tripDays-1;
    else if(arrival>19.00)
        dinnerdays=tripDays-1;
    else if(arrival<19.00)
        dinnerdays=tripDays;
        cout<<"Dinner days\n";
    cout<<dinnerdays<<endl;
    cout<<" Enter total Dinner expenses for all days\n";
    cin>>DinnerExpenses;
    allowedDinner=20*dinnerdays;
    cout<<" Dinner Expenses\n";
    cout<<DinnerExpenses;
    return DinnerExpenses;
}
