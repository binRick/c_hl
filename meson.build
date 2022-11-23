project('c_hl', ['c'],default_options:['warning_level=0','c_std=gnu99','default_library=static'],
  subproject_dir: 'submodules/c_deps/subprojects',
  version: '0.0.1',
  )
cc = meson.get_compiler('c')
pwd = meson.current_source_dir()
c_deps_dir = join_paths(meson.current_source_dir(),'submodules/c_deps')
inc = [
  include_directories(
   'submodules/c_deps',
   'submodules/c_deps/submodules/c_ansi',
   'submodules/c_deps/submodules',
   'submodules/c_deps/submodules/reproc',
   'submodules/c_deps/submodules/reproc/reproc',
   'submodules/c_deps/submodules/reproc/reproc/include',
   'submodules/c_deps/submodules/reproc/reproc/include/reproc',
   'submodules/c_deps/meson/deps/libansilove',
   'submodules/c_deps/meson/deps',
   '.',
  ),
]
#############################################################################
subdir('submodules')
#//////////////////////////////////////////////////////////////////////
subdir('submodules/c_deps/meson/deps/c_kat')
subdir('submodules/c_deps/meson/deps/libansilove')
#//////////////////////////////////////////////////////////////////////
subdir('bat')
subdir('hl')
#//////////////////////////////////////////////////////////////////////
subdir('png')
#//////////////////////////////////////////////////////////////////////
subdir('ansilove')
#//////////////////////////////////////////////////////////////////////
subdir('hl-cli')
subdir('hl-test')
subdir('png-test')
subdir('ansilove-test')
