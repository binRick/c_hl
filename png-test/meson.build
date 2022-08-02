png_test_srcs = [
  'png-test.c',
]
png_include_dirs = [
]
png_test_deps = [
  c_greatest_dep,
  png_dep,
]

if get_option('enable-binaries')
  png_test_exec = executable('png-test',
     png_test_srcs,
     dependencies: png_test_deps,
     include_directories: [
       inc,
       png_include_dirs,
     ],
  )
  if get_option('enable-binary-tests')
    test('png-test', png_test_exec, args: [])
  endif
endif
