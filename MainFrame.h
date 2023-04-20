#include <wx/wx.h>
//#include "Arithmetic.h"
//#include "../../Absolute test/Absolute test/Absolute test/Arithmetic.h"

#pragma once

class MainFrame : public wxFrame
{
	wxFloat64 lhs;
	wxFloat64 rhs;
public:
	MainFrame(const wxString&);
	wxFloat64 sum();
	wxFloat64 difference();
	wxFloat64 product();
	wxFloat64 quotient();
};

