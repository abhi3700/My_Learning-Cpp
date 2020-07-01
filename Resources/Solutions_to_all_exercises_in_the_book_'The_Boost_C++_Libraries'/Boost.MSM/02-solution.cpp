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

BOOST_MSM_EUML_DECLARE_ATTRIBUTE(int, opened)
BOOST_MSM_EUML_DECLARE_ATTRIBUTE(int, tilted)

BOOST_MSM_EUML_ACTION(count)
{
    template <class Event, class Fsm>
    void operator()(const Event &ev, Fsm &fsm,
        decltype(Closed) &sourceState,
        decltype(Open) &targetState) const
    {
        ++fsm.get_attribute(opened);
    }

    template <class Event, class Fsm>
    void operator()(const Event &ev, Fsm &fsm,
        decltype(Closed) &sourceState,
        decltype(Tilted) &targetState) const
    {
        ++fsm.get_attribute(tilted);
    }
};

BOOST_MSM_EUML_TRANSITION_TABLE((
    Closed + open_ / count == Open,
    Open + close_ == Closed,
    Closed + tilt / count == Tilted,
    Tilted + close_ == Closed
), window_transition_table)

BOOST_MSM_EUML_DECLARE_STATE_MACHINE(
(window_transition_table, init_ << Closed,
no_action, no_action, attributes_ << opened << tilted),
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
    window.process_event(tilt);
    std::cout << *window.current_state() << '\n';
    std::cout << "opened: " << window.get_attribute(opened) << '\n';
    std::cout << "tilted: " << window.get_attribute(tilted) << '\n';
}
