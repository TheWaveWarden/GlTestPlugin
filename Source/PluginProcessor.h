#pragma once

#include <JuceHeader.h>
using namespace juce;

class FilterBankEditor;

class FilterBankAudioProcessor : public AudioProcessor {
public:
  FilterBankAudioProcessor();
  ~FilterBankAudioProcessor();
  void prepareToPlay(double sampleRate, int samplesPerBlock) override;
  void releaseResources() override;

  void processBlock(AudioBuffer<float> &, MidiBuffer &) override;
  AudioProcessorEditor *createEditor() override;
  bool hasEditor() const override;
  const String getName() const override;
  bool acceptsMidi() const override;
  bool producesMidi() const override;
  bool isMidiEffect() const override;
  double getTailLengthSeconds() const override;
  int getNumPrograms() override;
  int getCurrentProgram() override;
  void setCurrentProgram(int index) override;
  const String getProgramName(int index) override;
  void changeProgramName(int index, const String &newName) override;
  void getStateInformation(MemoryBlock &destData) override;
  void setStateInformation(const void *data, int sizeInBytes) override;
  void loadStateFromBinaryData(const void *p_data, size_t p_size);
  void loadStateWithFileChooser();
  void saveStateWithFileChooser();
  void saveStateToLocation(StringRef p_abs_location);
  void loadStateFromLocation(StringRef p_abs_location);
  void deletePreset(StringRef p_abs_location);
  void setPresetMetaData(const String &p_name, const String &p_author,
                         const String &p_comment, const String &p_category);
  void setSamplerate(float p_samplerate, size_t p_process_size);

  bool isBusesLayoutSupported(const BusesLayout &layouts) const;

private:
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FilterBankAudioProcessor)
};