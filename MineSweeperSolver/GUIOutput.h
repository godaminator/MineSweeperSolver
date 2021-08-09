#pragma once
#include "Output.h"
#include "GuiInput.h"
class GUIOutput :
    public Output
{
public:
    GUIOutput(GuiInput *);
    void show(std::vector<std::pair<Cell*, float>>);

    GuiInput* guiobj;
};

