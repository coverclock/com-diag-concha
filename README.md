com-diag-concha
===============

[![Say Thanks!](https://img.shields.io/badge/Say%20Thanks-!-1EAEDB.svg)](https://saythanks.io/to/coverclock)

Copyright 2009-2020 by the Digital Aggregates Corp., Arvada CO 80001-0587 USA.

# License

Licensed under the terms found in LICENSE.txt.

# Abstract

This file is part of the Digital Aggregates Corporation Concha package.
Concha illustrates how to exploit abstraction, encapsulation, inheritance,
and polymorphism in ANSI C. The ideas behind Concha are based on work the
author did for one of the Corporation's clients, but is a fully clean
room reimplementation and is in fact completely incompatible with that
prior commercial intellectual property.

This software is an original work of its authors.

# Implementations

* Sink, Source - generic interfaces to write, read, and push.
* DescriptorSink, DescriptorSource - implements Sink and Source using a file descriptor or a socket.
* StreamSink, StreamSource - implements Sink and Source using a FILE * object.
* FileSink, FileSource - implements a StreamSink and StreamSource using a file.
* BufferSink, BufferSource - implements Sink and Source using a fixed buffer.
* NullSink, NullSource - implements a Sink that is the bit bucket, and a Source that always returns EOF.
* ClosingSink, ClosingSource - once EOF is observed, it is guaranteed to be returned henchforth.
* UnclosingSink, UnclosingSource - like Sink and Source except close is ignored.
* CompositeSource - composites two Sources such that EOF on the first results in that and subsequent reads being redirected to the second.
* ExpanderSink - composites two Sinks such that writes are done to both.
* BoundedSink, BoundedSource - implements a Sink and a Source that have a byte limit after which EOF is returned.
* Fletcher8Sink, Fletcher8Source - implements a Sink that appends a Fletcher8 checksum at EOF, and a Source that checks the Fletcher 8 checksum at input.
* RingBuffer - implements a Sink and Source against a common ring buffer.
* SpanningSink, SpanningSource -
* DescriptorSpanningSink, DescriptorSpanningSource -

# Repositories

<https://github.com/coverclock/com-diag-concha>

# Contact

Chip Overclock    
Digital Aggregates Corporation    
3440 Youngfield Street, Suite 209    
Wheat Ridge CO 80033 USA    
http://www.diag.com    
mailto:coverclock@diag.com    

# Soundtrack

<https://www.youtube.com/playlist?list=PLd7Yo1333iA9Cxg0o6L5AONAC7AgrgPhC>
