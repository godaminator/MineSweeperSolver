#pragma once
#ifndef CLEANGUI_H
#define CLEANGUI_H
#include <vector>


class CleanGUI
{
public:
    CleanGUI();
    int startWidget(int h, int w, bool** externalflag, bool** gridflag, std::vector<std::vector<std::pair<int, int> >>** gridPointer);
    bool readflag();
    bool setflag();
    
    bool getflagstatus();
    void setflagstatus(bool);
    std::vector<std::vector<std::pair<int, int>>> getgridpos();
    bool* myCleanstatusflag;
    std::vector<std::vector<std::pair<int, int>>>* gridpointer;
};

#endif
