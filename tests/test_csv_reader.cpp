#define BOOST_TEST_MODULE csv_reader

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include <csv.hpp>

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

    std::vector<int> foos;
    std::vector<double> bars;
    std::vector<std::string> bazs;

    int n = 0;

    while (in.read_row(foo, bar, baz))
    {
        foos.emplace_back(foo);
        bars.emplace_back(bar);
        bazs.emplace_back(baz);
        ++n;
    }

    BOOST_CHECK_EQUAL(n, 4);

    for (int i = 0; i < n; ++i)
    {
        BOOST_CHECK_EQUAL(foos[i], i);
        BOOST_CHECK_CLOSE(bars[i], 2.0, 1e-6);
    }

    BOOST_CHECK_EQUAL(bazs[0], "woo");
    BOOST_CHECK_EQUAL(bazs[1], "hi");
    BOOST_CHECK_EQUAL(bazs[2], "bye");
    BOOST_CHECK_EQUAL(bazs[3], "byebye");
}
