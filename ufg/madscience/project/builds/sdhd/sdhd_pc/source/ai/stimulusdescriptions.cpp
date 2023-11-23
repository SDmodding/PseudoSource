// File Line: 167
// RVA: 0x14B3160
UFG::`dynamic initializer for 'g_StimulusDescriptions''

// File Line: 2069
// RVA: 0x14B6D00
__int64 UFG::_dynamic_initializer_for__g_StimulusEventHash__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Stimulus", 0xFFFFFFFF);
  UFG::g_StimulusEventHash = result;
  return result;
}

// File Line: 2070
// RVA: 0x14B3120
__int64 UFG::_dynamic_initializer_for__g_StimulusChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::g_StimulusChannel, UFG::g_StimulusEventHash, "Stimulus", qword_1423BFB20);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__g_StimulusChannel__);
}

