/////////////////////////////////////////////////////////////////////////////
// Name:        PictureProcessorTestApp.cpp
// Purpose:     
// Author:      Vinicius Heineck dos Santos
// Modified by: 
// Created:     16/11/2010 15:59:15
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

#include "PictureProcessorTestApp.h"

////@begin XPM images
////@end XPM images


/*
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( PictureProcessorTestApp )
////@end implement app


/*
 * PictureProcessorTestApp type definition
 */

IMPLEMENT_CLASS( PictureProcessorTestApp, wxApp )


/*
 * PictureProcessorTestApp event table definition
 */

BEGIN_EVENT_TABLE( PictureProcessorTestApp, wxApp )

////@begin PictureProcessorTestApp event table entries
////@end PictureProcessorTestApp event table entries

END_EVENT_TABLE()


/*
 * Constructor for PictureProcessorTestApp
 */

PictureProcessorTestApp::PictureProcessorTestApp()
{
    Init();
}


/*
 * Member initialisation
 */

void PictureProcessorTestApp::Init()
{
////@begin PictureProcessorTestApp member initialisation
////@end PictureProcessorTestApp member initialisation
}

/*
 * Initialisation for PictureProcessorTestApp
 */

bool PictureProcessorTestApp::OnInit()
{    
////@begin PictureProcessorTestApp initialisation
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
	PictureProcessorFrame* mainWindow = new PictureProcessorFrame( NULL );
	mainWindow->Show(true);
////@end PictureProcessorTestApp initialisation

    return true;
}


/*
 * Cleanup for PictureProcessorTestApp
 */

int PictureProcessorTestApp::OnExit()
{    
////@begin PictureProcessorTestApp cleanup
	return wxApp::OnExit();
////@end PictureProcessorTestApp cleanup
}

