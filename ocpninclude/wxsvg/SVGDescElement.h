//////////////////////////////////////////////////////////////////////////////
// Name:        SVGDescElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_DESC_ELEMENT_H
#define WX_SVG_DESC_ELEMENT_H

#include "SVGElement.h"
#include "SVGLangSpace.h"
#include "SVGStylable.h"
#include "String_wxsvg.h"
#include "Element.h"
#include "SVGAnimatedType.h"

class wxSVGDescElement:
  public wxSVGElement,
  public wxSVGLangSpace,
  public wxSVGStylable
{
  public:
    wxSVGDescElement(wxString tagName = wxT("desc")):
      wxSVGElement(tagName) {}
    virtual ~wxSVGDescElement() {}
    wxSvgXmlNode* CloneNode(bool deep = true) { return new wxSVGDescElement(*this); }
    bool HasAttribute(const wxString& name) const;
    wxString GetAttribute(const wxString& name) const;
    bool SetAttribute(const wxString& name, const wxString& value);
    wxSvgXmlAttrHash GetAttributes() const;
    bool SetAnimatedValue(const wxString& name, const wxSVGAnimatedType& value);
    virtual wxSVGDTD GetDtd() const { return wxSVG_DESC_ELEMENT; }
};

#endif // WX_SVG_DESC_ELEMENT_H
