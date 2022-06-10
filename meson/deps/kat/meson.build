kat_lib = static_library('kat', 
  '../../../submodules/kat/hashtable.c',
  '../../../submodules/kat/highlight.c',
  install: false, 
  dependencies: [], 
  include_directories: [
    '../../../submodules/kat',
    '../../../submodules/kat/include',
  ]
)
kat_dep = declare_dependency(
  include_directories: [
    '../../../submodules/kat',
    '../../../submodules/kat/include',
  ], 
  link_with: kat_lib,
)
