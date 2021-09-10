#pragma once
#include <boost/preprocessor.hpp>

#ifndef BOOST_PP_TYPENAME
#  define BOOST_PP_TYPENAME(z, n, x) BOOST_PP_COMMA_IF(n) typename BOOST_PP_CAT(x, n) // , typename T0
#endif

#ifndef BOOST_PP_TYPE
#  define BOOST_PP_TYPE(z, n, x) BOOST_PP_COMMA_IF(n) BOOST_PP_CAT(x, n) // , T0
#endif

#ifndef BOOST_PP_CAT3
#  define BOOST_PP_CAT3(a, b, c) BOOST_PP_CAT(BOOST_PP_CAT(a, b), c)
#endif

#ifndef BOOST_PP_PARAMETER
#  define BOOST_PP_PARAMETER(z, n, x) BOOST_PP_COMMA_IF(n) BOOST_PP_CAT(x, n) BOOST_PP_CAT3(x, n, _) // , T0 T0_
#endif

#ifndef BOOST_PP_ARGUMENT
#  define BOOST_PP_ARGUMENT(z, n, x) BOOST_PP_COMMA_IF(n) BOOST_PP_CAT3(x, n, _) // , T0_
#endif

#ifndef BOOST_PP_REPEAT_Z
#  define BOOST_PP_REPEAT_Z(z, n, f, x) BOOST_PP_CAT(BOOST_PP_REPEAT_, z)(n, f, x)
#endif

#ifndef BOOST_PP_REPEAT_TYPENAME
#  define BOOST_PP_REPEAT_TYPENAME(z, n, x) BOOST_PP_REPEAT_Z(z, n, BOOST_PP_TYPENAME, x)
#endif

#ifndef BOOST_PP_COMMA_REPEAT_TYPENAME
#  define BOOST_PP_COMMA_REPEAT_TYPENAME(z, n, x) \
    BOOST_PP_COMMA_IF(n) BOOST_PP_REPEAT_TYPENAME(z, n, x)
#endif

#ifndef BOOST_PP_REPEAT_TYPE
#  define BOOST_PP_REPEAT_TYPE(z, n, x) BOOST_PP_REPEAT_Z(z, n, BOOST_PP_TYPE, x)
#endif

#ifndef BOOST_PP_COMMA_REPEAT_TYPE
#  define BOOST_PP_COMMA_REPEAT_TYPE(z, n, x) \
    BOOST_PP_COMMA_IF(n) BOOST_PP_REPEAT_TYPE(z, n, x)
#endif

#ifndef BOOST_PP_REPEAT_PARAMETER
#  define BOOST_PP_REPEAT_PARAMETER(z, n, x) BOOST_PP_REPEAT_Z(z, n, BOOST_PP_PARAMETER, x)
#endif

#ifndef BOOST_PP_COMMA_REPEAT_PARAMETER
#  define BOOST_PP_COMMA_REPEAT_PARAMETER(z, n, x) \
    BOOST_PP_COMMA_IF(n) BOOST_PP_REPEAT_PARAMETER(z, n, x)
#endif

#ifndef BOOST_PP_REPEAT_ARGUMENT
#  define BOOST_PP_REPEAT_ARGUMENT(z, n, x) BOOST_PP_REPEAT_Z(z, n, BOOST_PP_ARGUMENT, x)
#endif

#ifndef BOOST_PP_COMMA_REPEAT_ARGUMENT
#  define BOOST_PP_COMMA_REPEAT_ARGUMENT(z, n, x) \
    BOOST_PP_COMMA_IF(n) BOOST_PP_REPEAT_ARGUMENT(z, n, x)
#endif
