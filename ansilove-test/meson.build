ansilove_test_srcs = [
  'ansilove-test.c',
]
ansilove_include_dirs = [
]
ansilove_test_deps = [
  c_fsio_dep,
  hl_dep,
  c_greatest_dep,
  c_stringfn_dep,
  gd_dep,
  ansilove_dep,
]

if get_option('enable-binaries')
  ansilove_test_exec = executable('ansilove-test',
     ansilove_test_srcs,
     dependencies: ansilove_test_deps,
     include_directories: [
       inc,
       ansilove_include_dirs,
     ],
  )
  if get_option('enable-binary-tests')
    #    test('ansilove-test', ansilove_test_exec, args: [])
  endif
endif
