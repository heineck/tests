/////////////////////////////////////////////////////////////////////////////
// Name:        PluginFrame.cpp
// Purpose:     
// Author:      Vinicius Heineck dos Santos
// Modified by: 
// Created:     03/04/2011 18:29:37
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

#include "PluginFrame.h"
#include "PluginAPI.h"

using namespace br::com::sbVB::VBLib;
////@begin XPM images
////@end XPM images


/*
 * PluginFrame type definition
 */

IMPLEMENT_CLASS( PluginFrame, wxFrame )


/*
 * PluginFrame event table definition
 */

BEGIN_EVENT_TABLE( PluginFrame, wxFrame )

////@begin PluginFrame event table entries
    EVT_BUTTON( ID_PLUGINFRAME_BTN_OPEN, PluginFrame::OnPluginframeBtnOpenClick )

////@end PluginFrame event table entries

END_EVENT_TABLE()


/*
 * PluginFrame constructors
 */

PluginFrame::PluginFrame()
{
    Init();
}

PluginFrame::PluginFrame( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create( parent, id, caption, pos, size, style );
}


/*
 * PluginFrame creator
 */

bool PluginFrame::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin PluginFrame creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    Centre();
////@end PluginFrame creation
    return true;
}


/*
 * PluginFrame destructor
 */

PluginFrame::~PluginFrame()
{
////@begin PluginFrame destruction
////@end PluginFrame destruction
}


/*
 * Member initialisation
 */

void PluginFrame::Init()
{
////@begin PluginFrame member initialisation
    m_mainVertSizer = NULL;
    m_mainPanel = NULL;
    m_btnOpen = NULL;
	m_plugin = NULL;
////@end PluginFrame member initialisation
}


/*
 * Control creation for PluginFrame
 */

void PluginFrame::CreateControls()
{    
////@begin PluginFrame content construction
    PluginFrame* itemFrame1 = this;

    m_mainVertSizer = new wxBoxSizer(wxVERTICAL);
    itemFrame1->SetSizer(m_mainVertSizer);

    m_mainPanel = new wxPanel( itemFrame1, ID_PLUGINFRAME, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    m_mainVertSizer->Add(m_mainPanel, 1, wxGROW, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxVERTICAL);
    m_mainPanel->SetSizer(itemBoxSizer4);

    m_btnOpen = new wxButton( m_mainPanel, ID_PLUGINFRAME_BTN_OPEN, _("Open"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(m_btnOpen, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

////@end PluginFrame content construction
}


/*
 * Should we show tooltips?
 */

bool PluginFrame::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap PluginFrame::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin PluginFrame bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end PluginFrame bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon PluginFrame::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin PluginFrame icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end PluginFrame icon retrieval
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PLUGINFRAME_BTN_OPEN
 */

void PluginFrame::OnPluginframeBtnOpenClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PLUGINFRAME_BTN_OPEN in PluginFrame.
    // Before editing this code, remove the block markers.
   // wxMessageBox(_("To be implemented"));

	StringHash pluginHash = GetAvailablePlugins();

	// explicit type cast to avoid warning on conversion from size_t to int;
	// we reckon we'll never have over 4 billion (!) plugins.
	int n_pluginLibrary = (int)pluginHash.size();

	if(n_pluginLibrary == 0)
	{
		wxMessageBox(NO_PLUGIN_FOUND);
	}
	else
	{
		// 
		wxString *choices = new wxString [n_pluginLibrary];

		// 
		StringHash::iterator j = pluginHash.begin();
		for(int i = 0; i < n_pluginLibrary; i++, j++)
		{
			choices[i] = j->first;

			if (m_pluginSelected == choices[i])
				m_indexPlugin = i;
		}

		// 
		wxSingleChoiceDialog dialog(this,
											CHOOSE_PLUGIN_CAPTION,
											CHOOSE_PLUGIN,
											n_pluginLibrary, choices);
		
		//dialog.SetSelection(m_indexPlugin);
		
		if (dialog.ShowModal() == wxID_OK)
		{
			wxString choice = choices[dialog.GetSelection()];
			//Hide();	// done so that there is no more than one instance of this window visible at any time
			
			LoadPlugin(pluginHash[choice]);
		}
		// Delete the choices (after the dialog modal, no more need of them)
		delete [] choices;
	}

////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PLUGINFRAME_BTN_OPEN in PluginFrame. 
}

StringHash PluginFrame::GetAvailablePlugins()
{
	VBCrossDLLContainer dllContainer;

	//const char *exportedNamesDllMustHave[] = {"AllocPlugin", "GetPluginName"};
	const char *exportedNamesDllMustHave[] = {"GetPluginName"};
	unsigned s = sizeof(exportedNamesDllMustHave)/sizeof(const char *);

	//typedef PluginAPI *(*AllocPluginPtrType)(wxWindow *);
	typedef const char *(*GetNamePtrType)();

//	AllocSkinPtrType allocSkinPtr;
	GetNamePtrType getNamePtr;

	StringHash pluginHash;

	try
	{
		// Loads dynamic libraries
		dllContainer.loadDllsWithAllExportedNames
			(exportedNamesDllMustHave, s, DYNAMIC_LIBRARY_FOLDER, DYNAMIC_LIBRARY_EXTENSION);

		// Gets the number of dynamic libraries loaded
		unsigned n_dll = dllContainer.getNumberOfDlls();

		// Fill the hash table
		for(unsigned i=0 ; i < n_dll ; i++)
		{
			getNamePtr = (GetNamePtrType) dllContainer[i].getAddress("GetPluginName");

			wxString pluginName = wxString(getNamePtr(), wxConvUTF8);
			wxString pluginLibrary = wxString(dllContainer[i].getName(), wxConvUTF8);

			pluginHash[pluginName] = pluginLibrary;
		}

		return pluginHash;
	}

	catch(VBException_crossDLL & e)
	{
		wxMessageBox(wxString(e.getExplanation(), wxConvUTF8), VBEXCEPTION_CROSSDLL);
		StringHash emptyHash;
		return emptyHash;
	}

	catch(VBException & e)
	{
		wxMessageBox(wxString(e.getExplanation(), wxConvUTF8), VBEXCEPTION);
		StringHash emptyHash;
		return emptyHash;
	}

	StringHash emptyHash;
	return emptyHash;
}

bool PluginFrame::LoadPlugin(wxString pluginLibrary)
{
	typedef PluginAPI *(*AllocPluginPtrType)(wxWindow *);
	AllocPluginPtrType allocPluginPtr;

	try
	{
		PluginAPI *plugin;
		VBCrossDLL newPluginLibrary;
							
		newPluginLibrary.load(pluginLibrary.mb_str());

		// Gets the function pointer of the plugin
		allocPluginPtr = (AllocPluginPtrType) newPluginLibrary.getAddress("AllocPlugin");

		// Late bind here, new Plugin instantiation
		plugin = allocPluginPtr(this);

		if(m_plugin != NULL)
		{
			//m_plugin->Close(true);
		}

		m_plugin = plugin;

		m_vbCrossDll.unLoad();
		m_vbCrossDll = newPluginLibrary;

		plugin->Show();
		return true;
	}

	catch(VBException_crossDLL & e)
	{
		wxMessageBox(wxString(e.getExplanation(), wxConvUTF8), VBEXCEPTION_CROSSDLL);
		return false;
	}

	catch(VBException & e)
	{
		wxMessageBox(wxString(e.getExplanation(), wxConvUTF8), VBEXCEPTION);
		return false;
	}

	return false;
}
