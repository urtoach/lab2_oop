{ pkgs }: {
	deps = [
		pkgs.valgrind
  pkgs.nano
  pkgs.cmake
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}