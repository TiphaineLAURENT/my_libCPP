file(REMOVE_RECURSE
  "libmy_libCPP.pdb"
  "libmy_libCPP.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/my_libCPP.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
