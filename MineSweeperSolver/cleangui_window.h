#pragma once
#ifndef CLEANGUI_WINDOW_H
#define CLEANGUI_WINDOW_H
#include <vector>


class Cleangui_window
{
public:
    Cleangui_window();
    int startWidget(int **h, int **w, bool** externalflag, bool** gridflag, std::vector<std::vector<std::pair<int, int> >>** gridPointer);
    bool readflag();
    bool setflag();
    
    bool getflagstatus();
    void setflagstatus(bool);
    std::vector<std::vector<std::pair<int, int>>> getgridpos();
    bool* myCleanstatusflag;
    std::vector<std::vector<std::pair<int, int>>>* gridpointer;
};

#endif
