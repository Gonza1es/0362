#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v1, v2, v3, v4;
//������� �� ���������� � �������������
int df(int n)
{
    int q=2;
    while (n!=0)
    {
        v1.push_back(n%q);
        n=n/q;
        q++;
    }
    reverse(v1.begin(),v1.end());
    return 0;
}
//������� �� ������������� � ����������
int fd()
{
    int a=0,q=1, i=2;
    reverse(v2.begin(),v2.end());
    for(vector<int>::iterator it=v2.begin();it!=v2.end();it++)
    {
        a=a+(*it)*q;
        q=q*i;
        i++;
    }
     return a;
}
//���������� ����� �� ������������ � ��������
int npa ( )
{
    v2.clear();
    for(vector<int>::iterator it=v4.begin();it!=v4.end();it++)
    {
        vector<int>::iterator it1=find(v3.begin(), v3.end(),*it);
        v2.push_back (it1-v3.begin());
        v3.erase(it1);
    }
    v2.pop_back();
    int n=fd()+1;
    return n;
}
//���������� ������������ �� ������ � ��������
int pna(int n,int a)
{
    v1.clear();
    df(n);
    int d=v1.size();
    for (int i=d; i<a; i++)
        v1.push_back(0);
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        v4.push_back(v3[*it]);
        v3.erase(v3.begin()+ *it);
    }
    return 0;
}
//���������� ��������� ������������ �� ��������
int pp()
{
    int d=v4.size();
    for (int i=1; i<=d; i++)
        v3.push_back(i);
    int n=npa()+1;
    v4.clear();
    for (int i=1; i<=d; i++)
        v3.push_back(i);
    pna( n-1, d);
    return 0;
}
int main()
{
    int n, a;
    cout<<endl<<"enter a number in the 10 number system"<<endl; //������� ����� � 10 ������� ���������
    cin>>n;
    df(n);
    cout<<"your number in the factorial number system"<<endl;//���� ����� � ������������� ������� ���������
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //
    cout<<endl<<"enter a number in the factorial number system. each number is separated by a space"<<endl;//������� ����� � ������������� ������� ��������� ������ ����� ����� ������
    while (cin>>n)
    {
      v2.push_back(n);
      if (cin.get()=='\n')
        break;
    }
    a=fd();
    cout<<"your number is in decimal notation"<<endl;//���� ����� � ���������� ������� ���������
    cout<<a;
    cout<<endl;
    //
    cout<<endl<<"Enter the permutation number"<<endl;//������� ����� ������������
    cin>>n;
    cout<<endl<<"Enter the number of digits in the alphabet"<<endl;//������� ���������� ���� � ��������
    cin>>a;
    cout<<endl;
    for (int i=1; i<=a; i++)
        v3.push_back(i);
    pna( n-1, a);
    cout<<"the resulting permutation"<<endl;//���������� ������������
    for(vector<int>::iterator it=v4.begin();it!=v4.end();it++)
    {
        cout<<*it<<" ";
    }
    //
    cout<<endl<<"enter the number of digits in the alphabet"<<endl;//������� ���������� ���� � ��������
    cin>>a;
    cout<<endl;
    v3.clear();
    v4.clear();
    for (int i=1; i<=a; i++)
        v3.push_back(i);
    cout<<endl<<"enter the permutation. each number is separated by a space"<<endl;//������� ������������ ������ ����� ����� ������
    while (cin>>n)
    {
      v4.push_back(n);
      if (cin.get()=='\n')
        break;
    }
    n=npa();
    cout<<"your permutation number"<<endl;//����� ����� ������������
    cout<<n<<endl;
    //
    v1.clear();
    v4.clear();
    cout<<endl<<"enter the permutation. each number is separated by a space"<<endl;//������� ������������ ������ ����� ����� ������
    while (cin>>n)
    {
      v4.push_back(n);
      if (cin.get()=='\n')
        break;
    }
    pp();
    cout<<"next permutation of the current one"<<endl;//��������� ������������ �� �������
    for(vector<int>::iterator it=v4.begin();it!=v4.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}
