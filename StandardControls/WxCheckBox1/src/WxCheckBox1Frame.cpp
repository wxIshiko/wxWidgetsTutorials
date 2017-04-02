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

#include "WxCheckBox1Frame.h"
#include "WindowIDs.h"
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>

WxCheckBox1Frame::WxCheckBox1Frame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title), m_textctrl(0)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    panel->SetBackgroundColour(*wxWHITE);

    // Create the wxCheckBox control
    wxCheckBox* checkbox = new wxCheckBox(panel, wxID_CHECKBOX, "Checkbox 1");

    m_textctrl = new wxTextCtrl(panel, wxID_ANY, "Checkbox not checked", 
        wxDefaultPosition, wxSize(140, wxDefaultCoord));

    // Set up the sizer for the panel
    wxBoxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
    panelSizer->AddSpacer(15);
    panelSizer->Add(checkbox, 0, wxCENTER);
    panelSizer->AddSpacer(15);
    panelSizer->Add(m_textctrl, 0, wxCENTER);
    panelSizer->AddSpacer(15);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
    topSizer->SetMinSize(215, 50);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}

void WxCheckBox1Frame::OnCheckBoxEvent(wxCommandEvent& evt)
{
    if (evt.IsChecked())
    {
        m_textctrl->SetValue("Checkbox checked");
    }
    else
    {
        m_textctrl->SetValue("Checkbox not checked");
    }
}

wxBEGIN_EVENT_TABLE(WxCheckBox1Frame, wxFrame)
    EVT_CHECKBOX(wxID_CHECKBOX, WxCheckBox1Frame::OnCheckBoxEvent)
wxEND_EVENT_TABLE()
