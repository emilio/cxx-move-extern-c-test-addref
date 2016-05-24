use std::ptr;
use std::mem;

static TEST: i32 = 0;

#[repr(C)]
#[derive(Debug)]
pub struct already_AddRefed<T> {
    ptr: *const T,
}

impl<T> already_AddRefed<T> {
    fn take(&mut self) -> *const T {
        mem::replace(&mut self.ptr, ptr::null())
    }
}

#[no_mangle]
pub extern "C" fn UseAddRefed(mut t: already_AddRefed<i32>) -> already_AddRefed<i32> {
    println!("rust: UseAddRefed");
    let ptr = t.take();
    println!("rust: UseAddRefed after take: {:?}", ptr);
    println!("rust: returning ptr: {:?}", &TEST as *const _);

    already_AddRefed {
        ptr: &TEST as *const _
    }
}

#[no_mangle]
pub extern "C" fn UseAddRefedPtr(mut t: *mut already_AddRefed<i32>) {
    println!("rust: UseAddRefedPtr: {:?}", t);
}
