#include "ImportMap.h"

void import_map(char file_name[]) { //const char* map_name
    FILE* fp;
    errno_t error_code;
    error_code = fopen_s(&fp, file_name, "r");
    if (error_code != 0) {
        printf("FILE DOESN'T EXIST");
    }
    else
    {
        for (int i = 0; i < (MAP_WIDTH+1)*MAP_HEIGHT; i++) map[i] = fgetc(fp);
    }
    fclose(fp);
}