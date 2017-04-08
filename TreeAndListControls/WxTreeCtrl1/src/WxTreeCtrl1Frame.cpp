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

#include "WxTreeCtrl1Frame.h"
#include <wx/panel.h>
#include <wx/treectrl.h>
#include <wx/sizer.h>

WxTreeCtrl1Frame::WxTreeCtrl1Frame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Create a wxTreeCtrl control and add a few nodes to it
    wxTreeCtrl* treeCtrl = new wxTreeCtrl(panel, wxID_ANY, 
        wxDefaultPosition, wxSize(250,200));
    wxTreeItemId rootId = treeCtrl->AddRoot("Root");
    treeCtrl->AppendItem(rootId, "Node 1");
    wxTreeItemId child2Id = treeCtrl->AppendItem(rootId, "Node 2");
    treeCtrl->AppendItem(child2Id, "Child of node 2");
    treeCtrl->AppendItem(rootId, "Node 3");

    // Expand all the nodes
    treeCtrl->ExpandAll();

    // Set up the sizer for the panel
    wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(treeCtrl, 1, wxEXPAND);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}
