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

#include "WxTreeCtrl3Frame.h"
#include "WindowIDs.h"
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/msgdlg.h>

WxTreeCtrl3Frame::WxTreeCtrl3Frame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title), m_treeCtrl(0)
{
    // Create a top-level panel to hold all the contents of the frame
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Create a wxTreeCtrl control and add a few nodes to it
    m_treeCtrl = new wxTreeCtrl(panel, TreeCtrlID,
        wxDefaultPosition, wxSize(250,200));
    wxTreeItemId rootId = m_treeCtrl->AddRoot("Root");
    m_treeCtrl->AppendItem(rootId, "Node 1");
    wxTreeItemId child2Id = m_treeCtrl->AppendItem(rootId, "Node 2");
    m_treeCtrl->AppendItem(child2Id, "Child of node 2");
    m_treeCtrl->AppendItem(rootId, "Node 3");

    // Expand all the nodes
    m_treeCtrl->ExpandAll();

    // Set up the sizer for the panel
    wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(m_treeCtrl, 1, wxEXPAND);
    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}

void WxTreeCtrl3Frame::OnTreeItemMenu(wxTreeEvent& evt)
{
    // This event handler creates a new menu and displays 
    // it as a popup menu with the wxWindow::PopupMenu function

    wxMenu menu;
    menu.Append(MenuItemID, "Show node text");

    // We need to pass some data (the text of the node) to
    // the menu event handler. We create a class that holds
    // the needed data and use the Connect function to 
    // associate our event handler with the menu.
    UserData* userData = new UserData();
    userData->m_data = m_treeCtrl->GetItemText(evt.GetItem());
    menu.Connect(MenuItemID, wxEVT_MENU, 
        (wxObjectEventFunction)&WxTreeCtrl3Frame::OnMenuItem,
        userData, this);

    // Display the menu as a popup menu
    PopupMenu(&menu);

    evt.Skip();
}

void WxTreeCtrl3Frame::OnMenuItem(wxCommandEvent& evt)
{
    // Display a message with the text of the node
    // the user right-clicked on
    UserData* userData = dynamic_cast<UserData*>(evt.GetEventUserData());
    if (userData)
    {
        wxMessageBox("You clicked on item: " + userData->m_data);
    }
}

wxBEGIN_EVENT_TABLE(WxTreeCtrl3Frame, wxFrame)
    EVT_TREE_ITEM_MENU(TreeCtrlID, WxTreeCtrl3Frame::OnTreeItemMenu)
wxEND_EVENT_TABLE()
