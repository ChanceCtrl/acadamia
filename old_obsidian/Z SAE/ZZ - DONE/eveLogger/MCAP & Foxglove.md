#motorsports 

A light analysis of this MCAP + FoxGlove for data aqq and storage.

# Quick overview

In short, its a logging library with support for message [[serialization]]. It was created by a company called Foxglove. They offer self-managed storage for robotics data. They also have a (opensource :) tool called Foxglove Studio for visualization. It appears to have an extensive library of extensions and layouts created by other users.

# Support
It has support for both C++ & Python and a fistful of other languages, so that's nice. [Here](https://mcap.dev/spec) is the spec for the actual file format. 

# Layout
MCAP organizes data into messages, channels, and schemas.

## Message
The unit of communication between nodes in the pub/sub system.

## Channel
A stream of messages that have the same type.

## Schema
A description of the structure & messages on a Channel (i.e JSON, Protobuf)

# Management
MCAP files can be stored locally and read by things like Foxglove Studio or Uploaded to something like a file server or Foxglove's Data Platform and read straight from it.

# The benefits
MCAP files would be easier to scale and parse when scaled, Foxglove Studio would make visualizations much easier and useful, and having a proper storage location would make assessing the data a more streamlined process.
