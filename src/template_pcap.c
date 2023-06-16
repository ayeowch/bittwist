/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * template_pcap - Template pcap files to be used as input files for bittwiste
 * Copyright (C) 2006 - 2023 Addy Yeow Chin Heng <ayeowch@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <stddef.h>

#include "template_pcap.h"

/*
To define a new template using packet from e.g. out.pcap:

$ xxd -p out.pcap | tr -d '\n'
d4c3b2a102000400000000000000000000000400010000002f467864d41404000e0000000e000000

$ python
>>> s = "d4c3b2a102000400000000000000000000000400010000002f467864d41404000e0000000e000000"
>>> v = ', '.join([f"0x{b:02x}" for b in bytes.fromhex(s)])
>>> print(f"const unsigned char TEMPLATE[] = {{{v}}};")

Fields in templates have been scrubbed as follow using bittwiste:
1) MAC address = 00:00:00:00:00:00
2) IPv4 address = 127.0.0.1
3) IPv6 address = ::1
4) Source port = 1000
5) Destination port = 2000
*/

/*
Template name: TEMPLATE_PCAP_ETH (-I eth)
Description: Ethernet header
Wireshark output:
Frame 1: 14 bytes on wire (112 bits), 14 bytes captured (112 bits)
Ethernet II, Src: 00:00:00_00:00:00 (00:00:00:00:00:00), Dst: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Destination: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Source: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Type: IPv4 (0x0800)
*/
const unsigned char TEMPLATE_PCAP_ETH[] = {
    0xd4, 0xc3, 0xb2, 0xa1, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2f, 0x46, 0x78, 0x64,
    0xd4, 0x14, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00};
const size_t TEMPLATE_PCAP_ETH_LEN = sizeof(TEMPLATE_PCAP_ETH);

/*
Template name: TEMPLATE_PCAP_ARP (-I arp)
Description: ARP header
Wireshark output:
Frame 1: 42 bytes on wire (336 bits), 42 bytes captured (336 bits)
Ethernet II, Src: 00:00:00_00:00:00 (00:00:00:00:00:00), Dst: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Destination: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Source: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Type: ARP (0x0806)
Address Resolution Protocol (ARP Announcement)
    Hardware type: Ethernet (1)
    Protocol type: IPv4 (0x0800)
    Hardware size: 6
    Protocol size: 4
    Opcode: request (1)
    Sender MAC address: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Sender IP address: 127.0.0.1
    Target MAC address: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Target IP address: 127.0.0.1
*/
const unsigned char TEMPLATE_PCAP_ARP[] = {
    0xd4, 0xc3, 0xb2, 0xa1, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x05, 0xd6, 0x7e, 0x64,
    0x33, 0x2f, 0x0a, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x01};
const size_t TEMPLATE_PCAP_ARP_LEN = sizeof(TEMPLATE_PCAP_ARP);

/*
Template name: TEMPLATE_PCAP_IP (-I ip)
Description: IPv4 header
Wireshark output:
Frame 1: 34 bytes on wire (272 bits), 34 bytes captured (272 bits)
Ethernet II, Src: 00:00:00_00:00:00 (00:00:00:00:00:00), Dst: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Destination: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Source: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Type: IPv4 (0x0800)
Internet Protocol Version 4, Src: 127.0.0.1, Dst: 127.0.0.1
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
    Total Length: 20
    Identification: 0x3282 (12930)
    Flags: 0x40, Don't fragment
    ...0 0000 0000 0000 = Fragment Offset: 0
    Time to Live: 64
    Protocol: TCP (6)
    Header Checksum: 0x0a60
    Source Address: 127.0.0.1
    Destination Address: 127.0.0.1
*/
const unsigned char TEMPLATE_PCAP_IP[] = {
    0xd4, 0xc3, 0xb2, 0xa1, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0xaa, 0x72, 0x64, 0x2c, 0x74,
    0x06, 0x00, 0x22, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x45, 0x00, 0x00, 0x14, 0x32, 0x82,
    0x40, 0x00, 0x40, 0x06, 0x0a, 0x60, 0x7f, 0x00, 0x00, 0x01, 0x7f, 0x00, 0x00, 0x01};
const size_t TEMPLATE_PCAP_IP_LEN = sizeof(TEMPLATE_PCAP_IP);

