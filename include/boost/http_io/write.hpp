//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/http_io
//

#ifndef BOOST_HTTP_IO_WRITE_HPP
#define BOOST_HTTP_IO_WRITE_HPP

#include <boost/http_io/detail/config.hpp>
#include <boost/http_io/error.hpp>
#include <boost/http_proto/serializer.hpp>
#include <boost/asio/write.hpp>

namespace boost {
namespace http_io {

template<class SyncWriteStream>
std::size_t
write_some(
    SyncWriteStream& stream,
    http_proto::serializer& sr,
    error_code& ec)
{
    std::size_t bytes_transferred = 0;
    if(sr.is_complete())
    {
        // error::end_of_message ?
        return 0;
    }
    auto buf = sr.prepare(ec);
    if(ec)
        return 0;
}

template<class SyncWriteStream>
std::size_t
write(
    SyncWriteStream& stream,
    http_proto::serializer& sr,
    error_code& ec)
{
    std::size_t bytes_transferred = 0;
    //if(sr.is_complete())
    {
        // error::end_of_message ?
        //return 0;
    }
    auto bp = sr.prepare(ec);
    if(ec)
        return 0;
    std::array<asio::const_buffer, 2> cb;
    cb[0] = asio::const_buffer(
        bp.data[0], bp.size[0]);
    cb[1] = asio::const_buffer(
        bp.data[1], bp.size[1]);
    return asio::write(stream, cb, ec);
}


} // http_io
} // boost

#include <boost/http_io/impl/read.hpp>

#endif
