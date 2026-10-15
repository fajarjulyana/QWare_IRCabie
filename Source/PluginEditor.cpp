#include "PluginProcessor.h"
#include "PluginEditor.h"

QWare_IRCabieAudioProcessorEditor::QWare_IRCabieAudioProcessorEditor (QWare_IRCabieAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Memuat background dari BinaryData hasil CMake
    backgroundImages = juce::ImageCache::getFromMemory(
        IRCabieAssets::BinaryData::background_bmp, 
        IRCabieAssets::BinaryData::background_bmpSize
    );

    // Menetapkan ukuran jendela UI tetap di 800x600
    setSize (800, 600);
}

QWare_IRCabieAudioProcessorEditor::~QWare_IRCabieAudioProcessorEditor() {}

void QWare_IRCabieAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Jika gambar background berhasil dimuat, gambar ke layar
    if (backgroundImages.isValid())
    {
        g.drawImageWithin(backgroundImages, 0, 0, getWidth(), getHeight(), 
                          juce::RectanglePlacement::stretchToFit);
    }
    else
    {
        // Fallback warna dasar jika background gagal dimuat
        g.fillAll (juce::Colours::darkgrey);
        g.setColour (juce::Colours::white);
        g.setFont (16.0f);
        g.drawText ("Background BMP Not Found", getLocalBounds(), juce::Justification::centred, true);
    }
}

void QWare_IRCabieAudioProcessorEditor::resized()
{
    // Penataan komponen UI lain (jika nanti ditambahkan di sini)
}