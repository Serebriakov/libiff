/*
 * id.cpp
 *
 *  Created on: 07/02/2010
 *      Author: igorgu
 */

#include "id.hpp"
#define MAKE_ID(a,b,c,d)						\
  ((unsigned long)(a) << 24 | (unsigned long)(b) << 16			\
   | (unsigned long)(c) << 8 | (unsigned long)(d))

id_c::id_c(char a, char b, char c, char d)
{
	m_id = MAKE_ID (a,b,c,d);
}
// --------------------------------------------------------------
id_c::id_c(iff_id_t id)
: m_id (id)
  {
  }
// --------------------------------------------------------------
id_c::~id_c()
{
}
// --------------------------------------------------------------
#define ID_OP(S) return (a.m_id S b.m_id)
// --------------------------------------------------------------
bool operator == (const id_c& a, const id_c& b)
{
	ID_OP (==);
}
// --------------------------------------------------------------
bool operator != (const id_c& a, const id_c& b)
{
	ID_OP (!=);
}
// --------------------------------------------------------------
bool operator <  (const id_c& a, const id_c& b)
{
	ID_OP (<);
}
// --------------------------------------------------------------
bool operator <= (const id_c& a, const id_c& b)
{
	ID_OP (<=);
}
// --------------------------------------------------------------
bool operator >  (const id_c& a, const id_c& b)
{
	ID_OP (>);
}
// --------------------------------------------------------------
bool operator >= (const id_c& a, const id_c& b)
{
	ID_OP (>=);
}
// --------------------------------------------------------------
std::ostream& operator << (std::ostream& os, const id_c& a)
{
	iff_id_t v = a.m_id;
	char c1, c2, c3, c4;
	  c4 = v & 0xFF;
	  v >>= 8;
	  c3 = v & 0xFF;
	  v >>= 8;
	  c2 = v & 0xFF;
	  v >>= 8;
	  c1 = v & 0xFF;
	  const char h [] = { c1, c2, c3, c4, 0 };
	  os << h;
	  return os;
}


