#include <boost/msm/front/euml/euml.hpp>
#include <boost/msm/front/euml/state_grammar.hpp>
#include <boost/msm/back/state_machine.hpp>
#include <iostream>

namespace msm = boost::msm;
using namespace boost::msm::front::euml;

BOOST_MSM_EUML_STATE((), Closed)
BOOST_MSM_EUML_STATE((), Open)
BOOST_MSM_EUML_STATE((), Tilted)

BOOST_MSM_EUML_EVENT(close_)
BOOST_MSM_EUML_EVENT(open_)
BOOST_MSM_EUML_EVENT(tilt)

BOOST_MSM_EUML_TRANSITION_TABLE((
    Closed + open_ == Open,
    Open + close_ == Closed,
    Closed + tilt == Tilted,
    Tilted + close_ == Closed
), window_transition_table)

BOOST_MSM_EUML_DECLARE_STATE_MACHINE(
(window_transition_table, init_ << Closed),
window_state_machine)

int main()
{
    msm::back::state_machine<window_state_machine> window;
    std::cout << *window.current_state() << '\n';
    window.process_event(open_);
    std::cout << *window.current_state() << '\n';
    window.process_event(close_);
    std::cout << *window.current_state() << '\n';
    window.process_event(tilt);
    std::cout << *window.current_state() << '\n';
    window.process_event(close_);
    std::cout << *window.current_state() << '\n';
}
