#include <stdlib.h>
#include <string.h>

#include <ncurses.h>
#include <menu.h>

#define COLOR_FILL_DEFAULT 1
#define COLOR_FILL_PERIL   2
#define COLOR_BG_DEFAULT   3
#define COLOR_BG_PERIL     4

typedef struct {
	WINDOW *win;
	int content_width;
} HealthBar;

HealthBar* health_bar_new(const char *name, int x, int y, int width) {
	HealthBar* bar = (HealthBar*) malloc(sizeof(HealthBar));

	bar->win = newwin(3, width, x, y);
	bar->content_width = width - 2;
	box(bar->win, 0, 0);
	mvwaddstr(bar->win, 0, 1, name);
	wrefresh(bar->win);

	return bar;
}

void health_bar_update(HealthBar *bar, unsigned int health) {
	int fill;
	int bg;
	int bar_width = (int) ((float) health / 100 * bar->content_width);
	char s[bar->content_width + 1];

	sprintf(s, "%*d%%%*s",
		bar->content_width / 2 + 1, health,
		bar->content_width - bar->content_width / 2 - 2, ""
	);

	if (health < 20) {
		fill = COLOR_PAIR(COLOR_FILL_PERIL);
		bg   = COLOR_PAIR(COLOR_BG_PERIL);
	} else {
		fill = COLOR_PAIR(COLOR_FILL_DEFAULT);
		bg   = COLOR_PAIR(COLOR_BG_DEFAULT);
	}

	wmove(bar->win, 1, 1);
	wattron(bar->win, fill);
	waddnstr(bar->win, s, bar_width);
	wattroff(bar->win, fill);
	wattron(bar->win, bg);
	waddstr(bar->win, &s[bar_width]);
	wattroff(bar->win, bg);
	wrefresh(bar->win);
}

void health_bar_destroy(HealthBar *bar) {
	delwin(bar->win);
	free(bar);
}

typedef struct {
	MENU *menu;
	ITEM **items;
	WINDOW *win;
} Menu;

Menu* menu_new() {
	Menu* menu = (Menu*) malloc(sizeof(Menu));

	menu->items = (ITEM**) calloc(4, sizeof(ITEM*));
	menu->items[0] = new_item("Foo", NULL);
	menu->items[1] = new_item("Bar", NULL);
	menu->items[2] = new_item("Baz", NULL);
	menu->items[3] = NULL;

	menu->menu = new_menu(menu->items);
	menu->win = newwin(10, 40, LINES - 10, COLS - 40);

	set_menu_win(menu->menu, menu->win);
	set_menu_sub(menu->menu, derwin(menu->win, 8, 38, 1, 1));
	set_menu_mark(menu->menu, NULL);

	box(menu->win, 0, 0);
	post_menu(menu->menu);
	wrefresh(menu->win);
	
	return menu;
};

void menu_destroy(Menu *menu) {
	ITEM** items;

	for (items = menu->items; *items != NULL; items++)
		free_item(*items);

	free(menu->items);
	free_menu(menu->menu);
	delwin(menu->win);
	free(menu);

}

void draw(HealthBar **you, HealthBar **opponent, Menu **menu) {
	int width = COLS / 2 - 1;

	*you = health_bar_new("You", 0, 0, width);
	*opponent = health_bar_new("Opponent", 0, COLS - width, width);
	*menu = menu_new();
}


int main(int argc, char *argv[]) {
	HealthBar *you;
	HealthBar *opponent;
	Menu *menu;
	int ch;

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);

	start_color();
	init_pair(COLOR_FILL_DEFAULT, COLOR_BLACK, COLOR_WHITE);
	init_pair(COLOR_FILL_PERIL,   COLOR_BLACK, COLOR_RED);
	init_pair(COLOR_BG_DEFAULT,   COLOR_WHITE, COLOR_BLACK);
	init_pair(COLOR_BG_PERIL,     COLOR_RED,   COLOR_BLACK);

	refresh();

	draw(&you, &opponent, &menu);

	while (true) {
		switch (ch = getch()) {
			case KEY_UP:
				menu_driver(menu->menu, REQ_UP_ITEM);
				wrefresh(menu->win);
				break;
			case KEY_DOWN:
				menu_driver(menu->menu, REQ_DOWN_ITEM);
				wrefresh(menu->win);
				break;
			case KEY_RESIZE:
				health_bar_destroy(you);
				health_bar_destroy(opponent);
				menu_destroy(menu);

				erase();
				refresh();
			
				draw(&you, &opponent, &menu);
				break;
		}

	//	mvprintw(0, 0, "%d, %d\n", ch, KEY_DOWN);

		health_bar_update(you, random() % 101);
		health_bar_update(opponent, random() % 101);
	}


	health_bar_destroy(you);
	health_bar_destroy(opponent);

	getch();	
	endwin();

	return 0;
}
