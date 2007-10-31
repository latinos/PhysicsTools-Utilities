#ifndef Utilities_ExpressionSetter_h
#define Utilities_ExpressionSetter_h
/* \class reco::parser::ExpressionSetter
 *
 * Expression setter
 *
 * \author original version: Chris Jones, Cornell, 
 *         adapted to Reflex by Luca Lista, INFN
 *
 * \version $Revision: 1.3 $
 *
 */
#include "PhysicsTools/Utilities/src/ExpressionPtr.h"
#include "PhysicsTools/Utilities/src/ExpressionStack.h"

namespace reco {
  namespace parser {    
    struct ExpressionSetter {
      ExpressionSetter( ExpressionPtr & expr, ExpressionStack & exprStack ) :
	expr_( expr ), exprStack_( exprStack ) { }
      
      void operator()( const char*, const char* ) const;
      ExpressionPtr & expr_;
      ExpressionStack & exprStack_;
    };
  }
 }

#endif
