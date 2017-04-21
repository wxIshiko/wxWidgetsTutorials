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

#include "Drawing1Frame.h"
#include <wx/dcclient.h>

Drawing1Frame::Drawing1Frame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
{
    SetBackgroundColour(*wxWHITE);
}

void Drawing1Frame::OnPaint(wxPaintEvent& evt)
{
    wxPaintDC dc(this);

    dc.SetPen(*wxGREY_PEN);
    dc.SetBrush(*wxLIGHT_GREY_BRUSH);
    dc.DrawRectangle(10, 10, 50, 50);
    dc.DrawCircle(95, 35, 25);
}

wxBEGIN_EVENT_TABLE(Drawing1Frame, wxFrame)
    EVT_PAINT(Drawing1Frame::OnPaint)
wxEND_EVENT_TABLE()
