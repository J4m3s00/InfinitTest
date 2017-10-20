#include <Infinit.h>

#include <in\core\Editor.h>

using namespace in;
using namespace graphics;
using namespace maths;
using namespace core;

void StartEditor()
{
	Editor* editor = new Editor();
	editor->Start();
	delete editor;
}

void StartGame()
{
}

int main(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		char* string = argv[i];
		if (strstr(string, "Editor"))
		{
			StartEditor();
			break;
		}
		else if (strstr(string, "Game"))
		{
			//StartGame();
			break;
		}
	}
	return 0;
}