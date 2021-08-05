//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/http_io
//

// Test that header file is self-contained.
#include <boost/http_io/read.hpp>

#include "test_suite.hpp"

namespace boost {
namespace http_io {

class read_test
{
public:
    void
    testRead()
    {
    }

    void
    run()
    {
        testRead();
    }
};

TEST_SUITE(read_test, "boost.http_io.read");

} // http_io
} // boost
