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

#include "WxAuiNotebook1Frame.h"
#include <wx/aui/aui.h>
#include <wx/textctrl.h>

WxAuiNotebook1Frame::WxAuiNotebook1Frame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
	// Create a top-level panel to hold all the contents of the frame
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	// Create the wxAuiNotebook widget
	wxAuiNotebook* auiNotebook = new wxAuiNotebook(panel, wxID_ANY);

	// Add 2 pages to the wxNotebook widget
	wxTextCtrl* textCtrl1 = new wxTextCtrl(auiNotebook, wxID_ANY, L"Tab 1 Contents");
	auiNotebook->AddPage(textCtrl1, L"Tab 1");
	wxTextCtrl* textCtrl2 = new wxTextCtrl(auiNotebook, wxID_ANY, L"Tab 2 Contents");
	auiNotebook->AddPage(textCtrl2, L"Tab 2");

	// Set up the sizer for the panel
	wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
	panelSizer->Add(auiNotebook, 1, wxEXPAND);
	panel->SetSizer(panelSizer);
	
	// Set up the sizer for the frame and resize the frame
	// according to its contents
	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->SetMinSize(250, 200);
	topSizer->Add(panel, 1, wxEXPAND);
	SetSizerAndFit(topSizer);
}
