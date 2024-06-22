#include <stdio.h>

// Definitions
#define NPORT 7    // Number of authorized ports
#define NLINK 4    // Number of parts in the incoming link ID
#define NPKTS 5    // Number of sample packets
#define NPKTSL 5   // Length of each packet ID parts

// Function prototypes
int is_authorised(int port, const int authPorts[], int size);
int packet_route(const int pkt_ID[], const int local_ID[], int size);
void display_packet(int authorised, int routed);
void format_packet_id(char *formatted_id, const int pkt_ID[]);
void get_incoming_link(int incoming_link_ID[]);

int main(void) {
    printf("\n*************************************************************\n");
    printf("*                                                           *\n");
    printf("*    Welcome to the Basic Data Router Modelling Program!    *\n");
    printf("*                                                           *\n");
    printf("*************************************************************\n\n");

    
    // Sample list of test packets
    int Pkts[NPKTS][NPKTSL] = {
        {192, 168, 10, 2, 212},
        {192, 168, 2, 100, 120},
        {10, 190, 200, 10, 80},
        {192, 168, 10, 200, 173},
        {10, 100, 1, 40, 25}
    };

    // Authorized ports
    int authPorts[NPORT] = {20, 73, 60, 80, 212, 173, 2211};

    // ID of incoming link
    int incoming_link_ID[NLINK];
    get_incoming_link(incoming_link_ID); // Get incoming link ID from user

    // Print incoming link & authorized ports
    printf("\nIncoming link ID: ");
    for (int i = 0; i < NLINK; i++) {
         printf(i < NLINK - 1 ? "%d." : "%d", incoming_link_ID[i]);
    }
    
    printf("\n");

    printf("\nAuthorized ports: ");
    for (int i = 0; i < NPORT; i++) {
         printf(i < NPORT - 1 ? "%d, " : "%d", authPorts[i]);
    }

    printf("\n");

    // Packet processing & printing
    printf("\n%-24s %-20s %-25s\n", "Packet ID", "Port Authorisation", "    Routing");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < NPKTS; i++) {
        int port = Pkts[i][NPKTSL - 1];
        int authorised = is_authorised(port, authPorts, NPORT);
        int routed = packet_route(Pkts[i], incoming_link_ID, 3);

        char formatted_id[50];
        format_packet_id(formatted_id, Pkts[i]);

        printf("%-25s", formatted_id);
        display_packet(authorised, routed);
        printf("\n");
    }

    return 0;
}

// Function to check if port is authorized
int is_authorised(int port, const int authPorts[], int size) {
    for (int i = 0; i < size; i++) {
        if (port == authPorts[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to determine if packet should be routed
int packet_route(const int pkt_ID[], const int local_ID[], int size) {
    for (int i = 0; i < size; i++) {
        if (pkt_ID[i] != local_ID[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to display packet authorization and routing status
void display_packet(int authorised, int routed) {
    if (authorised) {
        printf("%-25s", "Authorised");
        printf(routed ? "Packet Routed" : "Packet Discarded");
    } else {
        printf("%-25s", "Not Authorised");
        printf("Packet Discarded");
    }
}

// Function to format packet ID
void format_packet_id(char *formatted_id, const int pkt_ID[]) {
    sprintf(formatted_id, "%d.%d.%d.%d:%d", pkt_ID[0], pkt_ID[1], pkt_ID[2], pkt_ID[3], pkt_ID[4]);
}

// Function to get incoming link ID from user with validation
void get_incoming_link(int incoming_link_ID[]) {
    printf("Enter the incoming link ID (four parts separated by spaces): ");
    for (int i = 0; i < NLINK; i++) {
        int input;
        while (scanf("%d", &input) != 1 || input < 0 || input > 255) {
            printf("Invalid input. Please enter a number between 0 and 255: ");
            while (getchar() != '\n'); // Clear input buffer
        }
        incoming_link_ID[i] = input;
    }
}
