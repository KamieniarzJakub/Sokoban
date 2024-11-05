#include "Settings.h"
#include "Allegro.h"

#include "DestinationSquares.h"
#include "Draw.h"
#include "ImportMap.h"
#include "Player.h"

int main()
{

	if (!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);
		return -1;
	}

	//al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW | ALLEGRO_RESIZABLE | ALLEGRO_ALIGN_CENTER);
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	ALLEGRO_DISPLAY* display = al_create_display(ScreenWidth, ScreenHeight);
	al_set_window_position(display, (1920-ScreenWidth)/2, 0);
	al_set_window_title(display, "Sokoban");

	if (!display)
	{
		al_show_native_message_box(display, "ERROR", "Display settings", "Display window was not created successfully", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	al_install_keyboard();

	const float FPS = 60.0;
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	char level_map[] = "levels/level_0.txt";
	int level = 0;

	import_map(level_map);

	int pos_x, pos_y;
	int dest_num = GetDestSquares();

	//printf("%s\n", map);
	//al_map_rgb(255, 255, 255), ScreenWidth / 2, ScreenHeight / 5, ALLEGRO_ALIGN_CENTER, text
	draw_text("SOKOBAN", ScreenWidth / 2, ScreenHeight / 5, al_map_rgb(255,255,255), 64);
	draw_text("PRESS ANY KEY TO START", ScreenWidth / 2, ScreenHeight-700, al_map_rgb(255, 255, 255), 32);
	draw_map(level);
	al_start_timer(timer);

	bool game = true;
	while (game)
	{
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) game = false;
		else if (events.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			PlayerPosition(&pos_x, &pos_y);

			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_DOWN:
			case ALLEGRO_KEY_S:
				MoveCharacter(pos_x, pos_y, MAP_WIDTH + 1);
				break;
			case ALLEGRO_KEY_UP:
			case ALLEGRO_KEY_W:
				MoveCharacter(pos_x, pos_y, -MAP_WIDTH - 1);
				break;
			case ALLEGRO_KEY_RIGHT:
			case ALLEGRO_KEY_D:
				MoveCharacter(pos_x, pos_y, 1);
				break;
			case ALLEGRO_KEY_LEFT:
			case ALLEGRO_KEY_A:
				MoveCharacter(pos_x, pos_y, -1);
				break;
			case ALLEGRO_KEY_R:
			case ALLEGRO_KEY_SPACE:
				import_map(level_map);
				break;
			case ALLEGRO_KEY_ESCAPE:
				game = false;
				break;
			}

			int dest_count = Check_destination_Squares();
			if (dest_num == dest_count)
			{	
				level_map[13]++;
				level++;
				import_map(level_map);
				dest_num = GetDestSquares();
			}

			if (level == 0)
			{
				draw_text("SOKOBAN", ScreenWidth / 2, ScreenHeight / 5, al_map_rgb(255, 255, 255), 64);
				draw_text("PUSH BOXES TO DESIGNATED PLACES", ScreenWidth / 2, ScreenHeight - 700, al_map_rgb(255, 255, 255), 32);
			}
			else if (level == LAST_LEVEL)
			{
				draw_text("YOU DID IT", ScreenWidth / 2, ScreenHeight /2, al_map_rgb(255, 255, 255), 64);
				draw_text("ALL BOXES ARE PLACED AT STORAGE LOCATIONS", ScreenWidth / 2, ScreenHeight / 2 + 100, al_map_rgb(255, 255, 255), 32);
				draw_text("THANKS FOR PLAYING", ScreenWidth / 2, ScreenHeight / 2 + 250, al_map_rgb(255, 255, 255), 48);
			}

			draw_map(level);
		}
	}

	al_flip_display();
	
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}