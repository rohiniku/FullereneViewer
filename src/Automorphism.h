/*
 * Project: FullereneViewer
 * Version: 1.0
 * Copyright: (C) 2011-14 Dr.Sc.KAWAMOTO,Takuji (Ext)
 * Create: 2012/01/19 21:05:58 JST
 */

#ifndef __AUTOMORPHISM_H__
#define __AUTOMORPHISM_H__

#include "Object.h"

class Carbon;
class Bond;
class CarbonAllotrope;

class Automorphism : public Object {
  // friend classes & functions

  // members
private:
  CarbonAllotrope* p_ca;
  int p_index;
  int p_order;
  int* p_carbon_map;
  int* p_bond_map;
  int* p_ring_map;

  // private tools

  // constructors & the destructor
public:
  Automorphism(CarbonAllotrope* ca);
  Automorphism(CarbonAllotrope* ca, Bond* from_bond, Carbon* from_carbon,
               Bond* to_bond, Carbon* to_carbon);
  void initialize(int from_seq, int to_seq);
  virtual ~Automorphism();
  Automorphism& operator = (const Automorphism& that); /* dont use */

  // type converters

  // comparators
  friend bool operator == (const Automorphism& one, const Automorphism& the_other);
  friend bool operator != (const Automorphism& one, const Automorphism& the_other);

  // math operators
public:
  Automorphism* composition(const Automorphism* that) const;
  Automorphism* inverse() const;
  bool is_unit() const;

  // I/O
public:
  void print_out();
  void print_orbit(Carbon* carbon);

  // class decision

  // member accessing methods
public:
  int number_of_carbons() const;
  int number_of_bonds() const;
  int number_of_rings() const;
  CarbonAllotrope* get_carbon_allotrope() const { return p_ca; }
  int operator () (int sequence_no) const;
  int carbon_map(int sequence_no) const;
  int bond_map(int sequence_no) const;
  int ring_map(int sequence_no) const;
  void set_step(int sequence_no);
  int order();
  int fixed_carbons(int& sequence_no0, int& sequence_no1);
  int fixed_bonds(int& sequence_no0, int& sequence_no1);
  int fixed_rings(int& sequence_no0, int& sequence_no1);

};

inline bool operator != (const Automorphism& one, const Automorphism& the_other)
{
  return !(one == the_other);
}

#endif /* __AUTOMORPHISM_H__ */

/* Local Variables:	*/
/* mode: c++		*/
/* End:			*/
