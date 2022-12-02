#include <stdio.h>
#include <time.h>
#include <string.h>
void toss(char* pl1,char* pl2,char* p1,char* p2)
{
  int tos;
  time_t x=time(NULL)%2;
  if(x)
  {
    printf("%s You won the toss,\nPress to \n1. Bat\n2.Ball",pl1);
    scanf("%d",&tos);
    tos=tos%2;
    if(tos==1)
    {
      strcpy(p1,pl1);
      strcpy(p2,pl2);
    }
    else
    {
      strcpy(p1,pl2);
      strcpy(p2,pl1);
    }
  }
  else
  {
    printf("%s You won the toss,\nPress to \n1. Bat\n2.Ball\n",pl2);
    scanf("%d",&tos);
    tos=tos%2;
    if(tos==0)
    {
      strcpy(p1,pl1);
      strcpy(p2,pl2);
    }
    else
    {
      strcpy(p2,pl2);
      strcpy(p1,pl1);
    }
  }
}

int comprun(int ul)
{
  time_t sec=time(NULL)%ul;
  return sec;
}

int play(char* pname,int ul,int firstInningRuns)
{
  int run;
  int notout=1;
  int runscored=0;
  printf("\n%s All the best!\n To bat press a number between 1 to %d\n",pname,ul);
  while(notout&&(firstInningRuns>runscored||firstInningRuns==-1))
  {
    printf("\nplay\n");
    scanf("%d",&run);
    run=run%(ul+1);
    if(run==comprun(ul))
    {
      printf("\nOUT!\n");
      notout=0;
      printf("\n Runs scored by %s is %d\n",pname,runscored);
    }
    else
    {
      runscored+=run;
    }
  }
  return runscored;
}
void main()
{
  char ch;
  char p1[30],p2[30],pl1[30],pl2[30];
  int ul,mode,p1run=0,p2run=0,p1secinnruns=0,p2secinnruns=0;
  printf("Hey welcome to Game of number cricket!");
  printf("\n Enter any key to continue");
  scanf("%c",&ch);
  printf("\nEnter name of player 1: ");
  scanf("%s",&pl1);
  printf("\nEnter name of player 2: ");
  scanf("%s",&pl2);
  printf("\nEnter mode of game:\n1. T20i\n2.Test Cricket\n");
  scanf("%d",&mode);
  printf("\nEnter Upper Limit in one shot: ");
  scanf("%d",&ul);
  toss(pl1,pl2,p1,p2);
  switch(mode)
  {
    case 1:
    p1run=play(p1,ul,-1);
    p2run=play(p2,ul,p1run);
    if(p1run>p2run)
    {
      printf("\n\t%s won by %d runs",p1,p1run-p2run);
    }
    else if(p1run<p2run)
    {
      printf("\n\t%s Won!!",p2);
    }
    else
    {
      printf("\n\tIt's a Draw");
    }
    break;

    case 2:
    printf("\nFIRST INNING BEGINS\n BATTING %s\t\tBOWLING %s\n",p1,p2);
    p1run=play(p1,ul,-1);
    printf("\nSECOND INNING BEGINS\n BATTING %s\t\tBOWLING %s\n",p2,p1);
    p2run=play(p2,ul,-1);
    printf("\nTHIRD INNING BEGINS\n BATTING %s\t\tBOWLING %s\n",p1,p2);
    p1secinnruns=play(p1,ul,-1);
    printf("\nFOURTH INNING BEGINS\n BATTING %s\t\tBOWLING %s\n",p2,p1);
    p2secinnruns=play(p2,ul,p1run+p1secinnruns-p2run);

    int diff=(p1run+p1secinnruns)-(p2run+p2secinnruns);
    if(diff>0)
    {
      printf("\n%s won by %d runs\n",p1,diff);
    }
    else if(diff<0)
    {
      printf("\n%s WON!!\n",p2);
    }
    else
    {
      printf("It's a draw");
    }
    break;
    default:
    printf("\nSorry but you will have to wait till we bring in more formats\n");
  }
}
