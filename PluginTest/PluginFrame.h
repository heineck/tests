/////////////////////////////////////////////////////////////////////////////
// Name:        PluginFrame.h
// Purpose:     
// Author:      Vinicius Heineck dos Santos
// Modified by: 
// Created:     03/04/2011 18:29:37
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _PLUGINFRAME_H_
#define _PLUGINFRAME_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"

#include "VBLib/VBLib.h"
#include "Constants.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxBoxSizer;
class PluginAPI;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_PLUGINFRAME 10000
#define ID_PLUGINFRAME_BTN_OPEN 10001
#define SYMBOL_PLUGINFRAME_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_PLUGINFRAME_TITLE _("PluginFrame")
#define SYMBOL_PLUGINFRAME_IDNAME ID_PLUGINFRAME
#define SYMBOL_PLUGINFRAME_SIZE wxSize(400, 300)
#define SYMBOL_PLUGINFRAME_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * PluginFrame class declaration
 */

class PluginFrame: public wxFrame
{    
    DECLARE_CLASS( PluginFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    PluginFrame();
    PluginFrame( wxWindow* parent, wxWindowID id = SYMBOL_PLUGINFRAME_IDNAME, const wxString& caption = SYMBOL_PLUGINFRAME_TITLE, const wxPoint& pos = SYMBOL_PLUGINFRAME_POSITION, const wxSize& size = SYMBOL_PLUGINFRAME_SIZE, long style = SYMBOL_PLUGINFRAME_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_PLUGINFRAME_IDNAME, const wxString& caption = SYMBOL_PLUGINFRAME_TITLE, const wxPoint& pos = SYMBOL_PLUGINFRAME_POSITION, const wxSize& size = SYMBOL_PLUGINFRAME_SIZE, long style = SYMBOL_PLUGINFRAME_STYLE );

    /// Destructor
    ~PluginFrame();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

	//Plugin methods
	StringHash GetAvailablePlugins();
	bool LoadPlugin(wxString pluginLibrary);

////@begin PluginFrame event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PLUGINFRAME_BTN_OPEN
    void OnPluginframeBtnOpenClick( wxCommandEvent& event );

////@end PluginFrame event handler declarations

////@begin PluginFrame member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end PluginFrame member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin PluginFrame member variables
    wxBoxSizer* m_mainVertSizer;
    wxPanel* m_mainPanel;
    wxButton* m_btnOpen;

	PluginAPI *m_plugin;
	wxString m_pluginSelected;
	int m_indexPlugin;
	
	br::com::sbVB::VBLib::VBCrossDLL m_vbCrossDll;
////@end PluginFrame member variables
};

#endif
    // _PLUGINFRAME_H_
