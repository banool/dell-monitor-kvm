#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

use anyhow::{bail, Result};

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

pub const NUM_EXPECTED_MONITORS: u8 = 2;

fn call(res: MONITOR_CODE, desc: &str) -> Result<()> {
    match res {
        MONITOR_CODE::MONITOR_SUCCESS => {
            println!("Call {} succeeded", desc);
            Ok(())
        },
        wildcard => bail!("Call {} failed with {:?}", desc, wildcard),
    }
}


fn main() -> Result<()> {
    unsafe {
        call(SetDebugLevel(4), "SetDebugLevel")?;
    }

    unsafe {
        call(Initialize(), "Initialize")?;
    }

    unsafe {
        let sdk_version: *mut u16 = &mut 0;
        call(GetVersionSDK(sdk_version), "GetVersionSDK")?;
        println!("SDK version: {}", *sdk_version);
    }

    unsafe {
        let num_monitors: *mut u8 = &mut 100;
        call(GetAvailableMonitors(num_monitors), "GetAvailableMonitors" )?;
        if *num_monitors != NUM_EXPECTED_MONITORS {
            bail!("Failed to find all {} monitors, only found {}", NUM_EXPECTED_MONITORS, *num_monitors);
        }
    }

    unsafe {
        call(ConnectMonitor(0), "ConnectMonitor")?;
    }

    unsafe {
        call(DisconnectMonitor(), "DisconnectMonitor")?;
    }


    Ok(())
}
