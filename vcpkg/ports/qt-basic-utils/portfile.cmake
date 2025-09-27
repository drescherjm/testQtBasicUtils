set(GIT_REF_of_library 614ec6c4aa2860bceb314eb28fa085c6db1b4a5a)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO drescherjm/QtBasicUtils
    REF ${GIT_REF_of_library} 
    SHA512 6157f7b605c0d8974de79c36d9c49956d35a96d15e74eb503358ffa8cff7f1120ed1b6dcdd512cafc9a8265d59b095b9d5f40f0bbf3feb8ea487b5a3f1ac7448
	#Note: The SHA512 will need to change if you change the GIT_REF_of_library. The next CMake configure will fail and tell you
	#the new SHA512 code. Copy and paste the note: Actual  : SHA512 hash code above.
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
)

vcpkg_cmake_build()
vcpkg_cmake_install()

# Fixup cmake config locations and paths. This is essential for vcpkg to setup the SimpleLibraryExampleConfig.cmake file 
# and setup each configuration for multiconfig generators like Visual Studio 2022. 
# Remember that vcpkg builds the Debug and Release config then maps the other configs: MinSizeRel, RelWithDebInfo to
# use the binaries created for the Release config. 
vcpkg_cmake_config_fixup(PACKAGE_NAME QtBasicUtils CONFIG_PATH lib/cmake/QtBasicUtils)

# Install license into share/${PORT}/
file(INSTALL "${SOURCE_PATH}/LICENSE" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}")
