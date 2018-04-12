#include<iostream>
using namespace std;
#define MAX 15
int main()
{
 int number[MAX] , burst[MAX] , arrival[MAX] , response[MAX] , n , i , j , rem[MAX] , ttime=0 , min , premin=n-1 , turnaround[MAX];
 cout<<"Enter number of processes : ";
 cin>>n;
 cout<<"\nEnter arrival time , burst time and priority for each process : ";
 for(i=0 ; i<n ; i++)
 {
 number[i]=i+1;
 cout<<"P"<<i+1<<" : "; 
 cin>>arrival[i]>>burst[i];
 rem[i]=burst[i];
 ttime=ttime+burst[i];
 }
 cout<<"Gantt Chart : ";
 cout<<"\n";
 for(i=0 ; i<=ttime ; i++)
 {
 min=0;
 for(j=0 ; j<n ; j++)
 {
 if(arrival[j]<=i&&rem[j]<
rem[min]&&rem[j]!=0)
 {
 min=j;
 }
 }
 if(rem[min]==burst[min])
 {
 response[min]=i;
 }
 if(premin!=min||i==0)
 {
 cout<<i<<" "<<"P"<<number[min]<<" ";
 }
 rem[min]-=1;
 if(rem[min]==0)
 {
 turnaround[min]=i-arrival[min]
+1;
 }
 premin=min;
 }
 cout<<ttime<<"\n";
 cout<<"Turnaround time : ";
 for(i=0 ; i<n ; i++)
 {
 cout<<"P"<<i+1<<" : "<<turnaround[i]<<"\n";
 }
 cout<<"Waiting time : ";
 for(i=0 ; i<n ; i++)
 {
 cout<<"P"<<i+1<<" : "<<turnaround[i]-burst[i]<<"\
n";
 }
 cout<<"Response time : ";
 for(i=0 ; i<n ; i++)
 {
 cout<<"P"<<i+1<<" : "<<response[i]<<"\n";
 }
 cout<<"Throughput : "<<n*1000/ttime<<" processes per second\n";
 return 0;
}
