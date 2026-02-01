#include <stdio.h>
#include <stdint.h>

#define POWER       (1 << 0) // 00000001
#define WIFI        (1 << 1) // 00000010
#define BLUETOOTH   (1 << 2) // 00000100
#define GPS         (1 << 3) // 00001000
#define LOW_POWER   (1 << 4) // 00010000
#define ERROR       (1 << 5) // 00100000
#define CONNECTIVITY_MASK (WIFI | BLUETOOTH | GPS)

void enable(uint8_t *device, uint8_t feature) {
    // OR
    *device = *device | feature;
}

void disable(uint8_t *device, uint8_t feature) {
    // AND + flip
    // ~ flips all of the bits so mostly 1s and and the target becomes 0
    // & AND wit those flips bits, clearing only the target bit
    *device &= ~feature;
}

int is_feature_enabled(uint8_t device, uint8_t feature) {
    return (device & feature) != 0;
}

void print_feature_state(uint8_t device, uint8_t feature) {
    char *label = "Unknown";
    switch(feature) {
        case POWER:
            label = "POWER: ";
            break;
        case WIFI:
            label = "WIFI: ";
            break;
        case BLUETOOTH:
            label = "BLUETOOTH: ";
            break;
        case GPS:
            label = "GPS: ";
            break;
        case LOW_POWER:
            label = "LOW_POWER: ";
            break;
        case ERROR:
            label = "ERROR: ";
            break;
    }
    int is_enabled =  is_feature_enabled(device, feature);
    printf("%s%s\n", label, is_enabled ? "ENABLED" : "DISABLED");
}

uint8_t is_connected(uint8_t device) {
    return device & CONNECTIVITY_MASK;
}

void print_connection_status(uint8_t device) {
    if (is_connected(device)) {
        printf("Conncted!\n");
        return;
    }
    printf("Not Connected!\n");
}

void reset(uint8_t *device) {
    *device &= 0;
}

void print_bits(uint8_t device) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (device >> i) & 1);
    }

    printf("\n");
}
int main(void) {
    // specifically 8 bit int container.
    uint8_t device_state = 0;

    print_feature_state(device_state, POWER);
    enable(&device_state, POWER);
    print_feature_state(device_state, POWER);
    print_connection_status(device_state);
    enable(&device_state, WIFI);
    print_feature_state(device_state, WIFI);
    print_connection_status(device_state);

    print_bits(device_state);
    reset(&device_state);
    print_feature_state(device_state, WIFI);
    print_connection_status(device_state);

    print_bits(device_state);
    return 0;
}
