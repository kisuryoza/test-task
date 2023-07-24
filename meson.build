project('test-task', 'cpp')

sources = [
   'src/main.cpp',
   'src/processFiles.cpp',
   'src/Point2D.cpp',
   'src/Polygon.cpp',
   'src/Segment.cpp',
]

bin = executable('bin',
    sources,
    cpp_args : [
      '-Wall',
      '-std=c++20',
      # '-fconcepts-ts',
      '-static',
      ],
    # link_args : '',
)

# for development purposes
# custom_target('Symlinking compile_commands.json to parent dir',
#           depends : bin,
#           output : 'fake',
#           command : ['ln', '-sf', meson.current_build_dir() + '/compile_commands.json', '..'],
#           build_by_default : true)
