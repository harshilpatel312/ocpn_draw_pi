#ifndef OCPNDRAWCANVASMENUHANDLER_H
#define OCPNDRAWCANVASMENUHANDLER_H

#include <canvasMenu.h>

//----------------------------------------------------------------------------
//    Forward Declarations
//----------------------------------------------------------------------------
      class Path;
      class OCPNPoint;

//class OCPNDrawCanvasMenuHandler : public CanvasMenuHandler
class OCPNDrawCanvasMenuHandler
{
    public:
        OCPNDrawCanvasMenuHandler(ChartCanvas *parentCanvas,
          Path *selectedPath,
          OCPNPoint *selectedOCPNPoint);
        virtual ~OCPNDrawCanvasMenuHandler();
        void    PopupMenuHandler( wxCommandEvent& event );

    
    protected:
    private:
      int               popx, popy;
      ChartCanvas       *parent;
      Path             *m_pSelectedPath;
      OCPNPoint        *m_pFoundOCPNPoint;
};

#endif // OCPNDRAWCANVASMENUHANDLER_H
