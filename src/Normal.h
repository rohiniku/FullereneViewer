/*
 * Project: FullereneViewer
 * Version: 1.0
 * Copyright: (C) 2011-14 Dr.Sc.KAWAMOTO,Takuji (Ext)
 * Create: 2012/01/20 22:07:29 JST
 */

#ifndef __NORMAL_H__
#define __NORMAL_H__

class Normal {
  // members
public:
  int clockwise;
  
  // constructors & the destructor
public:
  Normal() : clockwise(+1) { }
  ~Normal() { }
  Normal& operator = (const Normal& that); /* dont use */

};

#endif /* __NORMAL_H__ */

/* Local Variables:	*/
/* mode: c++		*/
/* End:			*/
