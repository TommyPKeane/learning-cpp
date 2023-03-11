# C++ Standard Template Library

C++ Specifications for Compilers provide detailed requirements ("standards") for a set of definitions and Template-based functionality that should be made available through Header file pre-processor includes in any C++ code files.

Templates are the C++ form of "Generic Programming" whereby the compiler will dynamically create viable C++ code to be compiled, based-on the shorthand, "generic" syntax of the templates.

The "Standard Template Library" (STL) is the collection of these utility templates provided by definition in the C++ Language Standard (the specifications).

Note that each named C++ Language Standard ("spec") -- like C++11 or C++23 -- will have differences from each other in their own Standard Template Libraries, and each C++ compiler will implement its own version of the standard(s). Since the compilers are separate implementations, they may have slight variations, but they ___should___ adhere to the common definitions in the Standard ("spec").

Be sure to check the compiler support if you're using a new STL feature, because it may not necessarily be supported.

<!-- MarkdownTOC -->

- [C++23 STL](#c23-stl)
    - [Build then Run Examples](#build-then-run-examples)
- [References](#references)

<!-- /MarkdownTOC -->

<a id="c23-stl"></a>
## C++23 STL

The examples provided here will leverage functionality up-to-and-including the C++23 Standard _via_ `gcc@12` -- version `12` of the GNU Compiler Collection (GCC) -- installed with `brew` on macOS.

If you're on a macOS system, you simply need to use [`brew.sh`](https://brew.sh/) to run the following command:

```bash
brew install gcc@12
```

Which will install the compiler collection which supports C++ and other languages. You can see the C++23 support in GCC 12 here: https://en.cppreference.com/w/cpp/compiler_support/23 -- where you should note that certain features require `gcc@13`, which (at the time of this repo's initial development) is not available.

One tricky thing here is the issue that macOS requires `gcc` for its own functionality, so when you use `brew` to install `gcc@12`, you'll notice that it won't actually change the default alias for `gcc` in your system PATH:

```bash
❯ which gcc
/usr/bin/gcc

❯ ls -alF `which gcc`
-rwxr-xr-x  76 root  wheel  167120 Jan 11 02:03 /usr/bin/gcc*

❯ gcc --version
Apple clang version 14.0.0 (clang-1400.0.29.202)
Target: arm64-apple-darwin21.6.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

The above commands show that the `gcc` alias is directly pointing at the `/usr/bin/gcc` executable, which, itself, is actually Apple's `clang` (LLVM) compiler. We definitely ___do not___ want to break or change this ... so where did our `brew` version get installed and how do we reference it?

```bash
❯ brew list gcc
/opt/homebrew/Cellar/gcc/12.2.0/bin/aarch64-apple-darwin21-c++-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/aarch64-apple-darwin21-g++-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/aarch64-apple-darwin21-gcc-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/aarch64-apple-darwin21-gcc-ar-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/aarch64-apple-darwin21-gcc-nm-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/aarch64-apple-darwin21-gcc-ranlib-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/aarch64-apple-darwin21-gfortran-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/c++-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/cpp-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/g++-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/gcc-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/gcc-ar-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/gcc-nm-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/gcc-ranlib-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/gcov-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/gcov-dump-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/gcov-tool-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/gfortran
/opt/homebrew/Cellar/gcc/12.2.0/bin/gfortran-12
/opt/homebrew/Cellar/gcc/12.2.0/bin/lto-dump-12
/opt/homebrew/Cellar/gcc/12.2.0/include/c++/ (806 files)
/opt/homebrew/Cellar/gcc/12.2.0/lib/gcc/ (607 files)
/opt/homebrew/Cellar/gcc/12.2.0/libexec/gcc/ (14 files)
/opt/homebrew/Cellar/gcc/12.2.0/share/gcc-12/ (4 files)
/opt/homebrew/Cellar/gcc/12.2.0/share/man/ (11 files)
```

Ah, ok, so if we run `brew list gcc` we can see that the set of GCC compiler applications have all been installed into the `/opt/homebrew/Cellar/` directory, but is there any alias?

Yes, actually you should find that when you ran `brew install`, it automatically ran the `brew link` command to update your PATH, and you'll find that `gcc-12` is actually the alias to the `brew` installation of GCC version 12:

```bash
❯ which gcc-12
/opt/homebrew/bin/gcc-12

❯ ls -alF `which gcc-12`
lrwxr-xr-x  1 USERNAME  admin  31 Sep  5  2022 /opt/homebrew/bin/gcc-12@ -> ../Cellar/gcc/12.2.0/bin/gcc-12

❯ gcc-12 --version
gcc-12 (Homebrew GCC 12.2.0) 12.2.0
Copyright (C) 2022 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

Success!

Ok, so, TLDR: the following STL examples are all going to be built with the command `gcc-12` (or `g++-12` for C++ specifically as a shorthand) on macOS after having run `brew install gcc@12`.

<a id="build-then-run-examples"></a>
### Build then Run Examples

Each example basically follows the same pattern, so out of convenience we've used `direnv` (see the `.envrc` file at in the same directory as this README) to create an alias that makes it simpler to build executables from all these single-file examples.

We've created the following aliases in case you want to try different C++ Standards:

- `c++11_compile`
- `c++17_compile`
- `c++20_compile`
- `c++23_compile`

To use these, you need to first run `direnv allow`, `source ./.aliases.sh`, and then you can `cd` into any of the subdirectories here and run the following on any `example.cpp` file:

1. Build: `c++23_compile ./example.cpp -o example`
1. Run: `./example`

You'll need to use the actual filename instead of `example`, so here's a full _example_ to clarify and show the actual output of each command:

```bash
❯ direnv allow
direnv: loading ~/dev/tommypkeane/learning-cpp/cpp_stl/.envrc
direnv: loading ~/dev/tommypkeane/learning-cpp/.envrc
⚠️  Remember to run `source ./.aliases.sh` to get the bash aliases!

❯ source ./.aliases.sh

❯ cd strings/

❯ c++23_compile ./literals.cpp -o literals

❯ ls -alF literals
-rwxr-xr-x  1 USERNAME  staff  67349 Mar 11 12:30 literals*

❯ ./literals
"👋 Hello, First M. Last! Welcome to C++ and the world of Strings!"
```

Success!

As you can see if you look at `.aliases.sh`, we have created `c++23_compile` as an alias for the command:

```bash
g++-12 -std=c++23 -L/usr/local/lib -I/usr/local/include
```

So that takes care of making sure the common basics of a build are supported without any GNU Makefiles or any such build management, and you just have to then supply the source code files and with the `-o` option we can then give the name for the executable that we want to build.

After that runs (presumably without any errors), we can then see the output by running `./literals` where `literals` is the name of the executable and `./` is the relative path to the new executable.

> ⚠️ A common mistake/confusion that people have is that since we just built `literals` as our executable, it should seem like we'd be able to just use the command `literals` to run it, instead of needing to call `./literals`. But why wouldn't that work? Well, we just built a new executable and it now lives in a directory that very likely is _not_ in our system PATH. So if the current directory is not in the path, then how can the system find the `literals` executable? It can't 😭🙈 Thus, we need to give the explicit (absolute or relative) path to the executable in order to run it. This is a relatively trivial thing, but can be wildly maddening if you forget how this fuzzy-water-electric-abacus we call a "computer" all works 👻.

Unfortunately, we can't innately add aliases through the `direnv allow` command with the `.envrc` file, but if you wanted to remove this one extra step of calling `source`, you can follow the examples at this link on how to add an `export_alias` command into `direnv`: https://github.com/direnv/direnv/issues/73.

<a id="references"></a>
## References

- https://en.cppreference.com/w/
