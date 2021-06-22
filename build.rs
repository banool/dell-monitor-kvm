extern crate bindgen;

use std::path::PathBuf;

// Everything to do with linked libraries here is only for
// checking stuff at compile time. When it comes to running
// the binary, you have to let it know where it can find the
// library, it is not linked into the binary. Check the README.
fn main() {

    // Note how the dylib name does not have the `lib` prefix.
    println!("cargo:rustc-link-lib=dylib=DellMonitorSdkLib");
    // This only tells cargo where to find the library at compile
    // time, not the binary where to find the library at runtime.
    println!("cargo:rustc-link-search=native=include/latest/libs");

    let bindings = bindgen::Builder::default()
        .header("include/latest/headers/UP_API.h")
        .header("include/latest/headers/UP_DATA.h")
        .blocklist_type("tm")
        .blocklist_function("SetDateTime")
        .blocklist_function("GetDateTime")
        .rustified_enum("monitor_code")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings");

    // Write the bindings to the $OUT_DIR/bindings.rs file.
    let out_path = PathBuf::from(std::env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
