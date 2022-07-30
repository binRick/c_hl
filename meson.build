project('c_hl', ['c'],default_options:['warning_level=0','c_std=gnu99'],
  subproject_dir: 'submodules/meson_deps/subprojects',
  version: '0.0.1',
  )
cc = meson.get_compiler('c')
pwd = meson.current_source_dir()
meson_deps_dir = join_paths(meson.current_source_dir(),'submodules/meson_deps')
inc = [
  include_directories(
   'submodules/meson_deps',
   'submodules/meson_deps/submodules/c_ansi',
   'submodules/meson_deps/submodules',
   'submodules/meson_deps/meson/deps/libansilove',
   'submodules/meson_deps/meson/deps',
   '.',
  ),
]
#############################################################################
subdir('submodules')
#//////////////////////////////////////////////////////////////////////
subdir('submodules/meson_deps/meson/deps/c_kat')
subdir('submodules/meson_deps/meson/deps/libansilove')
#//////////////////////////////////////////////////////////////////////
subdir('hl')
subdir('hl-test')
#//////////////////////////////////////////////////////////////////////
subdir('png')
subdir('png-test')
#//////////////////////////////////////////////////////////////////////
subdir('ansilove')
subdir('ansilove-test')
#//////////////////////////////////////////////////////////////////////
