#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("dell-monitor-kvm/include/headers/UP_API.h");

        fn GetAvailableMonitors() -> u8;
    }
}

fn main() {
    let client = ffi::GetAvailableMonitors();
}
