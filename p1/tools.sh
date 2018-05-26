# type '. tools.sh' to add gcc6.2 to your path

# Add gcc-6.2 to the front of the path, so it comes before the default gcc
export PATH=/proj/spear0/gcc-6.2/bin:/proj/spear0/gdb-7.11.1/bin:/proj/spear0/cmake-3.6.2/bin:/proj/spear0/python-2.7.12/bin:/proj/spear1/llvm/bin:$PATH
# Add gcc's run-time libraries
export LD_LIBRARY_PATH=/proj/spear0/gcc-6.2/lib64:/proj/spear0/gcc-6.2/lib:/proj/spear0/gdb-7.11.1/lib:/proj/spear1/llvm/lib:$LD_LIBRARY_PATH

# disable some password request popups when X-forwarding
unset SSH_ASKPASS

# Installation Notes
#   GCC
#     Source Files:        gcc-6.2.0.tar.bz2
#     Configuration Flags: --prefix=/proj/spear0/gcc-6.2 --enable-languages=c,c++,lto,go --enable-lto --enable-multilib
#
#   GDB
#     Source Files:        gdb-7.11.1.tar.gz
#     Configuration Flags: --prefix=/proj/spear0/gdb-7.11.1 --enable-tui
#
#   CMAKE
#     Binary Files:        cmake-3.6.2-Linux-x86_64.tar.gz
#
#   PYTHON
#     Source Files:        Python-2.7.12.tgz
#     Configuration Flags: --prefix=/proj/spear0/python-2.7.12
#
#   LLVM
#     Source Files:        CLANG:   cfe-3.9.0.src.tar.xz
#                          RUNTIME: compiler-rt-3.9.0.src.tar.xz
#                          LLVM:    llvm-3.9.0.src.tar.xz
#     Configuration Flags: CC=/proj/spear0/gcc-6.2/bin/gcc CXX=/proj/spear0/gcc-6.2/bin/g++ cmake -DCMAKE_INSTALL_PREFIX=/proj/spear1/llvm ../llvm

