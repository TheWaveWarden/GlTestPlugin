#pragma once

#include <JuceHeader.h>
using namespace juce;

class FilterBankAudioProcessor;

class RectComponent : public Component {
public:
  void paint(Graphics &g) override;
};

class FilterBankEditor : public AudioProcessorEditor,
                         public juce::OpenGLRenderer {
public:
  FilterBankEditor(FilterBankAudioProcessor &);
  ~FilterBankEditor();

  void paint(Graphics &) override;
  void resized() override;

  // ========= we have an openGL context and one component ============

  juce::OpenGLContext m_openGL;
  RectComponent m_rect_component;

  void newOpenGLContextCreated() override;
  void renderOpenGL() override;
  void openGLContextClosing() override;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FilterBankEditor)
};