// Copyright (c) 2005 - 2017 Settlers Freaks (sf-team at siedler25.org)
//
// This file is part of Return To The Roots.
//
// Return To The Roots is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Return To The Roots is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Return To The Roots. If not, see <http://www.gnu.org/licenses/>.

#pragma once
#ifndef LIB_UTIL_DEFINES_H__
#define LIB_UTIL_DEFINES_H__

#ifdef _WIN32
#ifndef _CRTDBG_MAP_ALLOC
#define _CRTDBG_MAP_ALLOC
#endif

#ifdef _MSC_VER
#define getch _getch
#if !defined(snprintf) && _MSC_VER < 1800
#define snprintf _snprintf
#endif
#endif

#ifdef _DEBUG
#include <crtdbg.h>
#endif // _DEBUG
#endif //_WIN32

// Macro that can be used to suppress unused warnings. Required e.g. for const boost::arrays defined in headers
// Don't use this if not absolutely necessary!
#ifdef __GNUC__
#define SUPPRESS_UNUSED __attribute__((unused))
#else
#define SUPPRESS_UNUSED
#endif

#include <stdint.h>

namespace boost { namespace filesystem {
}} // namespace boost::filesystem
namespace boost { namespace nowide {
}} // namespace boost::nowide
namespace bfs = boost::filesystem;
namespace bnw = boost::nowide;

// Suppress uninitialized v_
//-V:BOOST_SCOPED_ENUM_DECLARE_BEGIN:101

#endif
