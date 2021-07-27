#include "ConsoleOutput.h"

void ConsoleOutput::show(std::vector<std::pair<Cell*, float>> result)
{
	for (auto i : result) {
		std::cout << *i.first << "  " << i.second << std::endl;
	}
}
