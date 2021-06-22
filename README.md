# Dell Monitor KVM

This repository uses the SDK provided by Dell (specifically 3.1.0 [here](https://www.dell.com/support/home/en-us/drivers/driversdetails?driverid=ktgyn)) to control the monitor such that you can switch inputs.

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

You may not want to do this on Mac though because of the security bullshit.

To run this E2E, try this:
```
rm DellMonitorSdk.log && DYLD_LIBRARY_PATH=include/libs cargo run; cat DellMonitorSdk.log
```

Current state is I can see the monitors from the trace output of the library, but it still says there are zero monitors. Connecting to the monitor fails too. See:

```
# Two monitors
2021-06-21 19:09:47.189 [25867] HID   --- AvailableDevices ---
2021-06-21 19:09:47.189 [25867] HID   [0] Device 000000451 / 00000CA01 with path id:4294969356
2021-06-21 19:09:47.192 [25867] HID   [1] Device 000000451 / 00000CA01 with path id:4294981423

# It still returns 0 for GetAvailableMonitors
2021-06-21 19:05:51.303 [20115] DEBUG UP_API:GetAvailableMonitors()-SUCCESS => 0
```

