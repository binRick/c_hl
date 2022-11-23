ansilove_test_srcs = [
  'ansilove-test.c',
]
ansilove_include_dirs = [
]
ansilove_c_args = [
  '-DINCBIN_SILENCE_BITCODE_WARNING'
  ]
ansilove_test_deps = [
  c_fsio_dep,
  hl_dep,ansilove_dep,libansilove_dep,
  c_greatest_dep,
  incbin_dep,
  c_stringfn_dep,
  gd_dep,
  ansilove_dep,
  hl_dep,
]

if get_option('enable-binaries')
  ansilove_test_exec = executable('ansilove-test',
     ansilove_test_srcs,
     dependencies: ansilove_test_deps,
     c_args: ansilove_c_args,
     include_directories: [
       inc,
       ansilove_include_dirs,
     ],
  )
  if get_option('enable-binary-tests')
    test('ansilove-test', ansilove_test_exec, args: [])
  endif
endif
