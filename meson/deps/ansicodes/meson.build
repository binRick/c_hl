ansicodes_lib = library('ansicodes', 
  #//'../../../vendor/ansicodes/rgb2ansi.c',
#//'../../../vendor/ansicodes/ansidb.c',
#'../../../vendor/ansicodes/rgbansi.c',
install: false, dependencies: [], 
  include_directories: [
'../../../vendor/ansicodes',
  ]
)
ansi_codes_dep = declare_dependency(include_directories: [
'../../../vendor/ansicodes',
  ], link_with: ansicodes_lib)
#deps += b64_dep
