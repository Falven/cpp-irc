#include <boost/spirit/include/classic.hpp>
#include <iostream>

#include "dapps/irclib/client/irc_nickname.hpp"

using namespace boost::spirit::classic;
using namespace boost;
using namespace std;

struct record_grammar : public grammar<record_grammar>
{

	template<class ScannerT>
	struct definition
	{
		rule<ScannerT> identifier;
		rule<ScannerT> string_literal;
		rule<ScannerT> prop_decl;
		rule<ScannerT> prop_list;
		rule<ScannerT> record_list;
		rule<ScannerT> record;

		definition(const record_grammar &self)
{
			identifier = lexeme_d[
				alpha_p >> *(alnum_p | ch_p('_'))
			];

			string_literal = lexeme_d[
				ch_p('"') >>
					*(
					(anychar_p - ch_p('"')) |
					str_p("\\\"")
					) >>
					ch_p('"')
			];

			prop_decl = identifier >> ch_p('=') >>
				string_literal;

			prop_list = prop_decl >> *(ch_p(',') >> prop_decl);

			record_list = record >> *(ch_p(',') >> record);

			record = identifier >> identifier >> ch_p('{') >>
				!(
				(
				prop_list >>
				!(ch_p(',') >> record_list)
				) | record_list
				) >>
				ch_p('}');

		};

		rule<ScannerT> const& start()
		{
			return record_list;
		}
	};
};

int main(int argc, const char * argv [])
{
	string input(
		R"(Person Bob{
    age="12",
    height="6 ft.",
    Address home{
        street="1234 applecourt rd",
        city="New York",
        State="NY"
    }
})"
	);

	record_grammar g;
	parse_info<> info = parse(input.c_str(), g, space_p);
	if (!info.full)
	{
		cout << "Error found at location: " << info.stop << endl;
	}
	else
	{
		cout << "Success!" << endl;
	}
	return 0;
}