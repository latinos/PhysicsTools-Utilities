#ifndef Utilities_BinaryCutSetter_h
#define Utilities_BinaryCutSetter_h
/* \class reco::parser::BinaryCutSetter
 *
 * Cut setter
 *
 * \author original version: Chris Jones, Cornell, 
 *         adapted to Reflex by Luca Lista, INFN
 *
 * \version $Revision: 1.1 $
 *
 */
#include "PhysicsTools/Utilities/src/SelectorStack.h"
#include "PhysicsTools/Utilities/src/LogicalBinaryOperator.h"

namespace reco {
  namespace parser {    
    template<typename Op>
    struct BinaryCutSetter {
      BinaryCutSetter(SelectorStack & selStack) :
	selStack_(selStack) { }
      void operator()(const char*, const char*) const {
	selStack_.push_back(SelectorPtr(new LogicalBinaryOperator<Op>(selStack_)));
      }     
      void operator()(const char&) const {
	const char * c;
	operator()(c, c);
      }  
      SelectorStack & selStack_;
    };
  }
 }

#endif
