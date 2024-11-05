#include "Draw.h"

void draw_map(int level)
{
	ALLEGRO_BITMAP* box = al_load_bitmap("images/sokoban_box.png");
	ALLEGRO_BITMAP* box_in_place = al_load_bitmap("images/sokoban_box_in_place.png");
	ALLEGRO_BITMAP* marker = al_load_bitmap("images/sokoban_marker.png");
	ALLEGRO_BITMAP* brickwall = al_load_bitmap("images/sokoban_brickwall.png");
	ALLEGRO_BITMAP* up_down_arrow = al_load_bitmap("images/up_down_arrow.png");
	ALLEGRO_BITMAP* left_right_arrow = al_load_bitmap("images/left_right_arrow.png");
	ALLEGRO_BITMAP* restart_arrow = al_load_bitmap("images/restart_arrow.png");
	ALLEGRO_BITMAP* R_button = al_load_bitmap("images/R_button.png");

	ALLEGRO_BITMAP* player;
	switch (level)
	{
	case 0:
	case 1:
		player = al_load_bitmap("images/player_red.png");
		break;
	case 2:
		player = al_load_bitmap("images/player_yellow.png");
		break;
	case 3:
		player = al_load_bitmap("images/player_green.png");
		break;
	case 4:
		player = al_load_bitmap("images/player_blue.png");
		break;
	default:
		player = al_load_bitmap("images/player_white.png");
		break;
	}


	int row = 0, col = -1;
	for (int i = 0; i < (MAP_WIDTH + 1) * MAP_HEIGHT;i++)
	{
		col++;
		char c = map[i];
		if (c == '\n') row++, col = -1;
		else if (c == 'B') al_draw_bitmap(box, col * IMAGE_SIZE, row * IMAGE_SIZE, NULL);
		else if (c == 'O') al_draw_bitmap(box_in_place, col * IMAGE_SIZE, row * IMAGE_SIZE, NULL);
		else if (c == '@') al_draw_bitmap(player, col * IMAGE_SIZE, row * IMAGE_SIZE, NULL);
		else if (c == 'x') al_draw_bitmap(marker, col * IMAGE_SIZE, row * IMAGE_SIZE, NULL);
		else if (c == '#') al_draw_bitmap(brickwall, col * IMAGE_SIZE, row * IMAGE_SIZE, NULL);
		else if (c == 'w') al_draw_bitmap(up_down_arrow, col * IMAGE_SIZE, row * IMAGE_SIZE, NULL);
		else if (c == 's') al_draw_bitmap(up_down_arrow, col * IMAGE_SIZE, row * IMAGE_SIZE, ALLEGRO_FLIP_VERTICAL);
		else if (c == 'a') al_draw_bitmap(left_right_arrow, col * IMAGE_SIZE, row * IMAGE_SIZE, NULL);
		else if (c == 'd') al_draw_bitmap(left_right_arrow, col * IMAGE_SIZE, row * IMAGE_SIZE, ALLEGRO_FLIP_HORIZONTAL);
		else if (c == 'r') al_draw_bitmap(restart_arrow, col * IMAGE_SIZE, row * IMAGE_SIZE, NULL);
		else if (c == 'R') al_draw_bitmap(R_button, col * IMAGE_SIZE, row * IMAGE_SIZE, NULL);
	}

	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_destroy_bitmap(box);
	al_destroy_bitmap(box_in_place);
	al_destroy_bitmap(player);
	al_destroy_bitmap(marker);
	al_destroy_bitmap(brickwall);
	al_destroy_bitmap(up_down_arrow);
	al_destroy_bitmap(left_right_arrow);
	al_destroy_bitmap(restart_arrow);
	al_destroy_bitmap(R_button);
}


void draw_text(const char text[], int x, int y, ALLEGRO_COLOR color, int size)
{
	ALLEGRO_FONT* font = al_load_font("Orbitron Black.ttf", size, NULL);

	al_draw_text(font, color, x, y, ALLEGRO_ALIGN_CENTER, text);

	al_destroy_font(font);
}