#include <wx/wx.h>
#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* mf = new MainFrame("Arithmetic GUI");
	mf->Show();
	mf->Center();
	mf->SetSize(403, 500);
	return true;
}