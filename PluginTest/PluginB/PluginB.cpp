/////////////////////////////////////////////////////////////////////////////
// Name:        pluginb.cpp
// Purpose:     
// Author:      Vinicius Heineck dos Santos
// Modified by: 
// Created:     03/04/2011 21:53:58
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////


#pragma once

//#include "targetver.h"
#ifdef WIN32

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

#endif

#include "pluginb.h"

/*
 * PluginB event table definition
 */

BEGIN_EVENT_TABLE( PluginB, wxFrame )

////@begin PluginB event table entries
    EVT_BUTTON( ID_BUTTON, PluginB::OnButtonClick )

////@end PluginB event table entries

END_EVENT_TABLE()


PluginB::PluginB( wxWindow* parent): PluginAPI()
{
    Init();
	Create( parent, ID_PLUGINB, _("PluginB"));

	CreateControls();
    Centre();
}


/*
 * PluginB destructor
 */

PluginB::~PluginB()
{
////@begin PluginB destruction
////@end PluginB destruction
}


/*
 * Member initialisation
 */

void PluginB::Init()
{
////@begin PluginB member initialisation
    m_mainVertSizer = NULL;
    m_mainPanel = NULL;
    m_mainPanelVertSizer = NULL;
    m_btnClickMe = NULL;
////@end PluginB member initialisation
}


/*
 * Control creation for PluginB
 */

void PluginB::CreateControls()
{    
////@begin PluginB content construction
    PluginB* itemFrame1 = this;

    m_mainVertSizer = new wxBoxSizer(wxVERTICAL);
    itemFrame1->SetSizer(m_mainVertSizer);

    m_mainPanel = new wxPanel( itemFrame1, ID_PANEL, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    m_mainVertSizer->Add(m_mainPanel, 1, wxGROW, 5);

    m_mainPanelVertSizer = new wxBoxSizer(wxVERTICAL);
    m_mainPanel->SetSizer(m_mainPanelVertSizer);

    m_btnClickMe = new wxButton( m_mainPanel, ID_BUTTON, _("Click Me"), wxDefaultPosition, wxDefaultSize, 0 );
    m_mainPanelVertSizer->Add(m_btnClickMe, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

////@end PluginB content construction
}


/*
 * Should we show tooltips?
 */

bool PluginB::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap PluginB::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin PluginB bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end PluginB bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon PluginB::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin PluginB icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end PluginB icon retrieval
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

void PluginB::OnButtonClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON in PluginB.
    // Before editing this code, remove the block markers.
    wxMessageBox(_("This is the Plugin B!"));
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON in PluginB. 
}

extern "C" {
	PLUGINB_API const char * GetPluginName()
	{
		return "Plugin B";
	}
	
	
	PLUGINB_API PluginAPI * AllocPlugin(wxWindow *parent)
	{
		return new PluginB(parent);
	}

};
