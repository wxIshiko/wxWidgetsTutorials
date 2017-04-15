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

#include "DragAndDropText1Frame.h"
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/dataobj.h>
#include <wx/dnd.h>

DragAndDropText1Frame::DragAndDropText1Frame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title), m_sourceTextCtrl(0)
{
	// Create a top-level panel to hold all the contents of the frame
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	// Create a control that will be the source of of the drag and
	// drop operation. We connect an event handler for the
	// left mouse button event.
	m_sourceTextCtrl = new wxStaticText(panel, wxID_ANY, 
		"Hello World!", wxDefaultPosition, wxSize(250,100));
	m_sourceTextCtrl->Connect(wxEVT_LEFT_DOWN, 
		(wxObjectEventFunction)&DragAndDropText1Frame::OnLeftButtonDown, 0, this);
	
	// Set up the sizer for the panel
	wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
	panelSizer->Add(m_sourceTextCtrl, 0, wxEXPAND | wxALL, 5);
	panel->SetSizer(panelSizer);

	// Set up the sizer for the frame and resize the frame
	// according to its contents
	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->Add(panel, 1, wxEXPAND);
	SetSizerAndFit(topSizer);
}

void DragAndDropText1Frame::OnLeftButtonDown(wxMouseEvent& evt)
{
	wxTextDataObject dragData(m_sourceTextCtrl->GetLabelText());
	wxDropSource dragSource(m_sourceTextCtrl);
	dragSource.SetData(dragData);
	wxDragResult result = dragSource.DoDragDrop();
}

wxBEGIN_EVENT_TABLE(DragAndDropText1Frame, wxFrame)
	EVT_LEFT_DOWN(DragAndDropText1Frame::OnLeftButtonDown)
wxEND_EVENT_TABLE()
