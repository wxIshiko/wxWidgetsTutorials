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

#include "WxColourPickerCtrl1Frame.h"
#include "WindowIDs.h"
#include <wx/panel.h>
#include <wx/sizer.h>

WxColourPickerCtrl1Frame::WxColourPickerCtrl1Frame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title), m_textCtrl(0)
{
	// Create a top-level panel to hold all the contents of the frame
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	// Create a wxTextCtrl to have some text we can select the color of
	m_textCtrl = new wxTextCtrl(panel, wxID_ANY, "Some text of the selected color.",
		wxDefaultPosition, wxSize(200, wxDefaultCoord));

	// Create a wxColourPickerCtrl control
	wxColourPickerCtrl* colourPickerCtrl = new wxColourPickerCtrl(panel, ColourPickerID);

	// Set up the sizer for the panel
	wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
	panelSizer->Add(m_textCtrl, 0, wxEXPAND | wxALL, 15);
	panelSizer->Add(colourPickerCtrl, 0, wxEXPAND | wxALL, 15);
	panel->SetSizer(panelSizer);

	// Set up the sizer for the frame and resize the frame
	// according to its contents
	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->Add(panel, 1, wxEXPAND);
	SetSizerAndFit(topSizer);
}

void WxColourPickerCtrl1Frame::OnColourChanged(wxColourPickerEvent& evt)
{
	// Use the wxColourPickerEvent::GetColour() function to get the selected
	// color and set the color of the text control accordingly.
	m_textCtrl->SetForegroundColour(evt.GetColour());
	m_textCtrl->Refresh();
}

// Add the event handler to the event table. As you can see we use the
// window ID to link the event handler to the wxColourPickerCtrl we created.
wxBEGIN_EVENT_TABLE(WxColourPickerCtrl1Frame, wxFrame)
	EVT_COLOURPICKER_CHANGED(ColourPickerID, WxColourPickerCtrl1Frame::OnColourChanged)
wxEND_EVENT_TABLE()
