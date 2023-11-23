// File Line: 19
// RVA: 0x15D42C0
__int64 dynamic_initializer_for__HK_TRIGGER_VOLUME_DEBUG_COLOR__()
{
  __int64 result; // rax

  result = hkColor::rgbFromChars(0xFFu, 0xFFu, 0xFFu, 0x70u);
  HK_TRIGGER_VOLUME_DEBUG_COLOR = result;
  return result;
}

