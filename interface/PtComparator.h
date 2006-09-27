#ifndef RecoAlgos_PtComparator_h
#define RecoAlgos_PtComparator_h
/** \class PtComparator
 *
 * compare by pt
 * 
 * \author Luca Lista, INFN
 *
 * \version $Revision: 1.1 $
 *
 * $Id: PtComparator.h,v 1.1 2006/07/25 09:02:56 llista Exp $
 *
 */

template<typename T>
struct PtComparator {
  bool operator()( const T & t1, const T & t2 ) const {
    return t1.pt() < t2.pt();
  }
};

template<typename T>
struct PtInverseComparator {
  bool operator()( const T & t1, const T & t2 ) const {
    return t1.pt() > t2.pt();
  }
};

#endif
