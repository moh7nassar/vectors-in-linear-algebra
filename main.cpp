/*
Student : Mohammed Hisham Nassar.
ID : 201910831
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define pb push_back
using namespace std;
void fun(string s , double &i, double &j, double &k)
{
    int x=0; //this variable was declared to store the values of a,b,c in ai+bj+ck in the loop below and then push back to the vector.
    vector<double>vec;
    i=0;j=0;k=0;
    bool flag=false;
    for(int e=0;e<s.size();e++)
    {
        if(s[e]>='0'&&s[e]<='9')
        {
            if(s[e-1]=='-'&&e!=0)flag=true;
            if(s[e]=='0')
            {x*=10;}
            else
            {x=(x*10)+s[e]-'0';}
        }
        else
        {
            if((s[e-1]>='0' && s[e-1]<='9' && e!=0)||(s[e-1]=='-'||s[e-1]=='+'||e==0)&&
             (s[e]>='i'&&s[e]<='k')||(e==0&&s[e]=='i'))
            {
               if(x==0)x=1;
               if(flag ||((s[e-1]=='-')&&(s[e]>='i'&&s[e]<='k')))
                  x*=-1;
               vec.pb(x);
            }
            x=0;
            flag=false;
        }
    }
    for(int e=0;e<s.size();e++)
    {
        if(s[e]=='i')i++;
        else if(s[e]=='j')j++;
        else if(s[e]=='k')k++;
    }
    if(i==0)
    {
        if(j!=0)
            j=vec[0];
        else
            k=vec[0];
        if(k!=0)
            k=vec[1];
    }
    else
    {
        bool note=true;
        i=vec[0];
        if(j!=0)
            j=vec[1];
        else
        {
            if(k!=0)
            {
                k=vec[1];
                note=false;
            }
        }
        if(k!=0 && note)
            k=vec[2];
    }
}
double length(double i, double j, double k)
{return sqrt((i*i)+(j*j)+(k*k));}
void unit(double i, double j, double k, char s)
{
    vector<double>vec;
    double len=length(i,j,k);
    if(len==1)
    {
        cout<<"This vector has length = 1, so it is a unit vector"<<endl;
    }
    else
    {
        i=(1/len)*(i);
        j=(1/len)*(j);
        k=(1/len)*(k);
        if(s=='s'){
        cout<<endl<<"The unit vector in the same direction is : "<<endl;
        if(i!=0)
        {
            if(i<0)
                cout<<'-';
            cout<<"("<<abs(i)<<")"<<"i";
        }
        if(j!=0)
        {
            if(j>0)
                cout<<'+';
            else
                cout<<'-';
            cout<<"("<<abs(j)<<")"<<"j";
        }
        if(k!=0)
        {
            if(k>0)
                cout<<'+';
            else
                cout<<'-';
            cout<<"("<<abs(k)<<")"<<"k";
        }
        }
        else
        {
            cout<<endl<<"The unit vector in the opposite direction is : "<<endl;
        if(i!=0)
        {
            if(i>0)
                cout<<'-';
            if(abs(i)==1)
                cout<<"i";
            else
            cout<<"("<<abs(i)<<")"<<"i";
        }
        if(j!=0)
        {
            if(j>0)
                cout<<'-';
            else
                cout<<'+';
            if(abs(j)==1)
                cout<<"j";
            else
            cout<<"("<<abs(j)<<")"<<"j";
        }
        if(k!=0)
        {
            if(k>0)
                cout<<'-';
            else
                cout<<'+';
            if(abs(k)==1)
                cout<<"k";
            else
            cout<<"("<<abs(k)<<")"<<"k";
        }
        }
    }
    cout<<endl;


}
double inner(double i, double j, double k, double l, double m, double n)
{return (i*l)+(j*m)+(k*n);}
void outer(double i, double j, double k, double l, double m, double n)
{
    double first=((j*n)-(k*m));
    double second=((k*l)-(i*n));
    double third=((i*m)-(j*l));
    cout<<"The Outer product of u & v is : ";
    if(first!=0)
    {
        if(first<0)
            cout<<'-';
        if(abs(first)==1)
            cout<<"i";
        else
        cout<<"("<<abs(first)<<")i";
    }
    if(second!=0)
    {
        if(second>0)
        cout<<'+';
        else
            cout<<'-';
        if(abs(second)==1)
            cout<<"j";
        cout<<"("<<abs(second)<<")j";
    }
    if(third!=0)
    {
        if(third>0)
        cout<<'+';
        else
            cout<<'-';
        if(abs(third)==1)
            cout<<"k";
        else
        cout<<"("<<abs(third)<<")k";
    }
    cout<<endl;
}
double angle(double i, double j, double k, double l, double m, double n)
{return inner(i,j,k,l,m,n)/((length(i,j,k))*(length(l,m,n)));}
double distance(double i, double j, double k, double l, double m, double n)
{return sqrt(((i-l)*(i-l))+((j-m)*(j-m))+((k-n)*(k-n)));}
void projection(double i, double j, double k, double l, double m, double n)
{
    double r=inner(i, j, k, l, m, n);
    double len=length(l,m,n);
    len*=len;
    double sol=r/len;
    cout<<"("<<sol*l<<","<<sol*m<<","<<sol*n<<")"<<endl;
}
void orthogonality(double i, double j, double k, double l, double m, double n)
{
    if(inner(i,j,k,l,m,n)==0)
        cout<<"u & v are orthogonal."<<endl;
    else
        cout<<"u & v are not Orthogonal."<<endl;
}
bool parallel(double i, double j, double k, double l, double m, double n)
{
    for(int e=-100;e<=100;e++)
    {
        if( (i/e==l && j/e==m && k/e==n) || (l/e==i && m/e==j && n/e==k) )
        {return true;}
    }
    return false;
}
int main()
{
    double iu=0,ju=0,ku=0,iv=0,jv=0,kv=0;
    int c;
    char n;
    bool exit=false;
    string s,d;
    cout<<"Please enter the first vector u : ";cin>>s;
    cout<<"Please enter the second vector v : ";cin>>d;
    fun(s,iu,ju,ku);
    fun(d,iv,jv,kv);
    while(true){
    cout<<endl<<"Choose the operation : "<<endl<<"1. The length of the vector."<<endl<<"2. Find the unit vector in the same direction"<<endl;
    cout<<"3. Find the unit vector in the opposite direction."<<endl<<"4. Inner products."<<endl<<"5. Outer product."<<endl;
    cout<<"6. Angle between two vectors."<<endl<<"7. Distance between two vectors."<<endl<<"8. The projection."<<endl;
    cout<<"9. Check if the two vectors are orthogonal."<<endl<<"10. Check if the two vectors are parallel."<<endl<<"11. Exit."<<endl;
    cout<<endl<<"I want to find : ";
    cin>>c;
    switch(c)
    {
    case 1:
        cout<<"Choose the vector that you want to find its length (u or v) : ";
        cin>>n;
        while(true)
        {
            if(n=='v'||n=='V')
            {
                cout<<"The length of v is : "<<length(iv,jv,kv)<<endl;
                break;
            }
            else if(n=='u'||n=='U')
            {
                cout<<"The length of u is : "<<length(iu,ju,ku)<<endl;
                break;
            }
            else
            {
                cout<<"Invalid entry, please try again : ";
                cin>>n;
            }
        }
        break;
    case 2:
        cout<<"Choose the vector that you want to find the unit vector in the same direction : ";
        cin>>n;
        while(true)
        {
            if(n=='v' || n=='V')
            {
                unit(iv,jv,kv,'s');
                break;
            }
            else if(n=='u'||n=='U')
            {
                unit(iu,ju,ku,'s');
                break;
            }
            else
            {
                cout<<"Invalid entry, please try again : ";
                cin>>n;
            }
        }
        break;
    case 3:
        cout<<"Choose the vector that you want to find the unit vector in the opposite direction : ";
        cin>>n;
        while(true)
        {
            if(n=='v')
            {
                unit(iv,jv,kv,'o');
                break;
            }
            else if(n=='u')
            {
                unit(iu,ju,ku,'o');
                break;
            }
            else
            {
                cout<<"Invalid entry, please try again : ";
                cin>>n;
            }
        }
        break;
    case 4:
        cout<<"The inner product of u & v is : "<<inner(iu,ju,ku,iv,jv,kv)<<endl;
        break;
    case 5:
        outer(iu,ju,ku,iv,jv,kv);
        break;
    case 6:
        cout<<"The angle between u & v is : "<<angle(iu,ju,ku,iv,jv,kv)<<endl;
        break;
    case 7:
        cout<<"The distance between u & v is : "<<distance(iu,ju,ku,iv,jv,kv)<<endl;
        break;
    case 8:
        cout<<"The projection between u & v is : ";
        projection(iu,ju,ku,iv,jv,kv);
        break;
    case 9:
        orthogonality(iu,ju,ku,iv,jv,kv);
        break;
    case 10:
        if(parallel(iu,ju,ku,iv,jv,kv))
            cout<<"u & v are parallel vectors"<<endl;
        else
            cout<<"u & v are not parallel vectors"<<endl;
        break;
    case 11:
        exit=true;
        break;
    default:
        cout<<"Invalid entry"<<endl;
    }
    if(exit)break;
    }
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"Thanks for trusting this program (:"<<endl<<endl;
    return 0;
}
