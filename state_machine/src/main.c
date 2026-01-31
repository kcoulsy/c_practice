#include "state_machine.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    State current_state = S_Locked;
    Event event;
    int input;

    while (1) {
        system("cls");
        printf("=== Turnstile State Machine ===\n");
        printf("\nCurrent state: %s\n", state_to_string(current_state));
        printf("Enter 1 for COIN, 2 for PUSH, 0 to exit: ");
        scanf_s("%d", &input);

        if (input == 0) break;

        event = (input == 1) ? E_Coin : E_Push;
        current_state = transition(current_state, event);
        system("cls");
    }

    printf("Goodbye!\n");

    return 0;
}
