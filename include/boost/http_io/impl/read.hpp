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

#include <boost/http_io/buffer.hpp>
#include <boost/url/grammar/error.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/error.hpp>

namespace boost {
namespace http_io {

template<
    class SyncReadStream>
std::size_t
read_some(
    SyncReadStream& s,
    http_proto::parser& p,
    error_code& ec)
{
    auto const b = p.prepare();
    auto const bytes_transferred =
        s.read_some(asio::mutable_buffer(b), ec);
    if(ec != asio::error::eof)
    {
        p.commit(bytes_transferred);
        return bytes_transferred;
    }
    BOOST_ASSERT(
        bytes_transferred == 0);
    p.commit_eof();
    ec = {};
    return bytes_transferred;
}

template<
    class SyncReadStream>
std::size_t
read_header(
    SyncReadStream& s,
    http_proto::parser& p,
    error_code& ec)
{
    std::size_t n = 0;
    for(;;)
    {
        p.parse_header(ec);
        if(! ec)
            break;
        if(ec != http_proto::grammar::error::incomplete)
            return n;
        auto const bytes_transferred =
            ::boost::http_io::read_some(s, p, ec);
        n += bytes_transferred;
        if(ec)
            return n;
    }

    return n;
}

template<
    class SyncReadStream>
std::size_t
read_body_part(
    SyncReadStream& s,
    http_proto::parser& p,
    error_code& ec)
{
    std::size_t n = 0;
    p.parse_body(ec);
    if(! ec)
        return 0;
    if(ec != http_proto::grammar::error::incomplete)
        return 0;
    auto const bytes_transferred =
        ::boost::http_io::read_some(s, p, ec);
    if(ec)
        return bytes_transferred;
    return bytes_transferred;
}

template<
    class SyncReadStream>
std::size_t
read_body(
    SyncReadStream& s,
    http_proto::parser& p,
    error_code& ec)
{
    std::size_t n = 0;
    for(;;)
    {
        n += ::boost::http_io::read_body_part(s, p, ec);
        if(ec)
            return n;
    }
}

} // http_io
} // boost

#endif
