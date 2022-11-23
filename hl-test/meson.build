hl_test_srcs = [
  'hl-test.c',
]
hl_include_dirs = [
]
hl_test_deps = [
  c_greatest_dep,
  c_fsio_dep,
  hl_dep,
  c_stringfn_dep,
  ansi_codes_dep,
  libansilove_dep,
  c_timer_dep,
  bytes_dep,
  bat_dep,
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
endif
