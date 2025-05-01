#include <bits/stdc++.h>
using namespace std;


class Date {

    public:
        int d,m,y;
        void init(int dd,int mm,int yy);

        void addYear(int n);
        void addMonth(int n);
        void addDay(int n);
        string display();
};
void Date::init(int dd,int mm,int yy){
    this->y = yy;
    this->m = mm;
    this->d = dd;
}
void Date::addYear(int n){
    this->y +=n;
}
string Date::display() {
    return "{" + this->d + ", "+ this->m + ", "+ this->y + "}\n";
}
int main() {

    Date myBd, today, age;
    int d,m,y, mr=0,yr=0;

    cout<<"ENTER YOUR DATE OF BIRTH <d,m,y>: ";
    cin >> d >> m >> y;
    myBd.init(d,m,y);
    cout<<"ENTER YOUR CURRENT DATE <d,m,y>: ";
    cin >> d >> m >> y;
    today.init(d,m,y);
    if(today.d - myBd.d < 0)
        {
            age.d = 30 + (today.d - myBd.d);
            mr = 1;
        }
    else
        age.d = today.d - myBd.d;
    if(today.m - myBd.m < 0) {
        age.m = 12 + (today.m - myBd.m) - mr;
        yr = 1;
    }
    else
        age.m = today.m - myBd.m - mr;
    age.y = today.y - myBd.y - yr;

    cout << "AGE: " << age.display();

    return 0;
}





