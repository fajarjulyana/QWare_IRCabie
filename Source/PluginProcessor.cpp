#include "PluginProcessor.h"
#include "PluginEditor.h"

QWare_IRCabieAudioProcessor::QWare_IRCabieAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

QWare_IRCabieAudioProcessor::~QWare_IRCabieAudioProcessor() {}

const juce::String QWare_IRCabieAudioProcessor::getName() const { return JucePlugin_Name; }
bool QWare_IRCabieAudioProcessor::acceptsMidi() const { return false; }
bool QWare_IRCabieAudioProcessor::producesMidi() const { return false; }
bool QWare_IRCabieAudioProcessor::isMidiEffect() const { return false; }
double QWare_IRCabieAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int QWare_IRCabieAudioProcessor::getNumPrograms() { return 1; }
int QWare_IRCabieAudioProcessor::getCurrentProgram() { return 0; }
void QWare_IRCabieAudioProcessor::setCurrentProgram (int) {}
const juce::String QWare_IRCabieAudioProcessor::getProgramName (int) { return {}; }
void QWare_IRCabieAudioProcessor::changeProgramName (int, const juce::String&) {}

void QWare_IRCabieAudioProcessor::prepareToPlay (double, int) {}
void QWare_IRCabieAudioProcessor::releaseResources() {}

#ifndef JucePlugin_PreferredChannelConfigurations
bool QWare_IRCabieAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void QWare_IRCabieAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

    }
}

bool QWare_IRCabieAudioProcessor::hasEditor() const { return true; }

juce::AudioProcessorEditor* QWare_IRCabieAudioProcessor::createEditor()
{
    return new QWare_IRCabieAudioProcessorEditor (*this);
}

void QWare_IRCabieAudioProcessor::getStateInformation (juce::MemoryBlock&) {}
void QWare_IRCabieAudioProcessor::setStateInformation (const void*, int) {}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new QWare_IRCabieAudioProcessor();
}