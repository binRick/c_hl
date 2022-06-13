project('c_hl', ['c'],default_options:['warning_level=0','c_std=gnu99'])
cc = meson.get_compiler('c')
inc = [
  include_directories(
   './',
  ),
]
pwd = meson.current_source_dir()
meson_deps_dir = join_paths(meson.current_source_dir(),'submodules/meson_deps')
#############################################################################
subdir('submodules/meson_deps/meson/args')
subdir('submodules/meson_deps/meson/inc')
#############################################################################
subdir('submodules/meson_deps/meson/deps/gd')
subdir('submodules/meson_deps/meson/deps/ansicodes')
subdir('submodules/meson_deps/meson/deps/parson')
subdir('submodules/meson_deps/meson/deps/cargs')
subdir('submodules/meson_deps/meson/deps/djbhash')
subdir('submodules/meson_deps/meson/deps/c_stringfn')
subdir('submodules/meson_deps/meson/deps/c_string_buffer')
subdir('submodules/meson_deps/meson/deps/asprintf')
subdir('submodules/meson_deps/meson/deps/uuid4')
subdir('submodules/meson_deps/meson/deps/c_fsio')
subdir('submodules/meson_deps/meson/deps/bytes')
subdir('submodules/meson_deps/meson/deps/ms')
subdir('submodules/meson_deps/meson/deps/timestamp')
subdir('submodules/meson_deps/meson/deps/slug')
subdir('submodules/meson_deps/meson/deps/greatest')
subdir('submodules/meson_deps/meson/deps/fs')
subdir('submodules/meson_deps/meson/deps/c_timer')
#//////////////////////////////////////////////////////////////////////
subdir('meson/deps/ansicodes')
subdir('meson/deps/c_kat')
subdir('meson/deps/libansilove')
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
