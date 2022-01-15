/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainPluginAudioProcessorEditor::GainPluginAudioProcessorEditor (GainPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    gainSlider.setSliderStyle (juce::Slider::SliderStyle::Rotary);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    gainSlider.setRange(-60.0f, 0.0f, 0.01f);
    gainSlider.setValue(-20.0f);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
    
    setSize (200, 300);
}

GainPluginAudioProcessorEditor::~GainPluginAudioProcessorEditor()
{
}

//==============================================================================
void GainPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void GainPluginAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth()/2 - 50, getHeight()/2 - 75, 100, 150);
}

void GainPluginAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if (slider == &gainSlider)
    {
        audioProcessor.gain = gainSlider.getValue();
    }
}
