#include "PluginProcessor.h"
#include "PluginEditor.h"

FilterBankAudioProcessor::FilterBankAudioProcessor()
    : AudioProcessor(
          BusesProperties()
              .withInput("Input", juce::AudioChannelSet::stereo(), true)
              .withOutput("Output", AudioChannelSet::stereo(), true)) {}

FilterBankAudioProcessor::~FilterBankAudioProcessor() {}

//==============================================================================
const String FilterBankAudioProcessor::getName() const {
  return JucePlugin_Name;
}

bool FilterBankAudioProcessor::acceptsMidi() const {
#if JucePlugin_WantsMidiInput
  return true;
#else
  return false;
#endif
}

bool FilterBankAudioProcessor::producesMidi() const {
#if JucePlugin_ProducesMidiOutput
  return true;
#else
  return false;
#endif
}

bool FilterBankAudioProcessor::isMidiEffect() const {
#if JucePlugin_IsMidiEffect
  return true;
#else
  return false;
#endif
}

double FilterBankAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int FilterBankAudioProcessor::getNumPrograms() {
  return 1; // NB: some hosts don't cope very well if you tell them there are 0
            // programs,
  // so this should be at least 1, even if you're not really implementing
  // programs.
}

int FilterBankAudioProcessor::getCurrentProgram() { return 0; }

void FilterBankAudioProcessor::setCurrentProgram(int index) { (void)index; }

const String FilterBankAudioProcessor::getProgramName(int index) {
  (void)index;
  return {};
}

void FilterBankAudioProcessor::changeProgramName(int index,
                                                 const String &newName) {
  (void)index;
  (void)newName;
}

//==============================================================================
void FilterBankAudioProcessor::prepareToPlay(double sampleRate,
                                             int samplesPerBlock) {}

void FilterBankAudioProcessor::releaseResources() {}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FilterBankAudioProcessor::isBusesLayoutSupported(
    const BusesLayout &layouts) const {
  (void)layouts;
#if JucePlugin_IsMidiEffect
  ignoreUnused(layouts);
  return true;
#else
  // This is the place where you check if the layout is supported.
  // In this template code we only support mono or stereo.
  if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono() &&
      layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
    return false;

// This checks if the input layout matches the output layout
#if !JucePlugin_IsSynth
  if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
    return false;
#endif

  return true;
#endif
}
#endif

void FilterBankAudioProcessor::processBlock(AudioBuffer<float> &buffer,
                                            MidiBuffer &midiMessages) {
  buffer.clear();
}

bool FilterBankAudioProcessor::hasEditor() const { return true; }

AudioProcessorEditor *FilterBankAudioProcessor::createEditor() {
  return new FilterBankEditor(*this);
}

AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
  return new FilterBankAudioProcessor();
}

void FilterBankAudioProcessor::getStateInformation(MemoryBlock &destData) {}

void FilterBankAudioProcessor::setStateInformation(const void *data,
                                                   int sizeInBytes) {}
