//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/http_io
//

#ifndef BOOST_HTTP_IO_READ_HPP
#define BOOST_HTTP_IO_READ_HPP

#include <boost/http_io/detail/config.hpp>
#include <boost/http_io/error.hpp>
#include <boost/http_proto/basic_parser.hpp>

namespace boost {
namespace http_io {

template<
    class SyncReadStream>
std::size_t
read_header(
    SyncReadStream& stream,
    http_proto::basic_parser& parser,
    error_code& ec);

} // http_io
} // boost

#include <boost/http_io/impl/read.hpp>

#endif
