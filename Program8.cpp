// Create two classes DM and DB. DM stores the distance in meters and centimeters and DB stores
// the distance in feet and inches. write a program to add object of DM with object of DB classe

#include <iostream>

using namespace std;
class DB;
class DM
{
private:
    double meters = 5; // 1mtr = 100 cm
    double centimeters = 0;

public:
    // parametrized constructor to intialize values
    DM(double mtrs, double cntmtrs)
    {
        setMeters(mtrs);
        setCentimeters(cntmtrs);
    }
    // setter and getter functions
    double getMeters() { return meters; }
    double getCentimeters() { return centimeters; }
    void setMeters(double mtrs) { meters = mtrs; }
    void setCentimeters(double centmtrs)
    {
        centimeters = centmtrs;
        meters = meters + (int)centimeters / 100;
        centimeters = (int)centimeters % 100;
    }
    //function to display values
    void display()
    {
        cout << meters << "mtrs, " << centimeters << "cms\n";
    }
    friend DM add(DM &dm, DB &db);
};

class DB
{
private:
    double feet = 0; // 1ft = 12 inch
    double inches = 0;

public:
    //constructor to initialize values
    DB(double ft, double inch)
    {
        setFeet(ft);
        setInches(inch);
    }
    //setter and getter functions
    double getFeet() { return feet; }
    double getInches() { return inches; }
    void setFeet(double ft) { feet = ft; }
    void setInches(double inch)
    {
        inches = inch;
        feet = feet + (int)inches / 12;
        inches = (int)inches % 12;
    }
    // friend function to add objects two classes
    friend DM add(DM &dm, DB &db);
    // function to display feets and inches
    void display()
    {
        cout << feet << "ft, " << inches << "inches\n";
    }
};
// definition of the function
DM add(DM &dm, DB &db)
{
    double newCM = db.inches * 2.54;
    newCM += dm.centimeters;
    double newMtrs = db.feet * 0.3048;
    newMtrs += dm.meters;
    return DM(newMtrs, newCM);
}

int main()
{
    double mtrs, centmtrs;
    double feet, inches;
    cout << "Enter Meters and Centimeters: " << endl;
    cin >> mtrs >> centmtrs;
    cout << "Enter Feet and Inches: " << endl;
    cin >> feet >> inches;
    DM dm1 = {mtrs, centmtrs};
    DB db1 = {feet, inches};
    DM dm2 = add(dm1, db1);
    dm1.display();
    db1.display();
    dm2.display();

    return 0;
}
