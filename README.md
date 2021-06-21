# Dell Monitor KVM

This repository uses the SDK provided by Dell (specifically 3.0 [here](https://www.dell.com/support/home/en-us/drivers/driversdetails?driverid=ktgyn)) to control the monitor such that you can switch inputs.

## Development
Development is easy, just run this:

```
cargo build
```

## Usage
Running this is a bit trickier because you need to let the application know at runtime where the linked library is, which actually does all the work of talking to the monitor. On Mac, this looks like:

```
DYLD_LIBRARY_PATH=include/libs cargo run
```

Another option would be to to put the library in the library path and then just run it normally:

```
cp include/libs/libDellMonitorSdkLib.dylib /usr/local/lib
cargo run
```

