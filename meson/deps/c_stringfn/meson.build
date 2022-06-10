c_stringfn_lib = library('c_stringfn', 
  '../../../submodules/c_stringfn/src/stringfn.c',
  install: false,
  dependencies: [
  ], 
  include_directories: [
    inc,
    '../../../submodules/c_stringfn/include',
  ]
)

c_stringfn_dep = declare_dependency(
  include_directories: [
    inc,
  ], 
  link_with: c_stringfn_lib,
)
