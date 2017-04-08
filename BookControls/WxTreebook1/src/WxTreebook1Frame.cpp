/*
	Copyright (c) 2015 Xavier Leclercq

	Permission is hereby granted, free of charge, to any person obtaining a
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

#include "WxTreebook1Frame.h"
#include <wx/panel.h>
#include <wx/treebook.h>
#include <wx/sizer.h>

WxTreebook1Frame::WxTreebook1Frame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
	// Create a top-level panel to hold all the contents of the frame
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	// Create a wxTreebook control
	wxTreebook* treebook = new wxTreebook(panel, wxID_ANY);

	// Create the first page and add it to the treebook
	wxPanel* page1 = new wxPanel(treebook, wxID_ANY);
	wxTextCtrl* textCtrl1 = new wxTextCtrl(page1, wxID_ANY,
		"Page 1 Text", wxDefaultPosition, wxSize(150, 50));
	wxBoxSizer* page1Sizer = new wxBoxSizer(wxHORIZONTAL);
	page1Sizer->Add(textCtrl1, 1, wxEXPAND);
	page1->SetSizer(page1Sizer);
	treebook->AddPage(page1, "Page 1");

	// Create the second page and add it to the treebook
	wxPanel* page2 = new wxPanel(treebook, wxID_ANY);
	wxTextCtrl* textCtrl2 = new wxTextCtrl(page2, wxID_ANY,
		"Page 2 Text", wxDefaultPosition, wxSize(150, 50));
	wxBoxSizer* page2Sizer = new wxBoxSizer(wxHORIZONTAL);
	page2Sizer->Add(textCtrl2, 1, wxEXPAND);
	page2->SetSizer(page2Sizer);
	treebook->AddPage(page2, "Page 2");

	// Set up the sizer for the panel
	wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
	panelSizer->Add(treebook, 1, wxEXPAND);
	panel->SetSizer(panelSizer);

	// Set up the sizer for the frame and resize the frame
	// according to its contents
	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->SetMinSize(225, 100);
	topSizer->Add(panel, 1, wxEXPAND);
	SetSizerAndFit(topSizer);
}
