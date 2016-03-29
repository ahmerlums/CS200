#include <curses.h>
#include <unistd.h>
#define DELAY 99999
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>

using namespace std;
int check_ghost_position(int r, int s, int xmax, int ymax );
int Check_Crossroad(int r , int s , int xmax, int ymax);
int Game_Over(int xmax, int ymax);


int main()
{
    srand(time(0));
    int ch=0;
    int x = 0;
    int y = 0;
    int max_y = 0;
    int max_x = 0;
    int next_x = 0;
    int next_y = 0;
    int direction = 1;
    int l=1;
    int r=1;
    int c=1;
    int d=1;
    int e=1;
    int u=1;
    int food=0;
    int food1=0;
    int food2=0;
    int lives=0;
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    getmaxyx(stdscr, max_y, max_x);
    x=max_x/2;
    y=max_y/2+7;

    int i=1;

    for (i=1; i<=78; i++)
        mvprintw(max_y/2-5,i, ".");

    for (i=1; i<=36; i++)
    {
        mvprintw(1,i, ".");
        mvprintw(1,i+42, ".");
    }

    for (i=1; i<=16; i++)
        mvprintw(max_y/2-2,i, ".");

    for (i=2; i<=15; i++)
        mvprintw(max_y/2-2,i+22, ".");

    for (i=18; i<=32; i++)
        mvprintw(max_y/2-2,i+25, ".");

    for (i=35; i<=50; i++)
        mvprintw(max_y/2-2,i+28, ".");

    for (i=1; i<=47; i++)
        mvprintw(max_y/2+1,i+16, ".");

    for (i=0; i<=79; i++)
        mvprintw(max_y/2+4,i, ".");

    for (i=1; i<=25; i++)
        mvprintw(max_y/2+8,i, ".");

    mvprintw(max_y/2+8,30, ".");

    mvprintw(max_y/2+8,50, ".");

    for (i=1; i<=25; i++)
        mvprintw(max_y/2+8,53+i, ".");

    for (i=1; i<=30; i++)
        mvprintw(23,i, ".");

    for (i=1; i<=29; i++)
        mvprintw(23,i+49, ".");

    for (i=5; i<=34; i++)
        mvprintw(22,i+20, ".");

    for (i=1; i<=10; i++)
        mvprintw(i,1, ".");

    for (i=1; i<=10; i++)
        mvprintw(i,max_x-2, ".");

    for (i=1; i<=20; i++)
        mvprintw(i,17, ".");

    for (i=1; i<=20; i++)
        mvprintw(i,max_x-17, ".");

    for (i=20; i<=22; i++)
        mvprintw(i,1, ".");

    for (i=20; i<=22; i++)
        mvprintw(i,max_x-2, ".");

    for (i=1; i<=7; i++)
        mvprintw(i,max_x/2-4, ".");

    for (i=10; i<=12; i++)
        mvprintw(i,max_x/2-3, ".");

    for (i=1; i<=7; i++)
        mvprintw(i,max_x/2+3, ".");

    for (i=10; i<=12; i++)
        mvprintw(i,max_x/2+3, ".");

    for (i=7; i<=9; i++)
        mvprintw(i,max_x/2-16, ".");

    mvprintw(21,max_x/2-15, ".");

    for (i=7; i<=9; i++)
        mvprintw(i,max_x/2+17, ".");

    mvprintw(21,max_x/2+14, ".");

    for (i=1; i<=8; i++)
        mvprintw(max_y/2+1+i,max_x/2-10, ".");

    for (i=1; i<=8; i++)
        mvprintw(max_y/2+1+i,max_x/2+10, ".");

    int v1 =0 ;
    int v2 =0 ;
    int g1 =0;
    int g2 =0;
    int h1 =0;
    int h2 =0;
    int z=0;
    int t=0;
    int vpos=0;
    int gpos=0;
    int hpos=0;
    int rnd=0;
    int pop=0;
    int xtest=0;
    int ytest=0;
    int test=0;
    int rnd1=0;
    int rnd2=0;
    int rnd3=0;
    int rnd_1=0;
    int rnd_2=0;
    int pop1=0;
    int pop2=0;
    int f1=0;
    int f2=0;
    int f3=0;
    int fpos=0;
    int ts=0;
    int fruittime=0;
    int fruitcount=0;
    int reghost=1;
    int timer=0;
    int over=0;
    int over1=0;
    int over2=0;

    while(getch()!='q')
    {
        if (lives==0)
            mvprintw(max_y/2+6,max_x/2-3, "Lives = 3");

        if (lives==1)
            mvprintw(max_y/2+6,max_x/2-3, "Lives = 2");

        if (lives==2)
            mvprintw(max_y/2+6,max_x/2-3, "Lives = 1");

        if (lives>=3)
        {
            mvprintw(max_y/2+8,max_x/2-3, "YOU LOSE!");
            over1++;

        }
        if (over1==2)
            break;

        over=Game_Over(max_x,max_y);
        if (over==50)
        {
            mvprintw(max_y/2+8,max_x/2-3, "YOU WIN!");
            over2++;
        }

        if (over2==2)
            break;

        ts++;
        while (fpos==0)
        {
            if (ts==3)
            {

                f1 = rand() % max_y + 1;
                f2 = rand() % max_x + 1;
                fpos=check_ghost_position(f1,f2,max_x,max_y);

                if (fpos==1)
                {
                    if (c==1)
                    {
                        mvprintw(f1,f2,"$") ;
                        break;
                    }

                }
            }

            else
                break;


        }

        if (c==1)
        {
            mvprintw(f1,f2,"$") ;
        }
        else
        {
            mvprintw(f1,f2," ") ;
        }
        while(vpos==0&&reghost==1)
        {

            v1 = rand() % max_y + 1;
            v2 = rand() % max_x + 1;
            vpos=check_ghost_position(v1,v2,max_x,max_y);
            if (vpos==1)
                break;

        }

        if (pop==0)
        {
            if (rnd1==1)
            {
                while (1)
                {
                    rnd=rand()% 4 + 1 ;
                    if (rnd != 2)
                        break;
                }
            }
            else if (rnd1==2)
            {
                while (1)
                {
                    rnd=rand()% 4 + 1 ;
                    if (rnd != 1)
                        break;
                }
            }
            else if (rnd1==3)
            {
                while (1)
                {
                    rnd=rand()% 4 + 1 ;
                    if (rnd != 4)
                        break;
                }
            }
            else if (rnd1==4)
            {
                while (1)
                {
                    rnd=rand()% 4 + 1 ;
                    if (rnd != 3)
                        break;
                }
            }
            else if (rnd1==0)
                rnd=rand()% 4 + 1 ;

        }
        rnd1=rnd;

        pop=1;
        if (rnd==1)

        {
            nodelay(stdscr , true);
            direction=1;


            if ( (v2 >= max_x-2) && (v1>=1) && (v1<=15))
                direction=0;

            if ( (v2 >= max_x-2) && (v1>=17) && (v1<=max_y))
                direction=0;

            if((v2==max_x/2-4) && (v1>=1) && (v1<=6))
                direction=0;

            if((v2==max_x/2-23) && (v1>=2) && (v1<=6))
                direction=0;

            if((v2==max_x/2-39) && (v1>=2) && (v1<=6))
                direction=0;

            if((v2==max_x/2+3) && (v1>=2) && (v1<=6))
                direction=0;

            if((v2==max_x/2+23) && (v1>=2) && (v1<=6))
                direction=0;

            if((v2==max_x/2-39) && (v1>=8) && (v1<=9))
                direction=0;

            if((v2==max_x/2+23) && (v1>=8) && (v1<=9))
                direction=0;

            if((v2==max_x/2-16) && (v1>=8) && (v1<=9))
                direction=0;

            if((v2==max_x/2-3) && (v1>=9) && (v1<=12))
                direction=0;

            if((v2==max_x/2-23) && (v1>=8) && (v1<=12))
                direction=0;

            if((v2==max_x/2+3) && (v1>=11) && (v1<=12))
                direction=0;

            if((v2==max_x/2+17) && (v1>=8) && (v1<=10))
                direction=0;

            if((v2==max_x/2+23) && (v1>=11) && (v1<=15))
                direction=0;

            if((v2==max_x/2-23) && (v1>=14) && (v1<=15))
                direction=0;

            if((v2==max_x/2+10) && (v1>=14) && (v1<=15))
                direction=0;

            if((v2==max_x/2-10) && (v1>=14) && (v1<=15))
                direction=0;

            if((v2==max_x/2+23) && (v1>=17) && (v1<=19))
                direction=0;

            if((v2==max_x/2-23) && (v1>=17) && (v1<=19))
                direction=0;

            if((v2==max_x/2-15) && (v1>=20) && (v1<=21))
                direction=0;

            if((v2==max_x/2+10) && (v1>=17) && (v1<=21))
                direction=0;

            if((v2==max_x/2-10) && (v1>=17) && (v1<=21))
                direction=0;

            if((v2==max_x/2+8) && (v1>=17) && (v1<=21))
                direction=0;

            if((v2==max_x/2+1) && (v1==17))
                direction=0;

            if((v2==max_x/2-39) && (v1>=21)&&(v1<=22))
                direction=0;

            if((v2==max_x/2+14) && (v1>=21)&&(v1<=22))
                direction=0;

            if((v2==max_x/2-10) && (v1==23))
                direction=0;

            if((v2==max_x) && (v1==16))
                direction=-max_x;

            if((v2==x) && (v1==y) && (fruittime==0))
            {

                mvprintw(v1, v2, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
                break;
            }

            if((v2==x) && (v1==y) && (fruittime==1))
            {

                mvprintw(y, x, " ");
                v1=10000;
                v2=10000;
                vpos=0;
            }


            v2 = v2 + direction;

            if (food==1)
                mvprintw(v1, v2-1, ".");
            if (food==0)
                mvprintw(v1, v2-1, " ");


            if (mvinch(v1,v2)== '.')
                food=1;
            if (mvinch(v1,v2)== ' ')
                food=0;

            if (c==1)


                mvprintw(v1 , v2 , ":");
            else
                mvprintw(v1, v2, "{");


        }

        else if (rnd==2)
        {
            nodelay(stdscr , true);
            direction=-1;

            if ( (v2 == 1) && (v1>=1) && (v1<=15))
                direction=0;

            if ( (v2 == 1) && (v1>=17) && (v1<=max_y))
                direction=0;

            if ((v2==(max_x/2)+3) && (v1>=1) && (v1<=6))
                direction=0;

            if ((v2==(max_x/2)-4) && (v1>=2) && (v1<=6))
                direction=0;

            if ((v2==(max_x/2)-23) && (v1>=2) && (v1<=6))
                direction=0;

            if ((v2==(max_x/2)+23) && (v1>=2) && (v1<=6))
                direction=0;

            if ((v2==(max_x/2)+38) && (v1>=2) && (v1<=6))
                direction=0;

            if ((v2==(max_x/2)-23) && (v1>=8) && (v1<=9))
                direction=0;

            if((v2==max_x/2+38) && (v1>=8) && (v1<=9))
                direction=0;

            if((v2==max_x/2+17) && (v1>=8) && (v1<=9))
                direction=0;

            if((v2==max_x/2+3) && (v1>=10) && (v1<=12))
                direction=0;

            if((v2==max_x/2-3) && (v1>=11) && (v1<=12))
                direction=0;

            if((v2==max_x/2-16) && (v1>=8) && (v1<=10))
                direction=0;

            if((v2==max_x/2+23) && (v1>=8) && (v1<=12))
                direction=0;

            if((v2==max_x/2-23) && (v1>=11) && (v1<=15))
                direction=0;

            if((v2==max_x/2-10) && (v1>=14) && (v1<=15))
                direction=0;

            if((v2==max_x/2+23) && (v1>=14) && (v1<=15))
                direction=0;

            if((v2==max_x/2+10) && (v1>=14) && (v1<=15))
                direction=0;

            if((v2==max_x/2-23) && (v1>=17) && (v1<=19))
                direction=0;

            if((v2==max_x/2+23) && (v1>=17) && (v1<=19))
                direction=0;

            if((v2==max_x/2-10) && (v1>=17) && (v1<=21))
                direction=0;

            if((v2==max_x/2+14) && (v1>=20) && (v1<=21))
                direction=0;

            if((v2==max_x/2+10) && (v1>=17) && (v1<=21))
                direction=0;

            if((v2==max_x/2-8) && (v1>=17) && (v1<=21))
                direction=0;

            if((v2==max_x/2-1) && (v1==17))
                direction=0;

            if((v2==max_x/2-15) && (v1>=21)&&(v1<=22))
                direction=0;

            if((v2==max_x/2+38) && (v1>=21)&&(v1<=22))
                direction=0;

            if((v2==max_x/2+10) && (v1==23))
                direction=0;

            if((v2==0) && (v1==16))
            {
                mvprintw(v1, v2, " ");
                direction=max_x;
            }

            if((v2==x) && (v1==y)&&(fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }
            if((v2==x) && (v1==y) && (fruittime==1))
            {

                mvprintw(v1, v2, " ");
                v1=10000;
                v2=10000;
                vpos=0;
            }


            v2 = v2 + direction;
            if (food==1)
                mvprintw(v1, v2+1, ".");
            if (food==0)
                mvprintw(v1, v2+1, " ");


            if (mvinch(v1,v2)== '.')
                food=1;
            if (mvinch(v1,v2)== ' ')
                food=0;

            if (c==1)
                mvprintw(v1 , v2 , ":");
            else
                mvprintw(v1, v2, "{");



        }

        else if (rnd==3)
        {
            nodelay(stdscr , true);
            direction=-1;

            if (direction!=0)
                next_y = v1 + direction;

            if (next_y < 1)
                direction=0;


            if ((v1==(max_y/2)-5) &&((v2>=(max_x/2)-3) && (v2 <=
                                     (max_x/2)+2)))
                direction=0;

            if ((v1==(max_y/2)-5) &&((v2>=(max_x/2)-22) && (v2 <=
                                     (max_x/2)-5)))
                direction=0;

            if ((v1==(max_y/2)-5) &&((v2>=(max_x/2)-38) && (v2 <=
                                     (max_x/2)-24)))
                direction=0;

            if ((v1==(max_y/2)-5) &&((v2>=(max_x/2)+4) && (v2 <=
                                     (max_x/2)+22)))
                direction=0;

            if ((v1==(max_y/2)-5) &&((v2>=(max_x/2)+24) && (v2 <=
                                     (max_x/2)+37)))
                direction=0;

            if ((v1==10) &&((v2>=(max_x/2)-38) && (v2 <= (max_x/2)-24)))
                direction=0;

            if ((v1==10) &&((v2>=(max_x/2)+24) && (v2 <= (max_x/2)+37)))
                direction=0;

            if ((v1==10) &&((v2>=(max_x/2)-15) && (v2 <= (max_x/2)+16)))
                direction=0;

            if ((v1==13) &&((v2>=(max_x/2)-2) && (v2 <= (max_x/2)+2)))
                direction=0;

            if ((v1==13) &&((v2>=(max_x/2)-22) && (v2 <= (max_x/2)-4)))
                direction=0;

            if ((v1==13) &&((v2>=(max_x/2)+4) && (v2 <= (max_x/2)+22)))
                direction=0;

            if ((v1==max_y/2+4) &&((v2>=(max_x/2)-39) && (v2 <=
                                   (max_x/2)-24)))
                direction=0;

            if ((v1==max_y/2+4) &&((v2>=(max_x/2)+24) && (v2 <=
                                   (max_x/2)+39)))
                direction=0;

            if ((v1==max_y/2+4) &&((v2>=(max_x/2)-22) && (v2 <=
                                   (max_x/2)-11)))
                direction=0;

            if ((v1==max_y/2+4) &&((v2>=(max_x/2)+11) && (v2 <=
                                   (max_x/2)+22)))
                direction=0;

            if ((v1==16) &&((v2>=(max_x/2)-9) && (v2 <= (max_x/2)+9)))
                direction=0;

            if ((v1==max_y/2+8) &&((v2>=(max_x/2)-39) && (v2 <=
                                   (max_x/2)-24)))
                direction=0;

            if ((v1==max_y/2+8) &&((v2>=(max_x/2)+24) && (v2 <=
                                   (max_x/2)+39)))
                direction=0;

            if ((v1==max_y/2+8) &&((v2>=(max_x/2)-22) && (v2 <=
                                   (max_x/2)-15)))
                direction=0;

            if ((v1==max_y/2+10) &&((v2>=(max_x/2)-14) && (v2 <=
                                    (max_x/2)-11)))
                direction=0;

            if ((v1==max_y/2+10) &&((v2>=(max_x/2)+11) && (v2 <=
                                    (max_x/2)+13)))
                direction=0;

            if ((v1==max_y/2+8) &&((v2>=(max_x/2)+14) && (v2 <=
                                   (max_x/2)+22)))
                direction=0;

            if ((v1==max_y/2+10) &&((v2>=(max_x/2)-9) && (v2 <=
                                    (max_x/2)+9)))
                direction=0;

            if ((v1==max_y/2+6) &&((v2>=(max_x/2)-9) && (v2 <=
                                   (max_x/2)-2)))
                direction=0;

            if ((v1==max_y/2+6) &&((v2>=(max_x/2)+2) && (v2 <=
                                   (max_x/2)+9)))
                direction=0;

            if ((v1==23) &&((v2>=(max_x/2)-38) && (v2 <= (max_x/2)-16)))
                direction=0;

            if ((v1==23) &&((v2>=(max_x/2)+15) && (v2 <= (max_x/2)+37)))
                direction=0;



            if((v2==x) && (v1==y)&& (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((v2==x) && (v1==y) && (fruittime==1))
            {

                mvprintw(v1, v2, " ");
                v1=10000;
                v2=10000;
                vpos=0;
            }

            v1=v1+direction;

            if (food==1)
                mvprintw(v1+1, v2, ".");
            if (food==0)
                mvprintw(v1+1, v2, " ");


            if (mvinch(v1,v2)== '.')
                food=1;
            if (mvinch(v1,v2)== ' ')
                food=0;
            if (c==1)
                mvprintw(v1 , v2 , ":");
            else
                mvprintw(v1, v2, "{");

        }

        else if (rnd==4)
        {
            nodelay(stdscr , true);
            direction=1;

            if (direction!=0)
                next_y = v1 + direction;

            if (next_y >= max_y-1)
                direction=0;

            if ((v1==1) &&((v2>=(max_x/2)-22) && (v2 <= (max_x/2)-5)))
                direction=0;

            if ((v1==1) &&((v2>=(max_x/2)+4) && (v2 <= (max_x/2)+22)))
                direction=0;

            if ((v1==1) &&((v2>=(max_x/2)+24) && (v2 <= (max_x/2)+37)))
                direction=0;

            if ((v1==1) &&((v2>=(max_x/2)-38) && (v2 <= (max_x/2)-24)))
                direction=0;

            if ((v1==7) &&((v2>=(max_x/2)-38) && (v2 <= (max_x/2)-24)))
                direction=0;

            if ((v1==7) &&((v2>=(max_x/2)+24) && (v2 <= (max_x/2)+37)))
                direction=0;

            if ((v1==7) &&((v2>=(max_x/2)-15) && (v2 <= (max_x/2)+16)))
                direction=0;

            if ((v1==10) &&((v2>=(max_x/2)-16) && (v2 <= (max_x/2)-4)))
                direction=0;

            if ((v1==7) &&((v2>=(max_x/2)-22) && (v2 <= (max_x/2)-17)))
                direction=0;

            if ((v1==10) &&((v2>=(max_x/2)+4) && (v2 <= (max_x/2)+17)))
                direction=0;

            if ((v1==7) &&((v2>=(max_x/2)+18) && (v2 <= (max_x/2)+22)))
                direction=0;

            if ((v1==max_y/2-2) &&((v2>=(max_x/2)-39) && (v2 <=
                                   (max_x/2)-24)))
                direction=0;

            if ((v1==max_y/2-2) &&((v2>=(max_x/2)+24) && (v2 <=
                                   (max_x/2)+39)))
                direction=0;

            if ((v1==13) &&((v2>=(max_x/2)-22) && (v2 <= (max_x/2)-11)))
                direction=0;

            if ((v1==13) &&((v2>=(max_x/2)+11) && (v2 <= (max_x/2)+22)))
                direction=0;


            if ((v1==13) &&((v2>=(max_x/2)-9) && (v2 <= (max_x/2)+9)))
                direction=0;

            if ((v1==max_y/2+4) &&((v2>=(max_x/2)-39) && (v2 <=
                                   (max_x/2)-24)))
                direction=0;

            if ((v1==max_y/2+4) &&((v2>=(max_x/2)+24) && (v2 <=
                                   (max_x/2)+39)))
                direction=0;

            if ((v1==max_y/2+4) &&((v2>=(max_x/2)-22) && (v2 <=
                                   (max_x/2)-11)))
                direction=0;

            if ((v1==max_y/2+4) &&((v2>=(max_x/2)+11) && (v2 <=
                                   (max_x/2)+22)))
                direction=0;

            if ((v1==max_y/2+4) &&((v2>=(max_x/2)-9) && (v2 <=
                                   (max_x/2)-2)))
                direction=0;

            if ((v1==max_y/2+4) &&((v2>=(max_x/2)+2) && (v2 <=
                                   (max_x/2)+9)))
                direction=0;

            if ((v1==max_y/2+8) &&((v2>=(max_x/2)-9) && (v2 <=
                                   (max_x/2)+9)))
                direction=0;

            if ((v1==20) &&((v2>=(max_x/2)-38) && (v2 <= (max_x/2)-16)))
                direction=0;

            if ((v1==20) &&((v2>=(max_x/2)+15) && (v2 <= (max_x/2)+37)))
                direction=0;

            if ((v1==22) &&((v2>=(max_x/2)-9) && (v2 <= (max_x/2)+9)))
                direction=0;

            if((v2==x) && (v1==y)&& (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((v2==x) && (v1==y) && (fruittime==1))
            {

                mvprintw(v1, v2, " ");
                v1=10000;
                v2=10000;
                vpos=0;
            }

            v1 = v1 + direction;
            if (food==1)
                mvprintw(v1-1, v2, ".");
            if (food==0)
                mvprintw(v1-1, v2, " ");


            if (mvinch(v1,v2)== '.')
                food=1;
            if (mvinch(v1,v2)== ' ')
                food=0;
            if (c==1)
                mvprintw(v1 , v2 , ":");
            else
                mvprintw(v1, v2, "{");



        }
        if (direction==0)
            pop=0;

        test=Check_Crossroad(v1,v2,max_x,max_y);

        if (test==0)
            pop=0;

        while(gpos==0&&reghost==1)
        {

            g1 = rand() % max_y + 1;
            g2 = rand() % max_x + 1;
            gpos=check_ghost_position(g1,g2,max_x,max_y);
            if (gpos==1)
                break;
        }

        if (pop1==0)
        {
            if (rnd2==1)
            {
                while (1)
                {
                    rnd_1=rand()% 4 + 1 ;
                    if (rnd_1 != 2)
                        break;
                }
            }
            else if (rnd2==2)
            {
                while (1)
                {
                    rnd_1=rand()% 4 + 1 ;
                    if (rnd_1 != 1)
                        break;
                }
            }
            else if (rnd2==3)
            {
                while (1)
                {
                    rnd_1=rand()% 4 + 1 ;
                    if (rnd_1 != 4)
                        break;
                }
            }
            else if (rnd2==4)
            {
                while (1)
                {
                    rnd_1=rand()% 4 + 1 ;
                    if (rnd_1 != 3)
                        break;
                }
            }
            else if (rnd2==0)
                rnd_1=rand()% 4 + 1 ;

        }
        rnd2=rnd_1;

        pop1=1;
        if (rnd_1==1)
        {
            nodelay(stdscr , true);
            direction=1;


            if ( (g2 >= max_x-2) && (g1>=1) && (g1<=15))
                direction=0;

            if ( (g2 >= max_x-2) && (g1>=17) && (g1<=max_y))
                direction=0;

            if((g2==max_x/2-4) && (g1>=1) && (g1<=6))
                direction=0;

            if((g2==max_x/2-23) && (g1>=2) && (g1<=6))
                direction=0;

            if((g2==max_x/2-39) && (g1>=2) && (g1<=6))
                direction=0;

            if((g2==max_x/2+3) && (g1>=2) && (g1<=6))
                direction=0;

            if((g2==max_x/2+23) && (g1>=2) && (g1<=6))
                direction=0;

            if((g2==max_x/2-39) && (g1>=8) && (g1<=9))
                direction=0;

            if((g2==max_x/2+23) && (g1>=8) && (g1<=9))
                direction=0;

            if((g2==max_x/2-16) && (g1>=8) && (g1<=9))
                direction=0;

            if((g2==max_x/2-3) && (g1>=9) && (g1<=12))
                direction=0;

            if((g2==max_x/2-23) && (g1>=8) && (g1<=12))
                direction=0;

            if((g2==max_x/2+3) && (g1>=11) && (g1<=12))
                direction=0;

            if((g2==max_x/2+17) && (g1>=8) && (g1<=10))
                direction=0;

            if((g2==max_x/2+23) && (g1>=11) && (g1<=15))
                direction=0;

            if((g2==max_x/2-23) && (g1>=14) && (g1<=15))
                direction=0;

            if((g2==max_x/2+10) && (g1>=14) && (g1<=15))
                direction=0;

            if((g2==max_x/2-10) && (g1>=14) && (g1<=15))
                direction=0;

            if((g2==max_x/2+23) && (g1>=17) && (g1<=19))
                direction=0;

            if((g2==max_x/2-23) && (g1>=17) && (g1<=19))
                direction=0;

            if((g2==max_x/2-15) && (g1>=20) && (g1<=21))
                direction=0;

            if((g2==max_x/2+10) && (g1>=17) && (g1<=21))
                direction=0;

            if((g2==max_x/2-10) && (g1>=17) && (g1<=21))
                direction=0;

            if((g2==max_x/2+8) && (g1>=17) && (g1<=21))
                direction=0;

            if((g2==max_x/2+1) && (g1==17))
                direction=0;

            if((g2==max_x/2-39) && (g1>=21)&&(g1<=22))
                direction=0;

            if((g2==max_x/2+14) && (g1>=21)&&(g1<=22))
                direction=0;

            if((g2==max_x/2-10) && (g1==23))
                direction=0;

            if((g2==max_x) && (g1==16))
                direction=-max_x;

            if((g2==x) && (g1==y)&&(fruittime==0))
            {

                mvprintw(g1, g2, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((g2==x) && (g1==y) && (fruittime==1))
            {

                mvprintw(y, x, " ");
                g1=10000;
                g2=10000;
                gpos=0;
            }

            g2 = g2 + direction;

            if (food1==1)
                mvprintw(g1, g2-1, ".");
            if (food1==0)
                mvprintw(g1, g2-1, " ");


            if (mvinch(g1,g2)== '.')
                food1=1;
            if (mvinch(g1,g2)== ' ')
                food1=0;

            if (c==1)
                mvprintw(g1 , g2 , ":");
            else
                mvprintw(g1, g2, "{");



        }


        if (rnd_1==2)
        {
            nodelay(stdscr , true);
            direction=-1;

            if ( (g2 == 1) && (g1>=1) && (g1<=15))
                direction=0;

            if ( (g2 == 1) && (g1>=17) && (g1<=max_y))
                direction=0;

            if ((g2==(max_x/2)+3) && (g1>=1) && (g1<=6))
                direction=0;

            if ((g2==(max_x/2)-4) && (g1>=2) && (g1<=6))
                direction=0;

            if ((g2==(max_x/2)-23) && (g1>=2) && (g1<=6))
                direction=0;

            if ((g2==(max_x/2)+23) && (g1>=2) && (g1<=6))
                direction=0;

            if ((g2==(max_x/2)+38) && (g1>=2) && (g1<=6))
                direction=0;

            if ((g2==(max_x/2)-23) && (g1>=8) && (g1<=9))
                direction=0;

            if((g2==max_x/2+38) && (g1>=8) && (g1<=9))
                direction=0;

            if((g2==max_x/2+17) && (g1>=8) && (g1<=9))
                direction=0;

            if((g2==max_x/2+3) && (g1>=10) && (g1<=12))
                direction=0;

            if((g2==max_x/2-3) && (g1>=11) && (g1<=12))
                direction=0;

            if((g2==max_x/2-16) && (g1>=8) && (g1<=10))
                direction=0;

            if((g2==max_x/2+23) && (g1>=8) && (g1<=12))
                direction=0;

            if((g2==max_x/2-23) && (g1>=11) && (g1<=15))
                direction=0;

            if((g2==max_x/2-10) && (g1>=14) && (g1<=15))
                direction=0;

            if((g2==max_x/2+23) && (g1>=14) && (g1<=15))
                direction=0;

            if((g2==max_x/2+10) && (g1>=14) && (g1<=15))
                direction=0;

            if((g2==max_x/2-23) && (g1>=17) && (g1<=19))
                direction=0;

            if((g2==max_x/2+23) && (g1>=17) && (g1<=19))
                direction=0;

            if((g2==max_x/2-10) && (g1>=17) && (g1<=21))
                direction=0;

            if((g2==max_x/2+14) && (g1>=20) && (g1<=21))
                direction=0;

            if((g2==max_x/2+10) && (g1>=17) && (g1<=21))
                direction=0;

            if((g2==max_x/2-8) && (g1>=17) && (g1<=21))
                direction=0;

            if((g2==max_x/2-1) && (g1==17))
                direction=0;

            if((g2==max_x/2-15) && (g1>=21)&&(g1<=22))
                direction=0;

            if((g2==max_x/2+38) && (g1>=21)&&(g1<=22))
                direction=0;

            if((g2==max_x/2+10) && (g1==23))
                direction=0;

            if((g2==0) && (g1==16))
            {
                mvprintw(g1, g2, " ");
                direction=max_x;
            }

            if((g2==x) && (g1==y)&&(fruittime==0))
            {

                mvprintw(g1, g2, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((g2==x) && (g1==y) && (fruittime==1))
            {

                mvprintw(y, x, " ");
                g1=10000;
                g2=10000;
                gpos=0;
            }

            g2 = g2 + direction;

            if (food1==1)
                mvprintw(g1, g2+1, ".");
            if (food1==0)
                mvprintw(g1, g2+1, " ");


            if (mvinch(g1,g2)== '.')
                food1=1;
            if (mvinch(g1,g2)== ' ')
                food1=0;

            if (c==1)
                mvprintw(g1 , g2 , ":");
            else
                mvprintw(g1, g2, "{");



        }

        if (rnd_1==3)
        {
            nodelay(stdscr , true);
            direction=-1;

            if (direction!=0)
                next_y = g1 + direction;

            if (next_y < 1)
                direction=0;


            if ((g1==(max_y/2)-5) &&((g2>=(max_x/2)-3) && (g2 <=
                                     (max_x/2)+2)))
                direction=0;

            if ((g1==(max_y/2)-5) &&((g2>=(max_x/2)-22) && (g2 <=
                                     (max_x/2)-5)))
                direction=0;

            if ((g1==(max_y/2)-5) &&((g2>=(max_x/2)-38) && (g2 <=
                                     (max_x/2)-24)))
                direction=0;

            if ((g1==(max_y/2)-5) &&((g2>=(max_x/2)+4) && (g2 <=
                                     (max_x/2)+22)))
                direction=0;

            if ((g1==(max_y/2)-5) &&((g2>=(max_x/2)+24) && (g2 <=
                                     (max_x/2)+37)))
                direction=0;

            if ((g1==10) &&((g2>=(max_x/2)-38) && (g2 <= (max_x/2)-24)))
                direction=0;

            if ((g1==10) &&((g2>=(max_x/2)+24) && (g2 <= (max_x/2)+37)))
                direction=0;

            if ((g1==10) &&((g2>=(max_x/2)-15) && (g2 <= (max_x/2)+16)))
                direction=0;

            if ((g1==13) &&((g2>=(max_x/2)-2) && (g2 <= (max_x/2)+2)))
                direction=0;

            if ((g1==13) &&((g2>=(max_x/2)-22) && (g2 <= (max_x/2)-4)))
                direction=0;

            if ((g1==13) &&((g2>=(max_x/2)+4) && (g2 <= (max_x/2)+22)))
                direction=0;

            if ((g1==max_y/2+4) &&((g2>=(max_x/2)-39) && (g2 <=
                                   (max_x/2)-24)))
                direction=0;

            if ((g1==max_y/2+4) &&((g2>=(max_x/2)+24) && (g2 <=
                                   (max_x/2)+39)))
                direction=0;

            if ((g1==max_y/2+4) &&((g2>=(max_x/2)-22) && (g2 <=
                                   (max_x/2)-11)))
                direction=0;

            if ((g1==max_y/2+4) &&((g2>=(max_x/2)+11) && (g2 <=
                                   (max_x/2)+22)))
                direction=0;

            if ((g1==16) &&((g2>=(max_x/2)-9) && (g2 <= (max_x/2)+9)))
                direction=0;

            if ((g1==max_y/2+8) &&((g2>=(max_x/2)-39) && (g2 <=
                                   (max_x/2)-24)))
                direction=0;

            if ((g1==max_y/2+8) &&((g2>=(max_x/2)+24) && (g2 <=
                                   (max_x/2)+39)))
                direction=0;

            if ((g1==max_y/2+8) &&((g2>=(max_x/2)-22) && (g2 <=
                                   (max_x/2)-15)))
                direction=0;

            if ((g1==max_y/2+10) &&((g2>=(max_x/2)-14) && (g2 <=
                                    (max_x/2)-11)))
                direction=0;

            if ((g1==max_y/2+10) &&((g2>=(max_x/2)+11) && (g2 <=
                                    (max_x/2)+13)))
                direction=0;

            if ((g1==max_y/2+8) &&((g2>=(max_x/2)+14) && (g2 <=
                                   (max_x/2)+22)))
                direction=0;

            if ((g1==max_y/2+10) &&((g2>=(max_x/2)-9) && (g2 <=
                                    (max_x/2)+9)))
                direction=0;

            if ((g1==max_y/2+6) &&((g2>=(max_x/2)-9) && (g2 <=
                                   (max_x/2)-2)))
                direction=0;

            if ((g1==max_y/2+6) &&((g2>=(max_x/2)+2) && (g2 <=
                                   (max_x/2)+9)))
                direction=0;

            if ((g1==23) &&((g2>=(max_x/2)-38) && (g2 <= (max_x/2)-16)))
                direction=0;

            if ((g1==23) &&((g2>=(max_x/2)+15) && (g2 <= (max_x/2)+37)))
                direction=0;



            if((g2==x) && (g1==y)&&(fruittime==0))
            {

                mvprintw(g1, g2, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
                gpos=0;
            }

            if((g2==x) && (g1==y) && (fruittime==1))
            {

                mvprintw(y, x, " ");
                g1=10000;
                g2=10000;
            }

            g1=g1+direction;
            if (food1==1)
                mvprintw(g1+1, g2, ".");
            if (food1==0)
                mvprintw(g1+1, g2, " ");


            if (mvinch(g1,g2)== '.')
                food1=1;
            if (mvinch(g1,g2)== ' ')
                food1=0;
            if (c==1)
                mvprintw(g1 , g2 , ":");
            else
                mvprintw(g1, g2, "{");



        }

        if (rnd_1==4)
        {
            nodelay(stdscr , true);
            direction=1;

            if (direction!=0)
                next_y = g1 + direction;

            if (next_y >= max_y-1)
                direction=0;

            if ((g1==1) &&((g2>=(max_x/2)-22) && (g2 <= (max_x/2)-5)))
                direction=0;

            if ((g1==1) &&((g2>=(max_x/2)+4) && (g2 <= (max_x/2)+22)))
                direction=0;

            if ((g1==1) &&((g2>=(max_x/2)+24) && (g2 <= (max_x/2)+37)))
                direction=0;

            if ((g1==1) &&((g2>=(max_x/2)-38) && (g2 <= (max_x/2)-24)))
                direction=0;

            if ((g1==7) &&((g2>=(max_x/2)-38) && (g2 <= (max_x/2)-24)))
                direction=0;

            if ((g1==7) &&((g2>=(max_x/2)+24) && (g2 <= (max_x/2)+37)))
                direction=0;

            if ((g1==7) &&((g2>=(max_x/2)-15) && (g2 <= (max_x/2)+16)))
                direction=0;

            if ((g1==10) &&((g2>=(max_x/2)-16) && (g2 <= (max_x/2)-4)))
                direction=0;

            if ((g1==7) &&((g2>=(max_x/2)-22) && (g2 <= (max_x/2)-17)))
                direction=0;

            if ((g1==10) &&((g2>=(max_x/2)+4) && (g2 <= (max_x/2)+17)))
                direction=0;

            if ((g1==7) &&((g2>=(max_x/2)+18) && (g2 <= (max_x/2)+22)))
                direction=0;

            if ((g1==max_y/2-2) &&((g2>=(max_x/2)-39) && (g2 <=
                                   (max_x/2)-24)))
                direction=0;

            if ((g1==max_y/2-2) &&((g2>=(max_x/2)+24) && (g2 <=
                                   (max_x/2)+39)))
                direction=0;

            if ((g1==13) &&((g2>=(max_x/2)-22) && (g2 <= (max_x/2)-11)))
                direction=0;

            if ((g1==13) &&((g2>=(max_x/2)+11) && (g2 <= (max_x/2)+22)))
                direction=0;


            if ((g1==13) &&((g2>=(max_x/2)-9) && (g2 <= (max_x/2)+9)))
                direction=0;

            if ((g1==max_y/2+4) &&((g2>=(max_x/2)-39) && (g2 <=
                                   (max_x/2)-24)))
                direction=0;

            if ((g1==max_y/2+4) &&((g2>=(max_x/2)+24) && (g2 <=
                                   (max_x/2)+39)))
                direction=0;

            if ((g1==max_y/2+4) &&((g2>=(max_x/2)-22) && (g2 <=
                                   (max_x/2)-11)))
                direction=0;

            if ((g1==max_y/2+4) &&((g2>=(max_x/2)+11) && (g2 <=
                                   (max_x/2)+22)))
                direction=0;

            if ((g1==max_y/2+4) &&((g2>=(max_x/2)-9) && (g2 <=
                                   (max_x/2)-2)))
                direction=0;

            if ((g1==max_y/2+4) &&((g2>=(max_x/2)+2) && (g2 <=
                                   (max_x/2)+9)))
                direction=0;

            if ((g1==max_y/2+8) &&((g2>=(max_x/2)-9) && (g2 <=
                                   (max_x/2)+9)))
                direction=0;

            if ((g1==20) &&((g2>=(max_x/2)-38) && (g2 <= (max_x/2)-16)))
                direction=0;

            if ((g1==20) &&((g2>=(max_x/2)+15) && (g2 <= (max_x/2)+37)))
                direction=0;

            if ((g1==22) &&((g2>=(max_x/2)-9) && (g2 <= (max_x/2)+9)))
                direction=0;

            if((g2==x) && (g1==y)&&(fruittime==0))
            {

                mvprintw(g1, g2, " ");
                x=max_x/2;
                y=max_y/2+7;
            }

            if((g2==x) && (g1==y) && (fruittime==1))
            {

                mvprintw(y, x, " ");
                g1=10000;
                g2=10000;
                lives++;
                gpos=0;
            }

            g1 = g1 + direction;
            if (food1==1)
                mvprintw(g1-1, g2, ".");
            if (food1==0)
                mvprintw(g1-1, g2, " ");


            if (mvinch(g1,g2)== '.')
                food1=1;
            if (mvinch(g1,g2)== ' ')
                food1=0;
            if (c==1)
                mvprintw(g1 , g2 , ":");
            else
                mvprintw(g1, g2, "{");


        }
        if (direction==0)
            pop1=0;

        test=Check_Crossroad(g1,g2,max_x,max_y);
        if (test==0)
            pop1=0;

        while(hpos==0&&reghost==1)
        {

            h1 = rand() % max_y + 1;
            h2 = rand() % max_x + 1;
            hpos=check_ghost_position(h1,h2,max_x,max_y);
            if (hpos==1)
                break;
        }
        if (pop2==0)
        {
            if (rnd3==1)
            {
                while (1)
                {
                    rnd_2=rand()% 4 + 1 ;
                    if (rnd_2 != 2)
                        break;
                }
            }
            else if (rnd3==2)
            {
                while (1)
                {
                    rnd_2=rand()% 4 + 1 ;
                    if (rnd_2 != 1)
                        break;
                }
            }
            else if (rnd3==3)
            {
                while (1)
                {
                    rnd_2=rand()% 4 + 1 ;
                    if (rnd_2 != 4)
                        break;
                }
            }
            else if (rnd3==4)
            {
                while (1)
                {
                    rnd_2=rand()% 4 + 1 ;
                    if (rnd_2 != 3)
                        break;
                }
            }
            else if (rnd3==0)
                rnd_2=rand()% 4 + 1 ;

        }
        rnd3=rnd_2;

        pop2=1;
        if (rnd_2==1)
        {
            nodelay(stdscr , true);
            direction=1;


            if ( (h2 >= max_x-2) && (h1>=1) && (h1<=15))
                direction=0;

            if ( (h2 >= max_x-2) && (h1>=17) && (h1<=max_y))
                direction=0;

            if((h2==max_x/2-4) && (h1>=1) && (h1<=6))
                direction=0;

            if((h2==max_x/2-23) && (h1>=2) && (h1<=6))
                direction=0;

            if((h2==max_x/2-39) && (h1>=2) && (h1<=6))
                direction=0;

            if((h2==max_x/2+3) && (h1>=2) && (h1<=6))
                direction=0;

            if((h2==max_x/2+23) && (h1>=2) && (h1<=6))
                direction=0;

            if((h2==max_x/2-39) && (h1>=8) && (h1<=9))
                direction=0;

            if((h2==max_x/2+23) && (h1>=8) && (h1<=9))
                direction=0;

            if((h2==max_x/2-16) && (h1>=8) && (h1<=9))
                direction=0;

            if((h2==max_x/2-3) && (h1>=9) && (h1<=12))
                direction=0;

            if((h2==max_x/2-23) && (h1>=8) && (h1<=12))
                direction=0;

            if((h2==max_x/2+3) && (h1>=11) && (h1<=12))
                direction=0;

            if((h2==max_x/2+17) && (h1>=8) && (h1<=10))
                direction=0;

            if((h2==max_x/2+23) && (h1>=11) && (h1<=15))
                direction=0;

            if((h2==max_x/2-23) && (h1>=14) && (h1<=15))
                direction=0;

            if((h2==max_x/2+10) && (h1>=14) && (h1<=15))
                direction=0;

            if((h2==max_x/2-10) && (h1>=14) && (h1<=15))
                direction=0;

            if((h2==max_x/2+23) && (h1>=17) && (h1<=19))
                direction=0;

            if((h2==max_x/2-23) && (h1>=17) && (h1<=19))
                direction=0;

            if((h2==max_x/2-15) && (h1>=20) && (h1<=21))
                direction=0;

            if((h2==max_x/2+10) && (h1>=17) && (h1<=21))
                direction=0;

            if((h2==max_x/2-10) && (h1>=17) && (h1<=21))
                direction=0;

            if((h2==max_x/2+8) && (h1>=17) && (h1<=21))
                direction=0;

            if((h2==max_x/2+1) && (h1==17))
                direction=0;

            if((h2==max_x/2-39) && (h1>=21)&&(h1<=22))
                direction=0;

            if((h2==max_x/2+14) && (h1>=21)&&(h1<=22))
                direction=0;

            if((h2==max_x/2-10) && (h1==23))
                direction=0;

            if((h2==max_x) && (h1==16))
                direction=-max_x;

            if((h2==x) && (h1==y)&&(fruittime==0))
            {

                mvprintw(h1, h2, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((h2==x) && (h1==y) && (fruittime==1))
            {

                mvprintw(y, x, " ");
                h1=10000;
                h2=10000;
                hpos=0;
            }

            h2 = h2 + direction;

            if (food2==1)
                mvprintw(h1, h2-1, ".");
            if (food2==0)
                mvprintw(h1, h2-1, " ");


            if (mvinch(h1,h2)== '.')
                food2=1;
            if (mvinch(h1,h2)== ' ')
                food2=0;

            if (c==1)
                mvprintw(h1 , h2 , ":");
            else
                mvprintw(h1, h2, "{");



        }


        if (rnd_2==2)
        {
            nodelay(stdscr , true);
            direction=-1;

            if ( (h2 == 1) && (h1>=1) && (h1<=15))
                direction=0;

            if ( (h2 == 1) && (h1>=17) && (h1<=max_y))
                direction=0;

            if ((h2==(max_x/2)+3) && (h1>=1) && (h1<=6))
                direction=0;

            if ((h2==(max_x/2)-4) && (h1>=2) && (h1<=6))
                direction=0;

            if ((h2==(max_x/2)-23) && (h1>=2) && (h1<=6))
                direction=0;

            if ((h2==(max_x/2)+23) && (h1>=2) && (h1<=6))
                direction=0;

            if ((h2==(max_x/2)+38) && (h1>=2) && (h1<=6))
                direction=0;

            if ((h2==(max_x/2)-23) && (h1>=8) && (h1<=9))
                direction=0;

            if((h2==max_x/2+38) && (h1>=8) && (h1<=9))
                direction=0;

            if((h2==max_x/2+17) && (h1>=8) && (h1<=9))
                direction=0;

            if((h2==max_x/2+3) && (h1>=10) && (h1<=12))
                direction=0;

            if((h2==max_x/2-3) && (h1>=11) && (h1<=12))
                direction=0;

            if((h2==max_x/2-16) && (h1>=8) && (h1<=10))
                direction=0;

            if((h2==max_x/2+23) && (h1>=8) && (h1<=12))
                direction=0;

            if((h2==max_x/2-23) && (h1>=11) && (h1<=15))
                direction=0;

            if((h2==max_x/2-10) && (h1>=14) && (h1<=15))
                direction=0;

            if((h2==max_x/2+23) && (h1>=14) && (h1<=15))
                direction=0;

            if((h2==max_x/2+10) && (h1>=14) && (h1<=15))
                direction=0;

            if((h2==max_x/2-23) && (h1>=17) && (h1<=19))
                direction=0;

            if((h2==max_x/2+23) && (h1>=17) && (h1<=19))
                direction=0;

            if((h2==max_x/2-10) && (h1>=17) && (h1<=21))
                direction=0;

            if((h2==max_x/2+14) && (h1>=20) && (h1<=21))
                direction=0;

            if((h2==max_x/2+10) && (h1>=17) && (h1<=21))
                direction=0;

            if((h2==max_x/2-8) && (h1>=17) && (h1<=21))
                direction=0;

            if((h2==max_x/2-1) && (h1==17))
                direction=0;

            if((h2==max_x/2-15) && (h1>=21)&&(h1<=22))
                direction=0;

            if((h2==max_x/2+38) && (h1>=21)&&(h1<=22))
                direction=0;

            if((h2==max_x/2+10) && (h1==23))
                direction=0;

            if((h2==0) && (h1==16))
            {
                mvprintw(h1, h2, " ");
                direction=max_x;
            }

            if((h2==x) && (h1==y)&&(fruittime==0))
            {

                mvprintw(h1, h2, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
                hpos=0;
            }

            if((h2==x) && (h1==y) && (fruittime==1))
            {

                mvprintw(y, x, " ");
                h1=10000;
                h2=10000;
            }


            h2 = h2 + direction;

            if (food2==1)
                mvprintw(h1, h2+1, ".");
            if (food2==0)
                mvprintw(h1, h2+1, " ");


            if (mvinch(h1,h2)== '.')
                food2=1;
            if (mvinch(h1,h2)== ' ')
                food2=0;

            if (c==1)
                mvprintw(h1 , h2 , ":");
            else
                mvprintw(h1, h2, "{");


        }

        if (rnd_2==3)
        {
            nodelay(stdscr , true);
            direction=-1;

            if (direction!=0)
                next_y = h1 + direction;

            if (next_y < 1)
                direction=0;


            if ((h1==(max_y/2)-5) &&((h2>=(max_x/2)-3) && (h2 <=
                                     (max_x/2)+2)))
                direction=0;

            if ((h1==(max_y/2)-5) &&((h2>=(max_x/2)-22) && (h2 <=
                                     (max_x/2)-5)))
                direction=0;

            if ((h1==(max_y/2)-5) &&((h2>=(max_x/2)-38) && (h2 <=
                                     (max_x/2)-24)))
                direction=0;

            if ((h1==(max_y/2)-5) &&((h2>=(max_x/2)+4) && (h2 <=
                                     (max_x/2)+22)))
                direction=0;

            if ((h1==(max_y/2)-5) &&((h2>=(max_x/2)+24) && (h2 <=
                                     (max_x/2)+37)))
                direction=0;

            if ((h1==10) &&((h2>=(max_x/2)-38) && (h2 <= (max_x/2)-24)))
                direction=0;

            if ((h1==10) &&((h2>=(max_x/2)+24) && (h2 <= (max_x/2)+37)))
                direction=0;

            if ((h1==10) &&((h2>=(max_x/2)-15) && (h2 <= (max_x/2)+16)))
                direction=0;

            if ((h1==13) &&((h2>=(max_x/2)-2) && (h2 <= (max_x/2)+2)))
                direction=0;

            if ((h1==13) &&((h2>=(max_x/2)-22) && (h2 <= (max_x/2)-4)))
                direction=0;

            if ((h1==13) &&((h2>=(max_x/2)+4) && (h2 <= (max_x/2)+22)))
                direction=0;

            if ((h1==max_y/2+4) &&((h2>=(max_x/2)-39) && (h2 <=
                                   (max_x/2)-24)))
                direction=0;

            if ((h1==max_y/2+4) &&((h2>=(max_x/2)+24) && (h2 <=
                                   (max_x/2)+39)))
                direction=0;

            if ((h1==max_y/2+4) &&((h2>=(max_x/2)-22) && (h2 <=
                                   (max_x/2)-11)))
                direction=0;

            if ((h1==max_y/2+4) &&((h2>=(max_x/2)+11) && (h2 <=
                                   (max_x/2)+22)))
                direction=0;

            if ((h1==16) &&((h2>=(max_x/2)-9) && (h2 <= (max_x/2)+9)))
                direction=0;

            if ((h1==max_y/2+8) &&((h2>=(max_x/2)-39) && (h2 <=
                                   (max_x/2)-24)))
                direction=0;

            if ((h1==max_y/2+8) &&((h2>=(max_x/2)+24) && (h2 <=
                                   (max_x/2)+39)))
                direction=0;

            if ((h1==max_y/2+8) &&((h2>=(max_x/2)-22) && (h2 <=
                                   (max_x/2)-15)))
                direction=0;

            if ((h1==max_y/2+10) &&((h2>=(max_x/2)-14) && (h2 <=
                                    (max_x/2)-11)))
                direction=0;

            if ((h1==max_y/2+10) &&((h2>=(max_x/2)+11) && (h2 <=
                                    (max_x/2)+13)))
                direction=0;

            if ((h1==max_y/2+8) &&((h2>=(max_x/2)+14) && (h2 <=
                                   (max_x/2)+22)))
                direction=0;

            if ((h1==max_y/2+10) &&((h2>=(max_x/2)-9) && (h2 <=
                                    (max_x/2)+9)))
                direction=0;

            if ((h1==max_y/2+6) &&((h2>=(max_x/2)-9) && (h2 <=
                                   (max_x/2)-2)))
                direction=0;

            if ((h1==max_y/2+6) &&((h2>=(max_x/2)+2) && (h2 <=
                                   (max_x/2)+9)))
                direction=0;

            if ((h1==23) &&((h2>=(max_x/2)-38) && (h2 <= (max_x/2)-16)))
                direction=0;

            if ((h1==23) &&((h2>=(max_x/2)+15) && (h2 <= (max_x/2)+37)))
                direction=0;



            if((h2==x) && (h1==y)&&(fruittime==0))
            {

                mvprintw(h1, h2, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((h2==x) && (h1==y) && (fruittime==1))
            {

                mvprintw(y, x, " ");
                h1=10000;
                h2=10000;
                hpos=0;
            }


            h1=h1+direction;

            if (food2==1)
                mvprintw(h1+1, h2, ".");
            if (food2==0)
                mvprintw(h1+1, h2, " ");


            if (mvinch(h1,h2)== '.')
                food2=1;
            if (mvinch(h1,h2)== ' ')
                food2=0;

            if (c==1)
                mvprintw(h1 , h2 , ":");
            else
                mvprintw(h1, h2, "{");



        }

        if (rnd_2==4)
        {
            nodelay(stdscr , true);
            direction=1;

            if (direction!=0)
                next_y = h1 + direction;

            if (next_y >= max_y-1)
                direction=0;

            if ((h1==1) &&((h2>=(max_x/2)-22) && (h2 <= (max_x/2)-5)))
                direction=0;

            if ((h1==1) &&((h2>=(max_x/2)+4) && (h2 <= (max_x/2)+22)))
                direction=0;

            if ((h1==1) &&((h2>=(max_x/2)+24) && (h2 <= (max_x/2)+37)))
                direction=0;

            if ((h1==1) &&((h2>=(max_x/2)-38) && (h2 <= (max_x/2)-24)))
                direction=0;

            if ((h1==7) &&((h2>=(max_x/2)-38) && (h2 <= (max_x/2)-24)))
                direction=0;

            if ((h1==7) &&((h2>=(max_x/2)+24) && (h2 <= (max_x/2)+37)))
                direction=0;

            if ((h1==7) &&((h2>=(max_x/2)-15) && (h2 <= (max_x/2)+16)))
                direction=0;

            if ((h1==10) &&((h2>=(max_x/2)-16) && (h2 <= (max_x/2)-4)))
                direction=0;

            if ((h1==7) &&((h2>=(max_x/2)-22) && (h2 <= (max_x/2)-17)))
                direction=0;

            if ((h1==10) &&((h2>=(max_x/2)+4) && (h2 <= (max_x/2)+17)))
                direction=0;

            if ((h1==7) &&((h2>=(max_x/2)+18) && (h2 <= (max_x/2)+22)))
                direction=0;

            if ((h1==max_y/2-2) &&((h2>=(max_x/2)-39) && (h2 <=
                                   (max_x/2)-24)))
                direction=0;

            if ((h1==max_y/2-2) &&((h2>=(max_x/2)+24) && (h2 <=
                                   (max_x/2)+39)))
                direction=0;

            if ((h1==13) &&((h2>=(max_x/2)-22) && (h2 <= (max_x/2)-11)))
                direction=0;

            if ((h1==13) &&((h2>=(max_x/2)+11) && (h2 <= (max_x/2)+22)))
                direction=0;


            if ((h1==13) &&((h2>=(max_x/2)-9) && (h2 <= (max_x/2)+9)))
                direction=0;

            if ((h1==max_y/2+4) &&((h2>=(max_x/2)-39) && (h2 <=
                                   (max_x/2)-24)))
                direction=0;

            if ((h1==max_y/2+4) &&((h2>=(max_x/2)+24) && (h2 <=
                                   (max_x/2)+39)))
                direction=0;

            if ((h1==max_y/2+4) &&((h2>=(max_x/2)-22) && (h2 <=
                                   (max_x/2)-11)))
                direction=0;

            if ((h1==max_y/2+4) &&((h2>=(max_x/2)+11) && (h2 <=
                                   (max_x/2)+22)))
                direction=0;

            if ((h1==max_y/2+4) &&((h2>=(max_x/2)-9) && (h2 <=
                                   (max_x/2)-2)))
                direction=0;

            if ((h1==max_y/2+4) &&((h2>=(max_x/2)+2) && (h2 <=
                                   (max_x/2)+9)))
                direction=0;

            if ((h1==max_y/2+8) &&((h2>=(max_x/2)-9) && (h2 <=
                                   (max_x/2)+9)))
                direction=0;

            if ((h1==20) &&((h2>=(max_x/2)-38) && (h2 <= (max_x/2)-16)))
                direction=0;

            if ((h1==20) &&((h2>=(max_x/2)+15) && (h2 <= (max_x/2)+37)))
                direction=0;

            if ((h1==22) &&((h2>=(max_x/2)-9) && (h2 <= (max_x/2)+9)))
                direction=0;

            if((h2==x) && (h1==y)&&(fruittime==0))
            {

                mvprintw(h1, h2, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((h2==x) && (h1==y) && (fruittime==1))
            {

                mvprintw(y, x, " ");
                h1=10000;
                h2=10000;
                hpos=0;
            }
            h1 = h1 + direction;

            if (food2==1)
                mvprintw(h1-1, h2, ".");
            if (food2==0)
                mvprintw(h1-1, h2, " ");


            if (mvinch(h1,h2)== '.')
                food2=1;
            if (mvinch(h1,h2)== ' ')
                food2=0;

            if (c==1)
                mvprintw(h1 , h2 , ":");
            else
                mvprintw(h1, h2, "{");


        }


        if (direction==0)
            pop2=0;

        test=Check_Crossroad(h1,h2,max_x,max_y);
        if (test==0)
            pop2=0;

        timer++;

        if (timer==1)
            reghost=0;

        u++;
        z++;
        t++;

        if (fruittime==1)
            fruitcount++;

        if (fruitcount==100)
        {
            fruittime=0;
            fruitcount=0;
            fpos=0;
            ts=0;
            timer=0;
            reghost=1;
        }

        if (c==1)
            mvprintw(y, x, "<");
        else if(fruittime==1 && c==-1)
            mvprintw(y, x, "P");
        else if(c==-1)
            mvprintw(y, x, "O");


        for (i=1; i<=max_x/2-3; i++)
            mvprintw(0,i-1, "=");

        for (i=1; i<=max_x/2-3; i++)
            mvprintw(0,i+max_x/2+2, "=");

        for (i=1; i<=max_x/2-8; i++)
            mvprintw(max_y-1,i-1, "=");

        for (i=1; i<=max_x/2-9; i++)
            mvprintw(max_y-1,i-1+max_x/2+9, "=");

        for (i=1; i<=max_y/2+3; i++)
            mvprintw(i,0, "{");

        for (i=1; i<=max_y/2-5; i++)
            mvprintw(i+max_y/2+4,0, "{");

        for (i=1; i<=max_y/2+3; i++)
            mvprintw(i,max_x-1, "}");

        for (i=1; i<=max_y/2-5; i++)
            mvprintw(i+max_y/2+4,max_x-1, "}");

        for (i=0; i<=6; i++)
            mvprintw(i,max_x/2-3, "|");

        for (i=0; i<=6; i++)
            mvprintw(i,max_x/2+2, "|");

        for (i=1; i<=4; i++)
            mvprintw(max_y/2-6,max_x/2-3+i, "_");

        for (i=1; i<=17; i++)
            mvprintw(max_y/2-6,max_x/2-22+i, "_");

        for (i=1; i<=5; i++)
            mvprintw(i+1,max_x/2-22, "|");

        for (i=1; i<=5; i++)
            mvprintw(i+1,max_x/2-5, "|");

        for (i=1; i<=16; i++)
            mvprintw(2,max_x/2-22+i, "^");

        for (i=1; i<=13; i++)
            mvprintw(max_y/2-6,max_x/2-38+i, "_");

        for (i=1; i<=5; i++)
            mvprintw(i+1,max_x/2-38, "|");

        for (i=1; i<=5; i++)
            mvprintw(i+1,max_x/2-24, "|");

        for (i=1; i<=13; i++)
            mvprintw(2,max_x/2-38+i, "^");

        for (i=1; i<=17; i++)
            mvprintw(max_y/2-6,max_x/2+4+i, "_");

        for (i=1; i<=5; i++)
            mvprintw(i+1,max_x/2+22, "|");

        for (i=1; i<=5; i++)
            mvprintw(i+1,max_x/2+4, "|");

        for (i=1; i<=17; i++)
            mvprintw(2,max_x/2+4+i, "^");

        for (i=1; i<=13; i++)
            mvprintw(max_y/2-6,max_x/2+24+i, "_");

        for (i=1; i<=5; i++)
            mvprintw(i+1,max_x/2+24, "|");

        for (i=1; i<=5; i++)
            mvprintw(i+1,max_x/2+37, "|");

        for (i=1; i<=12; i++)
            mvprintw(2,max_x/2+24+i, "^");

        for (i=1; i<=13; i++)
            mvprintw(max_y/2-3,max_x/2-38+i, "_");

        for (i=1; i<=2; i++)
            mvprintw(i+7,max_x/2-38, "|");

        for (i=1; i<=2; i++)
            mvprintw(i+7,max_x/2-24, "|");

        for (i=1; i<=13; i++)
            mvprintw(max_y/2-4,max_x/2-38+i, "^");

        for (i=1; i<=13; i++)
            mvprintw(max_y/2-3,max_x/2+24+i, "_");

        for (i=1; i<=2; i++)
            mvprintw(i+7,max_x/2+24, "|");

        for (i=1; i<=2; i++)
            mvprintw(i+7,max_x/2+37, "|");

        for (i=1; i<=12; i++)
            mvprintw(max_y/2-4,max_x/2+24+i, "^");

        for (i=1; i<=12; i++)
            mvprintw(max_y/2-3,max_x/2-15+i, "_");

        for (i=1; i<=13; i++)
            mvprintw(max_y/2-3,max_x/2+2+i, "_");

        for (i=1; i<=2; i++)
            mvprintw(i+7,max_x/2-15, "|");

        for (i=1; i<=2; i++)
            mvprintw(i+7,max_x/2+16, "|");

        for (i=1; i<=30; i++)
            mvprintw(max_y/2-4,max_x/2-15+i, "^");

        for (i=1; i<=3; i++)
            mvprintw(i+9,max_x/2-2, "|");

        for (i=1; i<=3; i++)
            mvprintw(i+9,max_x/2+2, "|");

        for (i=1; i<=3; i++)
            mvprintw(12,max_x/2-2+i, "_");


        for (i=1; i<=5; i++)
            mvprintw(i+7,max_x/2-22, "|");

        for (i=1; i<=17; i++)
            mvprintw(12,max_x/2-22+i, "_");

        for (i=1; i<=2; i++)
            mvprintw(13-i,max_x/2-4, "|");

        for (i=1; i<=13; i++)
            mvprintw(11,max_x/2-18+i, "^");

        for (i=1; i<=3; i++)
            mvprintw(11-i,max_x/2-17, "|");

        for (i=1; i<=4; i++)
            mvprintw(8,max_x/2-22+i, "^");

        for (i=1; i<=5; i++)
            mvprintw(i+7,max_x/2+22, "|");

        for (i=1; i<=17; i++)
            mvprintw(12,max_x/2+4+i, "_");

        for (i=1; i<=2; i++)
            mvprintw(13-i,max_x/2+4, "|");

        for (i=1; i<=14; i++)
            mvprintw(11,max_x/2+4+i, "^");

        for (i=1; i<=3; i++)
            mvprintw(11-i,max_x/2+18, "|");

        for (i=1; i<=3; i++)
            mvprintw(8,max_x/2+18+i, "^");

        for (i=1; i<=15; i++)
            mvprintw(max_y/2+3,max_x/2-40+i, "_");

        for (i=1; i<=5; i++)
            mvprintw(i+10,max_x/2-24, "|");

        for (i=1; i<=15; i++)
            mvprintw(max_y/2-1,max_x/2-40+i, "^");

        for (i=1; i<=15; i++)
            mvprintw(max_y/2+3,max_x/2+23+i, "_");

        for (i=1; i<=5; i++)
            mvprintw(i+10,max_x/2+24, "|");

        for (i=1; i<=14; i++)
            mvprintw(max_y/2-1,max_x/2+24+i, "^");

        for (i=1; i<=2; i++)
            mvprintw(i+13,max_x/2-22, "|");

        for (i=1; i<=10; i++)
            mvprintw(max_y/2+3,max_x/2-22+i, "_");

        for (i=1; i<=10; i++)
            mvprintw(14,max_x/2-22+i, "^");

        for (i=1; i<=2; i++)
            mvprintw(i+13,max_x/2-11, "|");

        for (i=1; i<=2; i++)
            mvprintw(i+13,max_x/2+11, "|");

        for (i=1; i<=11; i++)
            mvprintw(max_y/2+3,max_x/2+11+i, "_");

        for (i=1; i<=11; i++)
            mvprintw(14,max_x/2+11+i, "^");

        for (i=1; i<=2; i++)
            mvprintw(i+13,max_x/2+22, "|");

        for (i=1; i<=2; i++)
            mvprintw(i+13,max_x/2+9, "|");

        for (i=1; i<=2; i++)
            mvprintw(i+13,max_x/2-9, "|");

        for (i=1; i<=17; i++)
            mvprintw(14,max_x/2-9+i, "^");

        for (i=1; i<=17; i++)
            mvprintw(15,max_x/2-9+i, "_");

        for (i=1; i<=5; i++)
            mvprintw(i+16,max_x/2-9, "|");

        for (i=1; i<=5; i++)
            mvprintw(i+16,max_x/2+9, "|");

        for (i=1; i<=17; i++)
            mvprintw(21,max_x/2-9+i, "*");

        for (i=1; i<=7; i++)
            mvprintw(17,max_x/2-9+i, "#");

        for (i=1; i<=7; i++)
            mvprintw(17,max_x/2+i+1, "#");

        for (i=1; i<=15; i++)
            mvprintw(max_y/2+7,max_x/2-40+i, "_");

        for (i=1; i<=3; i++)
            mvprintw(i+16,max_x/2-24, "|");

        for (i=1; i<=15; i++)
            mvprintw(max_y/2+5,max_x/2-40+i, "^");

        for (i=1; i<=14; i++)
            mvprintw(max_y/2+7,max_x/2+24+i, "_");

        for (i=1; i<=3; i++)
            mvprintw(i+16,max_x/2+24, "|");

        for (i=1; i<=14; i++)
            mvprintw(max_y/2+5,max_x/2+24+i, "^");

        for (i=1; i<=22; i++)
            mvprintw(max_y/2+10,max_x/2-38+i, "_");

        for (i=1; i<=2; i++)
            mvprintw(i+20,max_x/2-38, "|");

        for (i=1; i<=22; i++)
            mvprintw(max_y/2+9,max_x/2-38+i, "^");

        for (i=1; i<=2; i++)
            mvprintw(i+20,max_x/2-16, "|");

        for (i=1; i<=22; i++)
            mvprintw(max_y/2+10,max_x/2+15+i, "_");

        for (i=1; i<=2; i++)
            mvprintw(i+20,max_x/2+15, "|");

        for (i=1; i<=22; i++)
            mvprintw(max_y/2+9,max_x/2+15+i, "^");

        for (i=1; i<=2; i++)
            mvprintw(i+20,max_x/2+37, "|");

        for (i=1; i<=2; i++)
            mvprintw(i+22,max_x/2-9, "|");

        for (i=1; i<=18; i++)
            mvprintw(max_y/2+11,max_x/2-9+i, "^");

        for (i=1; i<=2; i++)
            mvprintw(i+22,max_x/2+9, "|");

        for (i=1; i<=3; i++)
            mvprintw(i+16,max_x/2-22, "|");

        for (i=1; i<=7; i++)
            mvprintw(max_y/2+7,max_x/2-22+i, "_");

        for (i=1; i<=10; i++)
            mvprintw(max_y/2+5,max_x/2-22+i, "^");

        for (i=1; i<=2; i++)
            mvprintw(i+19,max_x/2-14, "|");

        for (i=1; i<=5; i++)
            mvprintw(i+16,max_x/2-11, "|");

        for (i=1; i<=2; i++)
            mvprintw(21,max_x/2-14+i, "_");

        for (i=1; i<=5; i++)
            mvprintw(i+16,max_x/2+11, "|");

        for (i=1; i<=9; i++)
            mvprintw(max_y/2+7,max_x/2+13+i, "_");

        for (i=1; i<=11; i++)
            mvprintw(max_y/2+5,max_x/2+11+i, "^");

        for (i=1; i<=2; i++)
            mvprintw(i+19,max_x/2+13, "|");

        for (i=1; i<=3; i++)
            mvprintw(i+16,max_x/2+22, "|");

        for (i=1; i<=1; i++)
            mvprintw(21,max_x/2+11+i, "_");


        refresh();
        usleep(DELAY);

        ch=getch();
        if (ch == KEY_RIGHT)
        {
            l=0;
            r=1;
            d=1;
            e=1;
        }

        if (ch == KEY_LEFT)
        {
            r=0;
            l=1;
            d=1;
            e=1;
        }

        if (ch == KEY_UP)
        {
            r=1;
            l=1;
            d=0;
            e=1;
        }

        if (ch == KEY_DOWN)
        {
            r=1;
            l=1;
            d=1;
            e=0;
        }
        if (l==0&&r==1&&d==1&&e==1)
        {
            nodelay(stdscr , true);
            direction=1;


            if ( (x >= max_x-2) && (y>=1) && (y<=15))
                direction=0;

            if ( (x >= max_x-2) && (y>=17) && (y<=max_y))
                direction=0;

            if((x==max_x/2-4) && (y>=1) && (y<=6))
                direction=0;

            if((x==max_x/2-23) && (y>=2) && (y<=6))
                direction=0;

            if((x==max_x/2-39) && (y>=2) && (y<=6))
                direction=0;

            if((x==max_x/2+3) && (y>=2) && (y<=6))
                direction=0;

            if((x==max_x/2+23) && (y>=2) && (y<=6))
                direction=0;

            if((x==max_x/2-39) && (y>=8) && (y<=9))
                direction=0;

            if((x==max_x/2+23) && (y>=8) && (y<=9))
                direction=0;

            if((x==max_x/2-16) && (y>=8) && (y<=9))
                direction=0;

            if((x==max_x/2-3) && (y>=9) && (y<=12))
                direction=0;

            if((x==max_x/2-23) && (y>=8) && (y<=12))
                direction=0;

            if((x==max_x/2+3) && (y>=11) && (y<=12))
                direction=0;

            if((x==max_x/2+17) && (y>=8) && (y<=10))
                direction=0;

            if((x==max_x/2+23) && (y>=11) && (y<=15))
                direction=0;

            if((x==max_x/2-23) && (y>=14) && (y<=15))
                direction=0;

            if((x==max_x/2+10) && (y>=14) && (y<=15))
                direction=0;

            if((x==max_x/2-10) && (y>=14) && (y<=15))
                direction=0;

            if((x==max_x/2+23) && (y>=17) && (y<=19))
                direction=0;

            if((x==max_x/2-23) && (y>=17) && (y<=19))
                direction=0;

            if((x==max_x/2-15) && (y>=20) && (y<=21))
                direction=0;

            if((x==max_x/2+10) && (y>=17) && (y<=21))
                direction=0;

            if((x==max_x/2-10) && (y>=17) && (y<=21))
                direction=0;

            if((x==max_x/2+8) && (y>=17) && (y<=21))
                direction=0;

            if((x==max_x/2+1) && (y==17))
                direction=0;

            if((x==max_x/2-39) && (y>=21)&&(y<=22))
                direction=0;

            if((x==max_x/2+14) && (y>=21)&&(y<=22))
                direction=0;

            if((x==max_x/2-10) && (y==23))
                direction=0;

            if((x==max_x) && (y==16))
                direction=-max_x;



            if((x==v2) && (y==v1) && (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((x==g2) && (y==g1)&& (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((x==h2) && (y==h1) && (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((x==v2) && (y==v1) && (fruittime==1))
            {
                v2=100000;
                v1=100000;
                vpos=0;
            }
            if((x==g2) && (y==g1) && (fruittime==1))
            {
                g2=100000;
                g1=100000;
                gpos=0;
            }

            if((x==h2) && (y==h1) && (fruittime==1))
            {
                h2=100000;
                h1=100000;
                hpos=0;
            }
            if((x==f2) && (y==f1))
            {
                mvprintw(y, x, " ");
                fruittime=1;
                f1=10000;
                f2=10000;
            }

            x = x + direction;

            mvprintw(y, x-1, " ");

        }

        else if (l==1&&r==0&&d==1&&e==1)
        {
            nodelay(stdscr , true);
            direction=-1;

            if ( (x == 1) && (y>=1) && (y<=15))
                direction=0;

            if ( (x == 1) && (y>=17) && (y<=max_y))
                direction=0;

            if ((x==(max_x/2)+3) && (y>=1) && (y<=6))
                direction=0;

            if ((x==(max_x/2)-4) && (y>=2) && (y<=6))
                direction=0;

            if ((x==(max_x/2)-23) && (y>=2) && (y<=6))
                direction=0;

            if ((x==(max_x/2)+23) && (y>=2) && (y<=6))
                direction=0;

            if ((x==(max_x/2)+38) && (y>=2) && (y<=6))
                direction=0;

            if ((x==(max_x/2)-23) && (y>=8) && (y<=9))
                direction=0;

            if((x==max_x/2+38) && (y>=8) && (y<=9))
                direction=0;

            if((x==max_x/2+17) && (y>=8) && (y<=9))
                direction=0;

            if((x==max_x/2+3) && (y>=10) && (y<=12))
                direction=0;

            if((x==max_x/2-3) && (y>=11) && (y<=12))
                direction=0;

            if((x==max_x/2-16) && (y>=8) && (y<=10))
                direction=0;

            if((x==max_x/2+23) && (y>=8) && (y<=12))
                direction=0;

            if((x==max_x/2-23) && (y>=11) && (y<=15))
                direction=0;

            if((x==max_x/2-10) && (y>=14) && (y<=15))
                direction=0;

            if((x==max_x/2+23) && (y>=14) && (y<=15))
                direction=0;

            if((x==max_x/2+10) && (y>=14) && (y<=15))
                direction=0;

            if((x==max_x/2-23) && (y>=17) && (y<=19))
                direction=0;

            if((x==max_x/2+23) && (y>=17) && (y<=19))
                direction=0;

            if((x==max_x/2-10) && (y>=17) && (y<=21))
                direction=0;

            if((x==max_x/2+14) && (y>=20) && (y<=21))
                direction=0;

            if((x==max_x/2+10) && (y>=17) && (y<=21))
                direction=0;

            if((x==max_x/2-8) && (y>=17) && (y<=21))
                direction=0;

            if((x==max_x/2-1) && (y==17))
                direction=0;

            if((x==max_x/2-15) && (y>=21)&&(y<=22))
                direction=0;

            if((x==max_x/2+38) && (y>=21)&&(y<=22))
                direction=0;

            if((x==max_x/2+10) && (y==23))
                direction=0;

            if((x==0) && (y==16))
            {
                mvprintw(y, x, " ");
                direction=max_x;
            }

            if((x==v2) && (y==v1) && (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((x==g2) && (y==g1)&& (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((x==h2) && (y==h1) && (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((x==v2) && (y==v1) && (fruittime==1))
            {
                v2=100000;
                v1=100000;
                vpos=0;
            }
            if((x==g2) && (y==g1) && (fruittime==1))
            {
                g2=100000;
                g1=100000;
                gpos=0;
            }

            if((x==h2) && (y==h1) && (fruittime==1))
            {
                h2=100000;
                h1=100000;
                hpos=0;
            }
            if((x==f2) && (y==f1))
            {
                mvprintw(y, x, " ");
                fruittime=1;
                f1=10000;
                f2=10000;
            }


            x = x + direction;
            mvprintw(y, x+1, " ");
        }

        else if (l==1&&r==1&&d==0&&e==1)
        {
            nodelay(stdscr , true);
            direction=-1;

            if (direction!=0)
                next_y = y + direction;

            if (next_y < 1)
                direction=0;


            if ((y==(max_y/2)-5) &&((x>=(max_x/2)-3) && (x <=
                                    (max_x/2)+2)))
                direction=0;

            if ((y==(max_y/2)-5) &&((x>=(max_x/2)-22) && (x <=
                                    (max_x/2)-5)))
                direction=0;

            if ((y==(max_y/2)-5) &&((x>=(max_x/2)-38) && (x <=
                                    (max_x/2)-24)))
                direction=0;

            if ((y==(max_y/2)-5) &&((x>=(max_x/2)+4) && (x <=
                                    (max_x/2)+22)))
                direction=0;

            if ((y==(max_y/2)-5) &&((x>=(max_x/2)+24) && (x <=
                                    (max_x/2)+37)))
                direction=0;

            if ((y==10) &&((x>=(max_x/2)-38) && (x <= (max_x/2)-24)))
                direction=0;

            if ((y==10) &&((x>=(max_x/2)+24) && (x <= (max_x/2)+37)))
                direction=0;

            if ((y==10) &&((x>=(max_x/2)-15) && (x <= (max_x/2)+16)))
                direction=0;

            if ((y==13) &&((x>=(max_x/2)-2) && (x <= (max_x/2)+2)))
                direction=0;

            if ((y==13) &&((x>=(max_x/2)-22) && (x <= (max_x/2)-4)))
                direction=0;

            if ((y==13) &&((x>=(max_x/2)+4) && (x <= (max_x/2)+22)))
                direction=0;

            if ((y==max_y/2+4) &&((x>=(max_x/2)-39) && (x <=
                                  (max_x/2)-24)))
                direction=0;

            if ((y==max_y/2+4) &&((x>=(max_x/2)+24) && (x <=
                                  (max_x/2)+39)))
                direction=0;

            if ((y==max_y/2+4) &&((x>=(max_x/2)-22) && (x <=
                                  (max_x/2)-11)))
                direction=0;

            if ((y==max_y/2+4) &&((x>=(max_x/2)+11) && (x <=
                                  (max_x/2)+22)))
                direction=0;

            if ((y==16) &&((x>=(max_x/2)-9) && (x <= (max_x/2)+9)))
                direction=0;

            if ((y==max_y/2+8) &&((x>=(max_x/2)-39) && (x <=
                                  (max_x/2)-24)))
                direction=0;

            if ((y==max_y/2+8) &&((x>=(max_x/2)+24) && (x <=
                                  (max_x/2)+39)))
                direction=0;

            if ((y==max_y/2+8) &&((x>=(max_x/2)-22) && (x <=
                                  (max_x/2)-15)))
                direction=0;

            if ((y==max_y/2+10) &&((x>=(max_x/2)-14) && (x <=
                                   (max_x/2)-11)))
                direction=0;

            if ((y==max_y/2+10) &&((x>=(max_x/2)+11) && (x <=
                                   (max_x/2)+13)))
                direction=0;

            if ((y==max_y/2+8) &&((x>=(max_x/2)+14) && (x <=
                                  (max_x/2)+22)))
                direction=0;

            if ((y==max_y/2+10) &&((x>=(max_x/2)-9) && (x <=
                                   (max_x/2)+9)))
                direction=0;

            if ((y==max_y/2+6) &&((x>=(max_x/2)-9) && (x <=
                                  (max_x/2)-2)))
                direction=0;

            if ((y==max_y/2+6) &&((x>=(max_x/2)+2) && (x <=
                                  (max_x/2)+9)))
                direction=0;

            if ((y==23) &&((x>=(max_x/2)-38) && (x <= (max_x/2)-16)))
                direction=0;

            if ((y==23) &&((x>=(max_x/2)+15) && (x <= (max_x/2)+37)))
                direction=0;

            if((x==v2) && (y==v1) && (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((x==g2) && (y==g1)&& (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;

            }

            if((x==h2) && (y==h1) && (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((x==v2) && (y==v1) && (fruittime==1))
            {
                v2=100000;
                v1=100000;
                vpos=0;
            }
            if((x==g2) && (y==g1) && (fruittime==1))
            {
                g2=100000;
                g1=100000;
                gpos=0;
            }

            if((x==h2) && (y==h1) && (fruittime==1))
            {
                h2=100000;
                h1=100000;
                hpos=0;
            }
            if((x==f2) && (y==f1))
            {
                mvprintw(y, x, " ");
                fruittime=1;
                f1=10000;
                f2=10000;
            }


            y=y+direction;

            mvprintw(y+1, x, " ");


        }

        else if (l==1&&r==1&&d==1&&e==0)
        {
            nodelay(stdscr , true);
            direction=1;

            if (direction!=0)
                next_y = y + direction;

            if (next_y >= max_y-1)
                direction=0;

            if ((y==1) &&((x>=(max_x/2)-22) && (x <= (max_x/2)-5)))
                direction=0;

            if ((y==1) &&((x>=(max_x/2)+4) && (x <= (max_x/2)+22)))
                direction=0;

            if ((y==1) &&((x>=(max_x/2)+24) && (x <= (max_x/2)+37)))
                direction=0;

            if ((y==1) &&((x>=(max_x/2)-38) && (x <= (max_x/2)-24)))
                direction=0;

            if ((y==7) &&((x>=(max_x/2)-38) && (x <= (max_x/2)-24)))
                direction=0;

            if ((y==7) &&((x>=(max_x/2)+24) && (x <= (max_x/2)+37)))
                direction=0;

            if ((y==7) &&((x>=(max_x/2)-15) && (x <= (max_x/2)+16)))
                direction=0;

            if ((y==10) &&((x>=(max_x/2)-16) && (x <= (max_x/2)-4)))
                direction=0;

            if ((y==7) &&((x>=(max_x/2)-22) && (x <= (max_x/2)-17)))
                direction=0;

            if ((y==10) &&((x>=(max_x/2)+4) && (x <= (max_x/2)+17)))
                direction=0;

            if ((y==7) &&((x>=(max_x/2)+18) && (x <= (max_x/2)+22)))
                direction=0;

            if ((y==max_y/2-2) &&((x>=(max_x/2)-39) && (x <=
                                  (max_x/2)-24)))
                direction=0;

            if ((y==max_y/2-2) &&((x>=(max_x/2)+24) && (x <=
                                  (max_x/2)+39)))
                direction=0;

            if ((y==13) &&((x>=(max_x/2)-22) && (x <= (max_x/2)-11)))
                direction=0;

            if ((y==13) &&((x>=(max_x/2)+11) && (x <= (max_x/2)+22)))
                direction=0;


            if ((y==13) &&((x>=(max_x/2)-9) && (x <= (max_x/2)+9)))
                direction=0;

            if ((y==max_y/2+4) &&((x>=(max_x/2)-39) && (x <=
                                  (max_x/2)-24)))
                direction=0;

            if ((y==max_y/2+4) &&((x>=(max_x/2)+24) && (x <=
                                  (max_x/2)+39)))
                direction=0;

            if ((y==max_y/2+4) &&((x>=(max_x/2)-22) && (x <=
                                  (max_x/2)-11)))
                direction=0;

            if ((y==max_y/2+4) &&((x>=(max_x/2)+11) && (x <=
                                  (max_x/2)+22)))
                direction=0;

            if ((y==max_y/2+4) &&((x>=(max_x/2)-9) && (x <=
                                  (max_x/2)-2)))
                direction=0;

            if ((y==max_y/2+4) &&((x>=(max_x/2)+2) && (x <=
                                  (max_x/2)+9)))
                direction=0;

            if ((y==max_y/2+8) &&((x>=(max_x/2)-9) && (x <=
                                  (max_x/2)+9)))
                direction=0;

            if ((y==20) &&((x>=(max_x/2)-38) && (x <= (max_x/2)-16)))
                direction=0;

            if ((y==20) &&((x>=(max_x/2)+15) && (x <= (max_x/2)+37)))
                direction=0;

            if ((y==22) &&((x>=(max_x/2)-9) && (x <= (max_x/2)+9)))
                direction=0;

            if((x==v2) && (y==v1) && (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((x==g2) && (y==g1)&& (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((x==h2) && (y==h1) && (fruittime==0))
            {

                mvprintw(y, x, " ");
                x=max_x/2;
                y=max_y/2+7;
                lives++;
            }

            if((x==v2) && (y==v1) && (fruittime==1))
            {
                v2=100000;
                v1=100000;
                vpos=0;
            }
            if((x==g2) && (y==g1) && (fruittime==1))
            {
                g2=100000;
                g1=100000;
                gpos=0;
            }

            if((x==h2) && (y==h1) && (fruittime==1))
            {
                h2=100000;
                h1=100000;
                hpos=0;
            }
            if((x==f2) && (y==f1))
            {
                mvprintw(y, x, " ");
                fruittime=1;
                f1=10000;
                f2=10000;
            }


            y = y + direction;
            mvprintw(y-1, x, " ");

        }

        c=-c;
    }
    cin.get();
    endwin();
}


int check_ghost_position(int r , int s , int xmax, int ymax)
{
    int i=0;
    int res=0;

    for (i=1; i<=100; i++)
    {
        if (r==ymax/2-5 && s==i)
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=37; i++)
    {
        if ((r==1 && s==i)||(r==1 && s==i+41) )
        {
            res=1;
            return res;
        }
    }

    for (i=1; i<=18; i++)
    {
        if (r==ymax/2-2 && s==i )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=16; i++)
    {
        if (r==ymax/2-2 && s==i+22 )
        {
            res=1;
            return res;
        }
    }
    for (i=17; i<=33; i++)
    {
        if (r==ymax/2-2 && s==i+25)
        {
            res=1;
            return res;
        }
    }
    for (i=34; i<=50; i++)
    {
        if (r==ymax/2-2 && s==i+29 )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=48; i++)
    {
        if (r==ymax/2+1 && s==i+16 )
        {
            res=1;
            return res;
        }
    }
    for (i=0; i<=100; i++)
    {
        if (r==ymax/2+4 && s==i )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=25; i++)
    {
        if ((r==ymax/2+8 && (s==i||s==30||s==50) ))
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=25; i++)
    {
        if (r==ymax/2+8 && s==53+i )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=40; i++)
    {
        if (r==23 && s==i )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=40; i++)
    {
        if (r==23 && s==i+49 )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=34; i++)
    {
        if (r==22 && s==i+20 )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=10; i++)
    {
        if (r==i && s==1 )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=10; i++)
    {
        if (r==i && s==xmax-2 )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=20; i++)
    {
        if (r==i && s==17 )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=20; i++)
    {
        if (r==i && s==xmax-17 )
        {
            res=1;
            return res;
        }
    }
    for (i=20; i<=22; i++)
    {
        if (r==i && s==1 )
        {
            res=1;
            return res;
        }
    }
    for (i=20; i<=22; i++)
    {
        if (r==i && s==xmax-2 )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=8; i++)
    {
        if (r==i && s==xmax/2-4 )
        {
            res=1;
            return res;
        }
    }
    for (i=10; i<=12; i++)
    {
        if (r==i && s==xmax/2-3 )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=8; i++)
    {
        if (r==i && s==xmax/2+3 )
        {
            res=1;
            return res;
        }
    }
    for (i=10; i<=12; i++)
    {
        if (r==i && s==xmax/2+3 )
        {
            res=1;
            return res;
        }
    }
    for (i=7; i<=9; i++)
    {
        if ((r==i && s==xmax/2-16)||(r==21 && xmax/2-16))
        {
            res=1;
            return res;
        }
    }
    for (i=7; i<=9; i++)
    {
        if ((r==i && s==xmax/2+17)||(r==21 && s==xmax/2+14) )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=8; i++)
    {
        if (r==ymax/2+1+i && s==xmax/2-10 )
        {
            res=1;
            return res;
        }
    }
    for (i=1; i<=8; i++)
    {
        if (r==ymax/2+1+i && s==xmax/2+10 )
        {
            res=1;
            return res;
        }

        return res;
    }

}

int Check_Crossroad(int r , int s , int xmax, int ymax)
{
    int ty=0;
    if(r==ymax/2-2 && s==17)
        return ty;

    if(r==ymax/2-2 && s== 34+29)
        return ty;

    if(r==ymax/2+1 && s== 17)
        return ty;

    if(r==ymax/2-2 && s== 47+16)
        return ty;

    if(r==ymax/2-2 && s== 17)
        return ty;

    if(r==ymax/2+9 && s== 30)
        return ty;

    if(r==ymax/2+9 && s== 50)
        return ty;

    if(r==1 && s== 17)
        return ty;

    if(r==7 && s== 17)
        return ty;

    if(r==13 && s== 17)
        return ty;

    if(r==16 && s== 17)
        return ty;

    if(r==7 && s== xmax/2-4)
        return ty;

    if(r==13 && s== xmax/2-3)
        return ty;

    if(r==7 && s==xmax/2+3)
        return ty;

    if(r==13 && s== xmax/2+3)
        return ty;

    if(r==7 && s== xmax/2-16)
        return ty;

    if(r==7 && s== xmax/2+17)
        return ty;

    if(r==ymax/2+4 && s== xmax/2-10)
        return ty;

    if(r==ymax/2+4 && s== xmax/2+10)
        return ty;

    if(r==1 && s== xmax-17)
        return ty;

    if(r==7 && s== xmax-17)
        return ty;

    if(r==10 && s== xmax-17)
        return ty;

    if(r==13 && s== xmax-17)
        return ty;

    if(r==16 && s== xmax-17)
        return ty;

    if(r==20 && s== xmax-17)
        return ty;

    if(r==20 && s== 17)
        return ty;
    if(r==7 && s==1)
        return ty;

    if(r==7 && s== xmax-2)
        return ty;

    if(r==23 && s==25)
        return ty;

    if(r==23 && s==54)
        return ty;

    ty=1;
    return ty;
}

int Game_Over(int xmax, int ymax)
{
    int i=1;
    int ch=1;

    vector <int> v;

    for (i=0; i<=79; i++)
    {
        if (mvinch(ymax/2+4,i) == ' ')
            v.push_back(1);
        else
            v.push_back(0);


        if( i==1&&i<=78)
        {
            if (mvinch(ymax/2-5,i) == ' ')
                v.push_back(1);
            else
                v.push_back(0);

        }

        if(i==1&&i<=36)
        {
            if(mvinch(1,i) == ' ')
                v.push_back(1);
            else
                v.push_back(0);
            if(mvinch(1,i+42)== ' ')
                v.push_back(1);
            else
                v.push_back(0);

        }



        if(i==1&&i<=16)
        {
            if(mvinch(ymax/2-2,i) == ' ')
                v.push_back(1);
            else
                v.push_back(0);


        }
        if(i==2&&i<=15)
        {
            if(mvinch(ymax/2-2,i+22) == ' ')
                v.push_back(1);
            else
                v.push_back(0);


        }

        if (i==18 && i<=32)
        {
            if (mvinch(ymax/2-2,i+25) ==' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==35&& i<=50)
        {
            if (mvinch(ymax/2-2,i+28) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }


        if(i==1&& i<=47)
        {
            if (mvinch(ymax/2+1,i+16) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==0&& i<=79)
        {
            if (mvinch(ymax/2+4,i) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==5&& i<=34)
        {
            if (mvinch(22,i+20) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==1&& i<=10)
        {
            if (mvinch(i,1) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==1&& i<=10)
        {
            if (mvinch(i,xmax-2) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==1&& i<=20)
        {
            if (mvinch(i,17) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==1&& i<=20)
        {
            if (mvinch(i,xmax-17) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==20&& i<=22)
        {
            if (mvinch(i,1) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==20&& i<=22)
        {
            if (mvinch(i,xmax-2) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }

        if(i==1&& i<=7)
        {
            if (mvinch(i,xmax/2-4) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==10&& i<=12)
        {
            if (mvinch(i,xmax/2-3) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==1&& i<=7)
        {
            if (mvinch(i,xmax/2+3) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==10&& i<=12)
        {
            if (mvinch(i,xmax/2+3) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==7&& i<=9)
        {
            if (mvinch(i,xmax/2-16) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
            if (mvinch(21,xmax/2-15) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==7&& i<=9)
        {
            if (mvinch(i,xmax/2+17) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
            if (mvinch(21,xmax/2+14) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==1&& i<=8)
        {
            if (mvinch(ymax/2+1+i,xmax/2-10) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }
        if(i==1&& i<=8)
        {
            if (mvinch(ymax/2+1+i,xmax/2+10) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }


        if (i==1 && i<=25)
        {
            if (mvinch(ymax/2+8,i) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
            if (mvinch(ymax/2+8,30) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);

            if (mvinch(ymax/2+8,50) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }

        if (i==1 && i<=25)
        {
            if (mvinch(ymax/2+8,53+i) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }

        if (i==1 && i<=30)
        {
            if (mvinch(23,i) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }

        if (i==1 && i<=29)
        {
            if (mvinch(23,i+49) == ' ')
                v.push_back(1) ;
            else
                v.push_back(0);
        }


    }

    for(i=1; i<v.size(); i++)
    {

        if (v[i]==0 || v[i-1]==0)
        {
            ch=0;
            break;
        }
        else
            ch=1;
    }


    if (ch==1)
        return 50;
}



