#include "state_machine.h"
#include "stdio.h"

// States: LOCKED, UNLOCKED
// Events: PUSH (person tries to pass), COIN (person deposits money)

// Rules:
// - If LOCKED and COIN → go to UNLOCKED
// - If UNLOCKED and PUSH → go to LOCKED
// - If LOCKED and PUSH → stay LOCKED (can't pass)
// - If UNLOCKED and COIN → stay UNLOCKED (thank you for extra payment!)


State handle_locked(Event event) {
    switch (event) {
        case E_Coin:
            printf("Coin inserted\n");
            return S_Unlocked;
        case E_Push:
            printf("Tried to pass locked gate\n");
            return S_Locked;
        default:
            printf("Gate is still Locked\n");
            return S_Locked;
    }
}

State handle_unlocked(Event event) {
    switch (event) {
        case E_Push:
            printf("Passed unlocked gate, locking behind.\n");
            return S_Locked;
        default:
            printf("Gate already unlocked\n");
            return S_Unlocked;
    }
}

State transition(State current_state, Event event) {
    switch (current_state) {
        case S_Locked:
            return handle_locked(event);
        case S_Unlocked:
            return handle_unlocked(event);
        default:
            return S_Locked;
    }
}


const char* state_to_string(State state) {
    switch (state) {
        case S_Locked:
            return "LOCKED";
        case S_Unlocked:
            return "UNLOCKED";
        default:
            return "UNKNOWN";
    }
}
