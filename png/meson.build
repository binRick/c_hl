png_srcs = [
  'png.c',
]
png_inc_dirs = [
  '../submodules',
  '../',
]
png_deps = [
     cargs_dep,
     c_stringfn_dep,
     parson_dep,
     fs_dep,
     ansi_codes_dep, 
     bytes_dep,
     c_string_buffer_dep,
     #c_timer_dep,
]
png_lib = static_library('png',
  png_srcs,
  install: false,
  dependencies: png_deps,
  include_directories: png_inc_dirs,
)

png_dep = declare_dependency(
  include_directories: png_inc_dirs,
  link_with: png_lib,
)
