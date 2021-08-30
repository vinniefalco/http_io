//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/http_io
//

#ifndef BOOST_HTTP_IO_BUFFER_HPP
#define BOOST_HTTP_IO_BUFFER_HPP

#include <boost/http_io/detail/config.hpp>
#include <boost/http_proto/buffer.hpp>
#include <boost/asio/buffer.hpp>

namespace boost {
namespace http_proto {

mutable_buffer::
operator asio::mutable_buffer() const noexcept
{
    return { data(), size() };
}

const_buffer::
operator asio::const_buffer() const noexcept
{
    return { data(), size() };
}

} // http_proto
} // boost

#endif
