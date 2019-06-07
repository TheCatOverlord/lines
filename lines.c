#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#define DELAY 10000 /*sleep time in microseconds*/

int main()
{
	int x = 0, y = 0;
	int max_y = 0, max_x =0;
	int direction = 0;
	initscr();    /*initalize curses*/
	noecho();     /*dont echo key input into terminal*/
	curs_set(FALSE);
	srand(time(NULL)); /*start random thingy*/
	getmaxyx(stdscr,max_y,max_x); /*grab the size of the screen*/
	while(1)
	{
		direction = rand() %2; /*decide which direction to draw the line*/
		if(direction == 0) /*if the direction is 0 draw the line vertical*/
		{
			y = 0; /*make sure y is 0*/
			x = rand() % max_x; /*generate a random value for x */
			while(y < max_y) 
			{
				mvprintw(0,0,"Y:%d,X:%d,maxY:%d,maxX:%d,Direction:%d",y,x,max_y,max_x,direction); /*print the varibles in the left top corner (not needed but was there for testing)*/
				mvprintw(y,x,"|#|"); /*print part of the line to stdscr*/
				y++; /*add to y*/
				refresh(); /*print stdscr to the screen*/
				usleep(DELAY); /*zzz*/
			}
		}
		else /*if direction is 1 (or anything else) draw the line horiziontal*/
		{
			x = 0; /*make sure x is 0*/
			y = rand() % max_y; /*generate a random value for y*/
			while(x<max_x)
			{
				mvprintw(0,0,"Y:%d,X:%d,maxY:%d,maxX:%d,Direction:%d",y,x,max_y,max_x,direction); /*print the varibles int he left top corner*/
				mvprintw(y,x,"-"); /*print top part of line segment to stdscr*/
				mvprintw(y-1,x,"#"); /*print middle part of line segment to stdscr*/
				mvprintw(y-2,x,"-"); /*print bottom part of the line segment to stdscr*/
				x++; /*add to x*/
				refresh(); /*print stdscr to the screen*/
				usleep(DELAY); /*WHERES MY BED*/
			}
		}
	}
	endwin(); /*end curses*/
	return 0; /*exit program*/
}
/*meow im a cat*/
