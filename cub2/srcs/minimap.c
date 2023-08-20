#include "../cub3D.h" // Inclure les fichiers d'en-tête nécessaires

void draw_map(t_data *data, int rect_size)
{
    int y = 0;
    int x;

    while (y < data->map.g_height)
    {
        x = 0;
        while (x < data->map.g_width)
        {
            int map_value = data->map.grid[y][x];
            int color = (map_value == '1') ? 0xFF0000 : 0x00FF00;
            mlx_pixel_put(data->mlx, data->win, x * rect_size, y * rect_size, color);
            x++;
        }
        y++;
    }
}

void draw_player(t_data *data, int rect_size)
{
    int player_color = 0x0000FF;
    int y_offset = -rect_size / 2;

    while (y_offset <= rect_size / 2) {
        int x_offset = -rect_size / 2;
        while (x_offset <= rect_size / 2) {
            if (x_offset * x_offset + y_offset * y_offset <= (rect_size / 2) * (rect_size / 2)) {
                mlx_pixel_put(data->mlx, data->win, data->player.x * rect_size + x_offset, data->player.y * rect_size + y_offset, player_color);
            }
            x_offset++;
        }
        y_offset++;
    }
}

void draw_minimap(t_data *data)
{
    int rect_size = 5;
    
    draw_map(data, rect_size);
    draw_player(data, rect_size);
}
