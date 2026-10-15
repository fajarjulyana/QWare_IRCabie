#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
#include "PluginProcessor.h"
#include <IRCabieAssets/BinaryData.h>

class QWare_IRCabieAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    QWare_IRCabieAudioProcessorEditor (QWare_IRCabieAudioProcessor&);
    ~QWare_IRCabieAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    QWare_IRCabieAudioProcessor& audioProcessor;
    juce::Image backgroundImages;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QWare_IRCabieAudioProcessorEditor)
};