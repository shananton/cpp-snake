project('cpp-snake', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++2a'])

sfmldep = dependency('sfml-graphics')

includes = include_directories('include')
sources = [
  'src/game.cpp',
]

exe = executable('cpp_snake', sources,
  include_directories: includes,
  dependencies: sfmldep)

test('basic', exe)
