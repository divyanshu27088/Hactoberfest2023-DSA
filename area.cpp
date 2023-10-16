#include<iostream>
using namespace std;
void rectangle(int l,int b,	int &area ,int &peri)
{
	area=l*b;
	peri=2*(l+b);
}
int main()
{
	int area,peri;
	int l,b;
	cout<<"enter the length=";
	cin>>l;
	cout<<"enter the breath=";
	cin>>b;
	rectangle(l,b,area,peri);
	cout<<"area ="<<area;
	cout<<"peri ="<<peri;
	return 0;
}
