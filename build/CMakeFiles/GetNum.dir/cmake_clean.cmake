file(REMOVE_RECURSE
  "libGetNum.a"
  "libGetNum.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/GetNum.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
