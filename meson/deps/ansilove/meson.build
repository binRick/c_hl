ansilove_lib = library('ansilove', 
  '../../../submodules/libansilove/include/ansilove.h',
  install: false,
  dependencies: [
  ], 
  include_directories: [
    inc,
    '../../../submodules/libansilove/include',
    '../../../submodules/libansilove/src',
  ]
)

ansilove_dep = declare_dependency(
  include_directories: [
    inc,
    '../../../submodules/libansilove/include',
    '../../../submodules/libansilove/src',
  ], 
  link_with: ansilove_lib,
)
