

fn main() {
    let mut builder = cxx_build::bridge("src/main.rs");
    builder
        .object("include/libs/libDellMonitorSdkLib.dylib")
        .compile("dell-monitor-sdk");
}
