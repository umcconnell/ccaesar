# ccaesar

[![test](https://github.com/umcconnell/ccaesar/actions/workflows/test.yml/badge.svg)](https://github.com/umcconnell/ccaesar/actions/workflows/test.yml)

Caesar cipher CLI. Written in C.

## Table of Contents

-   [Getting Started](#getting-started)
    -   [Prerequisites](#prerequisites)
    -   [Initial setup](#initial-setup)
-   [Using](#using)
    -   [Building](#building)
    -   [Running](#running)
    -   [Installing](#installing)
    -   [Testing](#testing)
    -   [Benchmarking](#benchmarking)
-   [Contributing](#contributing)
-   [Versioning](#versioning)
-   [Authors](#authors)
-   [License](#license)

## Getting Started

These instructions will get you a copy of the project up and running on your
local machine for development and testing purposes.

### Prerequisites

You will need a C compiler and [GNU Make](https://www.gnu.org/software/make/)
to compile the code. On Windows, it's probably easiest to use
[WSL](https://docs.microsoft.com/en-us/windows/wsl/).

_Optional requirements_:

To test the program, you will need to intall
[valgrind](https://www.valgrind.org/) on your machine. See [Testing](#testing)
for more informarion.

To benchmark the binary, you will need to install
[hyperfine](https://github.com/sharkdp/hyperfine) on your machine. See
[Benchmarking](#benchmarking) for more information.

### Initial setup

Clone the git repository and navigate into the folder.

```bash
git clone https://github.com/umcconnell/ccaesar.git
cd ccaesar/
```

## Using

### Building

To be able to run the program, it must first be compiled. Compile the program
using make:

```bash
make
```

### Running

All examples in this section assume you have compiled the program. See the
["Building" section](#building) for compilation instructions.

You can run the program by piping your text into `ccaesar` or inputting it
directly in interactive mode.

If you're piping in text over `STDIN`, you can for example run the following
command, using the provided example text files:

```bash
cat test/test2.txt | ./ccaesar -s 7
```

If you're using interactive mode, just run:

```
./ccaesar -s 7
```

For a list of all available options and examples, run:

```
./ccaesar --help
```

### Installing

Assuming you've compiled the program as outlined in the
["Building" section](#building), you can install the binary.

First, make it executable:

```bash
chmod a+x ./ccaesar
```

For a system-wide installation, `/usr/local/bin` is the recommended location to
place the binary in:

```
sudo cp ./ccaesar /usr/local/bin
```

### Testing

The tests use [valgrind](https://www.valgrind.org/) to check for memory issues.
Make sure you've installed it before continuing.

To test the program, use make:

```
make test
```

### Benchmarking

Benchmarking is done using [hyperfine](https://github.com/sharkdp/hyperfine).
Make sure you've installed it before continuing.

To benchmark the binary, use make:

```
make bench
```

Using [James Joyce's Ulysses](test/test2.txt) as input to `ccaesar`, yields
the following results on a laptop (Intel i7-9750H):

```
$ hyperfine --warmup 3 'cat test/test2.txt | ./ccaesar -s 7 -c'

Benchmark #1: cat test/test2.txt | ./ccaesar -s 7 -c
  Time (mean ± σ):      14.5 ms ±   1.0 ms    [User: 14.1 ms, System: 2.3 ms]
  Range (min … max):    13.3 ms …  20.7 ms    180 runs
```

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) and
[CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md) for details on our code of conduct, and
the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available,
see the [tags on this repository](https://github.com/umcconnell/python-boilerplate-repo/tags).

## Authors

Ulysse McConnell - [umcconnell](https://github.com/umcconnell/)

See also the list of
[contributors](https://github.com/umcconnell/python-boilerplate-repo/contributors)
who participated in this project.

## License

This project is licensed under the MIT License - see the
[LICENSE](LICENSE) file for details.
