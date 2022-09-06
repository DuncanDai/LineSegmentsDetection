# CMakeList.txt: CMake-Projektdatei der obersten Ebene. Führen Sie hier die globale Konfiguration aus,
# und schließen Sie Unterprojekte ein.
#
project ("test_CMakeProj")

cmake_minimum_required (VERSION 3.8)



# Schließen Sie Unterprojekte ein.
add_subdirectory ("test_CMakeProj")
