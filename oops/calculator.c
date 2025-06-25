/*input month and year and display 
calendar*/
#include<stdio.h>
#include<conio.h>

void main(){
int m,y,days=0,i;
char week_days[7][10]={"Sunday","Monday","Tuesday","Wednusday","Thursday","Friday","Saturday"};
//clrscr();
printf("\nEnter month & year mm/yyyy");
scanf("%d%d",&m,&y);
//1/1/2000 - Saturday
//Finding no. of day between the years
for(i=2000;i<y;i++)
if((i % 4 == 0 && i % 100 != 0) || (i% 100 == 0))
   days+=366;
 else
  days+=365;
//Finding no. of day of the months
for(i=1;i<m;i++)
 if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
   days+=31;
 else if(i==2)
   if((y % 4 == 0 && y % 100 != 0) || (y% 100 == 0))
    days+=29;
   else
    days+=28;
 else
   days+=30;
//clrscr();
printf("\n%d\n%d",days,days%7);
//gotoxy(36,5);
printf("CALENDAR\n\n");
for(i=0;i<7;i++)
printf("%10s",week_days[i]);
printf("\n");
for(i=0;i<(days-1)%7;i++)
 printf("%10s","");
for(i=1;i<31;i++){
printf("%10d",i);
if(((days+i-1)%7)==0)
 printf("\n");
}
}