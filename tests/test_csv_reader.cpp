#define BOOST_TEST_MODULE csv_reader

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <csv.h>

BOOST_AUTO_TEST_CASE(test_read)
{
    io::CSVReader<3,
                  io::trim_chars<' ', '\t'>,
                  io::double_quote_escape<',', '"'>>
        in("data/test.csv");

    in.read_header(io::ignore_no_column, "foo", "bar", "baz");

    int foo;
    double bar;
    std::string baz;

    int i = 0;

    const std::vector<std::string> bazs{"woo", "hi", "bye", "bye bye"};

    while (in.read_row(foo, bar, baz))
    {
        BOOST_CHECK_EQUAL(foo, i);
        BOOST_CHECK_CLOSE(bar, 2.0, 1e-6);
        BOOST_CHECK_EQUAL(baz, bazs[i]);
        ++i;
    }

    BOOST_CHECK_EQUAL(i, 4);
}
