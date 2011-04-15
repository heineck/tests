/////////////////////////////////////////////////////////////////////////////
// Name:        DllPluginTestApp.cpp
// Purpose:     
// Author:      Vinicius Heineck dos Santos
// Modified by: 
// Created:     03/04/2011 18:28:48
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "DllPluginTestApp.h"

////@begin XPM images
////@end XPM images


/*
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( DllPluginTestApp )
////@end implement app


/*
 * DllPluginTestApp type definition
 */

IMPLEMENT_CLASS( DllPluginTestApp, wxApp )


/*
 * DllPluginTestApp event table definition
 */

BEGIN_EVENT_TABLE( DllPluginTestApp, wxApp )

////@begin DllPluginTestApp event table entries
////@end DllPluginTestApp event table entries

END_EVENT_TABLE()


/*
 * Constructor for DllPluginTestApp
 */

DllPluginTestApp::DllPluginTestApp()
{
    Init();
}


/*
 * Member initialisation
 */

void DllPluginTestApp::Init()
{
////@begin DllPluginTestApp member initialisation
////@end DllPluginTestApp member initialisation
}

/*
 * Initialisation for DllPluginTestApp
 */

bool DllPluginTestApp::OnInit()
{    
////@begin DllPluginTestApp initialisation
	// Remove the comment markers above and below this block
	// to make permanent changes to the code.

#if wxUSE_XPM
	wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
	wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
	wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
	wxImage::AddHandler(new wxGIFHandler);
#endif
	PluginFrame* mainWindow = new PluginFrame( NULL );
	mainWindow->Show(true);
////@end DllPluginTestApp initialisation

	wxMessageBox(wxGetCwd());

    return true;
}


/*
 * Cleanup for DllPluginTestApp
 */

int DllPluginTestApp::OnExit()
{    
////@begin DllPluginTestApp cleanup
	return wxApp::OnExit();
////@end DllPluginTestApp cleanup
}

