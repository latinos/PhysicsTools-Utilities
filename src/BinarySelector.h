#ifndef Utilities_BinarySelector_h
#define Utilities_BinarySelector_h
/* \class reco::parser::BinarySelector
 *
 * Binary selector
 *
 * \author original version: Chris Jones, Cornell, 
 *         adapted to Reflex by Luca Lista, INFN
 *
 * \version $Revision: 1.1 $
 *
 */
#include "PhysicsTools/Utilities/src/SelectorBase.h"
#include "PhysicsTools/Utilities/src/ExpressionBase.h"
#include "PhysicsTools/Utilities/src/ComparisonBase.h"
#include <boost/shared_ptr.hpp>

namespace reco {
  namespace parser {
    struct BinarySelector : public SelectorBase {
      BinarySelector( boost::shared_ptr<ExpressionBase> lhs,
		      boost::shared_ptr<ComparisonBase> cmp,
		      boost::shared_ptr<ExpressionBase> rhs ) :
	lhs_( lhs ), cmp_( cmp ), rhs_( rhs ) { }
      virtual bool operator()( const ROOT::Reflex::Object & o ) const {
	return cmp_->compare( lhs_->value( o ), rhs_->value( o ) );
      }
      boost::shared_ptr<ExpressionBase> lhs_;
      boost::shared_ptr<ComparisonBase> cmp_;
      boost::shared_ptr<ExpressionBase> rhs_;
    };
  }
}

#endif
