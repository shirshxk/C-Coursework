# Basic Data Router Modelling Program

Welcome to the Basic Data Router Modelling Program! This program simulates a simple data router that processes incoming packets, checks for authorized ports, and determines whether to route or discard each packet based on predefined rules.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Algorithm](#algorithm)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This program takes an incoming link ID and a set of packets, then checks each packet against authorized ports and routing rules. The program outputs the packet ID, its authorization status, and whether it will be routed or discarded.

## Features

- Prompt user to enter an incoming link ID.
- Validate the incoming link ID.
- Check packets against a predefined list of authorized ports.
- Determine if packets should be routed based on the incoming link ID.
- Display the packet ID, authorization status, and routing decision.

## Algorithm

### Main Function Steps

1. Start
2. Print a welcome message.
3. Declare an array `Pkts[NPKTS][NPKTSL]` with sample packet data.
4. Declare an array `incoming_link_ID[NLINK]`.
5. Declare an array `authPorts[NPORT]` with authorized ports.
6. Call `get_incoming_link(incoming_link_ID)` function.
    - Prompt the user to enter the incoming link ID in four parts separated by spaces.
    - Validate each part to ensure it's between 0 and 255.
    - Store valid parts in `incoming_link_ID`.
7. Print the `incoming_link_ID`.
8. Print the `authPorts`.
9. Print the header for the packet processing table.
10. Repeat for each packet in `Pkts` array:
    - Extract the port from the packet.
    - Call `is_authorised(port, authPorts, NPORT)` function.
      - Check if the port is in `authPorts`.
      - Return 1 if authorized, else return 0.
    - Call `packet_route(Pkts[i], incoming_link_ID, 3)` function.
      - Compare the first three parts of `pkt_ID` with `local_ID`.
      - Return 1 if they differ, else return 0.
    - Call `format_packet_id(formatted_id, Pkts[i])` function.
      - Format the packet ID for display.
    - Print the formatted packet ID.
    - Call `display_packet(authorised, routed)` function.
      - Print the authorization and routing status based on the values of `authorised` and `routed`.
11. End

### Functions

- **Function 1: `is_authorised`**
  - Parameters: int port, const int authPorts[], int size
  - Check if the port is in `authPorts`.
  - Return 1 if authorized, else return 0.

- **Function 2: `packet_route`**
  - Parameters: const int pkt_ID[], const int local_ID[], int size
  - Compare the first `size` parts of `pkt_ID` with `local_ID`.
  - Return 1 if they differ, else return 0.

- **Function 3: `display_packet`**
  - Parameters: int authorised, int routed
  - Print "Authorised" or "Not Authorised" based on `authorised`.
  - Print "Packet Routed" if `routed` is 1, else print "Packet Discarded".

- **Function 4: `format_packet_id`**
  - Parameters: char *formatted_id, const int pkt_ID[]
  - Format the packet ID as a string "xxx.xxx.xxx.xxx:xxx".

- **Function 5: `get_incoming_link`**
  - Parameters: int incoming_link_ID[]
  - Prompt user to enter the incoming link ID.
  - Validate each part (0-255).
  - Store the valid parts in `incoming_link_ID`.

## Usage

1. Clone the repository:
    ```bash
    git clone https://github.com/shirshxk/C-Coursework.git
    ```

2. Compile the program:
    ```bash
    gcc -o router router.c
    ```

3. Run the program:
    ```bash
    ./router
    ```

4. Follow the prompts to enter the incoming link ID.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
