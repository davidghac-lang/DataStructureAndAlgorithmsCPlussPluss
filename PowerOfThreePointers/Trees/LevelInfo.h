#pragma once

struct LevelInfo {
    int level_number;
    int nodes_count;
    LevelInfo(int lvl, int count) : level_number(lvl), nodes_count(count) {}
};