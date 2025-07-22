#include<stdio.h>
struct polynomials
{
int coeff;
int expo;
};
struct polynomials p[20],q[20],r[20];
void main()
{
  int m,n,x,i,j,k=0;
printf("enter the no of terms of fisrt polynomial: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter the coefficient of first polynomial: ");
scanf("%d",&p[i].coeff);
printf("enter the exponents of first polynomial: ");
scanf("%d",&p[i].expo);
}
printf("first polynomial:\n");
for(i=0;i<n;i++)
{
printf("%dx^%d",p[i].coeff,p[i].expo);
if(i<n-1)
printf("+");
}

printf("\n");


printf("enter the no of terms of second polynomial: ");
scanf("%d",&m);
for(j=0;j<m;j++)
{
printf("enter the coefficient of second polynomial: ");
scanf("%d",&q[j].coeff);
printf("enter the exponents of second polynomial: ");
scanf("%d",&q[j].expo);
}
printf("second polynomial:\n");
for(j=0;j<m;j++)
{
printf("%dx^%d",q[j].coeff,q[j].expo);
if(j<m-1)
printf("+");
}
printf("\n");

 i=0;
 j=0;
 k=0;
while(i<=n&&j<=m)
{
if(p[i].expo==q[j].expo)
{
r[k].coeff=p[i].coeff+q[j].coeff;
r[k].expo=p[i].expo;
i++;
j++;
k++;
}
else if(p[i].expo>q[j].expo)
{
r[k].coeff=p[i].coeff;
r[k].expo=p[i].expo;
i++;
k++;
}
else
{
r[k].coeff=q[j].coeff;
r[k].expo=q[j].expo;
j++;
k++;
}
   
}
while(i<=n)
{
r[k].coeff=p[i].coeff;
r[k].expo=p[i].expo;
i++;
k++;
}
while(j<=m)
{
r[k].coeff=q[j].coeff;
r[k].expo=q[j].expo;
j++;
k++;
}
printf("\nResultant polynomial:");
if(m<n)
{
for(k=0;k<n;k++)
{
   
   
     printf("%dx^%d",r[k].coeff,r[k].expo);
     if(k<n-1)
     printf("+");
}
}
else
{
for(k=0;k<m;k++)
   {
    printf("%dx^%d",r[k].coeff,r[k].expo);
    if(k<m-1)
    printf("+");
}
}
}
