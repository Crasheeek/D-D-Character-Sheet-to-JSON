#include "DnDMenu.h"

using namespace DnDCharacterSheetV2;
using namespace System;
using namespace System::Windows::Forms;

void main()
{   
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    DnDMenu^ mainForm = gcnew DnDMenu();
    Application::Run(mainForm);
}

