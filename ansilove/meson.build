ansilove_srcs = [
  'ansilove.c',
]
ansilove_inc_dirs = [
  '../submodules',
  '../',
]
ansilove_deps = [
     cargs_dep,
     c_stringfn_dep,
     parson_shared_dep,
     fs_dep,
     ansi_codes_dep, 
     bytes_dep,
     c_string_buffer_dep,
     #c_timer_dep,
]
ansilove_lib = static_library('ansilove',
  ansilove_srcs,
  install: false,
  dependencies: ansilove_deps,
  include_directories: ansilove_inc_dirs,
)

ansilove_dep = declare_dependency(
  include_directories: ansilove_inc_dirs,
  link_with: ansilove_lib,
)
