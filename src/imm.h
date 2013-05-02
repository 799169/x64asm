/*
Copyright 2103 eric schkufza

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef X64ASM_SRC_IMM_H
#define X64ASM_SRC_IMM_H

#include <iostream>

#include "src/function.h"
#include "src/operand.h"

namespace x64asm {

/** An immediate value. */
class Imm : public Operand {
  public:
    /** Writes this immediate to an ostream using at&t syntax. */
    void write_att(std::ostream& os) const;
    /** Writes this immediate to an ostrema using intel syntax. */
    void write_intel(std::ostream& os) const;

    /** Comparison based on immediate value. */
    constexpr bool operator<(const Imm& rhs) {
      return val_ < rhs.val_;
    }

    /** Comparison based on immediate value. */
    constexpr bool operator==(const Imm& rhs) {
      return val_ == rhs.val_;
    }

    /** Conversion based on underlying value. */
    constexpr operator uint64_t() {
      return val_;
    }

  protected:
    /** Direct access to this constructor is disallowed. */
    constexpr Imm(uint64_t val) : Operand {val} { }
};

/** An immediate byte value. The imm8 symbol is a signed number between –128
	  and +127 inclusive. For instructions in which imm8 is combined with a
		word or doubleword operand, the immediate value is sign-extended to form
		a word or doubleword. The upper byte of the word is filled with the topmost
		bit of the immediate value.
*/
class Imm8 : public Imm {
  public:
    /** Creates a 8-bit immediate. */
    constexpr Imm8(uint8_t i)
      : Imm {i} {
    }

    /** Checks that this immediate value fits in 8 bits. */
    constexpr bool check() {
			return ((val_>>8) == 0x0ul) || ((val_>>8) == 0xfffffffffffffful);
    }
};

/** An immediate word value used for instructions whose operand-size attribute
	  is 16 bits. This is a number between -32,768 and +32,767 inclusive.
*/
class Imm16 : public Imm {
  public:
    /** Creates a 16-bit immediate. */
    constexpr Imm16(uint16_t i)
      : Imm {i} {
    }

    /** Checks that this immediate value fits in 16 bits. */
    constexpr bool check() {
			return ((val_>>16) == 0x0ul) || ((val_>>16) == 0xfffffffffffful);
    }
};

/** An immediate doubleword value used for instructions whose operand-size
	  attribute is 32 bits. It allows the use of a number between
		+2,147,483,647 and -2,147,483,648 inclusive.
*/
class Imm32 : public Imm {
  public:
    /** Creates a 32-bit immediate. */
    constexpr Imm32(uint32_t i)
      : Imm {i} {
    }

    /** Check that this immediate value fits in 32 bits. */
    constexpr bool check() {
			return ((val_>>32) == 0x0ul) || ((val_>>32) == 0xfffffffful);
    }
};

/** An immediate quadword value used for instructions whose operand-size
	  attribute is 64 bits. The value allows the use of a number between
		+9,223,372,036,854,775,807 and -9,223,372,036,854,775,808 inclusive.
*/
class Imm64 : public Imm {
  public:
    /** Creates a 64-bit immediate. */
    constexpr Imm64(uint64_t i)
      : Imm {i} {
    }

    /** Creates a 64-bit immediate from a 64-bit pointer. */
    template <typename T>
    constexpr Imm64(T* t)
      : Imm {(uint64_t)t} {
    }

    /** Creates a 64-bit immediate from the address of a function. */
    Imm64(const Function& f)
      : Imm {(uint64_t)f.buffer_} {
    }

    /** Checks that this immediate value fits in 64-bits. */
    constexpr bool check() {
      return true;
    }
};

/** The immediate constant value zero */
class Zero : public Imm8 {
    // Needs access to constructor.
    friend class Constants;

  public:
    /** Checks that this immediate value equals zero. */
    constexpr bool check() {
      return val_ == 0;
    }

  private:
    /** Direct access to this constructor is disallowed. */
    constexpr Zero()
      : Imm8 {0} {
    }
};

/** The immediate constant value one */
class One : public Imm8 {
    // Needs access to constructor.
    friend class Constants;

  public:
    /** Checks that this immediate value equals one. */
    constexpr bool check() {
      return val_ == 1;
    }

  private:
    /** Direct access to this construcotr is disallowed. */
    constexpr One()
      : Imm8 {1} {
    }
};

/** The immediate constant value three */
class Three : public Imm8 {
    // Needs access to constructor.
    friend class Constants;

  public:
    /** Checks that this immediate value equals three. */
    constexpr bool check() {
      return val_ == 3;
    }

  private:
    /** Direct access to this constructor is disallosed. */
    constexpr Three()
      : Imm8 {3} {
    }
};

} // namespace x64asm

#endif
