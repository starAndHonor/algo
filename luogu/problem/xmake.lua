target("1175")
    set_kind("binary")
    add_files("1175.cpp")

target("1772")
    set_kind("binary")
    add_files("1772.cpp")

target("2661")
    set_kind("binary")
    add_files("2661.cpp")

target("3812")
    set_kind("binary")
    add_files("3812.cpp")

target("4310")
    set_kind("binary")
    add_files("4310.cpp")

target("AT46")
    set_kind("binary")
    add_files("AT46.cpp")

target("P1006")
    set_kind("binary")
    add_files("P1006.cpp")

target("P1030")
    set_kind("binary")
    add_files("P1030.cpp")

target("P1063")
    set_kind("binary")
    add_files("P1063.cpp")

target("P1087")
    set_kind("binary")
    add_files("P1087.cpp")

target("P1119")
    set_kind("binary")
    add_files("P1119.cpp")

target("P1197")
    set_kind("binary")
    add_files("P1197.cpp")

target("P1234")
    set_kind("binary")
    add_files("P1234.cpp")

target("P1332")
    set_kind("binary")
    add_files("P1332.cpp")

target("P1352")
    set_kind("binary")
    add_files("P1352.cpp")

target("P1387")
    set_kind("binary")
    add_files("P1387.cpp")

target("P1396")
    set_kind("binary")
    add_files("P1396.cpp")

target("P1455")
    set_kind("binary")
    add_files("P1455.cpp")

target("P1638")
    set_kind("binary")
    add_files("P1638.cpp")

target("P1681")
    set_kind("binary")
    add_files("P1681.cpp")

target("P1955")
    set_kind("binary")
    add_files("P1955.cpp")

target("P2068")
    set_kind("binary")
    add_files("P2068.cpp")

target("P2170")
    set_kind("binary")
    add_files("P2170.cpp")

target("P2796")
    set_kind("binary")
    add_files("P2796.cpp")

target("P3078")
    set_kind("binary")
    add_files("P3078.cpp")

target("P3373")
    set_kind("binary")
    add_files("P3373.cpp")

target("P3535")
    set_kind("binary")
    add_files("P3535.cpp")

target("P3958")
    set_kind("binary")
    add_files("P3958.cpp")

target("P5146")
    set_kind("binary")
    add_files("P5146.cpp")

--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

