fn main() {
    // Everything to do with linked libraries here is only for
    // checking stuff at compile time. When it comes to running
    // the binary, you have to let it know where it can find the
    // library, it is not linked into the binary. Check the README.
    let mut builder = cxx_build::bridge("src/main.rs");
    builder
        .flag_if_supported("-std=c++14")
        .compile("dell-monitor-sdk");
    // Note how the dylib name does not have the `lib` prefix.
    println!("cargo:rustc-link-lib=dylib=DellMonitorSdkLib");
    // This only tells cargo where to find the library at compile
    // time, not the binary where to find the library at runtime.
    println!("cargo:rustc-link-search=native=include/libs");
}
