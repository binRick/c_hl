ansilove_srcs = [
  'ansilove.c',
]
ansilove_inc_dirs = [
  './',
]
ansilove_deps = [
     cargs_dep,
     c_stringfn_dep,
     parson_dep,
     module_dep,
     #     glib_dep,
     #     vips_dep,
     msf_gif_dep,
     qoir_dep,qoi_dep,
     fs_dep,
     gd_dep,
     ansi_codes_dep, 
     bytes_dep,
     c_string_buffer_dep,
     hl_dep,
     libansilove_dep,
]
ansilove_lib = library('ansilove',
  ansilove_srcs,
  install: false,
  dependencies: ansilove_deps,
  include_directories: ansilove_inc_dirs,
)

ansilove_dep = declare_dependency(
  include_directories: ansilove_inc_dirs,
  link_with: ansilove_lib,
)
