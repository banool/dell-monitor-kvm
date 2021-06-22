#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

use anyhow::{bail, Result};

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

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
        call(Initialize(), "Initialize")?;
    }

    let num_monitors: *mut u8 = &mut 0;
    unsafe {
        call(GetAvailableMonitors(num_monitors), "GetAvailableMonitors" )?;
        if *num_monitors != 2 {
            bail!("Failed to find all monitors, only found {}", *num_monitors);
        }
    }

    unsafe {
        call(ConnectMonitor(1), "ConnectMonitor")?;
    }

    Ok(())
}
