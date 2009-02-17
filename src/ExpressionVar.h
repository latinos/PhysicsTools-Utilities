#ifndef Utilities_ExpressionVar_h
#define Utilities_ExpressionVar_h
/* \class reco::parser::ExpressionVar
 *
 * Variable expression
 *
 * \author original version: Chris Jones, Cornell, 
 *         adapted to Reflex by Luca Lista, INFN
 *
 * \version $Revision: 1.8 $
 *
 */
#include "PhysicsTools/Utilities/src/ExpressionBase.h"
#include "PhysicsTools/Utilities/src/TypeCode.h"
#include "PhysicsTools/Utilities/src/MethodInvoker.h"
#include <vector>

namespace reco {
  namespace parser {
    struct ExpressionVar : public ExpressionBase {
      ExpressionVar(const std::vector<MethodInvoker> & methods, method::TypeCode retType);

      ~ExpressionVar() ;
      ExpressionVar(const ExpressionVar &var) ;

      virtual double value(const Reflex::Object & o) const;

      static bool isValidReturnType(method::TypeCode);
    private:
      std::vector<MethodInvoker>  methods_;
      mutable std::vector<Reflex::Object> objects_;
      method::TypeCode retType_;
      static void trueDelete(Reflex::Object & o) ;
      void initObjects_();
    }; 
  }
}

#endif
