#include<iostream.h>
#include<conio.h>
int deci,bits=0,deci_x3,bits_x3;
int array[100][20];
int array1[100][20];
int array2[100][20];
void binary(int [100][20],int,int,int);
void gray(int);
void display(int);
int find_bits(int);

void main()
{
textcolor(GREEN);
textbackground(BLUE);
clrscr();
cout<<"Enter the no. upto which gray code and excess 3 code is to be
generated : ";
cin>>deci;
bits=find_bits(deci);
deci_x3=deci+3;
bits_x3=find_bits(deci_x3);
for(int i2=0;i2<=deci;i2++)
{
for(int j2=0;j2<=bits;j2++)
{
array[i2][j2]=0;
array1[i2][j2]=0;
}
}
array2[0][bits_x3-1]=1;
array2[0][bits_x3-2]=1;
for( i2=1;i2<=deci_x3;i2++)
{
for(int j2=0;j2<=bits_x3;j2++)
{
array2[i2][j2]=0;
}
}
cout<<" DECI NO. BINARY EQ. GRAY CODE EXCESS 3";
cout<<endl<<"-------------------------------------------------------------
--";
display(0);
getch();
for(int i=1;i<=deci;i++)
{
binary(array,i,bits,0);
gray(i);
binary(array2,i,bits_x3,1);
display(i);
getch();
}
}

void binary(int array_bin[20][20],int i,int bits2,int flag)
{
int ix;
if(flag==1)
ix=i+3;
else
ix=i;
array_bin[i][bits2-1]=(array_bin[i-1][bits2-1]==0?1:0);
for(int k1=2,i1=2;k1<=bits2;k1++,i1*=2)
{
if((ix/i1)%2==0)
array_bin[i][bits2-k1]=0;
else
array_bin[i][bits2-k1]=1;
}
}



void gray(int i)
{
//FIXING THE HIGHEST ORDER BIT FIRST
array1[i][0]=array[i][0];
for(int j=1;j<bits;j++)
{
if((array[i][j-1]==0&&array[i][j]==0)||(array[i][j-1]==1&&array[i][j]==1))
array1[i][j]=0;
else
array1[i][j]=1;
}
}

void display(int m)
{
cout<<endl;
if(m<=9)
cout<<" "<<m<<" " ;
else
cout<<" "<<m<<" " ;
for(int j=0;j<bits;j++)
cout<<array[m][j];
cout<<" " ;
for( j=0;j<bits;j++)
cout<<array1[m][j];
cout<<" ";
for( j=0;j<bits_x3;j++)
cout<<array2[m][j];
}



int find_bits(int m)
{
int k,bits1=0;
do
{
bits1++;
k=1;
for(int i=1;i<=bits1;i++)
k=k*2;
}
while(k<=m);
return(bits1);
}
