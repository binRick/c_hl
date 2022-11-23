hl_srcs = [
  'hl.c',
]
hl_inc_dirs = [
  '../submodules',
  '../',
]
hl_deps = [
     c_stringfn_dep,
     c_string_buffer_dep,
     c_fsio_dep,
     parson_dep,
     fs_dep,
     ansi_codes_dep, 
     bytes_dep,
     c_kat_dep,
     bat_dep,
]
hl_lib = library('hl',
  hl_srcs,
  install: false,
  dependencies: hl_deps,
  include_directories: hl_inc_dirs,
)

hl_dep = declare_dependency(
  include_directories: hl_inc_dirs,
  link_with: hl_lib,
)
