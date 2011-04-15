/////////////////////////////////////////////////////////////////////////////
// Name:        pluginb.h
// Purpose:     
// Author:      Vinicius Heineck dos Santos
// Modified by: 
// Created:     03/04/2011 21:53:58
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _PLUGINB_H_
#define _PLUGINB_H_

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PLUGINB_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PLUGINB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PLUGINB_EXPORTS
#define PLUGINB_API __declspec(dllexport)
#else
#define PLUGINB_API __declspec(dllimport)
#endif


/*!
 * Includes
 */

#include "PluginAPI.h"


/*!
 * Forward declarations
 */

////@begin forward declarations
class wxBoxSizer;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
enum {
	ID_PLUGINB = 12000,
	ID_PANEL,
	ID_BUTTON
};

#define SYMBOL_PLUGINB_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_PLUGINB_TITLE _("PluginB")
#define SYMBOL_PLUGINB_IDNAME ID_PLUGINB
#define SYMBOL_PLUGINB_SIZE wxSize(400, 300)
#define SYMBOL_PLUGINB_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * PluginB class declaration
 */

class PLUGINB_API PluginB: public PluginAPI
{    
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    PluginB( wxWindow* parent);

    /// Destructor
    virtual ~PluginB();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin PluginB event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
    void OnButtonClick( wxCommandEvent& event );

////@end PluginB event handler declarations

////@begin PluginB member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end PluginB member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

private:
////@begin PluginB member variables
    wxBoxSizer* m_mainVertSizer;
    wxPanel* m_mainPanel;
    wxBoxSizer* m_mainPanelVertSizer;
    wxButton* m_btnClickMe;
////@end PluginB member variables
};

extern "C" {
	PLUGINB_API const char * GetPluginName();
	PLUGINB_API PluginAPI * AllocPlugin(wxWindow *parent);
};

#endif
    // _PLUGINB_H_
