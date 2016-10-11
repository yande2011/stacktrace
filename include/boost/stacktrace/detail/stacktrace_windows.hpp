// Copyright Antony Polukhin, 2016.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_STACKTRACE_DETAIL_STACKTRACE_WINDOWS_HPP
#define BOOST_STACKTRACE_DETAIL_STACKTRACE_WINDOWS_HPP

#include <boost/config.hpp>
#ifdef BOOST_HAS_PRAGMA_ONCE
#   pragma once
#endif

#include <boost/stacktrace.hpp>
#include <boost/stacktrace/detail/backtrace_holder_windows.hpp>
#include <boost/stacktrace/detail/helpers.hpp>

namespace boost { namespace stacktrace {

stacktrace::stacktrace() BOOST_NOEXCEPT {
    boost::stacktrace::detail::backtrace_holder& bt = boost::stacktrace::detail::construct_bt_and_return(impl_);
    bt.frames_count = CaptureStackBackTrace(0, boost::stacktrace::detail::backtrace_holder::max_size, bt.buffer, 0);
}

}} // namespace boost::stacktrace

#endif // BOOST_STACKTRACE_DETAIL_STACKTRACE_WINDOWS_HPP
