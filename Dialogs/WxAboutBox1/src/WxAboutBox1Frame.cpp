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

#include "WxAboutBox1Frame.h"
#include <wx/menu.h>
#include <wx/aboutdlg.h>

WxAboutBox1Frame::WxAboutBox1Frame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
	// The About dialog is usually accessible from
	// the "Help" menu so we create one.
	wxMenuBar* menuBar = new wxMenuBar;
	wxMenu* menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
}

// Event handler for the About menu item. It will
// display the About dialog.
void WxAboutBox1Frame::OnAbout(wxCommandEvent& evt)
{
	// Create the About dialog.
	// On Windows, since there is no website, icon or license,
	// the simple version of the dialog, based on a MessageBox,
	// will be used.
	wxAboutDialogInfo info;

	info.SetName(L"WxAboutBox1");
	info.SetVersion(L"1.0.0");
	info.SetDescription(L"A sample application to demonstrate the wxWidgets wxAboutBox function.");
	info.SetCopyright(L"Copyright (c) 2015 Xavier Leclercq");

	wxArrayString developers;
	developers.Add(L"Xavier Leclercq");
	info.SetDevelopers(developers);
	
	wxAboutBox(info);
}

// Add the event handler for the About menu item
// to the event table.
wxBEGIN_EVENT_TABLE(WxAboutBox1Frame, wxFrame)
	EVT_MENU(wxID_ABOUT, WxAboutBox1Frame::OnAbout)
wxEND_EVENT_TABLE()
