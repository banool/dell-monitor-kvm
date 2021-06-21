#[cxx::bridge]
mod ffi {

    #[repr(i32)]
    enum MONITOR_CODE {
        MONITOR_SUCCESS = 0,
        MONITOR_FAILURE = -1,      /* General failure */
        MONITOR_ERR_TIMEOUT = 1,   /* Function times out */
        MONITOR_ERR_PARAMS = 2, /* Errors in parameters, out of range, invalid or unsupported modes */
        MONITOR_ERR_CONNECT = 3, /* Errors in connecting to monitor */
        MONITOR_ERR_COMMS = 4,  /* Errors in communicating with monitor */
        MONITOR_ERR_STATE = 5,  /* Monitor in wrong state for API call */
        MONITOR_ERR_NOSUPPORT = 6, /* Monitor does not support this API call */
        MONITOR_ERR_CHECKSUM = 7, /* Checksum error */
        MONITOR_ERR_MODULEOFF = 8, /* Error due to related module is powered off. eg) GetCalibrationModulePowerState = OFF */
        MONITOR_ERR_INUSE = 9,     /* Monitor is currently connected to another application */
    }

    unsafe extern "C++" {
        include!("dell-monitor-kvm/include/headers/UP_API.h");
        include!("dell-monitor-kvm/include/headers/UP_DATA.h");

        type MONITOR_CODE;

        fn ConnectMonitor(monitor: u16) -> MONITOR_CODE;
    }
}

fn main() {
    ffi::ConnectMonitor(0);
}
