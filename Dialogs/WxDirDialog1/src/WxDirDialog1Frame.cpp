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

#include "WxDirDialog1Frame.h"
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/dirdlg.h>

WxDirDialog1Frame::WxDirDialog1Frame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title), m_textCtrl(0)
{
    // The Open dialog is usually accessible from
    // the "File" menu so we create one.
    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(wxID_OPEN);
    menuBar->Append(menuFile, "&File");
    SetMenuBar(menuBar);

    // Create a top-level panel to hold all the contents of the frame
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Add a wxTextCtrl that will be updated when the 
    // user selects a directory
    m_textCtrl = new wxTextCtrl(panel, wxID_ANY,
        L"", wxDefaultPosition, wxSize(400, 200));

    // Set up the sizer for the panel
    wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(m_textCtrl, 1, wxEXPAND);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}

// Event handler for the menu item. It will
// display a wxDirDialog.
void WxDirDialog1Frame::OnChooseDir(wxCommandEvent& evt)
{
    // Create a new wxDirDialog dialog
    wxDirDialog* dirDialog = new wxDirDialog(this);

    // Display the dialog and transfer the contents to
    // the wxTextCtrl on the main frame if the user
    // doesn't cancel
    if (dirDialog->ShowModal() == wxID_OK)
    {
        wxString selectedFile = dirDialog->GetPath();
        m_textCtrl->SetValue(selectedFile);
    }

    dirDialog->Destroy();
}

// Add the event handler for the menu item
// to the event table.
wxBEGIN_EVENT_TABLE(WxDirDialog1Frame, wxFrame)
    EVT_MENU(wxID_OPEN, WxDirDialog1Frame::OnChooseDir)
wxEND_EVENT_TABLE()
