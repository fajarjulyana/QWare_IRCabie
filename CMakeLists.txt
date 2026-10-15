cmake_minimum_required(VERSION 3.22)
project(QWare_IRCabie VERSION 1.0.0 LANGUAGES CXX)

# --- Fetch JUCE 7.0.9 secara otomatis dari GitHub ---
include(FetchContent)

FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG        7.0.9
)

FetchContent_MakeAvailable(JUCE)

# --- Konfigurasi Binary Data untuk Assets ---
juce_add_binary_data(IRCabieAssets
    SOURCES
        Assets/background.bmp
        Assets/icon.ico
        Assets/knob_sprites.png
        Assets/switch_sprites.png
)

# --- Konfigurasi Target Plugin Utama ---
juce_add_plugin(QWare_IRCabie
    COMPANY_NAME "QWare.id"
    PLUGIN_NAME "IRCabie"
    FORMATS VST3 Standalone
    PRODUCT_NAME "QWare IRCabie"
)

# --- Daftarkan Source Files Secara Eksplisit ---
target_sources(QWare_IRCabie
    PRIVATE
        Source/PluginProcessor.cpp
        Source/PluginProcessor.h
        Source/PluginEditor.cpp
        Source/PluginEditor.h
)

# --- HUBUNGKAN IRCabieAssets DAN MODUL JUCE ---
target_link_libraries(QWare_IRCabie
    PRIVATE
        IRCabieAssets  # <-- Ini yang membuat folder BinaryData.h otomatis terbaca!
        juce::juce_audio_utils
        juce::juce_audio_plugin_client
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

# --- Mematikan VST2 Wrapper agar tidak mencari vstfxstore.h ---
target_compile_definitions(QWare_IRCabie_VST3
    PUBLIC
        JUCE_VST3_CAN_REPLACE_VST2=0
)