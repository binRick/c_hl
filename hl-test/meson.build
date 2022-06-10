hl_test_srcs = [
  'hl-test.c',
]
hl_include_dirs = [
]
hl_test_deps = [
  greatest_dep,
  hl_dep,
]

if get_option('enable-binaries')
  hl_test_exec = executable('hl-test',
     hl_test_srcs,
     dependencies: hl_test_deps,
     include_directories: [
       inc,
       hl_include_dirs,
     ],
  )
  if get_option('enable-binary-tests')
    test('hl-test', hl_test_exec, args: [])
  endif
endif
