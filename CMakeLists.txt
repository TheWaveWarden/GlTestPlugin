cmake_minimum_required(VERSION 3.15)
project("GLTestPlugin")

add_subdirectory(JUCE)

option(FBANK_COPY_PLUGIN_AFTER_BUILD "Copy JUCE Plugins after built" ON)

juce_add_plugin(GLTestPlugin
  VERSION "1.0.0"
  COMPANY_NAME "TheWaveWarden"
  COMPANY_WEBSITE "https://thewavewarden.com"
  COMPANY_EMAIL "info@thewavewarden.com"

  FORMATS
    "VST3"
    "AU"
    "Standalone"
  PLUGIN_MANUFACTURER_CODE "WAWA"
  PLUGIN_CODE "Glte"
  NEEDS_MIDI_INPUT FALSE
  AU_MAIN_TYPE "kAudioUnitType_Effect"
  COPY_PLUGIN_AFTER_BUILD ${FBANK_COPY_PLUGIN_AFTER_BUILD}
)

juce_generate_juce_header(GLTestPlugin)

target_compile_definitions(GLTestPlugin
  PUBLIC
    JUCE_STRICT_REFCOUNTEDPOINTER=1
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
    JUCE_WEB_BROWSER=0
    JUCE_DISPLAY_SPLASH_SCREEN=0
)

target_sources(GLTestPlugin
  PRIVATE
    "Source/PluginEditor.cpp"
    "Source/PluginProcessor.cpp"
)

target_link_libraries(GLTestPlugin
  PRIVATE
    juce::juce_audio_basics
    juce::juce_audio_devices
    juce::juce_audio_formats
    juce::juce_audio_plugin_client
    juce::juce_audio_processors
    juce::juce_audio_utils
    juce::juce_core
    juce::juce_cryptography
    juce::juce_data_structures
    juce::juce_dsp
    juce::juce_events
    juce::juce_graphics
    juce::juce_gui_basics
    juce::juce_gui_extra
    juce::juce_opengl
  PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
)
