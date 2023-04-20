#include "MainFrame.h"
#include "App.h"
#include <wx/wx.h>
//#include "Arithmetic.h"
//#include <string>
//#include "../../Absolute test/Absolute test/Absolute test/Arithmetic.h"



MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

    wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    wxStaticText* leftHandSide = new wxStaticText(panel, wxID_ANY, "Enter left operand", wxPoint(50, 50));
    wxStaticText* rightHandSide = new wxStaticText(panel, wxID_ANY, "Enter right operand", wxPoint(200, 50));
    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(50, 100), wxSize(100,25));
    wxTextCtrl* textCtrl2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(200,100), wxSize(100, 25));
    wxButton* Add = new wxButton(panel, wxID_ANY, " + ", wxPoint(135, 200));
    wxButton* Subtract = new wxButton(panel, wxID_ANY, " - ", wxPoint(135, 225));
    wxButton* Product = new wxButton(panel, wxID_ANY, " * ", wxPoint(135, 250));
    wxButton* Qoutient = new wxButton(panel, wxID_ANY, " / ", wxPoint(135, 275));
 
    CreateStatusBar();

    Add->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& evt) {
            wxString result = wxString::Format(wxT("%.2f"), (wxFloat64)sum());
            wxLogMessage(result);    
            evt.Skip();
        });
    Subtract->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& evt) {
        wxString result = wxString::Format(wxT("%.2f"), (wxFloat64)difference());
    wxLogMessage(result);
    evt.Skip();
        });
    Product->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& evt) {
        wxString result = wxString::Format(wxT("%.2f"), (wxFloat64)product());
    wxLogMessage(result);
        });
    Qoutient->Bind(wxEVT_LEFT_DOWN, [this](wxMouseEvent& evt) {
        wxString result = wxString::Format(wxT("%.2f"), (wxFloat64)quotient());
    wxLogMessage(result);
        });
    textCtrl->Bind(wxEVT_TEXT, [this](wxCommandEvent& e) {
        //lhs = wxAtoi(e.GetString());
        e.GetString().ToDouble(&lhs);
        e.Skip();
        });
    textCtrl2->Bind(wxEVT_TEXT, [this](wxCommandEvent& e) {
        //rhs = wxAtoi(e.GetString());
        e.GetString().ToDouble(&rhs);
        e.Skip();
        }); 
}

wxFloat64 MainFrame::sum() {
    return rhs + lhs;
}

wxFloat64 MainFrame::quotient() {
    return lhs / rhs;
}

wxFloat64 MainFrame::product() {
    return rhs * lhs; 
}

wxFloat64 MainFrame::difference() {
    return lhs - rhs;
}