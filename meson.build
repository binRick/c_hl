project('c_hl', ['c'],
  default_options: [
   'warning_level=0',
   'c_std=gnu99',
  ]
)
#############################################################
cc = meson.get_compiler('c')
cmake = import('cmake')
#//***********************************************************/
osx_ldflags = []
deps = []
bin_srcs = []
submodule_srcs = []
#############################################################
fs = import('fs')
gnome = import('gnome')
pkg_config = import('pkgconfig')
#############################################################
config = configuration_data()
version = run_command('git', 'describe', '--tags')
config.set('version', version.stdout().strip())
add_project_arguments('-D_GNU_SOURCE', language : 'c')
add_project_arguments('-DDBG_H_DEF_ONCE', language : 'c')
add_project_arguments('-DDBG_H_NO_WARNING', language : 'c')
add_project_arguments('-DASSERTF_DEF_ONCE', language : 'c')
add_project_arguments('-DLOG_USE_COLOR', language : 'c')
add_project_arguments('-DLOG_LEVEL=TRACE', language : 'c')
add_project_arguments('-Wno-pragma-once-outside-header', language : 'c')
add_project_arguments('-Wno-incompatible-pointer-types', language : 'c')
add_project_arguments('-Wno-pointer-sign', language : 'c')
add_project_arguments('-Wno-unused-value', language : 'c')
add_project_arguments('-Wno-gnu-alignof-expression', language : 'c')
add_project_arguments('-Wno-varargs', language : 'c')
add_project_arguments('-Wno-return-type', language : 'c')
#############################################################################
osx_ldflags += ['-Wl,-framework,CoreFoundation']
osx_ldflags += '-Wl,-framework,Carbon'
osx_ldflags += ['-Wl,-framework,Foundation', '-Wl,-framework,AppKit']
add_project_link_arguments(osx_ldflags, language : ['objc', 'c'])
#############################################################################
inc = include_directories(
  'submodules/',
  './',
  '../',
  '../../',
  '../../../',
  '../submodules',
)
#//***********************************************************/
cargs_dep = dependency('cargs',fallback:['cargs', 'cargs_dep'])
parson_shared_dep = dependency('parson',fallback:['parson', 'parson_shared_dep'])
gd_dep = cc.find_library('gd', required: true)
m_dep = cc.find_library('m', required: false)
pwd_bin = find_program('pwd', required : true)
pwd = run_command(pwd_bin, check: true).stdout().strip()
#ansilove_dep = cmake.subproject('ansilove')
#//////////////////////////////////////////////////////////////////////
subdir('meson/deps/greatest')
subdir('meson/deps/c_stringfn')
subdir('meson/deps/ansicodes')
subdir('meson/deps/bytes')
subdir('meson/deps/c_string_buffer')
subdir('meson/deps/fs')
subdir('meson/deps/c_fsio')
subdir('meson/deps/c_timer')
subdir('submodules/meson_deps/meson/deps/c_kat')
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
