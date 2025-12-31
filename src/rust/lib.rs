use std::ffi::CStr;
use std::os::raw::c_char;
use std::fs::File;
use std::io::copy;
use reqwest::blocking::get;

#[no_mangle]
pub extern "C" fn r_download(url: *const c_char, target: *const c_char) -> i32 {
    if url.is_null() || target.is_null() {
        return -1;
    }

    let c_url = unsafe { CStr::from_ptr(url) };
    let c_target = unsafe { CStr::from_ptr(target) };

    let url_str = match c_url.to_str() {
        Ok(s) => s,
        Err(_) => return -2,
    };
    let target_str = match c_target.to_str() {
        Ok(s) => s,
        Err(_) => return -3,
    };

    match get(url_str) {
        Ok(mut resp) => {
            if !resp.status().is_success() {
                return -4;
            }
            match File::create(target_str) {
                Ok(mut file) => {
                    if copy(&mut resp, &mut file).is_err() {
                        return -5;
                    }
                }
                Err(_) => return -6,
            }
        }
        Err(_) => return -7,
    }

    0
}
