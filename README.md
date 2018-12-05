shacl variant
==================

In the C++17 standard, a templated class representing a type-safe union called
[`std::variant`](https://en.cppreference.com/w/cpp/utility/variant) was
introduced to the standard library, along with corresponding infrastructure for
working with variant instances. A component of this infrastructure is the
[`std::visit`](https://en.cppreference.com/w/cpp/utility/variant/visit) function
template, which, in combination with variant, provides an flexible and efficient
alternative to traditional inheritance-based runtime polymorphism.

For those unfamiliar with variant and visitation, a thorough introduction to
these concepts and techniques is beyond the scope of this README, but there are
introductory resources available online. See the *Recommended Introductory
Material* section at the end of this README.

This library provides:

+ additional and extended infrastructure for working with `std::variant`
+ a unified interface to the C++17 `std::variant` and C++14 `mpark::variant`
  (shipped with this library as an optional depencency).

shacl::Variant Class Template and shacl::variant Namespace
------------------------------------------------------------------

At the center of this library is the `shacl::Variant` type alias template and
the `shacl::variant` namespace. When compiling against the C++17 standard, the
alias template refers to the `std::variant` class template. When compiling with
against the C++14 standard, the standard library variant implementation is
unavailable. Rather than require C++17, this library rebases on a variant
implementation for C++11/14 provided by Micheal Park, the author of the libc++
variant implementation. Micheal's variant backport, along with the associated
support instructure, are defined within the `mpark` namespace. The
`shacl::Variant` alias and `shacl::variant` to shield library consumers from
this C++ standard dispatching.

Standard Capabilities
------------------------

The standard library provides a number of facilities for working with variant
types. These features are included in the `shacl::variant` namespace, albeit
under slightly different names in same cases.

+ `std::variant` => `shacl::Variant`
+ `std::bad_variant_access` => `shacl::variant::bad_access`
+ `std::get_if` => `shacl::variant::get_if`
+ `std::get` => `shacl::variant::get`
+ `std::holds_alternative` => `shacl::variant::holds_alternative`
+ `std::monostate` => `shacl::variant::monostate`
+ `std::variant_alternative_t` => `shacl::variant::alternative_t`
+ `std::variant_alternative` => `shacl::variant::alternative`
+ `std::variant_npos` => `shacl::variant::npos`
+ `std::variant_size_v` => `shacl::variant::size_v`
+ `std::variant_size` => `shacl::variant::size`

Extended Capabilities
------------------------

In addition to the standard library facilities, this library provides a small
amount of additional functionality.

+ [shacl::variant::cast](src/shacl/variant/cast/README.md)
+ [shacl::variant::visit](src/shacl/variant/visit/README.md)
+ [shacl::variant::map](src/shacl/variant/map/README.md)

Build System
--------------

As a header-only library, `shacl::variant` has no compiled components.
Nevertheless, a [CMake](https://cmake.org/overview/) build system is provided to allow easy testing, installation, and subproject composition on many platforms and operating systems.

#### Dependencies

The shacl::variant library is dependent on two other shared component libraries
(shacl) libraries:

+ empty base optimization (ebo)
+ compile time type traits (trait)

In addition, the shacl::variant library is dependent on the boost heterogenous
combinators libary (hana). Beyond the requirements of the library itself, the
tests depend on the Catch2 unit testing library.

Given an internet connection, by default, these libraries will be downloaded
without any need for user intervention. If this behavior is undesirable, users
can opt to consume a local installation of these libraries by setting the
`git.submodule.packages` CMake option to `OFF`. Non-standard installation roots
to these packages can be specified using the `CMAKE_PREFIX_PATH` environment
variable or CMake option. See the CMake [`find_package`](https://cmake.org/cmake/help/v3.0/command/find_package.html)
documentation for more information.

#### Testing
The shacl::variant library is distributed with a small suite of tests.
When shacl::variant is configured as the highest level CMake project, this suite of executables is built by default.
These test executables are integrated with the CMake test driver program, [CTest](https://cmake.org/cmake/help/latest/manual/ctest.1.html).

CMake supports a number of backends for compilation and linking.

To use a static configuration build tool, such as GNU Make or Ninja:

```sh
cd <shacl::variant source directory>
mkdir build
cd build

# Configure the build
cmake -D CMAKE_BUILD_TYPE=<Debug | Release> \
      -G <"Unix Makefiles" | "Ninja"> ..

# build the tests
< make | ninja | cmake --build . >

# run the tests
< make test | ninja test | cmake --build . --target test | ctest >
```

To use a dynamic configuration build tool, such as Visual Studio or Xcode:

```sh
cd <shacl::variant source directory>
mkdir build
cd build

# Configure the build
cmake -G <"Visual Studio 14 2015 Win64" | "Xcode"> ..

# build the tests
cmake --build . --config <Debug | Release>

# run the tests via ctest...
ctest --build-config <Debug | Release>

# ... or via CMake build tool mode...
cmake --build . --config <Debug | Release> --target test
```

Of course the **build** and **test** steps can also be executed via the **all** and **test** targets, respectively, from within the IDE after opening the project file generated during the configuration step.

This testing is also configured to operate as a client to the [CDash](https://www.cdash.org/) software quality dashboard application. Please see the [Kitware documentation](https://cmake.org/cmake/help/latest/manual/ctest.1.html#dashboard-client) for more information on this mode of operation.

#### Installation

The shacl::variant library build system provides an installation target and support for downstream consumption via CMake's [`find_package`](https://cmake.org/cmake/help/v3.0/command/find_package.html) intrinsic function.
CMake allows installation to an arbitrary location, which may be specified by defining `CMAKE_INSTALL_PREFIX` at configure time.
In the absense of a user specification, CMake will install shacl::variant to conventional location based on the platform operating system.

To use a static configuration build tool, such as GNU Make or Ninja:

```sh
cd <shacl::variant source directory>
mkdir build
cd build

# Configure the build
cmake [-D CMAKE_INSTALL_PREFIX="path/to/installation"] \
      [-D BUILD_TESTING=False]                         \
      -D CMAKE_BUILD_TYPE=Release                      \
      -G <"Unix Makefiles" | "Ninja"> ..

# install shacl::variant
<make install | ninja install | cmake --build . --target install>
```

To use a dynamic configuration build tool, such as Visual Studio or Xcode:

```sh
cd <shacl::variant source directory>
mkdir build
cd build

# Configure the project
cmake [-D CMAKE_INSTALL_PREFIX="path/to/installation"] \
      [-D BUILD_TESTING=False]                         \
      -G <"Visual Studio 14 2015 Win64" | "Xcode"> ..

# install shacl::variant
cmake --build . --config Release --target install
```

Note that the last command of the installation sequence may require administrator privileges (e.g. `sudo`) if the installation root directory lies outside your home directory.

This installation
+ copies the shacl::variant header files to the `include/shacl` subdirectory of the installation root
+ generates and copies several CMake configuration files to the `share/cmake/shacl/variant` subdirectory of the installation root

This latter step allows downstream CMake projects to consume shacl::variant via `find_package`, e.g.

```cmake
find_package( shacl REQUIRED COMPONENTS variant )
target_link_libraries( MyTarget PUBLIC shacl::variant )
```

If `shacl::variant` was installed to a non-conventional location, it may be necessary for downstream projects to specify the shacl installation root directory via either

+ the `CMAKE_PREFIX_PATH` configuration option,
+ the `CMAKE_PREFIX_PATH` environment variable, or
+ `shacl_DIR` environment variable.

Please see the [Kitware documentation](https://cmake.org/cmake/help/v3.0/command/find_package.html) for more information.

In addition, shacl::variant supports packaged relocatable installations via [CPack](https://cmake.org/cmake/help/latest/manual/cpack.1.html).
Following configuration, from the build directory, invoke cpack as follows to generate a packaged installation:

```sh
cpack -G <generator name> -C Release
```

The list of supported generators varies from platform to platform. See the output of `cpack --help` for a complete list of supported generators on your platform.

Recommended Introductory Material
------------------------

In suggested order

1. [A comparison of variant visitation to tradition inheritance-based polymophism](https://akrzemi1.wordpress.com/2016/02/27/another-polymorphism/)
1. [A gentle introduction to the classes and functions of the <variant> header](https://arne-mertz.de/2018/05/modern-c-features-stdvariant-and-stdvisit/)
1. [A detailed introduction to the classes and functions of the <variant> header](https://www.bfilipek.com/2018/06/variant.html#performance-memory-considerations)

### Related Material

+ [Using Types Effectively](https://www.youtube.com/watch?v=ojZbFIQSdl8)
+ [The (Functional) Functor Pattern in C++](https://www.fpcomplete.com/blog/2012/07/the-functor-pattern-in-c)
