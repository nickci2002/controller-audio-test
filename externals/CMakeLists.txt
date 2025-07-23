# FFmpeg
if (NOT TARGET FFmpeg::ffmpeg)
    add_subdirectory(ffmpeg)
    add_library(FFmpeg::ffmpeg ALIAS ffmpeg)
endif()

# SDL3
if (NOT TARGET SDL3::SDL3)
    set(SDL_TEST_LIBRARY OFF)
    set(SDL_PIPEWIRE OFF)
    add_subdirectory(sdl)
endif()