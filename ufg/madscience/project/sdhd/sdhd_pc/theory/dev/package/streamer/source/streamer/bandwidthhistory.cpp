// File Line: 121
// RVA: 0x146FC60
__int64 UFG::BandwidthHistory::_dynamic_initializer_for__smBandwidthMutex__()
{
  UFG::qMutex::qMutex(&UFG::BandwidthHistory::smBandwidthMutex, &customWorldMapCaption);
  return atexit(UFG::BandwidthHistory::_dynamic_atexit_destructor_for__smBandwidthMutex__);
}

// File Line: 123
// RVA: 0x146FD10
__int64 UFG::BandwidthHistory::_dynamic_initializer_for__smFilePostionOverlays__()
{
  return atexit(UFG::BandwidthHistory::_dynamic_atexit_destructor_for__smFilePostionOverlays__);
}

// File Line: 131
// RVA: 0x146FCF0
__int64 UFG::BandwidthHistory::_dynamic_initializer_for__smDiskReads__()
{
  return atexit(UFG::BandwidthHistory::_dynamic_atexit_destructor_for__smDiskReads__);
}

// File Line: 254
// RVA: 0x229710
signed __int64 __fastcall UFG::BandwidthHistory::GetCategoryFromFilename(const char *filename)
{
  const char *v1; // rbx
  unsigned int v2; // edi

  v1 = filename;
  v2 = 0;
  if ( UFG::qStringFindInsensitive(filename, "game.big") )
    v2 = 0;
  if ( UFG::qStringFindInsensitive(v1, "ui.big") )
    return 5i64;
  if ( UFG::qStringFindInsensitive(v1, "pck") )
    return 1i64;
  if ( UFG::qStringFindInsensitive(v1, "animation") )
    return 2i64;
  if ( UFG::qStringFindInsensitive(v1, "props_new") || UFG::qStringFindInsensitive(v1, "characters") )
    return 3i64;
  if ( UFG::qStringFindInsensitive(v1, "vehicles") )
    return 4i64;
  if ( UFG::qStringFindInsensitive(v1, "Global") )
    v2 = 6;
  return v2;
}

// File Line: 686
// RVA: 0x146F890
__int64 UFG::BandwidthHistory::_dynamic_initializer_for__font_handle__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&UFG::BandwidthHistory::font_handle.mPrev);
  return atexit(UFG::BandwidthHistory::_dynamic_atexit_destructor_for__font_handle__);
}

