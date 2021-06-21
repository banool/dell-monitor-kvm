fn main() {
    let mut builder = cxx_build::bridge("src/main.rs");
    builder
        .object("include/libs/libDellMonitorSdkLib.dylib")
        .flag_if_supported("-std=c++14")
        .compile("dell-monitor-sdk");
}
