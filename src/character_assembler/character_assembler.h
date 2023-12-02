#ifndef CHARACTER_ASSEMBLER_H_
#define CHARACTER_ASSEMBLER_H_

#include "movement/heading.h"

class CharacterAssembler {
 public:
  virtual ~CharacterAssembler() = default;
  virtual Heading GetCurrentHeading() const = 0;
  virtual void SetCurrentHeading(Heading heading) = 0;
};

#endif /* CHARACTER_ASSEMBLER_H_ */
