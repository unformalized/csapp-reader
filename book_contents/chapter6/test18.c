struct algae_position {
    int x;
    int y;
};

void test18() {
    struct algae_position grid[16][16];

    int total_x = 0, total_y = 0;
    int i, j;

    for (i = 0; i < 16; i++) {
        for (j = 0; i < 16; i++) {
            total_x += grid[i][j].x;
        }
    }

    for (i = 0; i < 16; i++) {
        for (j = 0; i < 16; i++) {
            total_y += grid[i][j].y;
        }
    }

    for (i = 0; i < 16; i++) {
        for (j = 0; i < 16; i++) {
            total_x += grid[j][i].x;
            total_y += grid[j][i].y;
        }
    }

    // 按列模式读取，
    // 总读数：512
    // 不命中总读数：256
    // 不命中率：50%
    // 增大一倍高速缓存不命中率：25%

    for (i = 0; i < 16; i++) {
        for (j = 0; i < 16; i++) {
            total_x += grid[i][j].x;
            total_y += grid[i][j].y;
        }
    }

    // 总读数：256
    // 不命中总读数：64
    // 不命中率：25%
    // 增大一倍高速缓存不命中率：当增加组数时不变为 25%，若是需要增加块大小不命中率为 12.5%

}
