#include<iostream>
#include<string>
using namespace std;
template <class T>
class array_operation
{
    private :
    T a[100];
    int n;
    public:
    void readdate();
    T findArraysum(T a);
    void display();
};
template <typename T>
void array_operation<T>::readdate()
{
    cout<<"Enter the size of array : ";
    std::cin>>n;
    cout<<"Enter the elements of array : ";
    for(int i=0;i<n;i++)
    {
        std::cin>>a[i];
    }
}
template <typename T>
void array_operation<T>::display()
{
    cout<<"The elements of array are : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
template <typename T>
T array_operation<T>::findArraysum(T key)
{
    int i,s;
    for (i=0;i<n;i++)
    {
        s=a[i]+key;
    }
    return s;
}
int main()
{
    array_operation<int> obj1;
    obj1.readdate();
    obj1.display();
    std::cout<<"\nThe sum of array elements is : "<<obj1.findArraysum(7)<<endl;
    array_operation<string> obj2;
    return 0;
}
