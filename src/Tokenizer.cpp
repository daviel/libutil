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

#include "libUtilDefines.h" // IWYU pragma: keep
#include "Tokenizer.h"

Tokenizer::Tokenizer(const std::string& data, const std::string& delimiter) : data(data), delimiter(delimiter) {}

Tokenizer::operator bool() const
{
    return !data.empty();
}

std::string Tokenizer::next()
{
    std::string r;
    std::string::size_type p = data.find_first_of(delimiter);

    if(std::string::npos != p)
    {
        r = data.substr(0, p);
        data = data.substr(p + 1);
    } else
    {
        r = data;
        data.erase();
    }
    return r;
}

std::vector<std::string> Tokenizer::explode()
{
    std::vector<std::string> result;
    while(*this)
        result.push_back(next());
    return result;
}
