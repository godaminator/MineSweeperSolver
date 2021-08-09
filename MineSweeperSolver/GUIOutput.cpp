#include "GUIOutput.h"

GUIOutput::GUIOutput(GuiInput* pguiobj)
{
	guiobj = pguiobj;
}

void GUIOutput::show(std::vector<std::pair<Cell*, float>> result)
{
	for (auto i : result) {
		guiobj->updateGrid(result);
	}
}
