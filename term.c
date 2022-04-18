#include <curses.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void die();
int main(void){
	WINDOW *win;
	char c;
	char *mes1 = "Hello!!";
	char *mes2 = "Hit Spacebar";
	initscr();
	signal(SIGINT, die);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	noecho();
	cbreak();

	win = newwin(7, strlen(mes2) + 6, (LINES - 7)/2, (COLS - (strlen(mes2) + 6) )/2);
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLUE);
	init_pair(2, COLOR_WHITE, COLOR_BLUE);
	wbkgd(win, COLOR_PAIR(1));
	wattron(win, COLOR_PAIR(2));
	box(win, 0, 0);
	wmove(win, 2, 3);
	waddstr(win, mes1);
	wmove(win, 4, 3);
	waddstr(win, mes2);
	wrefresh(win);

	while((c = wgetch(win)) != ' ');
	clear();
	endwin();
	exit(0);
	return 0;
}

void die(void)
{
	clear();
	endwin();
	printf("Ctrl+C Termination.");
	sleep(3);
	exit(0);
}
