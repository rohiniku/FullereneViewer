/*
 * Project: FullereneViewer
 * Version: 1.0
 * Copyright: (C) 2011-14 Dr.Sc.KAWAMOTO,Takuji (Ext)
 * Create: 2012/01/23 00:16:18 JST
 */

#ifndef __SYMMETRYAXIS_H__
#define __SYMMETRYAXIS_H__

#include "Object.h"

class Automorphism;

enum AxisType {
  AXIS_TYPE_CENTER_OF_RING = 1,
  AXIS_TYPE_CENTER_OF_BOND = 2,
  AXIS_TYPE_CENTER_OF_CARBON = 3,
  AXIS_TYPE_CENTER_OF_RING_AND_BOND = 4,
  AXIS_TYPE_CENTER_OF_RING_AND_CARBON = 5,
};

class SymmetryAxis : public Object {
  // friend classes & functions

  // members
private:
  AxisType p_type;
  int p_order;
  int p_north_sequence_no;
  int p_south_sequence_no;
  Automorphism* p_generator;
  int p_generator_step;

  // private tools

  // constructors & the destructor
public:
  SymmetryAxis(AxisType type, int order, int north_sequence_no,
               int south_sequence_no, Automorphism* generator);
  virtual ~SymmetryAxis();

  // type converters

  // comparators
public:
  bool operator <= (const SymmetryAxis& that) const;
  bool operator >= (const SymmetryAxis& that) const;
  bool operator == (const SymmetryAxis& that) const;
  bool operator != (const SymmetryAxis& that) const;

  // math operators

  // I/O
public:
  void print_out() const;

  // class decision

  // member accessing methods
public:
  AxisType get_type() const { return p_type; }
  int get_order() const { return p_order; }
  void set_order(int order) { p_order = order; }
  int get_north_sequence_no() const { return p_north_sequence_no; }
  int get_south_sequence_no() const { return p_south_sequence_no; }
  Automorphism* get_generator() const { return p_generator; }
  void set_generator(Automorphism* generator, int generator_step);
  int get_generator_step() const { return p_generator_step; }

};

#endif /* __SYMMETRYAXIS_H__ */

/* Local Variables:	*/
/* mode: c++		*/
/* End:			*/
