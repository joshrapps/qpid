# Qpid Python

This distribution contains a Python client implementation and AMQP
conformance tests for Apache Qpid.

Apache Qpid is a high speed, language independent, platform
independent enterprise messaging system. It currently provides two
messaging brokers (one implemented in C++, one implemented in Java),
and messaging client libraries for Java JMS, C++, C# .NET, Python,
Ruby, and WCF. The messaging protocol for Apache Qpid is AMQP
(Advanced Message Queuing Protocol). You can read more about Qpid
here:

    http://qpid.apache.org/

Documentation can be found here:

    http://qpid.apache.org/documentation.html

## Getting started

1. Make sure the Qpid Python client libraries are on your PYTHONPATH.
   Extract the archive and add the local directory to your PYTHONPATH:

        $ tar -xf qpid-python-VERSION.tar.gz
        $ cd qpid-python-VERSION
        $ export PYTHONPATH=$PWD:$PYTHONPATH

2. Make sure a broker is running.

3. Run the 'hello' example from qpid-0.8/python/examples/api:

        $ cd examples/api
        $ ./hello
        Hello world!

## Examples

The examples/api directory contains several examples.

Read examples/README.txt for further details on these examples.

## Running the tests

The "tests" directory contains a collection of unit tests for the
python client. The "tests\_0-10", "tests\_0-9", and "tests\_0-8"
directories contain protocol level conformance tests for AMQP brokers
of the specified version.

The qpid-python-test script may be used to run these tests. It will by
default run the python unit tests and the 0-10 conformance tests:

1. Run a broker on the default port.

2. Run the tests:

        $ ./qpid-python-test

If you wish to run the 0-8 or 0-9 conformence tests, they may be
selected as follows:

1. Run a broker on the default port.

2. Run the tests:

        $ ./qpid-python-test tests_0-8.*

        [or]

        $ ./qpid-python-test tests_0-9.*

See the qpid-python-test usage for for additional options:

    $ ./qpid-python-test -h

## Installation

Other Qpid components depend on Qpid Python for testing.  You can use
setup.py to install Qpid Python to a standard location:

    # User-local install

    $ python setup.py install --user
    $ export PYTHONPATH=$HOME/.local/lib/python2.7/site-packages
    $ export PATH=$HOME/.local/bin:$PATH

    [or]

    # System-wide install

    $ sudo python setup.py install
