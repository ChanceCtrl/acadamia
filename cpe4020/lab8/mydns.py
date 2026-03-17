import socket
import struct
import random
import sys


def encode_domain(domain):
    parts = domain.split(".")
    result = b""
    for part in parts:
        result += bytes([len(part)]) + part.encode()
    result += b"\x00"
    return result


def build_query(domain):
    transaction_id = random.randint(0, 65535)
    flags = 0x0100  # standard query
    questions = 1
    header = struct.pack("!HHHHHH", transaction_id, flags, questions, 0, 0, 0)

    qname = encode_domain(domain)
    qtype = 1  # A record
    qclass = 1  # IN
    question = qname + struct.pack("!HH", qtype, qclass)

    return header + question


def parse_response(response):
    # header is first 12 bytes
    header = struct.unpack("!HHHHHH", response[:12])
    answer_count = header[3]

    offset = 12

    # skip question section
    while response[offset] != 0:
        offset += 1
    offset += 5

    # parse answer section
    for _ in range(answer_count):
        # skip name (pointer)
        offset += 2

        rtype, rclass, ttl, rdlength = struct.unpack(
            "!HHIH", response[offset : offset + 10]
        )
        offset += 10

        if rtype == 1 and rdlength == 4:  # IPv4 A record
            ip = socket.inet_ntoa(response[offset : offset + 4])
            return ip

        offset += rdlength

    return None


def main():
    if len(sys.argv) != 2:
        print("Usage: python3 mydns.py <domain>")
        sys.exit(1)

    domain = sys.argv[1]

    query = build_query(domain)

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.settimeout(5)

    dns_server = ("8.8.8.8", 53)

    sock.sendto(query, dns_server)

    try:
        response, _ = sock.recvfrom(512)
    except socket.timeout:
        print("DNS request timed out")
        sys.exit(1)

    sock.close()

    ip = parse_response(response)

    if ip:
        print(f"The IP address for {domain} is {ip}")
    else:
        print("Could not resolve domain")


if __name__ == "__main__":
    main()
