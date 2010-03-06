/*
 * The ckCore library provides core software functionality.
 * Copyright (C) 2006-2009 Christian Kindahl
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cxxtest/TestSuite.h>
#include "ckcore/types.hh"
#include "ckcore/convert.hh"
#include "ckcore/string.hh"

class ConvertTestSuite : public CxxTest::TestSuite
{
public:
    void testConvert()
    {
		// Test boolean values.
		{  // Scoping to prevent inadvertently testing the wrong variables
		const ckcore::tchar *str11 = ckT("0");
		const ckcore::tchar *str12 = ckcore::convert::b_to_str(false);
		TS_ASSERT(!ckcore::string::astrcmp(str11,str12));

		const ckcore::tchar *str21 = ckT("1");
		const ckcore::tchar *str22 = ckcore::convert::b_to_str(true);
		TS_ASSERT(!ckcore::string::astrcmp(str21,str22));
		}

		// Test 32-bit integer values.
		{  // Scoping to prevent inadvertently testing the wrong variables
		const ckcore::tchar *str31 = ckT("2147483647");
		const ckcore::tchar *str32 = ckcore::convert::i32_to_str(2147483647);
		TS_ASSERT(!ckcore::string::astrcmp(str31,str32));

		const ckcore::tchar *str41 = ckT("-2147483647");
		const ckcore::tchar *str42 = ckcore::convert::i32_to_str(-2147483647);
		TS_ASSERT(!ckcore::string::astrcmp(str41,str42));

		const ckcore::tchar *str51 = ckT("4294967295");
		const ckcore::tchar *str52 = ckcore::convert::ui32_to_str(4294967295UL);
		TS_ASSERT(!ckcore::string::astrcmp(str51,str52));
		}

		// Test 64-bit integer values.
		{  // Scoping to prevent inadvertently testing the wrong variables
		const ckcore::tchar *str61 = ckT("9223372036854775807");
		const ckcore::tchar *str62 = ckcore::convert::i64_to_str(9223372036854775807LL);
		TS_ASSERT(!ckcore::string::astrcmp(str61,str62));

		const ckcore::tchar *str71 = ckT("-9223372036854775807");
		const ckcore::tchar *str72 = ckcore::convert::i64_to_str(-9223372036854775807LL);
		TS_ASSERT(!ckcore::string::astrcmp(str71,str72));

		const ckcore::tchar *str81 = ckT("18446744073709551615");
		const ckcore::tchar *str82 = ckcore::convert::ui64_to_str(18446744073709551615ULL);
		TS_ASSERT(!ckcore::string::astrcmp(str81,str82));
		}

        ckcore::tchar convBuffer[ckcore::convert::INT_TO_STR_BUFLEN];

		// Test 32-bit integer values.
		{  // Scoping to prevent inadvertently testing the wrong variables
        const ckcore::tint32 max32 = 2147483647;
        const ckcore::tint32 min32 = (-max32 - 1LL);
        
		const ckcore::tchar *str131 = ckT("2147483647");
		ckcore::convert::i32_to_str2(max32, convBuffer);
		TS_ASSERT(!ckcore::string::astrcmp(str131,convBuffer));

		const ckcore::tchar *str141 = ckT("-2147483648");
		ckcore::convert::i32_to_str2(min32, convBuffer);
		TS_ASSERT(!ckcore::string::astrcmp(str141,convBuffer));

		const ckcore::tchar *str151 = ckT("4294967295");
		ckcore::convert::ui32_to_str2(4294967295UL, convBuffer);
		TS_ASSERT(!ckcore::string::astrcmp(str151,convBuffer));
		}
        
		// Test 64-bit integer values.
		{  // Scoping to prevent inadvertently testing the wrong variables
        const ckcore::tint64 max64 = 9223372036854775807LL;
        const ckcore::tint64 min64 = (-max64 - 1LL);
        
		const ckcore::tchar *str61 = ckT("9223372036854775807");
		ckcore::convert::i64_to_str2(max64, convBuffer);
		TS_ASSERT(!ckcore::string::astrcmp(str61,convBuffer));

		const ckcore::tchar *str71 = ckT("-9223372036854775808");
		ckcore::convert::i64_to_str2(min64, convBuffer);
		TS_ASSERT(!ckcore::string::astrcmp(str71,convBuffer));
        

		const ckcore::tchar *str81 = ckT("18446744073709551615");
		ckcore::convert::ui64_to_str2(18446744073709551615ULL, convBuffer);
		TS_ASSERT(!ckcore::string::astrcmp(str81,convBuffer));
		}

        // sprintf function.
        const ckcore::tchar *str91 = ckT("Test: 42.");
        ckcore::tchar buffer[64];
        ckcore::convert::sprintf(buffer,sizeof(buffer),ckT("Test: %u."),42);
        TS_ASSERT(!ckcore::string::astrcmp(str91,buffer));
	}
};