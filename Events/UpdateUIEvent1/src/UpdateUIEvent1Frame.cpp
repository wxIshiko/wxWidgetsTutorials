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

#include "UpdateUIEvent1Frame.h"
#include <wx/menu.h>
#include <wx/panel.h>

UpdateUIEvent1Frame::UpdateUIEvent1Frame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150)), m_checkbox(0)
{
	wxMenuBar* menuBar = new wxMenuBar;

	wxMenu* menuFile = new wxMenu;
	menuFile->Append(wxID_EXIT);
	menuBar->Append(menuFile, "&File");

	SetMenuBar(menuBar);

	// Add a checkbox that will determine
	// whether the Exit menu is enabled or not
	wxPanel* panel = new wxPanel(this);
	panel->SetBackgroundColour(*wxWHITE);
	m_checkbox = new wxCheckBox(panel, wxID_ANY, "Enable Exit menu", 
		wxPoint(50, 30));
}

void UpdateUIEvent1Frame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void UpdateUIEvent1Frame::OnExitUpdate(wxUpdateUIEvent& evt)
{
	evt.Enable(m_checkbox->GetValue());
}

wxBEGIN_EVENT_TABLE(UpdateUIEvent1Frame, wxFrame)
	EVT_MENU(wxID_EXIT, UpdateUIEvent1Frame::OnExit)
	EVT_UPDATE_UI(wxID_EXIT, UpdateUIEvent1Frame::OnExitUpdate)
wxEND_EVENT_TABLE()
