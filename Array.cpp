#include"array.h"
#include<iostream>
using namespace std;
template<class T>
array1<T>::array1()
{
    int i;
    cout<<"Enter the lower bound";
    cin>>lb;
    cout<<"Enter the upper bound";
    cin>>ub;
    cout<<"Enter the elements:";
    for(i=lb;i<=ub;i++)
    {
        cin>>a[i];
    }
}
template <class T>
void array1<T>::displayarray1()
{
    int i;
for(i=lb;i<=ub;i++)
{
    cout<<a[i]<<" ";
}
}                                                                         
