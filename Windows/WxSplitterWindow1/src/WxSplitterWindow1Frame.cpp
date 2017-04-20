/*
    Copyright (c) 2015 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining  a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "WxSplitterWindow1Frame.h"
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/splitter.h>
#include <wx/textctrl.h>

WxSplitterWindow1Frame::WxSplitterWindow1Frame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{
    // Create the wxSplitterWindow window
    // and set a minimum pane size to prevent unsplitting
    wxSplitterWindow* splitterWindow = new wxSplitterWindow(this, wxID_ANY);
    splitterWindow->SetMinimumPaneSize(50);

    // Create the left panel
    wxPanel* panel1 = new wxPanel(splitterWindow, wxID_ANY);
    wxTextCtrl* textCtrl1 = new wxTextCtrl(panel1, wxID_ANY, L"Panel 1 Text",
        wxDefaultPosition, wxSize(150, 150));
    wxBoxSizer* panel1Sizer = new wxBoxSizer(wxHORIZONTAL);
    panel1Sizer->Add(textCtrl1, 1, wxEXPAND);
    panel1->SetSizer(panel1Sizer);

    // Create the right panel
    wxPanel* panel2 = new wxPanel(splitterWindow, wxID_ANY);
    wxTextCtrl* textCtrl2 = new wxTextCtrl(panel2, wxID_ANY, L"Panel 2 Text",
        wxDefaultPosition, wxSize(150, 150));
    wxBoxSizer* panel2Sizer = new wxBoxSizer(wxHORIZONTAL);
    panel2Sizer->Add(textCtrl2, 1, wxEXPAND);
    panel2->SetSizer(panel2Sizer);

    // Split the window vertically and set the left and right panes
    splitterWindow->SplitVertically(panel1, panel2);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(splitterWindow, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}
