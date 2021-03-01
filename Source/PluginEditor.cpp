/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionAudioProcessorEditor::DistortionAudioProcessorEditor (DistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 200);
    
    //replaced deprecated ScopedPtr with unique_ptr
    
    driveKnob = std::make_unique<juce::Slider> ("Drive");
    addAndMakeVisible(*driveKnob);
    driveKnob->setSliderStyle(juce::Slider::Rotary);
    driveKnob->setTextBoxStyle(juce::Slider::NoTextBox, false, 100, 100);
    
    rangeKnob = std::make_unique<juce::Slider> ("Range");
    addAndMakeVisible(*rangeKnob);
    rangeKnob->setSliderStyle(juce::Slider::Rotary);
    rangeKnob->setTextBoxStyle(juce::Slider::NoTextBox, false, 100, 100);
    
    blendKnob = std::make_unique<juce::Slider> ("Blend");
    addAndMakeVisible(*blendKnob);
    blendKnob->setSliderStyle(juce::Slider::Rotary);
    blendKnob->setTextBoxStyle(juce::Slider::NoTextBox, false, 100, 100);
    
    volumeKnob = std::make_unique<juce::Slider> ("Volume");
    addAndMakeVisible(*volumeKnob);
    volumeKnob->setSliderStyle(juce::Slider::Rotary);
    volumeKnob->setTextBoxStyle(juce::Slider::NoTextBox, false, 100, 100);
    
    driveAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(p.getState(), "drive", *driveKnob));
    
    rangeAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(p.getState(), "range", *rangeKnob));
    
    blendAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(p.getState(), "blend", *blendKnob));
    
    volumeAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(p.getState(), "volume", *volumeKnob));
}

DistortionAudioProcessorEditor::~DistortionAudioProcessorEditor()
{
}

//==============================================================================
void DistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void DistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    driveKnob->setBounds(((getWidth()/5)*1) - (100/2), (getHeight()/2) -(100/2), 100, 100);
    rangeKnob->setBounds(((getWidth()/5)*2) - (100/2), (getHeight()/2) -(100/2), 100, 100);
    blendKnob->setBounds(((getWidth()/5)*3) - (100/2), (getHeight()/2) -(100/2), 100, 100);
    volumeKnob->setBounds(((getWidth()/5)*4) - (100/2), (getHeight()/2) -(100/2), 100, 100);
}
