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

#include "WxTreeCtrl2Frame.h"
#include "WindowIDs.h"
#include <wx/panel.h>
#include <wx/sizer.h>

WxTreeCtrl2Frame::WxTreeCtrl2Frame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title), m_treeCtrl(0), m_textCtrl(0)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Create a wxTreeCtrl control and add a few nodes to it
    m_treeCtrl = new wxTreeCtrl(panel, TreeCtrlID,
        wxDefaultPosition, wxSize(250, 200));
    wxTreeItemId rootId = m_treeCtrl->AddRoot("Root");
    m_treeCtrl->AppendItem(rootId, "Node 1");
    wxTreeItemId child2Id = m_treeCtrl->AppendItem(rootId, "Node 2");
    m_treeCtrl->AppendItem(child2Id, "Child of node 2");
    m_treeCtrl->AppendItem(rootId, "Node 3");

    // Expand all the nodes
    m_treeCtrl->ExpandAll();

    // Create a wxTextCtrl that will be updated when 
    // nodes of the tree are selected
    m_textCtrl = new wxTextCtrl(panel, wxID_ANY);

    // Set up the sizer for the panel
    wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(m_treeCtrl, 1, wxEXPAND);
    panelSizer->Add(m_textCtrl, 1, wxEXPAND);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}

// This will be called when the selected node of the tree changes.
// It will copy the selected node text into the wxTextCtrl
void WxTreeCtrl2Frame::OnTreeSelectionChanged(wxTreeEvent& evt)
{
    if (m_treeCtrl && m_textCtrl)
    {
        wxTreeItemId selectedNode = evt.GetItem();
        wxString nodeText = m_treeCtrl->GetItemText(selectedNode);
        m_textCtrl->SetValue(nodeText);
    }

    // Just in case something else is interested in
    // this event
    evt.Skip();
}

// The event table associate the wxTreeCtrl with the event handler
wxBEGIN_EVENT_TABLE(WxTreeCtrl2Frame, wxFrame)
    EVT_TREE_SEL_CHANGED(TreeCtrlID, WxTreeCtrl2Frame::OnTreeSelectionChanged)
wxEND_EVENT_TABLE()
