#include "PluginEditor.h"
#include "PluginProcessor.h"

void RectComponent::paint(Graphics &g) {
  g.fillAll(juce::Colours::black);

  g.setColour(juce::Colours::red);
  g.drawText("Center", getLocalBounds(), Justification::centred, false);
}

FilterBankEditor::FilterBankEditor(FilterBankAudioProcessor &p)
    : AudioProcessorEditor(&p) {
  addAndMakeVisible(m_rect_component);

  m_openGL.setOpenGLVersionRequired(
      juce::OpenGLContext::OpenGLVersion::openGL3_2);
  setOpaque(false);
  
  m_openGL.setContinuousRepainting(true);
  m_openGL.setRenderer(this);
  m_openGL.attachTo(*this);

  setSize(800, 600);
}

FilterBankEditor::~FilterBankEditor() { m_openGL.detach(); }

void FilterBankEditor::paint(Graphics &g) { g.fillAll(juce::Colours::red); }

void FilterBankEditor::resized() {
  m_rect_component.setBounds(getLocalBounds().reduced(2));
}

void FilterBankEditor::newOpenGLContextCreated() {}

void FilterBankEditor::renderOpenGL() {}

void FilterBankEditor::openGLContextClosing() {}