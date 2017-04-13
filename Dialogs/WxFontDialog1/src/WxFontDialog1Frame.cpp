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

#include "WxFontDialog1Frame.h"
#include "WindowIDs.h"
#include <wx/menu.h>
#include <wx/dcclient.h>

WxFontDialog1Frame::WxFontDialog1Frame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
	// The Open dialog is usually accessible from
	// the "File" menu so we create one.
	wxMenuBar* menuBar = new wxMenuBar;
	wxMenu* menuFile = new wxMenu;
	menuFile->Append(SelectFontMenuID, "Select Font...");
	menuBar->Append(menuFile, "&Options");
	SetMenuBar(menuBar);

	SetBackgroundColour(*wxWHITE);
}

// Event handler for the paint event
void WxFontDialog1Frame::OnPaint(wxPaintEvent& evt)
{
	wxPaintDC dc(this);

	// Set the font and text color based on the user 
	// selection and draw some text
	dc.SetFont(m_fontData.GetChosenFont());
	dc.SetTextForeground(m_fontData.GetColour());
	dc.DrawText("Hello World!", 20, 20);
}

// Event handler for the Select Font menu item. It will
// display a wxFontDialog.
void WxFontDialog1Frame::OnSelectFont(wxCommandEvent& evt)
{
	// Create a new wxFontDialog dialog
	wxFontDialog* fontDialog = new wxFontDialog(this);

	// Display the dialog, save the select font
	// and color and refresh the window to
	// repaint it with the new font
	if (fontDialog->ShowModal() == wxID_OK)
	{
		m_fontData = fontDialog->GetFontData();
		Refresh();
	}

	fontDialog->Destroy();
}

// Add the event handler for the Select Font menu item
// to the event table and for the paint event
wxBEGIN_EVENT_TABLE(WxFontDialog1Frame, wxFrame)
	EVT_PAINT(WxFontDialog1Frame::OnPaint)
	EVT_MENU(SelectFontMenuID, WxFontDialog1Frame::OnSelectFont)
wxEND_EVENT_TABLE()
