typedef enum State {
    S_Locked,
    S_Unlocked
} State;

typedef enum Event {
    E_Push,
    E_Coin
} Event;

State handle_locked(Event event);
State handle_unlocked(Event event);
State transition(State current_state, Event event);
const char* state_to_string(State state);
