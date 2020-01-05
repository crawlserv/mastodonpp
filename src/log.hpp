/*  This file is part of mastodonpp.
 *  Copyright © 2020 tastytea <tastytea@tastytea.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published by
 *  the Free Software Foundation, version 3.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MASTODONPP_LOG_HPP
#define MASTODONPP_LOG_HPP

#include <iostream>
#include <string_view>

namespace mastodonpp
{

using std::cerr;
using std::string_view;

constexpr auto shorten_filename(const string_view &filename)
{
    for (const string_view &dir : {"/src/", "/include/"})
    {
        auto pos{filename.rfind("/src/")};
        if (pos != string_view::npos)
        {
            return filename.substr(pos + dir.size());
        }
    }
    return filename;
}

#define commonlog cerr << '[' << shorten_filename(__FILE__) \
                       << ':' << __LINE__ << ']'
#ifndef NDEBUG
#define debuglog commonlog << " DEBUG: "
#else
    #define debuglog false && cerr
#endif
#define errorlog commonlog << " ERROR: "

} // namespace mastodonpp

#endif  // MASTODONPP_LOG_HPP
