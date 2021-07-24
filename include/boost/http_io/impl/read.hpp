//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/http_io
//

#ifndef BOOST_HTTP_IO_IMPL_READ_HPP
#define BOOST_HTTP_IO_IMPL_READ_HPP

#include <boost/asio/buffer.hpp>

namespace boost {
namespace http_io {

template<
    class SyncReadStream>
std::size_t
read_header(
    SyncReadStream& s,
    http_proto::basic_parser& p,
    error_code& ec)
{
    std::size_t n = 0;

    while(p.need_more())
    {
        auto const b = p.prepare();
        auto const bytes_transferred =
            s.read_some(
            asio::mutable_buffer(
                b.first, b.second), ec);
        n += bytes_transferred;
        if(ec)
            break;
        p.commit(bytes_transferred);
        p.parse_header(ec);
        if(ec)
            break;
    }

    return n;
}

} // http_io
} // boost

#endif
