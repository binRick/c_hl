db_test_srcs = [
  'db-test.c',
]
db_include_dirs = [
]
db_test_deps = [
  greatest_dep,
  c_stringfn_dep,
  db_dep,
]

if get_option('enable-binaries')
  db_test_exec = executable('db-test',
     [
      db_test_srcs,
     ],
     dependencies: db_test_deps,
     include_directories: [
       db_include_dirs,
       inc,
     ],
  )
  if get_option('enable-binary-tests')
    test('db-test', db_test_exec, args: [])
  endif
endif