/*
Template name: TEMPLATE_PCAP_IP6 (-I ip6)
Description: IPv6 header
Wireshark output:
Frame 1: 54 bytes on wire (432 bits), 54 bytes captured (432 bits)
Ethernet II, Src: 00:00:00_00:00:00 (00:00:00:00:00:00), Dst: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Destination: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Source: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Type: IPv6 (0x86dd)
Internet Protocol Version 6, Src: ::1, Dst: ::1
    0110 ....                               = Version: 6
    .... 0000 0000 .... .... .... .... .... = Traffic Class: 0x00 (DSCP: CS0, ECN: Not-ECT)
    .... .... .... 0011 0101 0001 1011 0011 = Flow Label: 0x351b3
    Payload Length: 0
    Next Header: TCP (6)
    Hop Limit: 53
    Source Address: ::1
    Destination Address: ::1
*/
const unsigned char TEMPLATE_PCAP_IP6[] = {
    0xd4, 0xc3, 0xb2, 0xa1, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x6b, 0x86, 0x79, 0x64, 0x64, 0x45, 0x02, 0x00,
    0x36, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x86, 0xdd, 0x60, 0x03, 0x51, 0xb3, 0x00, 0x00, 0x06, 0x35, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};
const size_t TEMPLATE_PCAP_IP6_LEN = sizeof(TEMPLATE_PCAP_IP6);

/*
Template name: TEMPLATE_PCAP_ICMP (-I icmp)
Description: ICMPv4 header
Wireshark output:
Frame 1: 42 bytes on wire (336 bits), 42 bytes captured (336 bits)
Ethernet II, Src: 00:00:00_00:00:00 (00:00:00:00:00:00), Dst: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Destination: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Source: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Type: IPv4 (0x0800)
Internet Protocol Version 4, Src: 127.0.0.1, Dst: 127.0.0.1
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
    Total Length: 28
    Identification: 0x4321 (17185)
    Flags: 0x40, Don't fragment
    ...0 0000 0000 0000 = Fragment Offset: 0
    Time to Live: 64
    Protocol: ICMP (1)
    Header Checksum: 0xf9bd
    Source Address: 127.0.0.1
    Destination Address: 127.0.0.1
Internet Control Message Protocol
    Type: 8 (Echo (ping) request)
    Code: 0
    Checksum: 0xf58a
    Identifier (BE): 299 (0x012b)
    Sequence Number (BE): 330 (0x014a)
*/
const unsigned char TEMPLATE_PCAP_ICMP[] = {
    0xd4, 0xc3, 0xb2, 0xa1, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0xff, 0x24, 0x78, 0x64,
    0x96, 0x33, 0x05, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x45, 0x00,
    0x00, 0x1c, 0x43, 0x21, 0x40, 0x00, 0x40, 0x01, 0xf9, 0xbd, 0x7f, 0x00, 0x00, 0x01,
    0x7f, 0x00, 0x00, 0x01, 0x08, 0x00, 0xf5, 0x8a, 0x01, 0x2b, 0x01, 0x4a};
const size_t TEMPLATE_PCAP_ICMP_LEN = sizeof(TEMPLATE_PCAP_ICMP);

