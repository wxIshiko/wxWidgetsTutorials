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

#include "WxStyledTextCtrl2Frame.h"
#include <wx/panel.h>
#include <wx/stc/stc.h>
#include <wx/sizer.h>

WxStyledTextCtrl2Frame::WxStyledTextCtrl2Frame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Create a wxStyledTextCtrl control
    wxStyledTextCtrl* styledTextCtrl = new wxStyledTextCtrl(panel, wxID_ANY,
        wxDefaultPosition, wxSize(350, 200));

    // Set the lexer to the C++ lexer
    styledTextCtrl->SetLexer(wxSTC_LEX_CPP);
    
    // Set the color to use for various elements
    styledTextCtrl->StyleSetForeground(wxSTC_C_COMMENTLINE, wxColor(60, 162, 2));
    styledTextCtrl->StyleSetForeground(wxSTC_C_PREPROCESSOR, wxColor(0, 0, 255));
    styledTextCtrl->StyleSetForeground(wxSTC_C_STRING, wxColor(255, 60, 10));
    styledTextCtrl->StyleSetForeground(wxSTC_C_WORD, wxColor(0, 0, 255));

    // Give a list of keywords. They will be given the style specified for
    // wxSTC_C_WORD items.
    styledTextCtrl->SetKeyWords(0, wxT("return int char"));
    
    // Populate the wxStyledTextCtrl with a small C++ program
    styledTextCtrl->AddText("// A simple program\n\n");
    styledTextCtrl->AddText("#include <stdio.h>\n\n");
    styledTextCtrl->AddText("int main(int argc, char* argv[])\n");
    styledTextCtrl->AddText("{\n");
    styledTextCtrl->AddText("    printf(\"Hello World!\");\n");
    styledTextCtrl->AddText("    return 0;\n");
    styledTextCtrl->AddText("}\n");

    // Set up the sizer for the panel
    wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(styledTextCtrl, 1, wxEXPAND);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}
