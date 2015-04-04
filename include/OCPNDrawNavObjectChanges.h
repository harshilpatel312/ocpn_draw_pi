/***************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  OCPN Draw Nav Objects support
 * Author:   Jon Gough
 *
 ***************************************************************************
 *   Copyright (C) 2010 by David S. Register                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 **************************************************************************/
 
#ifndef OCPNDRAWNAVOBJECTCHANGES_H
#define OCPNDRAWNAVOBJECTCHANGES_H

//#include <NavObjectCollection.h>
#include "pugixml.hpp"
#include "Path.h"

#define OUT_OCPNPOINT_RANGE_RINGS OUT_WAYPOINT_RANGE_RINGS << 1

//      Bitfield definition controlling the GPX nodes output for point objects
#define         OUT_TYPE        1 << 1          //  Output point type
#define         OUT_TIME        1 << 2          //  Output time as ISO string
#define         OUT_NAME        1 << 3          //  Output point name if defined
#define         OUT_NAME_FORCE  1 << 4          //  Output point name, even if empty
#define         OUT_DESC        1 << 5          //  Output description if defined
#define         OUT_DESC_FORCE  1 << 6          //  Output description, even if empty
#define         OUT_SYM_FORCE   1 << 7          //  Output symbol name, using "empty" if undefined
#define         OUT_GUID        1 << 8          //  Output GUID if defined
#define         OUT_VIZ         1 << 9          //  Output point viz, if non-zero(true)
#define         OUT_VIZ_NAME    1 << 10         //  Output point name viz, if non-zero(true)
#define         OUT_SHARED      1 << 11         //  Output point shared state, if non-zero(true)
#define         OUT_AUTO_NAME   1 << 12         //  Output point auto_name state, if non-zero(true)
#define         OUT_HYPERLINKS  1 << 13         //  Output point Hyperlinks, if present
#define         OUT_ACTION_ADD  1 << 14         //  opencpn:action node support
#define         OUT_ACTION_DEL  1 << 15
#define         OUT_ACTION_UPD  1 << 16
#define         OUT_EXTENSION   1 << 17
#define         OUT_ARRIVAL_RADIUS 1 << 18
#define         OUT_WAYPOINT_RANGE_RINGS 1 << 19

#define  OPT_WPT        (OUT_TYPE) +\
                        (OUT_TIME) +\
                        (OUT_NAME) +\
                        (OUT_DESC) +\
                        (OUT_SYM_FORCE) +\
                        (OUT_GUID) +\
                        (OUT_VIZ) +\
                        (OUT_VIZ_NAME) +\
                        (OUT_SHARED) +\
                        (OUT_AUTO_NAME) +\
                        (OUT_HYPERLINKS) +\
                        (OUT_ARRIVAL_RADIUS) +\
                        (OUT_WAYPOINT_RANGE_RINGS)

#define OPT_OCPNPOINT   (OPT_WPT) +\
                        (OUT_OCPNPOINT_RANGE_RINGS)


//class OCPNDrawNavObjectChanges : public NavObjectChanges
class OCPNDrawNavObjectChanges : public pugi::xml_document
{
    public:
        OCPNDrawNavObjectChanges();
        OCPNDrawNavObjectChanges( wxString file_name );
        virtual ~OCPNDrawNavObjectChanges();

    bool CreateNavObjGPXPaths(void);
    
    bool AddPath ( Path *pb, const char *action );
    bool AddOCPNPoint( OCPNPoint *pr, const char *action );
    bool AddGPXPathsList( PathList *pPaths );
    bool AddGPXPath(Path *pPath);
    bool AddGPXOCPNPoint(OCPNPoint *pWP );
    bool AddGPXOCPNPointsList( OCPNPointList *pOCPNPoints );
    bool LoadAllGPXObjects( bool b_full_viz = false);
    int  LoadAllGPXObjectsAsLayer(int layer_id, bool b_layerviz);
    //OCPNPoint * GPXLoadOCPNPoint1( pugi::xml_node &odpt_node, wxString def_symbol_name, wxString GUID, bool b_fullviz, bool b_layer, bool b_layerviz, int layer_id );

    bool CreateAllGPXObjects();
    void SetRootGPXNode(void);
    
    bool ApplyChanges(void);
    bool SaveFile( const wxString filename );

    
    FILE        *m_OCPNDrawchanges_file;
    
    pugi::xml_node      m_gpx_root;
    
    bool            m_bFirstPath;

    protected:
    private:
        OCPNPoint *GPXLoadOCPNPoint1( pugi::xml_node &opt_node, 
                               wxString def_symbol_name,
                               wxString GUID,
                               bool b_fullviz,
                               bool b_layer,
                               bool b_layerviz,
                               int layer_id
                             );
        Path *GPXLoadPath1( pugi::xml_node &wpt_node, bool b_fullviz,
                      bool b_layer, bool b_layerviz, int layer_id, wxString *TypeString );
        OCPNPoint *OCPNPointExists( const wxString& guid );
        OCPNPoint *OCPNPointExists( const wxString& name, double lat, double lon );
        void InsertPathA( Path *pTentPath );
        void UpdatePathA( Path *pTentPath );
        Path *PathExists( const wxString& guid);
        Path *PathExists( Path * pTentPath );
        wxString m_ODfilename;


};

#endif // OCPNDRAWNAVOBJECTCHANGES_H
