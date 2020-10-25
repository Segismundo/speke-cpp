project('speke-cpp', 'cpp',
	default_options: ['cpp_std=c++17'])

# Dependencies
openssl_dep = dependency('openssl')
protobuf_dep = dependency('protobuf')


# Protobuf
protoc = find_program('protoc')
grpc_cpp_plugin = find_program('grpc_cpp_plugin')

gen_protobuf = generator(protoc,
			 output: ['@BASENAME@.pb.cc', '@BASENAME@.pb.h'],
			 arguments: ['--proto_path=@CURRENT_SOURCE_DIR@',
				     '--cpp_out=@BUILD_DIR@',
				     '@INPUT@'])

protobuf_speke_files = gen_protobuf.process(
  'SPEKE.proto',
  preserve_path_from: meson.current_source_dir())


# Executables
speke_sources = ['SPEKE.cpp',
		 'SpekeSession.cpp',
		 'BigNum.cpp']

shared_library('speke-cpp',
	       sources: [speke_sources, protobuf_speke_files],
	       dependencies: [openssl_dep, protobuf_dep])


# Tests
gtest = meson.get_compiler('cpp').find_library('gtest', required: false)
if gtest.found()
  test_all = executable('test_all',
			sources: ['test/main.cpp',
				  'test/test-SPEKE.cpp',
				  'test/test-SpekeSession.cpp',
				  speke_sources,
				  protobuf_speke_files],
			link_args: ['-lpthread'],
			dependencies: [gtest, openssl_dep, protobuf_dep])
  test('all', test_all)
endif
