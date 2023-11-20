// File Line: 32
// RVA: 0xA751D0
void __fastcall AkAudioLibSettings::SetSampleFrequency(unsigned int in_uSampleFrequency)
{
  AkAudioLibSettings::g_pipelineCoreFrequency = in_uSampleFrequency;
  AkAudioLibSettings::g_msPerBufferTick = (signed int)(float)(1024.0
                                                            / (float)((float)(signed int)in_uSampleFrequency * 0.001));
  AkAudioLibSettings::g_pcWaitTime = (signed int)(float)((float)(1024000.0 / (float)(signed int)in_uSampleFrequency)
                                                       * 0.5);
  AkAudioLibSettings::g_uLpfUpdatePeriod = (in_uSampleFrequency << 7) / 0xBB80;
}

