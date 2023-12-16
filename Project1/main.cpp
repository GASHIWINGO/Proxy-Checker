#include "interface.h"

using namespace System;
using namespace System::Windows::Forms;
 [STAThreadAttribute]

int main(array<String^>^ args) {
	 Application::SetCompatibleTextRenderingDefault(false);
	 Application::EnableVisualStyles();
	 Project1::MyForm frm;
	 Application::Run(% frm);
 }