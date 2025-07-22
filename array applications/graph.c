#include<stdio.h>
int a[20][20],q[20],vis[20],stack[20],top=-1,front=-1,rear=-1;
int deq();
void enq(int item);
void bfs(int s,int n);
void dfs(int s,int n);
void push(int item);
int pop();
void main()
{
int n,i,s,ch,j;
printf("Enter the number of vertices:\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("Enter 1 if %d has a node with %d, else 0: ",i,j);
scanf("%d",&a[i][j]);
}
}
printf("ADJACENCY MATRIX: \n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
do
{
for(i=1;i<=n;i++)
vis[i]=0;
printf("\n1.BFS\t2.DFS\t3.EXIT\n");
printf("ENTER YOUR CHOICE: ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\nENTER SOURCE VERTEX: ");
scanf("%d",&s);
bfs(s,n);
break;
case 2: printf("\nENTER SOURCE VERTEX: ");
scanf("%d",&s);
dfs(s,n);
break;
case 3: break;
}
}while(ch!=3);
}
void bfs(int s,int n)
{
int p,i;
enq(s);
vis[s]=1;
p=deq();
if(p!=0)
printf("%d\t",p);
while(p!=0)
{
for(i=0;i<=n;i++)
{
if((a[p][i]!=0)&&(vis[i]=0))
{
enq(i);
vis[i]=1;
}
p=deq();
if(p!=0)
{
printf("%d\t",p);
}
}
for(i=1;i<=n;i++)
{
if(vis[i]==0)
{
bfs(i,n);
}
}
}
}
void enq(int item)
{
if(rear==19)
printf("QUEUE FULL\n");
else
{
if(rear==-1)
{
q[++rear]=item;
front++;
}
else
q[++rear]=item;
}
}
int deq()
{
int k;
if((front>rear)||(front==-1))
return(0);
else
{
k=q[front++];
return(k);
}
}
void dfs(int s,int n)
{
int i,k;
push(s);
vis[s]=1;
k=pop();
if(k!=0)
printf("%d\t",k);
while(k!=0)
{
for(i=1;i<=n;i++)
{
if((a[k][i]!=0)&&(vis[i]==0))
{
push(i);
vis[i]=1;
}
}
k=pop();
if(k!=0)
printf("%d\t",k);
}
for(i=1;i<=n;i++)
{
if(vis[i]=0)
dfs(i,n);
}
}
void push(int item)
{
if(top==19)
printf("STACK OVERFLOW\n");
else
stack[++top]=item;
}
int pop()
{
int k;
if(top==-1)
return(0);
else
{
k=stack[top--];
return(k);
}
}
