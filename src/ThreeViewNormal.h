/*
 * Project: FullereneViewer
 * Version: 1.0
 * Copyright: (C) 2011-14 Dr.Sc.KAWAMOTO,Takuji (Ext)
 * Create: 2011/12/26 18:06:18 JST
 */

#ifndef __THREEVIEWNORMAL_H__
#define __THREEVIEWNORMAL_H__

#include <stdio.h>
#include "InteractiveRegularPolygon.h"
#include "CarbonAllotrope.h"

class ThreeViewNormal : public InteractiveRegularPolygon {
  // friend classes & functions

  // members
private:
  CarbonAllotrope* p_ca;

  // private tools
private:
  int p_get_nth() const;

  // constructors & the destructor
public:
  ThreeViewNormal(CarbonAllotrope* ca, int nth);
  virtual ~ThreeViewNormal();
  Bond& operator = (const ThreeViewNormal& that); /* dont use */

  // interactions
public:
  virtual void reset_interaction();
  virtual void interaction_original(OriginalForceType force_type,
                                    Interactives* interactives, double delta);

  // I/O
public:
  virtual void draw_opaque_by_OpenGL(bool selection) const;

  // member accessing methods

};

#endif /* __THREEVIEWNORMAL_H__ */

/* Local Variables:	*/
/* mode: c++		*/
/* End:			*/
