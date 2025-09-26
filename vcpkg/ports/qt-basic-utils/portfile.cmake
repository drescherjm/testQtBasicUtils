set(GIT_REF_of_library e90bc3b5a4721c590d22603019846191120bbc2a)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO drescherjm/QtBasicUtils
    REF ${GIT_REF_of_library} 
    SHA512 180ae6562e9d56d12ece34b986bc7ebe247262e66b361873c3be1fdc6132e38ec6bc5a758f779d353b5e9703cbf2abe0fefc262a8947c84d3d5510f36a597266
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
