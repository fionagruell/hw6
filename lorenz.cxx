#include <iostream>
#include <cmath>

using namespace std;
void fun(double*f, const double a, const double b, const double c, double x, double  y,double z);
int main(){
const double dt=0.001;
const int tend=100;
const int N=(tend-0)/dt+1;
double x,y,z;
double k1[3]; //3 dimensions x y z
double k2[3];
double k3[3];
double k4[3];
double f[3];
const double a=10;
const double b=28;
const double c=8.0/3.0;

x=1;
y=1;
z=1;
for (int i=1; i<N; i++){
  //calculating ks
fun(k1,a,b,c,x,y,z); //calculates k1;
fun(k2,a,b,c,x+dt/2*k1[0],y+dt/2*k1[1],z+dt/2*k1[2]); //calculates k2 (depends on k1)
fun(k3,a,b,c,x+dt/2*k2[0],y+dt/2*k2[1],z+dt/2*k2[2]); //calculates k3 (depends on k2)
fun(k4,a,b,c,x+dt*k3[0],y+dt*k3[1],z+dt*k3[2]); //calculates k4 (depends on k3)

x+=dt/6*(k1[0]+2*k2[0]+2*k3[0]+k4[0]); //calculating x
y+=dt/6*(k1[1]+2*k2[1]+2*k3[1]+k4[1]);//calculating y
z+=dt/6*(k1[2]+2*k2[2]+2*k3[2]+k4[2]); //calculating z

cout <<i*dt+0 <<"\t"<<x<<"\t"<<y<<"\t"<<z<< endl; //writing corrdinates to console

}

return 0;
}
//calculates function 
void fun(double*f, const double a, const double b, const double c, double x, double  y,double z){
  f[0]=a*(y-x); //f[0] is the derivative of x
  f[1]=x*(b-z)-y; //f[1] is the derivative of y
  f[2]=x*y-c*z; //f[2] is the derivative of z
}