/*
Template name: TEMPLATE_PCAP_ICMP6 (-I icmp6)
Description: ICMPv6 header
Wireshark output:
Frame 1: 118 bytes on wire (944 bits), 118 bytes captured (944 bits)
Ethernet II, Src: 00:00:00_00:00:00 (00:00:00:00:00:00), Dst: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Destination: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Source: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Type: IPv6 (0x86dd)
Internet Protocol Version 6, Src: ::1, Dst: ::1
    0110 ....                               = Version: 6
    .... 0000 0000 .... .... .... .... .... = Traffic Class: 0x00 (DSCP: CS0, ECN: Not-ECT)
    .... .... .... 0100 1110 1111 0100 0101 = Flow Label: 0x4ef45
    Payload Length: 64
    Next Header: ICMPv6 (58)
    Hop Limit: 48
    Source Address: ::1
    Destination Address: ::1
Internet Control Message Protocol v6
    Type: Echo (ping) request (128)
    Code: 0
    Checksum: 0x336f
    Identifier: 0x4c01
    Sequence: 19
    Data (56 bytes)
*/
const unsigned char TEMPLATE_PCAP_ICMP6[] = {
    0xd4, 0xc3, 0xb2, 0xa1, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x75, 0x86, 0x79, 0x64, 0x63, 0xb6, 0x00, 0x00,
    0x76, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x86, 0xdd, 0x60, 0x04, 0xef, 0x45, 0x00, 0x40, 0x3a, 0x30, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00,
    0x33, 0x6f, 0x4c, 0x01, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const size_t TEMPLATE_PCAP_ICMP6_LEN = sizeof(TEMPLATE_PCAP_ICMP6);

/*
Template name: TEMPLATE_PCAP_TCP (-I tcp)
Description: IPv4 TCP header
Wireshark output:
Frame 1: 74 bytes on wire (592 bits), 74 bytes captured (592 bits)
Ethernet II, Src: 00:00:00_00:00:00 (00:00:00:00:00:00), Dst: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Destination: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Source: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Type: IPv4 (0x0800)
Internet Protocol Version 4, Src: 127.0.0.1, Dst: 127.0.0.1
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
    Total Length: 60
    Identification: 0x3282 (12930)
    Flags: 0x40, Don't fragment
    ...0 0000 0000 0000 = Fragment Offset: 0
    Time to Live: 64
    Protocol: TCP (6)
    Header Checksum: 0x0a38
    Source Address: 127.0.0.1
    Destination Address: 127.0.0.1
Transmission Control Protocol, Src Port: 1000, Dst Port: 2000, Seq: 0, Len: 0
    Source Port: 1000
    Destination Port: 2000
    Sequence Number (raw): 2053058830
    Acknowledgment number (raw): 0
    1010 .... = Header Length: 40 bytes (10)
    Flags: 0x002 (SYN)
    Window: 43690
    Checksum: 0x469f
    Urgent Pointer: 0
    Options: (20 bytes), Maximum segment size, SACK permitted, Timestamps, No-Operation (NOP),
             Window scale
*/
const unsigned char TEMPLATE_PCAP_TCP[] = {
    0xd4, 0xc3, 0xb2, 0xa1, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0xaa, 0x72, 0x64, 0x2c, 0x74,
    0x06, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x32, 0x82,
    0x40, 0x00, 0x40, 0x06, 0x0a, 0x38, 0x7f, 0x00, 0x00, 0x01, 0x7f, 0x00, 0x00, 0x01, 0x03,
    0xe8, 0x07, 0xd0, 0x7a, 0x5f, 0x31, 0x0e, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x02, 0xaa, 0xaa,
    0x46, 0x9f, 0x00, 0x00, 0x02, 0x04, 0xff, 0xd7, 0x04, 0x02, 0x08, 0x0a, 0x37, 0xf3, 0x6f,
    0x74, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x0a};
const size_t TEMPLATE_PCAP_TCP_LEN = sizeof(TEMPLATE_PCAP_TCP);

/*
Template name: TEMPLATE_PCAP_IP6_TCP (-I ip6tcp)
Description: IPv6 TCP header
Wireshark output:
Frame 1: 86 bytes on wire (688 bits), 86 bytes captured (688 bits)
Ethernet II, Src: 00:00:00_00:00:00 (00:00:00:00:00:00), Dst: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Destination: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Source: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Type: IPv6 (0x86dd)
Internet Protocol Version 6, Src: ::1, Dst: ::1
    0110 ....                               = Version: 6
    .... 0000 0000 .... .... .... .... .... = Traffic Class: 0x00 (DSCP: CS0, ECN: Not-ECT)
    .... .... .... 0011 0101 0001 1011 0011 = Flow Label: 0x351b3
    Payload Length: 32
    Next Header: TCP (6)
    Hop Limit: 53
    Source Address: ::1
    Destination Address: ::1
Transmission Control Protocol, Src Port: 1000, Dst Port: 2000, Seq: 1, Ack: 1, Len: 0
    Source Port: 1000
    Destination Port: 2000
    Sequence Number (raw): 815706875
    Acknowledgment number (raw): 484792852
    1000 .... = Header Length: 32 bytes (8)
    Flags: 0x018 (PSH, ACK)
    Window: 224
    Checksum: 0xce0e
    Urgent Pointer: 0
    Options: (12 bytes), No-Operation (NOP), No-Operation (NOP), Timestamps
*/
const unsigned char TEMPLATE_PCAP_IP6_TCP[] = {
    0xd4, 0xc3, 0xb2, 0xa1, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x6b, 0x86, 0x79, 0x64, 0x64, 0x45, 0x02, 0x00,
    0x56, 0x00, 0x00, 0x00, 0x56, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x86, 0xdd, 0x60, 0x03, 0x51, 0xb3, 0x00, 0x20, 0x06, 0x35, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0xe8,
    0x07, 0xd0, 0x30, 0x9e, 0xb2, 0xfb, 0x1c, 0xe5, 0x5a, 0x14, 0x80, 0x18, 0x00, 0xe0, 0xce, 0x0e,
    0x00, 0x00, 0x01, 0x01, 0x08, 0x0a, 0x0e, 0x90, 0x91, 0x5f, 0x14, 0x01, 0x8d, 0x89};
const size_t TEMPLATE_PCAP_IP6_TCP_LEN = sizeof(TEMPLATE_PCAP_IP6_TCP);

/*
Template name: TEMPLATE_PCAP_UDP (-I udp)
Description: IPv4 UDP header
Wireshark output:
Frame 1: 42 bytes on wire (336 bits), 42 bytes captured (336 bits)
Ethernet II, Src: 00:00:00_00:00:00 (00:00:00:00:00:00), Dst: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Destination: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Source: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Type: IPv4 (0x0800)
Internet Protocol Version 4, Src: 127.0.0.1, Dst: 127.0.0.1
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
    Total Length: 28
    Identification: 0xbf86 (49030)
    Flags: 0x00
    ...0 0000 0000 0000 = Fragment Offset: 0
    Time to Live: 64
    Protocol: UDP (17)
    Header Checksum: 0xbd48
    Source Address: 127.0.0.1
    Destination Address: 127.0.0.1
User Datagram Protocol, Src Port: 1000, Dst Port: 2000
    Source Port: 1000
    Destination Port: 2000
    Length: 8
    Checksum: 0xf623
*/
const unsigned char TEMPLATE_PCAP_UDP[] = {
    0xd4, 0xc3, 0xb2, 0xa1, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x97, 0xa4, 0x7e, 0x64,
    0x15, 0x05, 0x0d, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x45, 0x00,
    0x00, 0x1c, 0xbf, 0x86, 0x00, 0x00, 0x40, 0x11, 0xbd, 0x48, 0x7f, 0x00, 0x00, 0x01,
    0x7f, 0x00, 0x00, 0x01, 0x03, 0xe8, 0x07, 0xd0, 0x00, 0x08, 0xf6, 0x23};
const size_t TEMPLATE_PCAP_UDP_LEN = sizeof(TEMPLATE_PCAP_UDP);

/*
Template name: TEMPLATE_PCAP_IP6_UDP (-I ip6udp)
Description: IPv6 UDP header
Wireshark output:
Frame 1: 62 bytes on wire (496 bits), 62 bytes captured (496 bits)
Ethernet II, Src: 00:00:00_00:00:00 (00:00:00:00:00:00), Dst: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Destination: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Source: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Type: IPv6 (0x86dd)
Internet Protocol Version 6, Src: ::1, Dst: ::1
    0110 ....                               = Version: 6
    .... 0000 0000 .... .... .... .... .... = Traffic Class: 0x00 (DSCP: CS0, ECN: Not-ECT)
    .... .... .... 0110 0001 0010 1010 0111 = Flow Label: 0x612a7
    Payload Length: 8
    Next Header: UDP (17)
    Hop Limit: 64
    Source Address: ::1
    Destination Address: ::1
User Datagram Protocol, Src Port: 1000, Dst Port: 2000
    Source Port: 1000
    Destination Port: 2000
    Length: 8
    Checksum: 0xf424
*/
const unsigned char TEMPLATE_PCAP_IP6_UDP[] = {
    0xd4, 0xc3, 0xb2, 0xa1, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x7e, 0x86, 0x79, 0x64, 0x29, 0x81,
    0x06, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0xdd, 0x60, 0x06, 0x12, 0xa7, 0x00, 0x08,
    0x11, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x03, 0xe8, 0x07, 0xd0, 0x00, 0x08, 0xf4, 0x24};
const size_t TEMPLATE_PCAP_IP6_UDP_LEN = sizeof(TEMPLATE_PCAP_IP6_UDP);
