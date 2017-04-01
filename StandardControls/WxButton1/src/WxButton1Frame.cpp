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

#include "WxButton1Frame.h"
#include "WindowIDs.h"
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <sstream>

WxButton1Frame::WxButton1Frame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title), m_textCtrl(0), m_buttonClicksCount(0)
{
	// Create a top-level panel to hold all the contents of the frame
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	// Create the button widget
	wxButton* button = new wxButton(panel, ButtonID, L"Button One");

	// Add a wxTextCtrl that will be updated when the button is clicked
	m_textCtrl = new wxTextCtrl(panel, wxID_ANY,
		L"Button has never been clicked.", wxDefaultPosition, 
		wxSize(200, wxDefaultCoord));
	
	// Set up the sizer for the panel
	wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
	panelSizer->Add(button, 0, wxEXPAND);
	panelSizer->Add(m_textCtrl, 1, wxEXPAND);
	panel->SetSizer(panelSizer);

	// Set up the sizer for the frame and resize the frame
	// according to its contents
	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->Add(panel, 1, wxEXPAND);
	SetSizerAndFit(topSizer);
}

void WxButton1Frame::OnButtonClicked(wxCommandEvent& evt)
{
	++m_buttonClicksCount;

	if (m_textCtrl)
	{
		std::wstringstream contents;
		contents << L"Button has been clicked "
			<< m_buttonClicksCount << " times";
		m_textCtrl->SetValue(contents.str());
	}

	evt.Skip();
}

// Add the event handler to the event table. As you can see we use
// the window ID to link the event handler to the wxButton we created.
wxBEGIN_EVENT_TABLE(WxButton1Frame, wxFrame)
	EVT_BUTTON(ButtonID, WxButton1Frame::OnButtonClicked)
wxEND_EVENT_TABLE()
