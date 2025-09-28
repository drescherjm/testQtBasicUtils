set(GIT_REF_of_library 94ba8c905bd558d680a5557f62dc7fcb9b93fa00)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO drescherjm/QtBasicUtils
    REF ${GIT_REF_of_library} 
    SHA512 a2b39f7b3e0621fa3c2dafa4eb7d8e2d03a89e125770a208c440fe4fff5dd56e41d869e5bdec2f0e0dbcf06bdd7bba47fbdc10f7030314487413abbf44207c2b
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
