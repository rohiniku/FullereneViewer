/*
 * Project: FullereneViewer
 * Version: 1.0
 * Copyright: (C) 2011-14 Dr.Sc.KAWAMOTO,Takuji (Ext)
 * Create: 2011/12/26 18:06:18 JST
 */

#include <assert.h>
#include "ThreeViewNormal.h"
#include "CarbonAllotrope.h"
#include "OpenGLUtil.h"

int ThreeViewNormal::p_get_nth() const
{
  return sequence_no();
}

ThreeViewNormal::ThreeViewNormal(CarbonAllotrope* ca, int nth)
  : InteractiveRegularPolygon(ca, nth, 1.0, 2), p_ca(ca)
{
}

ThreeViewNormal::~ThreeViewNormal()
{
}

void ThreeViewNormal::reset_interaction()
{
  InteractiveRegularPolygon::reset_interaction();
  p_ca->reset_three_axes();
}

void ThreeViewNormal::interaction_original(OriginalForceType force_type,
                                           Interactives* interactives, double delta)
{
  p_ca->calculate_three_axes();
  double Eigenvalue;
  Vector3 Eigenvector;
  switch (p_get_nth())
    {
    case 1:
      p_ca->get_primary_Eigenvalue_and_Eigenvector(Eigenvalue, Eigenvector);
      break;
    case 2:
      p_ca->get_secondary_Eigenvalue_and_Eigenvector(Eigenvalue, Eigenvector);
      break;
    default:
      p_ca->get_tertiary_Eigenvalue_and_Eigenvector(Eigenvalue, Eigenvector);
      break;
    }
  p_normal.clockwise = 1;
  fix_center_location(p_ca->get_center_location());
  fix_radius_length(Eigenvalue * 0.5);
  fix_posture(Matrix3(Quaternion(Vector3(0.0, 0.0, 1.0), Eigenvector)));
}

void ThreeViewNormal::draw_opaque_by_OpenGL(bool selection) const
{
  Vector3 norm = get_normal();
  norm *= p_radius.length;
  switch (p_get_nth())
    {
    case 1:
      OpenGLUtil::set_color(0xff80b0);
      break;
    case 2:
      OpenGLUtil::set_color(0xb0ff80);
      break;
    default:
      OpenGLUtil::set_color(0x80b0ff);
      break;
    }
  OpenGLUtil::draw_cylinder(0.1, get_center_location() - norm,
                            get_center_location() + norm);
}

/* Local Variables:	*/
/* mode: c++		*/
/* End:			*/
